// pngpixel.c
// Generated by decompiling pngpixel
// using Reko decompiler version 0.8.0.2.

#include "pngpixel.h"

// 0000000000400AE8: void _init()
void _init()
{
	word64 rax_4 = globals->qw601FF8;
	if (rax_4 != 0x00)
	{
		word64 rsp_15;
		byte SCZO_16;
		word64 rax_17;
		byte SZO_18;
		bool C_19;
		bool Z_20;
		__gmon_start__();
	}
}

// 0000000000400CD0: void _start(Register (ptr64 Eq_17) rdx, Stack Eq_18 qwArg00)
void _start( * rdx, Eq_18 qwArg00)
{
	__align((char *) fp + 0x08);
	__libc_start_main(&globals->t4012F9, qwArg00, (char *) fp + 0x08, &globals->t401780, &globals->t4017F0, rdx, fp);
	__hlt();
}

// 0000000000400D00: void deregister_tm_clones(Register word64 r8)
void deregister_tm_clones(word64 r8)
{
	if (false || 0x00 == 0x00)
		return;
	word64 rsp_42;
	word32 eax_43;
	word64 rax_44;
	word64 rbp_45;
	word64 r8_46;
	byte SCZO_47;
	byte CZ_48;
	byte SZO_49;
	bool C_50;
	bool Z_51;
	word32 edi_52;
	word64 rdi_53;
	null();
}

// 0000000000400D40: void register_tm_clones()
void register_tm_clones()
{
	if (0x00 == 0x00 || 0x00 == 0x00)
		return;
	word64 rsp_40;
	word64 rsi_41;
	word64 rbp_42;
	byte SCZO_43;
	word64 rax_44;
	bool Z_45;
	byte SZO_46;
	bool C_47;
	word64 rdi_48;
	null();
}

// 0000000000400D80: void __do_global_dtors_aux(Register word64 r8)
void __do_global_dtors_aux(word64 r8)
{
	if (globals->b602108 == 0x00)
	{
		deregister_tm_clones(r8);
		globals->b602108 = 0x01;
	}
}

// 0000000000400DA0: void frame_dummy()
void frame_dummy()
{
	if (globals->qw601E10 != 0x00 && 0x00 != 0x00)
	{
		word64 rsp_39;
		word32 edi_40;
		word64 rdi_41;
		byte SCZO_42;
		bool Z_43;
		word32 eax_44;
		word64 rax_45;
		byte SZO_46;
		bool C_47;
		word64 rbp_48;
		word32 esi_49;
		word64 rsi_50;
		fn0000000000000000();
		register_tm_clones();
	}
	else
		register_tm_clones();
}

// 0000000000400DC6: Register word32 component(Register Eq_119 ecx, Register word32 edx, Register word32 esi, Register word64 rdi, Register word32 r8d, Register Eq_124 r13)
word32 component(Eq_119 ecx, word32 edx, word32 esi, word64 rdi, word32 r8d, Eq_124 r13)
{
	*(r13 - 0x28) = r8d;
	ui32 eax_41 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) (edx + (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) esi) & 0x3F)) *s dwLoc30))) *s ecx);
	struct Eq_149 * v17_52 = rdi + ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) esi) >> 0x06)) *s dwLoc30)) *s ecx))) << 0x03) + (uint64) ((word32) ((uint64) ((word32) ((uint64) eax_41) >> 0x03)));
	if (ecx > 0x10)
		goto l0000000000400EC1;
	word32 eax_113;
	switch (ecx)
	{
	case 0x00:
	case 0x03:
	case 0x05:
	case 0x06:
	case 0x07:
	case 0x09:
	case 0x0A:
	case 11:
	case 0x0C:
	case 0x0D:
	case 0x0E:
	case 0x0F:
l0000000000400EC1:
		fprintf(globals->ptr602100, "pngpixel: invalid bit depth %u\n", (uint64) ecx);
		exit(0x01);
	case 0x01:
		eax_113 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (byte) (word32) v17_52->b0000 >> (byte) ((uint64) ((word32) ((uint64) (0x07 - (eax_41 & 0x07)))))) & 0x01);
		break;
	case 0x02:
		eax_113 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (byte) (word32) v17_52->b0000 >> (byte) ((uint64) ((word32) ((uint64) (0x06 - (eax_41 & 0x07)))))) & 0x03);
		break;
	case 0x04:
		eax_113 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (byte) (word32) v17_52->b0000 >> (byte) ((uint64) ((word32) ((uint64) (0x04 - (eax_41 & 0x07)))))) & 0x0F);
		break;
	case 0x08:
		eax_113 = (word32) (byte) (word32) v17_52->b0000;
		break;
	case 0x10:
		eax_113 = (word32) (uint64) (word32) ((byte) (word32) v17_52->b0001 + (uint64) ((word32) ((uint64) ((word32) ((byte) ((word32) v17_52->b0000)) << 0x08))));
		break;
	}
	return eax_113;
}

