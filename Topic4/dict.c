#include "dict.h"

void sayhello() {
    printf("Hello World!");
}

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
	int choice = 0;
	do
	{
		system("cls");
		generateMenu();
		printf("Select your choice:");
		scanf("%d", &choice);
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
		fp = checkFile(name, "r");
		if (fp == NULL)
		{
			printf("\nFailed to open file\n");
		}
	} while (fp == NULL);
	return fp;
}

void createDictionary(FILE *fp) {
	rewind(fp);
	int c;
}

void printDictionary() {
	/*printf("printDictionary");
	for (int i = 0; i < 5000; i++)
	{
		if (words[i].word)
		{
			printf("ID: %d, WORD: %s, COUNT: %d", words[i].id, words[i].word, words[i].count);
		}
	}*/
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

// Suplementary functions
FILE* checkFile(const char* filename, const char* mode) {
	FILE *fp = NULL;
	fp = fopen(filename, mode);
	return fp;
}
