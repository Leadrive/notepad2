#include "EditLexer.h"
#include "EditStyle.h"

// http://dlang.org/

static KEYWORDLIST Keywords_D = {{
"alias align asm assert body break case cast catch continue debug default delete "
"do else export false finally for foreach foreach_reverse goto if import invariant "
"is macro mixin new null package pragma private protected public ref return super "
"switch template this throw true try typedef typeid typeof version volatile while "
"with  __thread __traits abstract auto const deprecated extern final immutable "
"nothrow override pure __gshared scope shared static synchronized "
"in out inout lazy "
"class enum interface module struct union unittest "
"void function delegate "
, // type keyword
"bool byte ubyte cent ucent short ushort int uint long ulong char wchar dchar "
"float double real cfloat cdouble creal ifloat idouble ireal "

"string wstring dstring wchar_t "
"size_t ptrdiff_t hash_t "
"int8_t uint8_t int16_t uint16_t int32_t uint32_t int64_t uint64_t intmax_t "
"uintmax_t intptr_t uintptr_t Clong_t Culong_t va_list clock_t time_t "
, // preprocessor
"line"
, // directive
"disable property safe system trusted "
, // attribute
""
, // class
"Object TypeInfo ClassInfo Error Exception "
"FILE "
, // interface
""
, // enumeration
""
, // constant
"__FILE__ __LINE__ __EOF__ __DATE__ __TIME__ __TIMESTAMP__ __VERSION__ __VENDOR__ __LOCAL_SIZE "
"CLOCKS_PER_SEC "

#if NUMKEYWORD == 16
,// 2nd keyword
"even naked near far word dword qword ptr "
"da db dd de df di dl dq  ds dt dw"
,// 2nd type keyword
""
,// asm intruction
"aaa aad aam aas adc add addpd addps addsd addss and andnpd andnps andpd andps arpl bound bsf bsr bswap bt btc btr bts call cbw cdq clc cld clflush cli clts cmc cmova cmovae cmovb cmovbe cmovc cmove cmovg cmovge cmovl cmovle cmovna cmovnae cmovnb cmovnbe cmovnc cmovne cmovng cmovnge cmovnl cmovnle cmovno cmovnp cmovns cmovnz cmovo cmovp cmovpe cmovpo cmovs cmovz cmp cmppd cmpps cmps cmpsb cmpsd cmpss cmpsw cmpxch8b cmpxchg comisd comiss cpuid cvtdq2pd cvtdq2ps cvtpd2dq cvtpd2pi cvtpd2ps cvtpi2pd cvtpi2ps cvtps2dq cvtps2pd cvtps2pi cvtsd2si cvtsd2ss cvtsi2sd cvtsi2ss cvtss2sd cvtss2si cvttpd2dq cvttpd2pi cvttps2dq cvttps2pi cvttsd2si cvttss2si cwd cwde daa das dec div divpd divps divsd divss emms enter "
"f2xm1 fabs fadd faddp fbld fbstp fchs fclex fcmovb fcmovbe fcmove fcmovnb fcmovnbe fcmovne fcmovnu fcmovu fcom fcomi fcomip fcomp fcompp fcos fdecstp fdisi fdiv fdivp fdivr fdivrp feni ffree fiadd ficom ficomp fidiv fidivr fild fimul fincstp finit fist fistp fisub fisubr fld fld1 fldcw fldenv fldl2e fldl2t fldlg2 fldln2 fldpi fldz fmul fmulp fnclex fndisi fneni fninit fnop fnsave fnstcw fnstenv fnstsw fpatan fprem fprem1 fptan frndint frstor fsave fscale fsetpm fsin fsincos fsqrt fst fstcw fstenv fstp fstsw fsub fsubp fsubr fsubrp ftst fucom fucomi fucomip fucomp fucompp fwait fxam fxch fxrstor fxsave fxtract fyl2x fyl2xp1 "
"hlt idiv imul in inc ins insb insd insw int into invd invlpg iret iretd ja jae jb jbe jc jcxz je jecxz jg jge jl jle jmp jna jnae jnb jnbe jnc jne jng jnge jnl jnle jno jnp jns jnz jo jp jpe jpo js jz lahf lar ldmxcsr lds lea leave les lfence lfs lgdt lgs lidt lldt lmsw lock lods lodsb lodsd lodsw loop loope loopne loopnz loopz lsl lss ltr maskmovdqu maskmovq maxpd maxps maxsd maxss mfence minpd minps minsd minss mov movapd movaps movd movdq2q movdqa movdqu movhlps movhpd movhps movlhps movlpd movlps movmskpd movmskps movntdq movnti movntpd movntps movntq movq movq2dq movs movsb movsd movss movsw movsx movupd movups movzx mul mulpd mulps mulsd mulss neg nop not or orpd orps out outs outsb outsd outsw packssdw packsswb packuswb paddb paddd paddq paddsb paddsw paddusb paddusw paddw pand pandn pavgb pavgw pcmpeqb pcmpeqd pcmpeqw pcmpgtb pcmpgtd pcmpgtw pextrw pinsrw pmaddwd pmaxsw pmaxub pminsw pminub pmovmskb pmulhuw pmulhw pmullw pmuludq pop popa popad popf popfd por prefetchnta prefetcht0 prefetcht1 prefetcht2 psadbw pshufd pshufhw pshufw pslld pslldq psllq psllw psrad psraw psrld psrldq psrlq psrlw psubb psubd psubq psubsb psubsw psubusb psubusw psubw punpckhbw punpckhdq punpckhqdq punpckhwd punpcklbw punpckldq punpcklqdq punpcklwd push pusha pushad pushf pushfd pxor rcl rcpps rcpss rcr rdmsr rdpmc rdtsc rep repe repne repnz repz ret retf rol ror rsm rsqrtps rsqrtss sahf sal sar sbb scas scasb scasd scasw seta setae setb setbe setc sete setg setge setl setle setna setnae setnb setnbe setnc setne setng setnge setnl setnle setno setnp setns setnz setp setpe setpo sets setz sfence sgdt shl shld shr shrd shufpd shufps sidt sldt smsw sqrtpd sqrtps sqrtsd sqrtss stc std sti stmxcsr stos stosb stosd stosw str sub subpd subps subsd subss sysenter sysexit test ucomisd ucomiss ud2 unpckhpd unpckhps unpcklpd unpcklps verr verw wait wbinvd wrmsr xadd xchg xlat xlatb xor xorpd xorps "
"addsubpd addsubps fisttp haddpd haddps hsubpd hsubps lddqu monitor movddup movshdup movsldup mwait "
"pavgusb pf2id pfacc pfadd pfcmpeq pfcmpge pfcmpgt pfmax pfmin pfmul pfnacc pfpnacc pfrcp pfrcpit1 pfrcpit2 pfrsqit1 pfrsqrt pfsub pfsubr pi2fd pmulhrw pswapd"
,// asm register
"AL AH AX EAX BL BH BX EBX CL CH CX ECX DL DH DX EDX BP EBP SP ESP DI EDI SI ESI ES CS SS DS GS FS "
"CR0 CR2 CR3 CR4 DR0 DR1 DR2 DR3 DR6 DR7 TR3 TR4 TR5 TR6 TR7 ST ST0 ST1 ST2 ST3 ST4 ST5 ST6 ST7 "
"MM0 MM1 MM2 MM3 MM4 MM5 MM6 MM7 XMM0 XMM1 XMM2 XMM3 XMM4 XMM5 XMM6 XMM7 "
, "", "",
"for^() if^() switch^() while^() else^if^() foreach^() foreach_reverse^() with^() "
" synchronized^() catch^() scope^() version^() mixin^() "
#endif
}};

