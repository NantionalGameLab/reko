// main.c
// Generated by decompiling main.exe
// using Reko decompiler version 0.9.0.0.

#include "main.h"

// 00401000: Register ptr32 fn00401000()
ptr32 fn00401000()
{
	return 0x00403378;
}

// 00401010: void fn00401010(Stack word32 dwArg04)
void fn00401010(word32 dwArg04)
{
	ptr32 * esp_n;
	word32 eax_n;
	_acrt_iob_func();
	*esp_n = fp + 0x08;
	*(esp_n - 0x04) = 0x00;
	*(esp_n - 0x08) = dwArg04;
	*(esp_n - 0x0C) = eax_n;
	struct Eq_n * eax_n = fn00401000();
	*(esp_n - 0x0010) = eax_n->dw0004;
	*(esp_n - 0x0014) = eax_n->dw0000;
	_stdio_common_vfprintf();
}

// 00401040: Register word32 fn00401040(Register word32 ecx)
word32 fn00401040(word32 ecx)
{
	ptr32 esp_n;
	driver.dll!Ordinal_n();
	*(esp_n - 0x04) = 0x03;
	ptr32 esp_n;
	driver.dll!Ordinal_n();
	*(esp_n - 0x04) = 0x01;
	ptr32 esp_n;
	driver.dll!Ordinal_n();
	*(esp_n - 0x04) = 0x05;
	ptr32 esp_n;
	driver.dll!Ordinal_n();
	*(esp_n - 0x04) = ecx;
	*(esp_n - 0x08) = *driver.dll!Ordinal_n;
	*(esp_n - 0x0C) = 0x00402118;
	fn00401010(*(esp_n - 0x0C));
	return 0x00;
}

// 004012C9: Register Eq_n Win32CrtStartup()
Eq_n Win32CrtStartup()
{
	word24 ebx_24_8_n = SLICE(ebx, word24, 8);
	fn0040165E();
	struct Eq_n * ebp_n = fn00401980(ebx, esi, edi, dwLoc0C, 0x14);
	word32 * esp_n = fp - 0x08;
	if ((byte) (uint32) (uint8) fn0040146F(edx, 0x01) == 0x00)
	{
l00401172:
		esp_n -= 0x04;
		*esp_n = 0x07;
		fn0040176D(*esp_n);
	}
	*(ebp_n - 0x19) = 0x00;
	*(ebp_n - 0x04) &= 0x00;
	word32 edx_n;
	*(ebp_n - 0x24) = (byte) (uint32) (uint8) fn0040143A(out edx_n);
	struct Eq_n * ebp_n = ebp_n;
	uip32 eax_n = globals->dw403334;
	word32 ebx_n = SEQ(ebx_24_8_n, 0x00);
	if (eax_n != 0x01)
	{
		Eq_n eax_n;
		struct Eq_n * esp_n;
		if (eax_n == 0x00)
		{
			globals->dw403334 = 0x01;
			PVFV ** esp_n = esp_n - 0x04;
			*esp_n = (PVFV **) &globals->t4020F0;
			*(esp_n - 0x04) = 0x004020E4;
			esp_n = (struct Eq_n *) ((char *) esp_n + 0x04);
			if (_initterm_e(*(esp_n - 0x04), *esp_n) != 0x00)
			{
				*(ebp_n - 0x04) = ~0x01;
				eax_n = 0xFF;
				goto l004012C3;
			}
			*esp_n = (PVFV **) &globals->t4020E0;
			*(esp_n - 0x04) = 0x004020D8;
			_initterm(*(esp_n - 0x04), *esp_n);
			globals->dw403334 = 0x02;
		}
		else
		{
			*(ebp_n - 0x19) = 0x01;
			ebx_n = SEQ(ebx_24_8_n, 0x01);
		}
		union Eq_n * esp_n = esp_n - 0x04;
		*esp_n = *(ebp_n - 0x24);
		fn004015C9(*esp_n);
		ptr32 esp_n = (char *) esp_n + 0x04;
		Eq_n eax_n = fn00401761();
		Eq_n edi_n = 0x00;
		if (*eax_n != 0x00)
		{
			*esp_n = (union Eq_n *) eax_n;
			esp_n = (char *) esp_n + 0x04;
			<anonymous> ** esi_n;
			if ((byte) (uint32) (uint8) fn0040153F(ebx_n, eax_n, 0x00, out edx_n, out ebx_n, out ebp_n, out esi_n, out edi_n) != 0x00)
			{
				*esp_n = (union Eq_n *) edi_n;
				*(esp_n - 0x04) = 0x02;
				*(esp_n - 0x08) = (union Eq_n *) edi_n;
				<anonymous> * esi_n = *esi_n;
				fn00401972();
				esi_n();
			}
		}
		Eq_n eax_n = fn00401767();
		if (*eax_n != edi_n)
		{
			union Eq_n * esp_n = esp_n - 0x04;
			*esp_n = (union Eq_n *) eax_n;
			union Eq_n * esi_n;
			word32 edi_n;
			if ((byte) (uint32) (uint8) fn0040153F(ebx_n, eax_n, edi_n, out edx_n, out ebx_n, out ebp_n, out esi_n, out edi_n) != 0x00)
			{
				*esp_n = *esi_n;
				register_thread_local_exe_atexit_callback();
			}
		}
		word32 * eax_n;
		word32 edx_n;
		_p___argv();
		word32 * eax_n;
		word32 edx_n;
		_p___argc();
		ptr32 esp_n;
		word32 ecx_n;
		word32 eax_n;
		word32 edx_n;
		get_initial_narrow_environment();
		*(esp_n - 0x04) = eax_n;
		*(esp_n - 0x08) = *eax_n;
		*(esp_n - 0x0C) = *eax_n;
		Eq_n eax_n = fn00401040(ecx_n);
		byte bl_n = (byte) ebx_n;
		ptr32 esp_n = esp_n;
		if ((byte) (uint32) (uint8) fn0040188B() == 0x00)
		{
			*(esp_n - 0x04) = (uint32) eax_n;
			exit(*(esp_n - 0x04));
		}
		if (bl_n == 0x00)
			cexit();
		union Eq_n * esp_n = esp_n - 0x04;
		*esp_n = 0x00;
		*(esp_n - 0x04) = 0x01;
		fn004015E6(*esp_n);
		*(ebp_n - 0x04) = ~0x01;
		esp_n = (struct Eq_n *) ((char *) esp_n + 0x04);
		eax_n = eax_n;
l004012C3:
		word32 ebp_n;
		word32 edi_n;
		word32 esi_n;
		fn004019C6(ebp_n, esp_n->tFFFFFFFC, out ebp_n, out esi_n, out edi_n);
		return eax_n;
	}
	goto l00401172;
}