// 0000000000400EE9: void print_pixel(Register word32 ecx, Register word64 rdx, Register word32 edi, Register word64 r13, Register (ptr32 Eq_291) fs)
void print_pixel(word32 ecx, word64 rdx, word32 edi, word64 r13, Eq_291 * fs)
{
	word64 rsp_37;
	word64 rbp_38;
	word64 r13_39;
	word64 r12_40;
	word64 rbx_41;
	byte SCZO_42;
	word64 rdi_43;
	word64 rsi_44;
	word64 rdx_45;
	word32 ecx_46;
	word64 rax_47;
	struct Eq_303 * fs_48;
	word32 eax_49;
	byte SZO_50;
	bool C_51;
	byte al_52;
	byte CZ_53;
	word32 esi_54;
	bool Z_55;
	word32 edx_56;
	word32 r8d_57;
	word64 r8_58;
	word64 rcx_59;
	word32 r12d_60;
	word32 ebx_61;
	word32 edi_62;
	word32 r13d_63;
	word32 r9d_64;
	word64 r9_65;
	png_get_bit_depth();
	word32 eax_66 = (word32) al_52;
	word64 rsp_73;
	word64 rbp_74;
	Eq_124 r13_75;
	word64 r12_76;
	word64 rbx_77;
	byte SCZO_78;
	word64 rdi_79;
	word64 rsi_80;
	word64 rdx_81;
	word32 ecx_82;
	word64 rax_83;
	word32 eax_85;
	byte SZO_86;
	bool C_87;
	byte al_88;
	byte CZ_89;
	word32 esi_90;
	bool Z_91;
	word32 edx_92;
	word32 r8d_93;
	word64 r8_94;
	word64 rcx_95;
	word32 r12d_96;
	word32 ebx_97;
	word32 edi_98;
	word32 r13d_99;
	word32 r9d_100;
	word64 r9_101;
	struct Eq_353 * fs_120;
	png_get_color_type();
	word64 rax_26 = fs->qw0028;
	up32 eax_102 = (word32) al_88;
	if (eax_102 > 0x06)
		goto l00000000004012C9;
	switch ((word32) globals->a401958[(uint64) eax_102 * 0x08])
	{
	case 0x00:
		printf("GRAY %u\n", (uint64) component((word32) (uint64) (word32) (uint64) eax_66, 0x00, (word32) (uint64) ecx, rdx, 0x01, r13_75));
		break;
	case 0x01:
	case 0x05:
l00000000004012C9:
		word64 rsp_160;
		word64 rbp_161;
		word64 r13_162;
		word64 r12_163;
		word64 rbx_164;
		byte SCZO_165;
		word64 rdi_166;
		word64 rsi_167;
		word64 rdx_168;
		word32 ecx_169;
		word64 rax_170;
		word32 eax_172;
		byte SZO_173;
		bool C_174;
		byte al_175;
		byte CZ_176;
		word32 esi_177;
		bool Z_178;
		word32 edx_179;
		word32 r8d_180;
		word64 r8_181;
		word64 rcx_182;
		word32 r12d_183;
		word32 ebx_184;
		word32 edi_185;
		word32 r13d_186;
		word32 r9d_187;
		word64 r9_188;
		png_error();
		break;
	case 0x02:
		printf("RGB %u %u %u\n", (uint64) component((word32) (uint64) (word32) (uint64) eax_66, 0x00, (word32) (uint64) ecx, rdx, 0x03, r13_75), (uint64) (word32) (uint64) component((word32) (uint64) (word32) (uint64) eax_66, 0x01, (word32) (uint64) ecx, rdx, 0x03, r13_75), (uint64) (word32) (uint64) component((word32) (uint64) (word32) (uint64) eax_66, 0x02, (word32) (uint64) ecx, rdx, 0x03, r13_75));
		break;
	case 0x03:
		word32 esi_261 = (word32) (uint64) ecx;
		Eq_119 ecx_266 = (word32) (uint64) (word32) (uint64) eax_66;
		word64 rsp_280;
		word64 rbp_281;
		word64 r13_282;
		word64 r12_283;
		word64 rbx_284;
		byte SCZO_285;
		word64 rdi_286;
		word64 rsi_287;
		word64 rdx_288;
		word32 ecx_289;
		word64 rax_290;
		ui32 eax_292;
		byte SZO_293;
		bool C_294;
		byte al_295;
		byte CZ_296;
		word32 esi_297;
		bool Z_298;
		word32 edx_299;
		word32 r8d_300;
		word64 r8_301;
		word64 rcx_302;
		word32 r12d_303;
		word32 ebx_304;
		word32 edi_305;
		word32 r13d_306;
		word32 r9d_307;
		word64 r9_308;
		png_get_PLTE();
		up32 eax_270 = component(ecx_266, 0x00, esi_261, rdx, 0x01, r13_75);
		if ((word32) (uint64) (eax_292 & 0x08) != 0x00 && (false && 0x00 != 0x00))
		{
			word64 rsp_339;
			word64 rbp_340;
			ptr64 r13_341;
			word64 r12_342;
			word64 rbx_343;
			byte SCZO_344;
			word64 rdi_345;
			word64 rsi_346;
			word64 rdx_347;
			word32 ecx_348;
			word64 rax_349;
			ui32 eax_351;
			byte SZO_352;
			bool C_353;
			byte al_354;
			byte CZ_355;
			word32 esi_356;
			bool Z_357;
			word32 edx_358;
			word32 r8d_359;
			word64 r8_360;
			word64 rcx_361;
			word32 r12d_362;
			word32 ebx_363;
			word32 edi_364;
			word32 r13d_365;
			word32 r9d_366;
			word64 r9_367;
			png_get_tRNS();
			if ((word32) (uint64) (eax_351 & 0x10) != 0x00 && (false && 0x00 != 0x00))
			{
				word32 esi_440;
				if (eax_270 < 0x00)
					esi_440 = (word32) (byte) (word32) ((uint64) eax_270 + 0x00);
				else
					esi_440 = 0xFF;
				uint64 rdx_461 = (uint64) eax_270;
				printf("INDEXED %u = %d %d %d %d\n", (uint64) (word32) (uint64) eax_270, DPB(rdx_461, (word32) (byte) (word32) *((char *) *(r13_341 - 0x38) + rdx_461 * 0x03), 0), (word64) (word32) (byte) (word32) ((Eq_1503[]) 0x01)[(uint64) eax_270].b0000, (uint64) (word32) (byte) (word32) ((Eq_1504[]) 0x02)[(uint64) eax_270].b0000, (uint64) esi_440);
			}
			else
			{
				uint64 rdx_413 = (uint64) eax_270;
				printf("INDEXED %u = %d %d %d\n", (uint64) (word32) (uint64) eax_270, DPB(rdx_413, (word32) (byte) (word32) null[rdx_413].b0000, 0), (word64) (word32) (byte) (word32) ((Eq_1500[]) 0x01)[(uint64) eax_270].b0000, (uint64) (word32) (byte) (word32) ((Eq_1501[]) 0x02)[(uint64) eax_270]);
			}
		}
		else
			printf("INDEXED %u = invalid index\n", (uint64) (word32) (uint64) eax_270);
		break;
	case 0x04:
		printf("GRAY+ALPHA %u %u\n", (uint64) component((word32) (uint64) (word32) (uint64) eax_66, 0x00, (word32) (uint64) ecx, rdx, 0x02, r13_75), (uint64) (word32) (uint64) component((word32) (uint64) (word32) (uint64) eax_66, 0x01, (word32) (uint64) ecx, rdx, 0x02, r13_75));
		break;
	case 0x06:
		Eq_124 r13_535 = (uint64) component((word32) (uint64) (word32) (uint64) eax_66, 0x03, (word32) (uint64) ecx, rdx, 0x04, r13_75);
		printf("RGBA %u %u %u %u\n", (uint64) component((word32) (uint64) (word32) (uint64) eax_66, 0x00, (word32) (uint64) ecx, rdx, 0x04, r13_535), (uint64) (word32) (uint64) component((word32) (uint64) (word32) (uint64) eax_66, 0x01, (word32) (uint64) ecx, rdx, 0x04, r13_535), (uint64) (word32) (uint64) component((word32) (uint64) (word32) (uint64) eax_66, 0x02, (word32) (uint64) ecx, rdx, 0x04, r13_535), (uint64) (word32) r13_535);
		break;
	}
	if ((rax_26 ^ fs_120->qw0028) == 0x00)
		return;
	__stack_chk_fail();
}

