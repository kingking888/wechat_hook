#pragma once
#include "pch.h"
#include<WINSOCK2.H>


DWORD getWechatWin();
char* UnicodeToChar(const wchar_t* unicode);
wchar_t* UTF8ToUnicode(const char* str);
VOID DWORDToUnicode(DWORD value, wchar_t* wchar_t_list);