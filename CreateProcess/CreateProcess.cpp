// CreateProcess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <stdio.h>

int main()
{
    WCHAR name[] = L"notepad";
    STARTUPINFO si = { sizeof(si) };
   // memset(&si, 0, sizeof(si));
   // si.cb = sizeof(si);
    PROCESS_INFORMATION pi;
    BOOL success = CreateProcessW(nullptr, name, nullptr, nullptr, FALSE, HIGH_PRIORITY_CLASS, nullptr, nullptr, &si, &pi);
    if (success) {
        printf("PID: %u TID: %u\n", pi.dwProcessId, pi.dwThreadId);
        if (WAIT_TIMEOUT == WaitForSingleObject(pi.hProcess, 10000)) {
            printf("Notepad is still running ... \n");
        }
        else {
        DWORD code;
        GetExitCodeProcess(pi.hProcess, &code);
        printf("Notepad has terminated with code: %u\n", code);
        }
       
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    else {
        printf("Error creating process: %u\n", GetLastError());
    }
    return 0;
}
