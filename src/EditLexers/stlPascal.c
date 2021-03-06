#include "EditLexer.h"
#include "EditStyle.h"

// https://en.wikipedia.org/wiki/Pascal_%28programming_language%29
// https://en.wikipedia.org/wiki/Delphi_(programming_language)

static KEYWORDLIST Keywords_Pascal = {{
"absolute abstract all alias array as asm assembler begin break case cdecl class const constructor continue cppdecl destructor dispose do downto else end except exit export external far far16 finalization finally for forward function goto if implementation in at inherited initialization inline interface is label library local message name near new nostackframe not of oldfpccall on operator out overload override packed pascal private  procedure program protected public published raise record repeat register reintroduce resourcestring resident restricted safecall self set softfloat stdcall then threadvar to try interrupt only otherwise qualified segment type value unit until uses var view virtual while with read write default nodefault stored implements readonly writeonly add remove index property exports package platform contains requires automated dispid dispinterface final strict sealed unsafe varargs "
"object nil null true false div mod shl shr and or xor inc dec pow ""module import attribute static volatile ignorable iocritical noreturn and_then or_else cycle leave bindable dynamic deprecated "
,/********* Type *********/
"tobject void pointer file anyfile text boolean byte word dword qword integer int64 cardinal single float double extended real complex comp bytebool byteint bytecard cboolean cword cinteger ccardinal pbyte pword pdword pqword plongword pshortint plongint psmallint plargeint plargeuint pinteger pint64 pcardinal psingle pdouble pextended ptrword ptrint ptruint ptrcard longbool longword longint longcard longreal shortbool shortword shortint shortcard shortreal smallint largeint largeuint medbool medword medint medcard medreal wordbool systemword systeminteger sizeint sizeuint sizetype valreal cint cuint clong culong cint64 cuint64 cint32 cuint32 cshort cushort size_t "
"hwnd hmodule hresult variant iunknown idispatch iinterface lpstr lpcstr "
"char pchar string pstring tstring tstrings cstring ansichar widechar pwidechar ansistring widestring intlstring shortstring ""textrec filerec "
"tclass tmethod thandle tcomponent tpersistent tstream istream tguid tcollection tlist trect tpoint tsize tcoord tcolor tkey tdatetime ttimestamp "
,/**********  Function *************/
"sizeof high low assigned length ord pred align assign succ addr seg concat ofs chr upcase lowercase pos space hexstr octstr binstr eof eoln "
, "assert exclude include copy move insert delete setlength fillchar seek read readln write writeln rewrite reset close blockwrite blockread erase rename truncate append flush str val halt error runerror getdir chdir mkdir rmdir "
, "", "", "", "", ""

#if NUMKEYWORD == 16
, "", "", "", "", "", "", ""
#endif
}};

EDITLEXER lexPascal = { SCLEX_PASCAL, NP2LEX_PASCAL, L"Pascal Source", L"pas; inc; dpr; dpk; dfm; pp; lfm; lpr; fpd", L"", &Keywords_Pascal,
{
	{ STYLE_DEFAULT, NP2STYLE_Default, L"Default", L"", L"" },
	//{ SCE_PAS_DEFAULT, L"Default", L"", L"" },
	{ SCE_PAS_WORD, NP2STYLE_Keyword, L"Keyword", L"bold; fore:#FF8000", L"" },
	{ SCE_PAS_TYPE, NP2STYLE_TypeKeyword, L"Type Keyword", L"bold; fore:#1E90FF", L"" },
	{ SCE_PAS_FUNCTION, NP2STYLE_BasicFunction, L"Basic Function", L"fore:#0080FF", L"" },
	{ SCE_PAS_FUNCTION, NP2STYLE_Function, L"Function", L"fore:#A46000", L"" },
	{ MULTI_STYLE(SCE_PAS_PREPROCESSOR, SCE_PAS_PREPROCESSOR2, 0, 0), NP2STYLE_Preprocessor, L"Preprocessor", L"fore:#FF00FF", L"" },
	{ MULTI_STYLE(SCE_PAS_COMMENT, SCE_PAS_COMMENT2, SCE_PAS_COMMENTLINE, 0), NP2STYLE_Comment, L"Comment", L"fore:#008000", L"" },
	{ MULTI_STYLE(SCE_PAS_STRING, SCE_PAS_CHARACTER, SCE_PAS_STRINGEOL, 0), NP2STYLE_String, L"String", L"fore:#008000", L"" },
	{ MULTI_STYLE(SCE_PAS_NUMBER, SCE_PAS_HEXNUMBER, 0, 0), NP2STYLE_Number, L"Number", L"fore:#FF0000", L"" },
	{ SCE_PAS_OPERATOR, NP2STYLE_Operator, L"Operator", L"fore:#B000B0", L"" },
	{ SCE_PAS_ASM, NP2STYLE_InlineAsm, L"Inline Asm", L"#fore:#408080", L"" },
	{ -1, 00000, L"", L"", L"" }
}
};
