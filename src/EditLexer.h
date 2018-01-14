#ifndef NOTEPAD2_EDITLEXER_H_
#define NOTEPAD2_EDITLEXER_H_

#include <windows.h>
#include "Scintilla.h"
#include "SciLexer.h"

#define	MULTI_STYLE(a, b, c, d)	((a) | ((b) << 8) | ((c) << 16) | ((d) << 24))
#define	NUMKEYWORD				(KEYWORDSET_MAX + 1)

#if defined(_MSC_VER)
// C4200: zero-sized array in struct/union; C4201: nameless struct/union;
#pragma warning(push)
#pragma warning(disable: 4200 4201)
#endif

typedef struct _editstyle {
	union {
		INT32 iStyle;
		UINT8 iStyle8[4];
	};
	int rid;
	WCHAR	*pszName;
	WCHAR	*pszDefault;
	WCHAR	szValue[128];
} EDITSTYLE, *PEDITSTYLE;

typedef struct _keywordlist {
	char *pszKeyWords[NUMKEYWORD];
} KEYWORDLIST, *PKEYWORDLIST;

typedef struct _editlexer {
	int iLexer;
	int rid;
	WCHAR	*pszName;
	WCHAR	*pszDefExt;
	WCHAR	 szExtensions[128];
	PKEYWORDLIST	pKeyWords;
	EDITSTYLE		Styles[];
} EDITLEXER, *PEDITLEXER;

#if defined(_MSC_VER)
#pragma warning(pop) // C4200, C4201
#endif

// NP2LEX_, rid for EDITLEXERs
#define NP2LEX_DEFAULT	63000	// SCLEX_NULL		Default Text
#define NP2LEX_CPP		63001	// SCLEX_CPP		C/C++
#define NP2LEX_JAVA		63002	// SCLEX_CPP		Java
#define NP2LEX_CSHARP	63003	// SCLEX_CPP		C#
#define NP2LEX_JS		63004	// SCLEX_CPP		JavaScript
#define NP2LEX_RC		63005	// SCLEX_CPP		Resource Script
//#define NP2LEX_IDL		63006	// SCLEX_CPP		Interface Definition Language
#define NP2LEX_D		63007	// SCLEX_CPP		D
#define NP2LEX_ASY		63008	// SCLEX_CPP		Asymptote
#define NP2LEX_CIL		63009	// SCLEX_CIL		CIL
//#define NP2LEX_OBJC		63010	// SCLEX_CPP		Objective C/C++
#define NP2LEX_AS		63011	// SCLEX_CPP		ActionScript
#define NP2LEX_HAXE		63012	// SCLEX_CPP		haXe
#define NP2LEX_GROOVY	63013	// SCLEX_CPP		Groovy
#define NP2LEX_SCALA	63014	// SCLEX_CPP		Scala
#define NP2LEX_GO		63015	// SCLEX_CPP		Go Source
#define NP2LEX_GRADLE	63016	// SCLEX_CPP		Gradle

#define NP2LEX_VB		63021	// SCLEX_VB			VB
#define NP2LEX_FSHARP	63022	// SCLEX_FSHARP		F#
#define NP2LEX_ASM		63023	// SCLEX_ASM		Assembler
#define NP2LEX_PASCAL	63024	// SCLEX_PASCAL		Pascal
#define NP2LEX_XML		63025	// SCLEX_XML		XML
#define NP2LEX_HTML		63026	// SCLEX_HTML		HTML
#define NP2LEX_CSS		63027	// SCLEX_CSS		CSS
#define NP2LEX_SQL		63028	// SCLEX_SQL		SQL
#define NP2LEX_PHP		63029	// SCLEX_CPP		PHP
#define NP2LEX_VBS		63030	// SCLEX_VBSCRIPT	VBScript
#define NP2LEX_PERL		63031	// SCLEX_PERL		Perl
#define NP2LEX_PYTHON	63032	// SCLEX_PYTHON		Python
#define NP2LEX_RUBY		63033	// SCLEX_RUBY		Ruby
#define NP2LEX_LUA		63034	// SCLEX_LUA		Lua
#define NP2LEX_TCL		63035	// SCLEX_TCL		Tcl
#define NP2LEX_BATCH	63036	// SCLEX_BATCH		Batch
#define NP2LEX_BASH		63037	// SCLEX_BASH		Shell
#define NP2LEX_PS1		63038	// SCLEX_POWERSHELL	PowerShell
#define NP2LEX_AU3		63039	// SCLEX_AU3		AutoIt3
#define NP2LEX_MATLAB	63040	// SCLEX_MATLAB		MATLAB
#define NP2LEX_FORTRAN	63041	// SCLEX_FORTRAN	Fortran
#define NP2LEX_LATEX	63042	// SCLEX_LATEX		LaTeX
#define NP2LEX_VHDL		63043	// SCLEX_VHDL		VHDL
#define NP2LEX_VERILOG	63044	// SCLEX_VERILOG	Verilog HDL
#define NP2LEX_MAKE		63045	// SCLEX_MAKEFILE	Makefile
#define NP2LEX_CMAKE	63046	// SCLEX_CMAKE		CMake
#define NP2LEX_INNO		63047	// SCLEX_INNOSETUP	Inno
#define NP2LEX_INI		63048	// SCLEX_PROPERTIES	Configuration
#define NP2LEX_CONF		63049	// SCLEX_CONF		Apache Config
#define NP2LEX_DIFF		63050	// SCLEX_DIFF		Diff/Patch
#define NP2LEX_AWK		63051	// SCLEX_CPP		Awk
#define NP2LEX_JAM		63052	// SCLEX_CPP		Jamfile
#define NP2LEX_DOT		63053	// SCLEX_GRAPHVIZ	GraphViz Dot
#define NP2LEX_JSON		63054	// SCLEX_JSON		JSON File
#define NP2LEX_SMALI	63055	// SCLEX_SMALI		Android Smali
#define NP2LEX_NSIS		63056	// SCLEX_NSIS		Nsis
#define NP2LEX_TEXINFO	63057	// SCLEX_TEXINFO	Texinfo
#define NP2LEX_LISP		63058	// SCLEX_LISP		Lisp
#define NP2LEX_VIM		63059	// SCLEX_VIM		Vim
#define NP2LEX_LLVM		63060	// SCLEX_LLVM		LLVM
#define NP2LEX_OCTAVE	63061	// SCLEX_MATLAB		Octave
#define NP2LEX_SCILAB	63062	// SCLEX_MATLAB		SciLab
#define NP2LEX_JULIA	63066	// SCLEX_MATLAB		Julia
#define NP2LEX_ANSI		63099	// SCLEX_NULL		ANSI

#endif // NOTEPAD2_EDITLEXER_H_

// end of EditLexer.h
