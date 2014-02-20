// TaskList.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE h = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);

	if (h != NULL) {
		PROCESSENTRY32 entry;
		entry.dwSize = sizeof(PROCESSENTRY32);
		BOOL result = Process32First(h, &entry);
		if (result != NULL) {
			do {
				DWORD pid = entry.th32ProcessID;
				WCHAR* exefile = entry.szExeFile;
				wprintf(L"%d %s\n", pid, exefile);
			} while (Process32Next(h, &entry));		
		}

		CloseHandle(h);
	}

	return 0;
}

