#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Library.h"

int main()
{
	SetConsoleTitle(TEXT("图书馆管理系统"));
	Library* library = new Library();
	return 0;
}