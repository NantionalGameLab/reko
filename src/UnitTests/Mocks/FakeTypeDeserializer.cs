﻿#region License
/* 
 * Copyright (C) 1999-2016 Pavel Tomin.
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

using Reko.Core.Serialization;
using Reko.Core.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Reko.UnitTests.Mocks
{
    public class FakeTypeDeserializer : ISerializedTypeVisitor<DataType>
    {
        private int ptrSize;

        public FakeTypeDeserializer(int ptrSize)
        {
            this.ptrSize = ptrSize;
        }

        public DataType VisitArray(ArrayType_v1 array)
        {
            throw new NotImplementedException();
        }

        public DataType VisitCode(CodeType_v1 code)
        {
            throw new NotImplementedException();
        }

        public DataType VisitEnum(SerializedEnumType serializedEnumType)
        {
            throw new NotImplementedException();
        }

        public DataType VisitMemberPointer(MemberPointer_v1 memptr)
        {
            throw new NotImplementedException();
        }

        public DataType VisitPointer(PointerType_v1 pointer)
        {
            return new Pointer(pointer.DataType.Accept(this), ptrSize);
        }

        public DataType VisitPrimitive(PrimitiveType_v1 primitive)
        {
            return PrimitiveType.Create(primitive.Domain, primitive.ByteSize);
        }

        public DataType VisitSignature(SerializedSignature signature)
        {
            throw new NotImplementedException();
        }

        public DataType VisitString(StringType_v2 str)
        {
            throw new NotImplementedException();
        }

        public DataType VisitStructure(StructType_v1 structure)
        {
            return new StructureType(structure.Name, 0);
        }

        public DataType VisitTemplate(SerializedTemplate serializedTemplate)
        {
            throw new NotImplementedException();
        }

        public DataType VisitTypedef(SerializedTypedef typedef)
        {
            throw new NotImplementedException();
        }

        public DataType VisitTypeReference(TypeReference_v1 typeReference)
        {
            return new TypeReference(typeReference.TypeName, null);
        }

        public DataType VisitUnion(UnionType_v1 union)
        {
            throw new NotImplementedException();
        }

        public DataType VisitVoidType(VoidType_v1 serializedVoidType)
        {
            return VoidType.Instance;
        }
    }

}