// 004013F6: Register (ptr32 Eq_n) fn004013F6(Stack (ptr32 Eq_n) dwArg04, Stack uint32 dwArg08, Register out (ptr32 Eq_n) edxOut)
struct Eq_n * fn004013F6(struct Eq_n * dwArg04, uint32 dwArg08, struct Eq_n & edxOut)
{
	struct Eq_n * eax_n;
	struct Eq_n * ecx_n = dwArg04 + dwArg04->dw003C / 0x0040;
	struct Eq_n * edx_n = &ecx_n->w0014 + 0x02 + (word32) ecx_n->w0014 / 22;
	struct Eq_n * esi_n = edx_n + (word32) ecx_n->w0006;
	for (; edx_n != esi_n; ++edx_n)
	{
		if (dwArg08 >= edx_n->dw000C && dwArg08 < edx_n->dw0008 + edx_n->dw000C)
		{
			eax_n = edx_n;
			goto l00401433;
		}
	}
	eax_n = null;
l00401433:
	edxOut = edx_n;
	return eax_n;
}

// 0040143A: Register byte fn0040143A(Register out ptr32 edxOut)
byte fn0040143A(ptr32 & edxOut)
{
	word32 eax_n = fn00401B98();
	if (eax_n != 0x00)
	{
		ptr32 edx_n = fs->ptr0018->ptr0004;
		do
		{
			__lock();
			ptr32 eax_n;
			__cmpxchg(globals->dw403338, edx_n, 0x00, out eax_n);
			if (eax_n == 0x00)
			{
				edxOut = edx_n;
				return 0x00;
			}
		} while (edx_n != eax_n);
		edxOut = edx_n;
		return 0x01;
	}
	else
	{
		edxOut = edx;
		return 0x00;
	}
}

// 0040146F: Register byte fn0040146F(Register word32 edx, Stack word32 dwArg04)
byte fn0040146F(word32 edx, word32 dwArg04)
{
	if (dwArg04 == 0x00)
		globals->b403354 = 0x01;
	fn004019FE(edx);
	if (fn00401C46() == 0x00)
		return 0x00;
	if (fn00401C46() != 0x00)
		return 0x01;
	fn00401C46();
	return 0x00;
}

