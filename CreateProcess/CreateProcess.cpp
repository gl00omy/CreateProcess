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
    BOOL success = CreateProcessW(nullptr, name, nullptr, nullptr, FALSE,
        HIGH_PRIORITY_CLASS, nullptr, nullptr, &si, &pi);
    if (success) {
        printf("PID: %u TID: %u\n", pi.dwProcessId, pi.dwThreadId);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else {
        printf("Error creating process: %u\n", GetLastError());
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
