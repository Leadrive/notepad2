#include "EditLexer.h"
#include "EditStyle.h"

static KEYWORDLIST Keywords_XML = {{
"", "", "",
"xml xmlns xsi DOCTYPE doctype PUBLIC "
, // Attribute
"version encoding standalone noNamespaceSchemaLocation schemaLocation CDATA "
"lang id name type value "
, // Value
"utf-8 UTF-8 ISO-8859-1 "
"true false yes no on off "
, "", "", ""

#if NUMKEYWORD == 16
, "", "", "", "", "", "", ""
#endif
}};

EDITLEXER lexXML = { SCLEX_XML, NP2LEX_XML, L"XML Document", L"xml; xsl; xslt; xsd; dtd; rss; svg; xul; axl; rdf; xaml; resx; plist; ", L"", &Keywords_XML,
{
	{ STYLE_DEFAULT, NP2STYLE_Default, L"Default", L"", L"" },
	{ MULTI_STYLE(SCE_H_TAG, SCE_H_TAGUNKNOWN, SCE_H_TAGEND, 0), NP2STYLE_XMLTag, L"XML Tag", L"fore:#8B008B", L"" },
	{ MULTI_STYLE(SCE_H_ATTRIBUTE, SCE_H_ATTRIBUTEUNKNOWN, 0, 0), NP2STYLE_XMLAttribute, L"XML Attribute", L"fore:#FF0000", L"" },
	{ SCE_H_VALUE, NP2STYLE_XMLValue, L"XML Value", L"fore:#1A1AA6", L"" },
	{ MULTI_STYLE(SCE_H_DOUBLESTRING, SCE_H_SINGLESTRING, SCE_H_SGML_DOUBLESTRING, SCE_H_SGML_SIMPLESTRING), NP2STYLE_XMLString, L"XML String", L"fore:#008000", L"" },
	{ SCE_H_OTHER, NP2STYLE_XMLOtherTag, L"XML Other Tag", L"fore:#1A1AA6", L"" },
	{ MULTI_STYLE(SCE_H_COMMENT, SCE_H_XCCOMMENT, SCE_H_SGML_COMMENT, SCE_H_SGML_1ST_PARAM_COMMENT), NP2STYLE_XMLComment, L"XML Comment", L"fore:#808080", L"" },
	{ MULTI_STYLE(SCE_H_ENTITY, SCE_H_SGML_ERROR, 0, 0), NP2STYLE_XMLEntity, L"XML Entity", L"fore:#B000B0", L"" },
	{ SCE_H_DEFAULT, NP2STYLE_XMLElementText, L"XML Element Text", L"", L"" },
	{ MULTI_STYLE(SCE_H_XMLSTART, SCE_H_XMLEND, 0, 0), NP2STYLE_XMLIdentifier, L"XML Identifier", L"bold; fore:#881280", L"" },
	{ MULTI_STYLE(SCE_H_SGML_DEFAULT, SCE_H_SGML_BLOCK_DEFAULT, SCE_H_SGML_COMMAND, SCE_H_SGML_ENTITY), NP2STYLE_XMLSGML, L"SGML", L"fore:#881280", L"" },
	{ SCE_H_CDATA, NP2STYLE_XMLCDATA, L"CDATA", L"fore:#646464", L"" },
	{ -1, 00000, L"", L"", L"" }
}
};