// 0040153F: Register byte fn0040153F(Register word32 ebx, Register Eq_n esi, Register Eq_n edi, Register out ptr32 edxOut, Register out ptr32 ebxOut, Register out ptr32 ebpOut, Register out ptr32 esiOut, Register out ptr32 ediOut)
byte fn0040153F(word32 ebx, Eq_n esi, Eq_n edi, ptr32 & edxOut, ptr32 & ebxOut, ptr32 & ebpOut, ptr32 & esiOut, ptr32 & ediOut)
{
	word32 eax_n;
	struct Eq_n * ebp_n = fn00401980(ebx, esi, edi, dwLoc0C, 0x08);
	*(ebp_n - 0x04) &= 0x00;
	word24 eax_24_8_n = 0x5A;
	if (globals->w400000 == 23117)
	{
		struct Eq_n * eax_n = globals->ptr40003C;
		eax_24_8_n = SLICE(eax_n, word24, 8);
		eax_24_8_n = SLICE(eax_n, word24, 8);
		if (eax_n->dw400000 == 0x4550 && eax_n->w400018 == 0x010B)
		{
			ui32 eax_n = ebp_n->dw0008;
			struct Eq_n * eax_n = fn004013F6(&globals->w400000, eax_n - 0x00400000, out edx);
			dwLoc0C = eax_n - 0x00400000;
			eax_24_8_n = SLICE(eax_n, word24, 8);
			eax_24_8_n = SLICE(eax_n, word24, 8);
			if (eax_n != null && eax_n->dw0024 >= 0x00)
			{
				*(ebp_n - 0x04) = ~0x01;
				eax_n = SEQ(eax_24_8_n, 0x01);
l004015C3:
				ptr32 ebp_n;
				ptr32 edi_n;
				ptr32 esi_n;
				ptr32 ebx_n = fn004019C6(ebp_n, dwLoc0C, out ebp_n, out esi_n, out edi_n);
				edxOut = edx;
				ebxOut = ebx_n;
				ebpOut = ebp_n;
				esiOut = esi_n;
				ediOut = edi_n;
				return (byte) eax_n;
			}
		}
	}
	*(ebp_n - 0x04) = ~0x01;
	eax_n = SEQ(eax_24_8_n, 0x00);
	goto l004015C3;
}

// 004015C9: void fn004015C9(Stack Eq_n bArg04)
void fn004015C9(Eq_n bArg04)
{
	if (fn00401B98() != 0x00 && bArg04 == 0x00)
		globals->dw403338 = 0x00;
}

// 004015E6: void fn004015E6(Stack Eq_n bArg08)
void fn004015E6(Eq_n bArg08)
{
	if (globals->b403354 == 0x00 || bArg08 == 0x00)
	{
		fn00401C46();
		fn00401C46();
	}
}

// 0040165E: void fn0040165E()
void fn0040165E()
{
	ui32 eax_n = globals->dw403004;
	if (eax_n != 0xBB40E64E && (eax_n & 0xFFFF0000) != 0x00)
		globals->dw403000 = ~eax_n;
	else
	{
		GetSystemTimeAsFileTime(fp - 0x10);
		ui32 v14_n = dwLoc0C & 0x00 ^ dwLoc10 & 0x00 ^ GetCurrentThreadId() ^ GetCurrentProcessId();
		QueryPerformanceCounter(fp - 0x18);
		ui32 ecx_n = dwLoc14 ^ dwLoc18 ^ v14_n ^ fp - 0x08;
		if (ecx_n == 0xBB40E64E)
			ecx_n = ~0x44BF19B0;
		else if ((ecx_n & 0xFFFF0000) == 0x00)
			ecx_n |= (ecx_n | 0x4711) << 0x10;
		globals->dw403004 = ecx_n;
		globals->dw403000 = ~ecx_n;
	}
}

// 00401761: Register ptr32 fn00401761()
ptr32 fn00401761()
{
	return 0x00403384;
}

// 00401767: Register ptr32 fn00401767()
ptr32 fn00401767()
{
	return 0x00403380;
}

// 0040176D: void fn0040176D(Stack word32 dwArg04)
void fn0040176D(word32 dwArg04)
{
	if (IsProcessorFeaturePresent(0x17) == 0x00)
	{
		globals->dw403368 = 0x00;
		memset(fp - 808, 0x00, 0x02CC);
		memset(fp - 0x5C, 0x00, 0x50);
		byte bl_n = 0x00 - (IsDebuggerPresent() == 0x01);
		SetUnhandledExceptionFilter(null);
		if (UnhandledExceptionFilter(fp - 0x0C) == 0x00)
			globals->dw403368 &= 0x00 - (-((word32) (bl_n + 0x01)) == 0x00);
	}
	else
		__fastfail(dwArg04);
}

