#include "EditLexer.h"
#include "EditStyle.h"

// http://msdn.microsoft.com/library/d1wf56tt.aspx
// http://msdn.microsoft.com/en-us/library/ydz4cfk3.aspx

static KEYWORDLIST Keywords_VBS = {{
"Alias And As Attribute Array Begin ByRef ByVal Call Case Class Compare Const Continue "
"Declare Dim Do Each Else ElseIf Empty End Enum Eqv Erase Error Event Exit "
"Explicit False For Friend Function Get Global GoSub Goto If Imp Implement In Is Let Lib "
"Load Loop LSet Me Mid Mod Module New Next Not Nothing Null On Option Optional Or "
"Preserve Private Property Public RaiseEvent ReDim Rem Resume Return RSet Select Set "
"Static Stop Sub Then To True Type Unload Until Wend While With WithEvents Xor"
, // type keyword
"Boolean Byte Currency Date Double Integer Long Object Single String Variant "
"RegExp "
, // not used keyword
"Err WScript"
, // preprocessor
""
, // attribute/property
""
, // VB Const
// String
"vbCr vbCrLf vbFormFeed vbLf vbNewLine vbNullChar vbNullString vbTab vbVerticalTab "
// MsgBox
"vbOK vbCancel vbAbort vbRetry vbIgnore vbYes vbNo "
"vbOKOnly vbOKCancel vbAbortRetryIgnore vbYesNoCancel vbYesNo vbRetryCancel "
"vbCritical vbQuestion vbExclamation vbInformation vbDefaultButton1 vbDefaultButton2 "
"vbDefaultButton3 vbDefaultButton4 vbApplicationModal vbSystemModal "
// Color
"vbBlack vbRed vbGreen vbYellow vbBlue vbMagenta vbCyan vbWhite "
// Comparison
"vbBinaryCompare vbTextCompare "
// Date and Time
"vbSunday vbMonday vbTuesday vbWednesday vbThursday vbFriday vbSaturday "
"vbUseSystemDayOfWeek vbFirstJan1 vbFirstFourDays vbFirstFullWeek "
// Date Format
"vbGeneralDate vbLongDate vbShortDate vbLongTime vbShortTime "
// Tristate
"vbUseDefault vbTrue vbFalse"
// VarType
"vbEmpty vbNull vbInteger vbLong vbSingle vbDouble vbCurrency vbDate vbString "
"vbObject vbError vbBoolean vbVariant vbDataObject vbDecimal vbByte vbArray "
// Miscellaneous
"vbObjectError"
, "",
""
,
"WScript "

#if NUMKEYWORD == 16
, "", "", "", "", "", "", ""
#endif
}};


EDITLEXER lexVBS = { SCLEX_VBSCRIPT, NP2LEX_VBS, L"VBScript", L"vbs; dsm", L"", &Keywords_VBS,
{
	{ STYLE_DEFAULT, NP2STYLE_Default, L"Default", L"", L"" },
	//{ SCE_B_DEFAULT, L"Default", L"", L"" },
	{ SCE_B_KEYWORD, NP2STYLE_Keyword, L"Keyword", L"fore:#0000FF", L"" },
	{ SCE_B_KEYWORD2, NP2STYLE_TypeKeyword, L"Type Keyword", L"fore:#0000FF", L"" },
	{ SCE_B_CONSTANT, NP2STYLE_Constant, L"Constant", L"bold; fore:#B000B0", L""},
	{ SCE_B_COMMENT, NP2STYLE_Comment, L"Comment", L"fore:#008000", L"" },
	{ MULTI_STYLE(SCE_B_STRING, SCE_B_STRINGEOL, 0, 0), NP2STYLE_String, L"String", L"fore:#008000", L"" },
	{ SCE_B_LABEL, NP2STYLE_Label, L"Label", L"fore:#000000; back:#FFC040", L""},
	{ SCE_B_NUMBER, NP2STYLE_Number, L"Number", L"fore:#FF0000", L"" },
	{ SCE_B_OPERATOR, NP2STYLE_Operator, L"Operator", L"fore:#B000B0", L"" },
	{ -1, 00000, L"", L"", L"" }
}
};