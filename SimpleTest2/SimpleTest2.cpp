#include <stdio.h>
#include <Windows.h>

#include "..\SimpleLibrary\SimpleLibrary.h"

int main()
{
    HINSTANCE hInstDll = LoadLibrary(L"SimpleLibrary.dll");
    if (!hInstDll) {
        printf("Error: %u\n", GetLastError());
        return 1;
    }
    
    //typedef int (*PAdd)(int, int);

    auto add = (decltype(Add)*)GetProcAddress(hInstDll, "Add");
    if (add) {
        int result = add(5, 8);
        printf("Result: %d\n", result);
    }
    return 0;
}

