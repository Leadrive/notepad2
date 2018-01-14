#include "EditLexer.h"
#include "EditStyle.h"

// https://en.wikipedia.org/wiki/Common_Lisp
// https://common-lisp.net/

static KEYWORDLIST Keywords_LISP = {{
"nil car cdr list "
"cond defun defvar defmacro let setq setf and or not equal if while lambda loop when "
,
"", "", "", "", "", "", "",

#if NUMKEYWORD == 16
"", "", "", "", "", "", "", ""
#endif
}};

EDITLEXER lexLisp = { SCLEX_LISP, NP2LEX_LISP, L"Lisp Script", L"lisp; el; lsp", L"", &Keywords_LISP,
{
	{ STYLE_DEFAULT, NP2STYLE_Default, L"Default", L"", L"" },
	//{ SCE_C_DEFAULT, L"Default", L"", L"" },
	{ SCE_C_WORD, NP2STYLE_Keyword, L"Keyword", L"fore:#FF8000", L"" },
	{ MULTI_STYLE(SCE_C_STRING, SCE_C_CHARACTER, 0, 0), NP2STYLE_String, L"String", L"fore:#008000", L"" },
	{ SCE_C_NUMBER, NP2STYLE_Number, L"Number", L"fore:#FF0000", L"" },
	{ SCE_C_OPERATOR, NP2STYLE_Operator, L"Operator", L"fore:#B000B0", L"" },
	{ MULTI_STYLE(SCE_C_COMMENTLINE, SCE_C_COMMENT, 0, 0), NP2STYLE_Comment, L"Comment", L"fore:#008000", L"" },
	{ -1, 00000, L"", L"", L"" }
}
};
