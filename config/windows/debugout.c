/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  上記著作権者は，以下の条件を満たす場合に限り，本ソフトウェア（本ソ
 *  フトウェアを改変したものを含む．以下同じ）を使用・複製・改変・再配
 *  布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアをバイナリコードの形または機器に組み込んだ形で利
 *      用する場合には，次のいずれかの条件を満たすこと．
 *    (a) 利用に伴うドキュメント（利用者マニュアルなど）に，上記の著作
 *        権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 利用の形態を，別に定める方法によって，上記著作権者に報告する
 *        こと．
 *  (3) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者を免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者は，
 *  本ソフトウェアに関して，その適用可能性も含めて，いかなる保証も行わ
 *  ない．また，本ソフトウェアの利用により直接的または間接的に生じたい
 *  かなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: debugout.c,v 1.1 2000/11/14 16:31:38 takayuki Exp $
 */
#include "debugout.h"
#include "resource.h"

#ifdef DEBUG_ENABLE

static HANDLE DebugConsole;
static HWND DialogHandle;



LRESULT CALLBACK DebugOutDialogProc(HWND hDlg,UINT Msg,WPARAM wParam,LPARAM lParam)
{
	switch(Msg)
	{
	case WM_INITDIALOG:
		DebugConsole = GetDlgItem(hDlg,IDC_DEBUGOUT);
		ShowWindow(hDlg,SW_SHOW);

	case WM_SIZE:
		{
			RECT client;
			GetClientRect(hDlg,&client);
			MoveWindow(DebugConsole,0,0,client.right,client.bottom,TRUE);
			break;
		}

	case WM_CLOSE:
			/* Closing this dialog is restricted. */
		break;

	case WM_DESTROY:
		DialogHandle = 0;
		break;

	case WM_QUIT:
		DestroyWindow(hDlg);
		break;
	
	default:
		return FALSE;
	}
	return TRUE;
}

void InitializeDebugServices(HINSTANCE hinst,HWND dlg)
{
	int i;
	DialogHandle = CreateDialog(hinst,MAKEINTRESOURCE(DEBUGOUTDIALOG),0l,DebugOutDialogProc);
	i = GetLastError();
	ShowWindow(DialogHandle,SW_SHOW);
}


void FinalizeDebugServices(void)
{
	if(DialogHandle != 0l)
		DestroyWindow(DialogHandle);
}

unsigned int DebugOut(LPCSTR str)
{
	int i,j,k,l;
	char buffer[1024];

	i = GetWindowTextLength(DebugConsole);
	if(i > DEBUG_LIMITTERUPPERBOUND)
	{
		SendMessage(DebugConsole, EM_SETSEL, 0, i - DEBUG_LIMITTERUPPERBOUND);
		SendMessage(DebugConsole, EM_REPLACESEL, (WPARAM)FALSE, (LPARAM)"");
	}

	j = lstrlen(str);
	while(j>0)
	{
		k = j > 512 ? 511 : j;
		for(l=0;l<k;l++,str++)
		{
			if( (buffer[l] = *str) == '\n')
			{
				buffer[l] = '\r';
				buffer[++l] = '\n';
			}
		}
		buffer[l] = '\x0';

		i = GetWindowTextLength(DebugConsole);
		SendMessage(DebugConsole,EM_SETSEL,i,i);
		SendMessage(DebugConsole,EM_REPLACESEL,(WPARAM)FALSE,(LPARAM)buffer);
		
		j -= k;
	}
	return 1;


/*
	int i;
	HANDLE mem;
	char * buf;

	i=OpenClipboard(DialogHandle);

	i = lstrlen(str);
	mem = GlobalAlloc(GMEM_MOVEABLE|GMEM_DDESHARE,i+1);
	buf = GlobalLock(mem);
	lstrcpyn(buf,str,i+1);
	GlobalUnlock(mem);

	i=SetClipboardData(CF_TEXT,mem);
	CloseClipboard();

	SendMessage(DebugConsole,WM_PASTE,0,0);
	return (unsigned)i;
*/
}


#endif