#include "dict.h"

void generateMenu() {
	printf("\nPROGRAM DICTIONARY\n");
	printf("1) Select file\n"); // Done
	printf("2) Create dictionary\n");
	printf("3) Print out dictionary\n");
	printf("4) Word search\n");
	printf("5) Sort dictionary\n"); // Submenu is alphabethical sort or by frequency
	printf("6) Export dictionary\n"); // Submenu na vseki red po duma i do neq broikata ili dumite v txt a broikata v .cnt fail
	printf("7) Import dictionary from file\n");
	printf("8) Encode dictionary\n");
	printf("9) Decode dictionary\n");
	printf("10) Exit\n");
}

int userChoice() {
	char input[30];
	int choice;
	do
	{
	badInput:
		system("cls");
		generateMenu();
		printf("Select your choice:");
		scanf("%30s", input);
		if (atoi(input) == 0) {
			goto badInput;
		}
		else {
			choice = atoi(input);
		}
	} while (choice < 1 || choice > 10);
	return choice;
}

FILE* selectFile() {
	char name[255];
	FILE *fp = NULL;
	do
	{
		printf("Input the file name (including the extension):");
		scanf("%255s", name);
		fp = fopen(name, "r");
		if (fp == NULL)
		{
			printf("\nFailed to open file\n");
		}
	} while (fp == NULL);
	return fp;
}

int checkSeparator(char c) {
	int check = 0;
	switch (c) {
	case '?':
		check = -1;
		break;
	case '\n':
		check = -2;
		break;
	case ';':
		check = -3;
		break;
	case ':':
		check = -4;
		break;
	case ',':
		check = -5;
		break;
	case '.':
		check = -6;
		break;
	case '!':
		check = -7;
		break;
	case '/':
		check = -8;
		break;
	case EOF:
		check = -9;
		break;
	case ' ':
		check = -10;
		break;
	}
	return check;
}

void createDictionary(FILE *fp) {
	int c = 0, word_iter = 0, mempos = 0;
	current = head;
	char word[25];
	do {
		c = fgetc(fp);
		if (checkSeparator(c) == 0) {
			if (word_iter < ARRLEN(word)) {
				word[word_iter] = c;
				word_iter++;
			}
			else {
				
			}
		}
	} while (c != EOF);
}

void printDictionary() {
	
}

void wordSearch() {
	printf("wordSearch");
}

void sortDictionary() {
	printf("sortDictionary");
}

void exportDictionary() {
	printf("exportDictionary");
}

void importDictionary() {
	printf("importDictionary");
}

void encodeDictionary() {
	printf("encodeDictionary");
}

void decodeDictionary() {
	printf("decodeDictionary");
}