// 00000000004012F9: void main(Register (ptr64 Eq_754) rsi, Register word32 edi, Register word64 r13, Register (ptr32 Eq_757) fs)
void main(Eq_754 * rsi, word32 edi, word64 r13, Eq_757 * fs)
{
	word64 rax_13 = fs->qw0028;
	if (edi != 0x04)
	{
		fwrite(&globals->v401A70, 0x01, 0x27, globals->ptr602100);
		goto l000000000040175D;
	}
	char * rax_67 = rsi->ptr0008;
	uint64 rax_70 = DPB(rax_67, atol(rax_67), 0);
	char * rax_74 = rsi->ptr0010;
	uint64 rax_77 = DPB(rax_74, atol(rax_74), 0);
	FILE * rax_84 = fopen(rsi->ptr0018, "rb");
	if (rax_84 == null)
	{
		fprintf(globals->ptr602100, "pngpixel: %s: could not open file\n", rsi->ptr0018);
		goto l000000000040175D;
	}
	word64 rsp_120;
	word64 rbp_121;
	byte SCZO_122;
	word32 edi_123;
	word64 rsi_124;
	word64 rax_125;
	word32 eax_127;
	byte SZO_128;
	bool C_129;
	bool Z_130;
	word64 rdi_131;
	word32 esi_132;
	word32 ecx_133;
	word64 rcx_134;
	word32 edx_135;
	word64 rdx_136;
	word64 r13_137;
	word64 r9_138;
	word64 r8_139;
	byte SO_140;
	byte cl_141;
	byte al_142;
	png_create_read_struct();
	if (rax_125 == 0x00)
	{
		fwrite(&globals->v401A18, 0x01, 0x2E, globals->ptr602100);
		goto l000000000040175D;
	}
	word64 rsp_150;
	word64 rbp_151;
	byte SCZO_152;
	word32 edi_153;
	word64 rsi_154;
	word64 rax_155;
	struct Eq_860 * fs_156;
	word32 eax_157;
	byte SZO_158;
	bool C_159;
	bool Z_160;
	word64 rdi_161;
	word32 esi_162;
	word32 ecx_163;
	word64 rcx_164;
	word32 edx_165;
	word64 rdx_166;
	word64 r13_167;
	word64 r9_168;
	word64 r8_169;
	byte SO_170;
	byte cl_171;
	byte al_172;
	png_create_info_struct();
	if (rax_155 != 0x00)
	{
		word64 rsp_251;
		word64 rbp_252;
		byte SCZO_253;
		word32 edi_254;
		word64 rsi_255;
		word64 rax_256;
		struct Eq_896 * fs_257;
		word32 eax_258;
		byte SZO_259;
		bool C_260;
		bool Z_261;
		word64 rdi_262;
		word32 esi_263;
		word32 ecx_264;
		word64 rcx_265;
		word32 edx_266;
		word64 rdx_267;
		word64 r13_268;
		word64 r9_269;
		word64 r8_270;
		byte SO_271;
		byte cl_272;
		byte al_273;
		png_init_io();
		word64 rsp_278;
		word64 rbp_279;
		byte SCZO_280;
		word32 edi_281;
		word64 rsi_282;
		word64 rax_283;
		struct Eq_921 * fs_284;
		word32 eax_285;
		byte SZO_286;
		bool C_287;
		bool Z_288;
		word64 rdi_289;
		word32 esi_290;
		word32 ecx_291;
		word64 rcx_292;
		word32 edx_293;
		word64 rdx_294;
		word64 r13_295;
		word64 r9_296;
		word64 r8_297;
		byte SO_298;
		byte cl_299;
		byte al_300;
		png_read_info();
		word64 rsp_305;
		word64 rbp_306;
		byte SCZO_307;
		word32 edi_308;
		word64 rsi_309;
		word64 rax_310;
		struct Eq_946 * fs_311;
		word32 eax_312;
		byte SZO_313;
		bool C_314;
		bool Z_315;
		word64 rdi_316;
		word32 esi_317;
		word32 ecx_318;
		word64 rcx_319;
		word32 edx_320;
		word64 rdx_321;
		word64 r13_322;
		word64 r9_323;
		word64 r8_324;
		byte SO_325;
		byte cl_326;
		byte al_327;
		png_get_rowbytes();
		word64 rsp_332;
		word64 rbp_333;
		byte SCZO_334;
		word32 edi_335;
		word64 rsi_336;
		word64 rax_337;
		struct Eq_971 * fs_338;
		word32 eax_339;
		byte SZO_340;
		bool C_341;
		bool Z_342;
		word64 rdi_343;
		word32 esi_344;
		word32 ecx_345;
		word64 rcx_346;
		word32 edx_347;
		word64 rdx_348;
		word64 r13_349;
		word64 r9_350;
		word64 r8_351;
		byte SO_352;
		byte cl_353;
		byte al_354;
		png_malloc();
		word64 rsp_377;
		word64 rbp_378;
		byte SCZO_379;
		word32 edi_380;
		word64 rsi_381;
		word64 rax_382;
		struct Eq_996 * fs_383;
		word32 eax_384;
		byte SZO_385;
		bool C_386;
		bool Z_387;
		word64 rdi_388;
		word32 esi_389;
		word32 ecx_390;
		word64 rcx_391;
		word32 edx_392;
		word64 rdx_393;
		word64 r13_394;
		word64 r9_395;
		word64 r8_396;
		byte SO_397;
		byte cl_398;
		byte al_399;
		png_get_IHDR();
		if (eax_384 != 0x00)
		{
			word32 eax_406 = (word32) (uint64) dwLoc78;
			if (eax_406 != 0x00)
			{
				if (eax_406 != 0x01)
				{
					word64 rsp_872;
					word64 rbp_873;
					byte SCZO_874;
					word32 edi_875;
					word64 rsi_876;
					word64 rax_877;
					struct Eq_1059 * fs_878;
					word32 eax_879;
					byte SZO_880;
					bool C_881;
					bool Z_882;
					word64 rdi_883;
					word32 esi_884;
					word32 ecx_885;
					word64 rcx_886;
					word32 edx_887;
					word64 rdx_888;
					word64 r13_889;
					word64 r9_890;
					word64 r8_891;
					byte SO_892;
					byte cl_893;
					byte al_894;
					png_error();
				}
				else
					dwLoc6C = 0x07;
			}
			else
				dwLoc6C = 0x01;
			word64 rsp_414;
			word64 rbp_415;
			byte SCZO_416;
			word32 edi_417;
			word64 rsi_418;
			word64 rax_419;
			struct Eq_1091 * fs_420;
			word32 eax_421;
			byte SZO_422;
			bool C_423;
			bool Z_424;
			word64 rdi_425;
			word32 esi_426;
			word32 ecx_427;
			word64 rcx_428;
			word32 edx_429;
			word64 rdx_430;
			word64 r13_431;
			word64 r9_432;
			word64 r8_433;
			byte SO_434;
			byte cl_435;
			byte al_436;
			png_start_read_image();
			int32 dwLoc68_437 = 0x00;
			while (true)
			{
				int32 eax_466 = (word32) (uint64) dwLoc68_437;
				if (eax_466 >= dwLoc6C)
					break;
				word32 dwLoc5C_570;
				word32 dwLoc58_569;
				word32 dwLoc64_568;
				word32 dwLoc60_567;
				if ((word32) (uint64) dwLoc78 == 0x01)
				{
					word32 eax_687;
					if (dwLoc68_437 > 0x01)
						eax_687 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) (0x01 << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x07 - dwLoc68_437)) >> 0x01))))) - 0x01);
					else
						eax_687 = 0x07;
					word32 eax_725;
					uint32 edx_721 = (word32) (uint64) (word32) (uint64) ((word32) (uint64) (eax_687 - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc68_437))) & 0x01)) << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x03 - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc68_437) + 0x01)) >> 0x01)))))))))))) & 0x07))) + dwLoc88);
					if (dwLoc68_437 > 0x01)
						eax_725 = (word32) (uint64) ((word32) (uint64) (0x07 - dwLoc68_437) >> 0x01);
					else
						eax_725 = 0x03;
					if ((word32) (uint64) (word32) (uint64) (edx_721 >> (byte) ((uint64) eax_725)) == 0x00)
						goto l000000000040166F;
					word32 eax_810;
					dwLoc60_567 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (uint64) dwLoc68_437 & 0x01) << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x03 - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc68_437) + 0x01)) >> 0x01))))))))) & 0x07);
					dwLoc64_568 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) ((word32) (uint64) ((word32) (uint64) dwLoc68_437 & 0x01) == 0x00) << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x03 - (word32) ((uint64) ((word32) ((uint64) dwLoc68_437) >> 0x01))))))))) & 0x07);
					dwLoc58_569 = (word32) (uint64) (word32) (uint64) (0x01 << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x07 - dwLoc68_437)) >> 0x01)))));
					if (dwLoc68_437 > 0x02)
						eax_810 = (word32) (uint64) (word32) (uint64) (0x08 >> (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc68_437) - 0x01)) >> 0x01)))));
					else
						eax_810 = 0x08;
					dwLoc5C_570 = eax_810;
				}
				else
				{
					dwLoc60_567 = 0x00;
					dwLoc64_568 = 0x00;
					dwLoc58_569 = 0x01;
					dwLoc5C_570 = 0x01;
				}
				up32 dwLoc54_585;
				for (dwLoc54_585 = (word32) (uint64) dwLoc64_568; dwLoc54_585 < (word32) ((uint64) dwLoc84); dwLoc54_585 += (word32) (uint64) dwLoc5C_570)
				{
					int32 eax_614 = puts("png_read_row");
					word64 rsp_620;
					word64 rbp_621;
					byte SCZO_622;
					word32 edi_623;
					word64 rsi_624;
					word64 rax_625;
					struct Eq_291 * fs_626;
					word32 eax_627;
					byte SZO_628;
					bool C_629;
					bool Z_630;
					word64 rdi_631;
					word32 esi_632;
					word32 ecx_633;
					word64 rcx_634;
					word32 edx_635;
					word64 rdx_636;
					word64 r13_637;
					word64 r9_638;
					word64 r8_639;
					byte SO_640;
					byte cl_641;
					byte al_642;
					png_read_row();
					if ((uint64) dwLoc54_585 == rax_77)
					{
						up32 dwLoc50_657;
						word32 dwLoc4C_658 = 0x00;
						for (dwLoc50_657 = (word32) (uint64) dwLoc60_567; dwLoc50_657 < (word32) ((uint64) dwLoc88); dwLoc50_657 += (word32) (uint64) dwLoc58_569)
						{
							if ((uint64) dwLoc50_657 == rax_70)
							{
								print_pixel((word32) (uint64) dwLoc4C_658, rax_337, (word32) rax_125, r13_637, fs_626);
								goto l000000000040167F;
							}
							++dwLoc4C_658;
						}
					}
				}
