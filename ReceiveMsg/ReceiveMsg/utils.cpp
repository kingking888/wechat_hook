#include "pch.h"
#include <stdlib.h>
#include <WINSOCK2.H>
#include <stdio.h>


DWORD getWechatWin()
{
	return (DWORD)LoadLibrary(L"WeChatWin.dll");
}

char* UnicodeToChar(const wchar_t* unicode)
{
	int len;
	len = WideCharToMultiByte(CP_UTF8, 0, unicode, -1, NULL, 0, NULL, NULL);
	char* szCHAR = (char*)malloc(len + 1);
	memset(szCHAR, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, unicode, -1, szCHAR, len, NULL, NULL);
	return szCHAR;
}


wchar_t* UTF8ToUnicode(const char* str)
{
	int    textlen = 0;
	wchar_t* result;
	textlen = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	result = (wchar_t*)malloc((textlen + 1) * sizeof(wchar_t));
	memset(result, 0, (textlen + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_UTF8, 0, str, -1, (LPWSTR)result, textlen);
	return    result;
}


VOID DWORDToUnicode(DWORD value, wchar_t* wchar_t_list)
{
	CHAR char_str[0x100] = { 0 };
	_itoa_s(value, char_str, 10);
	swprintf(wchar_t_list, sizeof(wchar_t_list), L"%hs", char_str);
}
