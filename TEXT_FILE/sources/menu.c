#include "menu.h"

void readDirectory();
FILE *readFile();

FILE *menu() {
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
}