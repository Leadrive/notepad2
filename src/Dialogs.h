/******************************************************************************
*
*
* Notepad2
*
* Dialogs.h
*   Definitions for Notepad2 dialog boxes
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

#ifndef NOTEPAD2_DIALOGS_H_
#define NOTEPAD2_DIALOGS_H_

#define MBINFO			0
#define MBWARN			1
#define MBYESNO			2
#define MBYESNOWARN		3
#define MBYESNOCANCEL	4
#define MBOKCANCEL		8

/**
 * App message used to center MessageBox to the window of the program.
 */
#define APPM_CENTER_MESSAGE_BOX		(WM_APP + 1)

int 	MsgBox(int iType, UINT uIdMsg, ...);
void	DisplayCmdLineHelp(HWND hwnd);
BOOL	GetDirectory(HWND hwndParent, int iTitle, LPWSTR pszFolder, LPCWSTR pszBase, BOOL bNewDialogStyle);
INT_PTR CALLBACK AboutDlgProc(HWND hwnd, UINT umsg, WPARAM wParam, LPARAM lParam);
void	RunDlg(HWND hwnd, LPCWSTR lpstrDefault);
BOOL	OpenWithDlg(HWND hwnd, LPCWSTR lpstrFile);
BOOL	FavoritesDlg(HWND hwnd, LPWSTR lpstrFile);
BOOL	AddToFavDlg(HWND hwnd, LPCWSTR lpszName, LPCWSTR lpszTarget);
BOOL	FileMRUDlg(HWND hwnd, LPWSTR lpstrFile);
BOOL	ChangeNotifyDlg(HWND hwnd);
BOOL	ColumnWrapDlg(HWND hwnd, UINT uidDlg, int *iNumber);
BOOL	WordWrapSettingsDlg(HWND hwnd, UINT uidDlg, int *iNumber);
BOOL	LongLineSettingsDlg(HWND hwnd, UINT uidDlg, int *iNumber);
BOOL	TabSettingsDlg(HWND hwnd, UINT uidDlg, int *iNumber);
BOOL	SelectDefEncodingDlg(HWND hwnd, int *pidREncoding);
BOOL	SelectEncodingDlg(HWND hwnd, int *pidREncoding);
BOOL	RecodeDlg(HWND hwnd, int *pidREncoding);
BOOL	SelectDefLineEndingDlg(HWND hwnd, int *iOption);
INT_PTR InfoBox(int iType, LPCWSTR lpstrSetting, int uidMessage, ...);

#endif // NOTEPAD2_DIALOGS_H_

// End of Dialogs.h
