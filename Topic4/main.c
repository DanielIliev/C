#include <stdio.h>
#include <stdlib.h>

FILE *menu();
void readDirectory();
FILE *readFile();

int main() {
	FILE *fp;

	return;
}

#include "menu.h"

/*
	Глупостите които разбирам:
	Избор на файл за обработка
	Потребителя праска символи докато ръчно не сложи край на програмата (Ctrl Z)
	
*/

/*FILE *menu() {
	system("cls");
	printf("Menu items\n");
	readDirectory();
	FILE *fp = readFile();
	return fp;
}
void readDirectory() {
	DIR *d;
	struct dirent *dir;
	if ((d=opendir("."))!=NULL)
	{
		while ((dir=readdir(d)) != NULL) {
			if (strcmp(dir->d_name, "..") > 0)
			{
				printf("%s\n", dir->d_name);
			}
		}
	}
	closedir(d);
}
FILE *readFile() {
	FILE *fp;
	char user_file[255];
	int opened = 0;
	while(opened==0) {
		printf("Input the file name (as seen on screen):");
		scanf("%255s", user_file);
		if ((fp=fopen(user_file, "r")) != NULL)
		{
			printf("File opened\n");
			opened=1;
		} else {
			printf("Bad name, please try again\n");
			continue;
		}
	}
	return fp;
}*/