l000000000040166F:
				++dwLoc68_437;
			}
l000000000040167F:
			word64 rsp_481;
			word64 rbp_482;
			byte SCZO_483;
			word32 edi_484;
			word64 rsi_485;
			word64 rax_486;
			struct Eq_1125 * fs_487;
			word32 eax_488;
			byte SZO_489;
			bool C_490;
			bool Z_491;
			word64 rdi_492;
			word32 esi_493;
			word32 ecx_494;
			word64 rcx_495;
			word32 edx_496;
			word64 rdx_497;
			word64 r13_498;
			word64 r9_499;
			word64 r8_500;
			byte SO_501;
			byte cl_502;
			byte al_503;
			png_free();
			word64 rsp_508;
			word64 rbp_509;
			byte SCZO_510;
			word32 edi_511;
			word64 rsi_512;
			word64 rax_513;
			struct Eq_1150 * fs_514;
			word32 eax_515;
			byte SZO_516;
			bool C_517;
			bool Z_518;
			word64 rdi_519;
			word32 esi_520;
			word32 ecx_521;
			word64 rcx_522;
			word32 edx_523;
			word64 rdx_524;
			word64 r13_525;
			word64 r9_526;
			word64 r8_527;
			byte SO_528;
			byte cl_529;
			byte al_530;
			png_destroy_info_struct();
