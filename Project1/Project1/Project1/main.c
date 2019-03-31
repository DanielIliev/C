#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <conio.h>
#include "menu.h"

int main() {
	setlocale(LC_ALL, "bulgarian");
	menu();
	_getch();
	return 0;
}