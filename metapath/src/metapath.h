/******************************************************************************
*
*
* metapath - The universal Explorer-like Plugin
*
* metapath.h
*   Global definitions and declarations
*
* See Readme.txt for more information about this source code.
* Please send me your comments to this work.
*
* See License.txt for details about distribution and modification.
*
*                                              (c) Florian Balmer 1996-2011
*                                                  florian.balmer@gmail.com
*                                               http://www.flos-freeware.ch
*
*
******************************************************************************/

#ifndef METAPATH_H_
#define METAPATH_H_

//==== Main Window ============================================================
#define WC_METAPATH L"metapath"

#define WS_METAPATH ((WS_OVERLAPPEDWINDOW ^ \
					  (WS_MINIMIZEBOX | WS_MAXIMIZEBOX)) | \
					 (WS_CLIPCHILDREN | WS_POPUP))

//==== Data Type for WM_COPYDATA ==============================================
#define DATA_METAPATH_PATHARG 0xFB30

//==== ComboBox Control =======================================================
//#define WC_COMBOBOX L"ComboBox"
#define WS_DRIVEBOX (WS_CHILD | \
					 /*WS_VISIBLE |*/ \
					 WS_CLIPSIBLINGS | \
					 WS_VSCROLL | \
					 CBS_DROPDOWNLIST)

//==== Listview Control =======================================================
#define WS_DIRLIST (WS_CHILD | \
					WS_VISIBLE | \
					WS_CLIPSIBLINGS | \
					WS_CLIPCHILDREN | \
					LVS_REPORT | \
					LVS_NOCOLUMNHEADER | \
					LVS_SHAREIMAGELISTS | \
					LVS_AUTOARRANGE | \
					LVS_SINGLESEL | \
					LVS_SHOWSELALWAYS)

//==== Toolbar Style ==========================================================
#define WS_TOOLBAR (WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | \
					TBSTYLE_TOOLTIPS | TBSTYLE_ALTDRAG | TBSTYLE_LIST | \
					CCS_NODIVIDER | CCS_NOPARENTALIGN)

//==== ReBar Style ============================================================
#define WS_REBAR (WS_CHILD | /*WS_VISIBLE |*/ WS_CLIPCHILDREN | WS_BORDER | \
				  RBS_VARHEIGHT | RBS_BANDBORDERS /*| RBS_FIXEDORDER */ | \
				  CCS_NODIVIDER |/*CCS_NORESIZE | */CCS_NOPARENTALIGN)

//==== Ids ====================================================================
#define IDC_STATUSBAR 0x00A0
#define IDC_TOOLBAR   0x00A1
#define IDC_REBAR     0x00A2
#define IDC_DRIVEBOX  0xA000
#define IDC_DIRLIST   0xA001

//==== Statusbar ==============================================================
#define ID_FILEINFO   0
#define ID_MENUHELP 255

//==== Timer for Change Notifications =========================================
#define ID_TIMER 0xA000

//==== Callback Message from System Tray ======================================
#define APPM_TRAYMESSAGE	(WM_APP + 4)

//==== Function Declarations ==================================================
BOOL InitApplication(HINSTANCE hInstance);
HWND InitInstance(HINSTANCE hInstance, LPSTR pszCmdLine, int nCmdShow);
BOOL ActivatePrevInst(void);
void GetRelaunchParameters(LPWSTR szParameters);
void ShowNotifyIcon(HWND hwnd, BOOL bAdd);

BOOL ChangeDirectory(HWND hwnd, LPCWSTR lpszNewDir, BOOL bUpdateHistory);
void LoadSettings(void);
void SaveSettings(BOOL bSaveSettingsNow);

void ParseCommandLine(void);
void LoadFlags(void);
int CheckIniFile(LPWSTR lpszFile, LPCWSTR lpszModule);
int CheckIniFileRedirect(LPWSTR lpszFile, LPCWSTR lpszModule);
int FindIniFile(void);
int TestIniFile(void);
int CreateIniFile(void);
int CreateIniFileEx(LPCWSTR lpszIniFile);

BOOL DisplayPath(LPCWSTR lpPath, UINT uIdError);
BOOL DisplayLnkFile(LPCWSTR pszLnkFile);

void LaunchTarget(LPCWSTR lpFileName, BOOL bOpenNew);
void SnapToTarget(HWND hwnd);
void SnapToDefaultPos(HWND hwnd);

LRESULT CALLBACK MainWndProc(HWND hwnd, UINT umsg, WPARAM wParam, LPARAM lParam);
LRESULT MsgCreate(HWND hwnd, WPARAM wParam, LPARAM lParam);
void CreateBars(HWND hwnd, HINSTANCE hInstance);
void MsgThemeChanged(HWND hwnd, WPARAM wParam, LPARAM lParam);
void MsgSize(HWND hwnd, WPARAM wParam, LPARAM lParam);
void MsgInitMenu(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT MsgCommand(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT MsgNotify(HWND hwnd, WPARAM wParam, LPARAM lParam);

#endif // METAPATH_H_

///   End of metapath.h
