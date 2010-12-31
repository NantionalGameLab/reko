﻿#region License
/* 
 * Copyright (C) 1999-2011 John Källén.
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

using Decompiler.Arch.Intel;
using Decompiler.Assemblers.x86;
using Decompiler.Core;
using Decompiler.Core.Expressions;
using Decompiler.Core.Rtl;
using Decompiler.Core.Types;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;

namespace Decompiler.UnitTests.Arch.Intel
{
    [TestFixture]
    public partial class X86RewriterTests
    {
        private IntelArchitecture arch;
        private IntelArchitecture arch32;
        private IntelEmitter emitter;
        private RewriterHost host;
        private IntelState state;

        public X86RewriterTests()
        {
            arch = new IntelArchitecture(ProcessorMode.Real);
            arch32 = new IntelArchitecture(ProcessorMode.ProtectedFlat);
        }

        [SetUp]
        public void Setup()
        {
            host = new RewriterHost();
            state = new IntelState();
        }

        private IntelAssembler Create16bitAssembler()
        {
            emitter = new IntelEmitter();
            return new IntelAssembler(arch, new Address(0xC00, 0x000), emitter, new List<EntryPoint>());
        }

        private IntelAssembler Create32bitAssembler()
        {
            emitter = new IntelEmitter();
            return new IntelAssembler(arch32, new Address(0x10000000), emitter, new List<EntryPoint>());
        }

        private void AssertCode(string expected, IEnumerator<RtlInstruction> e)
        {
            Assert.IsTrue(e.MoveNext());
            Assert.AreEqual(expected, e.Current.ToString());
        }

        private void AssertCode(IEnumerator<RtlInstruction> e, params string[] expected)
        {
            int i = 0;
            while (i < expected.Length && e.MoveNext())
            {
                Assert.AreEqual(expected[i], string.Format("{0}|{1}", i, e.Current.ToString()));
                ++i;
            }
            Assert.AreEqual(expected.Length, i, "Expected " + expected.Length + " instructions.");
            Assert.IsFalse(e.MoveNext());
        }

        private void AssertCode(uint expectedAddr, string expected, IEnumerator<RtlInstruction> e)
        {
            Assert.IsTrue(e.MoveNext());
            Assert.AreEqual(expectedAddr, e.Current.Address.Linear, "Linear address was not as expected.");
            Assert.AreEqual(expected, e.Current.ToString(), "Instruction was not rewritten as expected");
        }

        private class RewriterHost : IRewriterHost2
        {
            private Dictionary<string, PseudoProcedure> ppp = new Dictionary<string,PseudoProcedure>();

            public PseudoProcedure EnsurePseudoProcedure(string name, DataType returnType, int arity)
            {
                PseudoProcedure p;
                if (ppp.TryGetValue(name, out p))
                    return p;
                p = new PseudoProcedure(name, returnType, arity);
                ppp.Add(name, p);
                return p;
            }

            public ProcedureSignature GetCallSignatureAtAddress(Address addrCallInstruction)
            {
                throw new NotImplementedException();
            }
        }

        [Test]
        public void MovAxBx()
        {
            var m = Create16bitAssembler();
            m.Mov(m.ax, m.bx);
            var rw = CreateRewriter(m);
            var e = rw.GetEnumerator();
            AssertCode("0C00:0000(2) ax = bx", e);
        }

        private X86Rewriter CreateRewriter(IntelAssembler m)
        {
            return new X86Rewriter(arch, host, state,  m.GetImage().CreateReader(0),new Frame(arch.WordWidth));
        }

        private X86Rewriter CreateRewriter32(IntelAssembler m)
        {
            return new X86Rewriter(arch32, host,  state, m.GetImage().CreateReader(0), new Frame(arch32.WordWidth));
        }

        [Test]
        public void MovStackArgument()
        {
            var m = Create16bitAssembler();
            m.Mov(m.ax, m.MemW(Registers.bp, -8));
            var e = CreateRewriter(m).GetEnumerator();
            AssertCode("0C00:0000(3) ax = Mem0[ss:bp - 0x0008:word16]", e);
        }

        [Test]
        public void AddToReg()
        {
            var m = Create16bitAssembler();
            m.Add(m.ax, m.MemW(Registers.si, 4));
            var e = CreateRewriter(m).GetEnumerator();
            AssertCode("0C00:0000(3) ax = ax + Mem0[ds:si + 0x0004:word16]", e);
            AssertCode("0C00:0000(3) SCZO = cond(ax)", e);
        }

        [Test]
        public void AddToMem()
        {
            var m = Create16bitAssembler();
            m.Add(m.WordPtr(0x1000), 3);
            var e = CreateRewriter(m).GetEnumerator();
            AssertCode("0C00:0000(5) v3 = Mem0[ds:0x1000:word16] + 0x0003", e);
            AssertCode("0C00:0000(5) Mem0[ds:0x1000:word16] = v3", e);
            AssertCode("0C00:0000(5) SCZO = cond(v3)", e);
        }

        [Test]
        public void Sub()
        {
            var m = Create16bitAssembler();
            m.Sub(m.ecx, 0x12345);
            var e = CreateRewriter(m).GetEnumerator();
            AssertCode("0C00:0000(7) ecx = ecx - 0x00012345", e);
            AssertCode("0C00:0000(7) SCZO = cond(ecx)", e);
        }

        [Test]
        public void Or()
        {
            var m = Create16bitAssembler();
            m.Or(m.ax, m.dx);
            var e = CreateRewriter(m).GetEnumerator();
            AssertCode("0C00:0000(2) ax = ax | dx", e);
            AssertCode("0C00:0000(2) SZO = cond(ax)", e);
            AssertCode("0C00:0000(2) C = false", e);
        }

        [Test]
        public void And()
        {
            var m = Create16bitAssembler();
            m.And(m.si, m.Imm(0x32));
            var e = CreateRewriter(m).GetEnumerator();
            AssertCode("0C00:0000(3) si = si & 0x0032", e);
            AssertCode("0C00:0000(3) SZO = cond(si)", e);
            AssertCode("0C00:0000(3) C = false", e);
        }



        [Test]
        public void Xor()
        {
            var m = Create16bitAssembler();
            m.Xor(m.eax, m.eax);
            var e = CreateRewriter(m).GetEnumerator();
            AssertCode("0C00:0000(3) eax = eax ^ eax", e);
            AssertCode("0C00:0000(3) SZO = cond(eax)", e);
            AssertCode("0C00:0000(3) C = false", e);
        }

        [Test]
        public void Test()
        {
            var m = Create16bitAssembler();
            m.Test(m.edi, m.Imm(0xFFFFFFFFu));
            var e = CreateRewriter(m).GetEnumerator();
            AssertCode("0C00:0000(7) SZO = cond(edi & 0xFFFFFFFF)", e);
            AssertCode("0C00:0000(7) C = false", e);
        }

        private IEnumerator<RtlInstruction> Run16bitTest(Action<IntelAssembler> fn)
        {
            var m = Create16bitAssembler();
            fn(m);
            return CreateRewriter(m).GetEnumerator();
        }

        private IEnumerator<RtlInstruction> Run32bitTest(Action<IntelAssembler> fn)
        {
            var m = Create32bitAssembler();
            fn(m);
            return CreateRewriter32(m).GetEnumerator();
        }

        [Test]
        public void Cmp()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Cmp(m.ebx, 3);
            });
            AssertCode("0C00:0000(4) SCZO = cond(ebx - 0x00000003)", e);
        }

        [Test]
        public void PushPop()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Push(m.eax);
                m.Pop(m.ebx);
            });
            AssertCode("0C00:0000(2) sp = sp - 0x0004", e);
            AssertCode("0C00:0000(2) Mem0[ss:sp:word32] = eax", e);
            AssertCode("0C00:0002(2) ebx = Mem0[ss:sp:word32]", e);
            AssertCode("0C00:0002(2) sp = sp + 0x0004", e);
        }

        [Test]
        public void Jmp()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Label("lupe");
                m.Jmp("lupe");
            });
            AssertCode("0C00:0000(3) goto 0C00:0000", e);
        }

        [Test]
        public void JmpIndirect()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Jmp(m.WordPtr(m.bx, 0x10));
            });
            AssertCode("0C00:0000(3) goto Mem0[ds:bx + 0x0010:word16]", e);
        }

        [Test]
        public void Jne()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Label("lupe");
                m.Jnz("lupe");
                m.Xor(m.ax, m.ax);
            });
            AssertCode(0xC000, "0C00:0000(2) if (Test(NE,Z)) branch 0C00:0000", e);
            AssertCode(0xC002, "0C00:0002(2) ax = ax ^ ax", e);
        }

        [Test]
        public void Call16bit()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Label("self");
                m.Call("self");
            });
            AssertCode(0x0C000, "0C00:0000(3) sp = sp - 0x0002", e);
            AssertCode(0x0C000, "0C00:0000(3) call 0C00:0000", e);
        }

        [Test]
        public void Call32Bit()
        {
            var e = Run32bitTest(delegate(IntelAssembler m)
            {
                m.Label("self");
                m.Call("self");
            });
            AssertCode(0x10000000, "10000000(5) esp = esp - 0x00000004", e);
            AssertCode(0x10000000, "10000000(5) call 10000000", e);
        }

        [Test]
        public void Bswap()
        {
            var e = Run32bitTest(delegate(IntelAssembler m)
            {
                m.Bswap(m.ebx);
            });
            AssertCode("10000000(2) ebx = __bswap(ebx)",e);
        }

        [Test]
        public void IntInstruction()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Mov(m.ax, 0x4C00);
                m.Int(0x21);
            });
            AssertCode("0C00:0000(3) ax = 0x4C00", e);
            AssertCode("0C00:0003(2) __syscall(0x21)", e);
            var s = (RtlSideEffect) e.Current;
            var app = (Application) s.Expression;
            var pc = (ProcedureConstant) app.Procedure;
            var ppp = (PseudoProcedure) pc.Procedure;
            Assert.AreEqual("__syscall", ppp.Name);
        }

        [Test]
        public void InInstruction()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.In(m.al, m.dx);
            });
            AssertCode("0C00:0000(1) al = __inb(dx)", e);
        }

        [Test]
        public void RetInstruction()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Ret();
            });
            AssertCode("0C00:0000(1) return (2,0)", e);
        }

        [Test]
        public void RealModeReboot()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.JmpF(new Address(0xF000, 0xFFF0));
            });
            AssertCode("0C00:0000(5) __bios_reboot()", e);
        }

        [Test]
        public void RetNInstruction()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Ret(8);
            });
            AssertCode("0C00:0000(3) return (2,8)", e);
        }

        [Test]
        public void Loop()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Label("lupe");
                m.Loop("lupe");
            });
            AssertCode("0C00:0000(2) cx = cx - 0x0001", e);
            AssertCode("0C00:0000(2) if (cx != 0x0000) branch 0C00:0000", e);
        }

        [Test]
        public void Loope()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Label("lupe");
                m.Loope("lupe");
                m.Mov(m.bx, m.ax);
            });
            AssertCode(e,
                "0|0C00:0000(2) cx = cx - 0x0001",
                "1|0C00:0000(2) if (Test(EQ,Z) && cx != 0x0000) branch 0C00:0000",
                "2|0C00:0002(2) bx = ax");
        }

        [Test]
        public void Adc()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Adc(m.WordPtr(0x100), m.ax);
            });
            AssertCode("0C00:0000(4) v2 = Mem0[ds:0x0100:word16] + ax", e);
            AssertCode("0C00:0000(4) v6 = v2 + (word16) C", e);
            AssertCode("0C00:0000(4) Mem0[ds:0x0100:word16] = v6", e);
            AssertCode("0C00:0000(4) SCZO = cond(v6)", e);
        }

        [Test]
        public void Lea()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Lea(m.bx, m.MemW(Registers.bx, 4));
            });
            AssertCode("0C00:0000(3) bx = bx + 0x0004", e);
        }

        [Test]
        public void Enter()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Enter(16, 0);
            });
            AssertCode(e,
                "0|0C00:0000(4) sp = sp - 0x0002",
                "1|0C00:0000(4) Mem0[ss:sp:word16] = bp",
                "2|0C00:0000(4) bp = sp",
                "3|0C00:0000(4) sp = sp - 0x0010");
        }

        [Test]
        public void Neg()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Neg(m.ecx);
            });
            AssertCode(e,
                "0|0C00:0000(3) ecx = -ecx",
                "1|0C00:0000(3) SCZO = cond(ecx)",
                "2|0C00:0000(3) C = ecx == 0x00000000");
        }

        [Test]
        public void Not()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Not(m.bx);
            });
            AssertCode(e,
                "0|0C00:0000(2) bx = ~bx");
        }

        [Test]
        public void Out()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Out(m.dx, m.al);
            });
            AssertCode("0C00:0000(1) __outb(dx, al)", e);
        }

        [Test]
        public void Jcxz()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Label("lupe");
                m.Jcxz("lupe");
                m.Enter(16, 0);
            });
            AssertCode("0C00:0000(2) if (cx == 0x0000) branch 0C00:0000", e);
        }

        [Test]
        public void Rep()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Rep();
                m.Lodsw();
                m.Xor(m.ax, m.ax);
            });
            AssertCode(e,
                "0|0C00:0000(2) if (cx == 0x0000) branch 0C00:0002",
                "1|0C00:0000(2) ax = Mem0[ds:si:word16]",
                "2|0C00:0000(2) si = si + 0x0002",
                "3|0C00:0000(2) cx = cx - 0x0001",
                "4|0C00:0000(2) goto 0C00:0000",
                "5|0C00:0002(2) ax = ax ^ ax",
                "6|0C00:0002(2) SZO = cond(ax)",
                "7|0C00:0002(2) C = false");
        }

        [Test]
        public void Shld()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Shld(m.edx, m.eax, m.cl);
            });
            AssertCode(
                "0C00:0000(4) edx = __shld(edx, eax, cl)", e);
        }

        [Test]
        public void Shrd()
        {
            var e = Run16bitTest(delegate(IntelAssembler m)
            {
                m.Shrd(m.eax, m.edx, 4);
            });
            AssertCode(
                "0C00:0000(5) eax = __shrd(eax, edx, 0x04)", e);
        }

    }
}