EDITLEXER lexD = { SCLEX_CPP, NP2LEX_D, L"D Source", L"d; di", L"", &Keywords_D,
{
	{ STYLE_DEFAULT, NP2STYLE_Default, L"Default", L"", L"" },
	//{ SCE_C_DEFAULT, L"Default", L"", L"" },
	{ SCE_C_WORD, NP2STYLE_Keyword, L"Keyword", L"fore:#0000FF", L"" },
	{ SCE_C_WORD2, NP2STYLE_TypeKeyword, L"Type Keyword", L"fore:#0000FF", L"" },
	{ SCE_C_PREPROCESSOR, NP2STYLE_Preprocessor, L"Preprocessor", L"fore:#FF8000", L"" },
	{ SCE_C_DIRECTIVE, NP2STYLE_Attribute, L"Attribute", L"fore:#FF8000", L""},
	{ SCE_C_2NDWORD, NP2STYLE_Directive, L"Directive", L"fore:#0000FF", L"" },
	{ SCE_C_CLASS, NP2STYLE_Class, L"Class", L"fore:#0080FF", L"" },
	{ SCE_C_STRUCT, NP2STYLE_Struct, L"Struct", L"fore:#0080FF", L"" },
	{ SCE_C_UNION, NP2STYLE_Union, L"Union", L"fore:#0080FF", L"" },
	{ SCE_C_INTERFACE, NP2STYLE_Interface, L"Interface", L"bold; fore:#1E90FF", L""},
	{ SCE_C_FUNCTION, NP2STYLE_Function, L"Function", L"fore:#A46000", L"" },
	{ SCE_C_ENUMERATION, NP2STYLE_Enumeration, L"Enumeration", L"fore:#FF8000", L""},
	{ SCE_C_CONSTANT, NP2STYLE_Constant, L"Constant", L"bold; fore:#B000B0", L""},
	{ MULTI_STYLE(SCE_C_COMMENT, SCE_C_COMMENTLINE, 0, 0), NP2STYLE_Comment, L"Comment", L"fore:#008000", L"" },
	{ SCE_C_COMMENTDOC_TAG, NP2STYLE_DocCommentTag, L"Doc Comment Tag", L"bold; fore:#008000F", L"" },
	{ MULTI_STYLE(SCE_C_COMMENTDOC, SCE_C_COMMENTLINEDOC, SCE_C_COMMENTDOC_TAG_XML, 0), NP2STYLE_DocComment, L"Doc Comment", L"fore:#008000", L"" },
	{ MULTI_STYLE(SCE_C_STRING, SCE_C_CHARACTER, SCE_C_STRINGEOL, 0), NP2STYLE_String, L"String", L"fore:#008000", L"" },
	{ MULTI_STYLE(SCE_C_VERBATIM, SCE_C_DSTRINGB, 0, 0), NP2STYLE_VerbatimString, L"Verbatim String", L"fore:#008080", L"" },
	{ SCE_C_DSTRINGX, NP2STYLE_HexString, L"Hex String", L"fore:#FF0080", L""},
	{ SCE_C_DSTRINGQ, NP2STYLE_DelimitedString, L"Delimited String", L"fore:#E24000", L""},
	{ SCE_C_DSTRINGT, NP2STYLE_TokenString, L"Token String", L"fore:#A46000", L""},
	{ SCE_C_LABEL, NP2STYLE_Label, L"Label", L"fore:#000000; back:#FFC040", L""},
	{ SCE_C_NUMBER, NP2STYLE_Number, L"Number", L"fore:#FF0000", L"" },
	{ SCE_C_OPERATOR, NP2STYLE_Operator, L"Operator", L"fore:#B000B0", L"" },
	{ SCE_C_ASM_INSTRUCTION, NP2STYLE_Instruction, L"Instruction", L"fore:#0080FF", L"" },
	{ SCE_C_ASM_REGISTER, NP2STYLE_Register, L"Register", L"fore:#FF8000", L"" },
	{ -1, 00000, L"", L"", L"" }
}
};
