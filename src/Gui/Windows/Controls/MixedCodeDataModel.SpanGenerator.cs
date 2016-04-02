﻿#region License
/* 
 * Copyright (C) 1999-2016 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Reko.Core;
using Reko.Core.Lib;
using Reko.Core.Machine;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;

namespace Reko.Gui.Windows.Controls
{
   public partial class MixedCodeDataModel
   {
        public LineSpan[] GetLineSpans(int count)
        {
            addrCur = SanitizeAddress(addrCur);

            var spans = new List<LineSpan>();
            ImageSegment seg;
            ImageMapItem item;
            program.ImageMap.TryFindSegment(addrCur, out seg);
            program.ImageMap.TryFindItem(addrCur, out item);

            SpanGenerator sp = CreateSpanifier(item, addrCur);
            while (count != 0 && seg != null && item != null)
            {
                bool memValid =
                    seg.MemoryArea.IsValidAddress(addrCur) &&
                    item.IsInRange(addrCur);

                if (memValid)
                {
                    var tuple = sp.GenerateSpan();
                    if (tuple != null)
                    {
                        addrCur = tuple.Item1;
                        spans.Add(tuple.Item2);
                        --count;
                    }
                    else
                    {
                        sp = null;
                    }
                }
                if (sp == null || !memValid)
                {
                    if (!memValid || !program.ImageMap.TryFindItem(addrCur, out item))
                    {
                        // Find next segment.
                        Address addrSeg;
                        if (program.ImageMap.Segments.TryGetUpperBoundKey(addrCur, out addrSeg))
                        {
                            program.ImageMap.TryFindSegment(addrSeg, out seg);
                            program.ImageMap.TryFindItem(addrSeg, out item);
                            addrCur = addrSeg;
                            sp = CreateSpanifier(item, addrCur);
                        }
                        else
                        {
                            seg = null;
                            item = null;
                            addrCur = addrEnd;
                            break;
                        }
                    }
                    sp = CreateSpanifier(item, addrCur);
                }
            }
            addrCur = SanitizeAddress(addrCur);
            return spans.ToArray();
        }

        private SpanGenerator CreateSpanifier(ImageMapItem item, Address addr)
        {
            SpanGenerator sp;
            var b = item as ImageMapBlock;
            if (b != null)
            {
                sp = new AsmSpanifyer(program, instructions[b], addr);
            }
            else
            {
                sp = new MemSpanifyer(program, item, addr);
            }

            return sp;
        }

        public abstract class SpanGenerator
        {
            public abstract Tuple<Address, LineSpan> GenerateSpan();
        }

        public class AsmSpanifyer : SpanGenerator
        {
            private Program program;
            private MachineInstruction[] instrs;
            private int offset;

            public AsmSpanifyer(Program program, MachineInstruction[] instrs, Address addr)
            {
                this.instrs = instrs;
                this.offset = FindIndexOfInstructionAddress(instrs, addr);
                this.program = program;
            }

            public override Tuple<Address, LineSpan> GenerateSpan()
            {
                if (offset >= instrs.Length || offset < 0)
                    return null;
                var instr = instrs[offset];
                ++offset;
                return Tuple.Create(
                    instr.Address + instr.Length,
                    DisassemblyTextModel.RenderAsmLine(program, instr));
            }
        }

        public class MemSpanifyer : SpanGenerator
        {
            private Program program;
            public Address addr;
            public ImageMapItem item;

            public MemSpanifyer(Program program, ImageMapItem item, Address addr)
            {
                this.program = program;
                this.item = item;
                this.addr = addr;
            }

            public override Tuple<Address, LineSpan> GenerateSpan()
            {
                var line = new List<TextSpan>();
                line.Add(new AddressSpan(addr.ToString(), addr, UiStyles.MemoryWindow));

                var addrStart = Align(addr, BytesPerLine);
                var addrEnd = Address.Min(addrStart + BytesPerLine, item.Address + item.Size);
                var linStart = addrStart.ToLinear();
                var linEnd = addrEnd.ToLinear();
                var lin = linStart;
                var cbFiller = addr.ToLinear() - linStart;
                var cbBytes = linEnd - addr.ToLinear();
                var cbPadding = BytesPerLine - (cbFiller + cbBytes);

                var sb = new StringBuilder();
                var abCode = new List<byte>();

                // Do any filler first

                if (cbFiller > 0)
                {
                    line.Add(new MemoryTextSpan(new string(' ', 3 * (int)cbFiller), UiStyles.MemoryWindow));
                }

                var rdr = program.CreateImageReader(addr);
                while (rdr.Address.ToLinear() < linEnd)
                {
                    if (rdr.IsValid)
                    {
                        byte b = rdr.ReadByte();
                        sb.AppendFormat(" {0:X2}", b);
                        //$BUG: should use platform.Encoding
                        abCode.Add(b);
                    }
                    else
                    {
                        cbPadding = linEnd - rdr.Address.ToLinear();
                        addrEnd = rdr.Address;
                        break;
                    }
                }
                line.Add(new MemoryTextSpan(sb.ToString(), UiStyles.MemoryWindow));

                // Do any padding after.

                if (cbPadding > 0)
                {
                    line.Add(new MemoryTextSpan(new string(' ', 3 * (int)cbPadding), UiStyles.MemoryWindow));
                }

                // Now display the code bytes.
                string sBytes = RenderBytesAsText(abCode.ToArray());
                line.Add(new MemoryTextSpan(" ", UiStyles.MemoryWindow));
                line.Add(new MemoryTextSpan(sBytes, UiStyles.MemoryWindow));

                this.addr = addrEnd;
                return Tuple.Create(
                    addrEnd,
                    new LineSpan(addr, line.ToArray()));
            }

            private string RenderBytesAsText(byte[] abCode)
            {
                var chars = program.TextEncoding.GetChars(abCode.ToArray());
                for (int i = 0; i < chars.Length; ++i)
                {
                    char ch = chars[i];
                    if (char.IsControl(ch) || char.IsSurrogate(ch))
                        chars[i] = '.';
                }

                return new string(chars);
            }
        }

        //$PERF: could benefit from a binary search, but basic blocks
        // are so small it may not make a difference.
        public static int FindIndexOfInstructionAddress(MachineInstruction[] instrs, Address addr)
        {
            var ul = addr.ToLinear();
            return Array.FindIndex(
                instrs,
                i => i.Contains(addr));
        }

        /// <summary>
        /// An segment of memory
        /// </summary>
        public class MemoryTextSpan : TextSpan
        {
            private string text;

            public MemoryTextSpan(string text, string style)
            {
                this.text = text;
                base.Style = style;
            }

            public override string GetText()
            {
                return text;
            }

            public override SizeF GetSize(string text, Font font, Graphics g)
            {
                SizeF sz = base.GetSize(text, font, g);
                return sz;
            }
        }

        /// <summary>
        /// An inert text span is not clickable nor has a context menu.
        /// </summary>
        public class InertTextSpan : TextSpan
        {
            private string text;

            public InertTextSpan(string text, string style)
            {
                this.text = text;
                base.Style = style;
            }

            public override string GetText()
            {
                return text;
            }

            public override SizeF GetSize(string text, Font font, Graphics g)
            {
                SizeF sz = base.GetSize(text, font, g);
                return sz;
            }
        }

    }
}
