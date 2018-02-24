#include<windows.h>
#include "resource.h"

#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK MyDlgProc(HWND, UINT, WPARAM, LPARAM);
ATOM InitApp(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);

char szClassName[] = "sample01";
HINSTANCE hInst;
HWND hDlg;
char szName[32];
HWND hMain;

int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE hPrevInst, LPSTR lpsCmdLine, int nCmdShow)
{
	MSG msg;
	BOOL bRet;
	HACCEL
	
	hInst = hCurInst;
	if (!InitApp(hCurInst))
		return FALSE;
	if (!InitInstance(hCurInst, nCmdShow))
		return FALSE;
		hAccel = LoadAccelerators(hCurInst, "MYACCEL");
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0){
		if (bRet == -1){
			MessageBox(NULL, "GetMessageError", "Error", MB_OK);
			break;
		} else {
			if(!hDlg || !IsDialogMessage(hDlg, &msg)){
				if(!TranslateAccelerator(hMain, hAccel, &msg)){
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				}
			}
		}
	}
	return (int)msg.wParam;
}

ATOM InitApp(HINSTANCE hInst)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = NULL;
	wc.hCursor = (HCURSOR)LoadImage(NULL, MAKEINTRESOURCE(IDC_ARROW), IMAGE_CURSOR, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = "MYMENU";
	wc.lpszClassName = (LPCSTR)szClassName;
	wc.hIconSm = (HICON)LoadImage(NULL, MAKEINTRESOURCE(IDI_APPLICATION), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_SHARED);
	return (RegisterClassEx(&wc));
}

BOOL InitInstance(HINSTANCE hInst, int nCmdShow)
{
	HWND hWnd;
	hWnd = CreateWindow(szClassName, "モードレスダイアログ", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	hMain = hWnd;
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch(msg){
		case WM_CREATE:
			hMenu = GetMenu(hWnd);;
			break;
		case WM_INITMENU:
			if (IsWindow(hDlg)){
				EnableMenuItem(hMenu, IDM_DLG, MF_BYCOMMAND | MF_GRAYED);
				EnableMenuItem(hMenu, IDM_CLOSEDLG, MF_BYCOMMAND | MF_ENABLED);
			} else {
				EnableMenuItem(hMenu, IDM_DLG, MF_BYCOMMAND | MF_ENABLED);
				EnableMenuItem(hMenu, IDM_CLOSEDLG, MF_BYCOMMAND | MF_GRAYED);
			break;
		case WM_PAINT:
			if(strcmp(szName, "") == 0)
				strcopy(szBuf, "まだ名前の入力はありません");
			else
				wsprintf(szBuf, "入力された氏名は%s", szName);
			hdc = BeginPaint(hWnd, &ps);
			TextOut(hdc, 10, 10, szBuf, (int)strlen(szBuf));
			EndPaint(hWnd, &ps);
			break;
		case WM_COMMAND:
			switch(LOWORD(wp)){
				case IDM_END:
					SendMessage(hWnd, WM_CLOSE, 0, 0);
					break;
				case IDM_DLG:
					hDlg = CreateDialog(hInst, "MYDLG", hWnd, (DLGPROC)MyDlgProc);
					ShowWindow(hDlg, SW_NORMAL);
					break;
				case IDM_CLOSEDLG:
					DestroyWindow(hDlg);
					break;
			}
			break;
		case WM_CLOSE:
			if(IsWindow(hDlg)){
				MessageBox(hWnd, "ダイアログボックスを閉じる", "閉じる", MB_OK);
				DestroyWindow(hDlg);
			}
			DestroyWindow(hWnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return (DefWindowProc(hWnd, msg, wp, lp));
	}
	return 0;
}
BOOL CALLBACK MyDlgProc(HWND hDlg, UNIT msg, WPARAM wp, LPARAM lp){
	static HWND hParent;
	switch(msg){
		case WM_INITDIALOG:
			hParent = GetParent(hDlg);
			return TRUE;
		case WM_COMMAND:
			switch(LOWORD(wp)){
				case IDOK:
					GetDlgItemText(hDlg, IDC_EDIT1, szName,(int)sizeof(szName) - 1);
					InvalidateRect(hParent, NULL, TRUE);
					return TRUE;
				case IDCANCEL:
					SetDlgItemText(hDlg, IDC_EDIT1, "");
					return TRUE;
				case IDC_CLOSE:
					DestroyWindow(hDlg);
					return TRUE;
			}
			return FALSE;
	}
	return FALSE;
}