// SimpleTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "..\SimpleLibrary\SimpleLibrary.h"

#ifdef _DEBUG
#pragma comment(lib, "..\\x64\\Debug\\SimpleLibrary.lib")
#else
#pragma comment(lib, "..\\x64\\Release\\SimpleLibrary.lib")
#endif


int main()
{
    int result = Add(5, 8);
    printf("Result: %d\n", result);

    return 0;
}