// 0040188B: Register byte fn0040188B()
byte fn0040188B()
{
	Eq_n eax_n = GetModuleHandleW(null);
	if (eax_n == null || eax_n->unused != 23117)
		return 0x00;
	struct Eq_n * eax_n = eax_n + eax_n->dw003C / 0x0040;
	word24 eax_24_8_n = SLICE(eax_n, word24, 8);
	if (eax_n->dw0000 != 0x4550 || (eax_n->w0018 != 0x010B || eax_n->dw0074 <= 0x0E))
		return 0x00;
	return (byte) SEQ(eax_24_8_n, eax_n->dw00E8 != 0x00);
}

// 00401972: void fn00401972()
void fn00401972()
{
	globals->ptr4020D4();
}

// 00401980: Register ptr32 fn00401980(Register word32 ebx, Register Eq_n esi, Register Eq_n edi, Stack Eq_n dwArg00, Stack ui32 dwArg08)
ptr32 fn00401980(word32 ebx, Eq_n esi, Eq_n edi, Eq_n dwArg00, ui32 dwArg08)
{
	ptr32 esp_n = fp - 0x08 - dwArg08;
	*(esp_n - 0x04) = ebx;
	*(esp_n - 0x08) = (union Eq_n *) esi;
	*(esp_n - 0x0C) = (union Eq_n *) edi;
	*(esp_n - 0x0010) = globals->dw403004 ^ fp + 0x08;
	*(esp_n - 0x0014) = (union Eq_n *) dwArg00;
	fs->ptr0000 = fp - 0x08;
	return fp + 0x08;
}

// 004019C6: Register word32 fn004019C6(Register (ptr32 Eq_n) ebp, Stack Eq_n dwArg00, Register out Eq_n ebpOut, Register out ptr32 esiOut, Register out ptr32 ediOut)
word32 fn004019C6(struct Eq_n * ebp, Eq_n dwArg00, union Eq_n & ebpOut, ptr32 & esiOut, ptr32 & ediOut)
{
	fs->dw0000 = *(ebp - 0x10);
	Eq_n ebp_n = ebp->t0000;
	ebp->t0000 = dwArg00;
	ebpOut = ebp_n;
	esiOut = dwArg0C;
	ediOut = dwArg08;
	return dwArg10;
}

// 004019FE: void fn004019FE(Register word32 edx)
void fn004019FE(word32 edx)
{
	globals->dw40336C &= 0x00;
	globals->dw403010 |= 0x01;
	if (IsProcessorFeaturePresent(0x0A) != 0x00)
	{
		ui32 edi_n;
		globals->dw403010 |= 0x02;
		globals->dw40336C = 0x01;
		__cpuid(0x00, 0x00, &0x00, &0x01, &0x00, &edx);
		__cpuid(0x01, 0x00, &0x01, &0x01, &0x00, &edx);
		byte bLoc14_n = (byte) (dwLoc14 & 0x00);
		if ((edx ^ 0x49656E69 | 1818588270 | 0x756E6546) == 0x00 && (0x00 == 0x000106C0 || (0x00 == 0x00020660 || (0x00 == 0x00020670 || (0x00 == 0x00030650 || (0x00 == 0x00030660 || false))))))
		{
			ui32 edi_n = globals->dw403370;
			globals->dw403370 = edi_n | 0x01;
			edi_n = edi_n | 0x01;
		}
		else
			edi_n = globals->dw403370;
		if (false)
		{
			__cpuid(0x07, 0x00, &0x07, &0x01, &0x00, &edx);
			bLoc14_n = 0x01;
			if (0x00 != 0x00)
				globals->dw403370 = edi_n | 0x02;
		}
		if (0x00 != 0x00)
		{
			globals->dw403010 |= 0x04;
			globals->dw40336C = 0x02;
			if (0x00 != 0x00 && (0x00 != 0x00 && (((word32) __xgetbv(0x00) & 0x06) == 0x06 && true)))
			{
				ui32 eax_n = globals->dw403010;
				globals->dw40336C = 0x03;
				globals->dw403010 = eax_n | 0x08;
				if ((bLoc14_n & 0x20) != 0x00)
				{
					globals->dw40336C = 0x05;
					globals->dw403010 = eax_n | 0x08 | 0x20;
				}
			}
		}
	}
}

// 00401B98: Register uint32 fn00401B98()
uint32 fn00401B98()
{
	return (uint32) (uint8) (globals->dw403014 != 0x00);
}

// 00401C46: Register byte fn00401C46()
byte fn00401C46()
{
	return 0x01;
}