l00000000004016DE:
			word64 rsp_196;
			word64 rbp_197;
			byte SCZO_198;
			word32 edi_199;
			word64 rsi_200;
			word64 rax_201;
			word32 eax_203;
			byte SZO_204;
			bool C_205;
			bool Z_206;
			word64 rdi_207;
			word32 esi_208;
			word32 ecx_209;
			word64 rcx_210;
			word32 edx_211;
			word64 rdx_212;
			word64 r13_213;
			word64 r9_214;
			word64 r8_215;
			byte SO_216;
			byte cl_217;
			byte al_218;
			png_destroy_read_struct();
l000000000040175D:
			if ((rax_13 ^ fs->qw0028) == 0x00)
				return;
			__stack_chk_fail();
		}
		word64 rsp_900;
		word64 rbp_901;
		byte SCZO_902;
		word32 edi_903;
		word64 rsi_904;
		word64 rax_905;
		struct Eq_1023 * fs_906;
		word32 eax_907;
		byte SZO_908;
		bool C_909;
		bool Z_910;
		word64 rdi_911;
		word32 esi_912;
		word32 ecx_913;
		word64 rcx_914;
		word32 edx_915;
		word64 rdx_916;
		word64 r13_917;
		word64 r9_918;
		word64 r8_919;
		byte SO_920;
		byte cl_921;
		byte al_922;
		png_error();
	}
	fwrite(&globals->v4019E8, 0x01, 44, globals->ptr602100);
	goto l00000000004016DE;
}

// 0000000000401780: void __libc_csu_init(Register word32 edi)
void __libc_csu_init(word32 edi)
{
	_init();
	if (0x00601E08 - 0x00601E00 >> 0x03 != 0x00)
	{
		do
		{
			word64 rsp_72;
			word64 r15_73;
			word64 r14_74;
			word32 r15d_75;
			word32 edi_76;
			word64 r13_77;
			word64 r12_78;
			word64 rbp_79;
			word64 rbx_80;
			word64 rsi_81;
			word64 rdx_82;
			byte SCZO_83;
			byte SZO_84;
			bool C_85;
			bool Z_86;
			word32 ebx_87;
			word64 rdi_88;
			globals->ptr601E00();
		} while (rbx_80 + 0x01 != rbp_79);
	}
}

// 00000000004017F0: void __libc_csu_fini()
void __libc_csu_fini()
{
}

// 00000000004017F4: void _fini()
void _fini()
{
}

