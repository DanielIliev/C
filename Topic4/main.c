#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

FILE* checkFile(const char* filename, const char* mode);
FILE* selectFile();
void generateDictionary(FILE *fp, int mempos, int buffer);
void generateMenu();
int userChoice();
void createDictionary();
void printDictionary();
void wordSearch();
void sortDictionary();
void exportDictionary();
void importDictionary();
void encodeDictionary();
void decodeDictionary();

struct word {
	int position; // Position in the dictionary
	char content[30]; // The word
	int count; // Frequency in the file
};

/*buffer = 50;
struct word *words;
words = (void*) malloc(buffer * sizeof(words));
if (fclose(fp) == 0)
{
	printf("\nFile closed... exiting\n");
}*/

int main() {
	FILE* fp = NULL;
	do
	{
		switch(userChoice()) {
			case 1:
				fp=selectFile();
			break;
			case 2:
				/*if (fp==NULL)
				{
					printf("Please select a file first!");
				} else {

				}*/
				createDictionary();
			break;
			case 3:
				printDictionary();
			break;
			case 4:
				wordSearch();
			break;
			case 5:
				sortDictionary();
			break;
			case 6:
				exportDictionary();
			break;
			case 7:
				importDictionary();
			break;
			case 8:
				encodeDictionary();
			break;
			case 9:
				decodeDictionary();
			break;
		}
		printf("\nPress ENTER to continue...");
		_getch();
	} while (userChoice()!=10);
	return 0;
}

void generateMenu() {
	printf("\nPROGRAM DICTIONARY\n");
	printf("1) Select file\n");
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

void createDictionary() {
	printf("createDictionary");
}

void printDictionary() {
	printf("printDictionary");
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
/*
void generateDictionary(FILE *fp) {
    char c;
    char word_stack[20];
    char word_separators[] = {'.', ',', '?', '!', ':', ';', '/', ' '};
    while((c=fgetc(fp)) != EOF) {
        for(int i = 0; i < 8; i++) {
            if(word_separators[i]==c) {
                c = fgetc(fp);
                break;
            }
        }
        fputc(c, words);
    }
    rewind(fp);
}*/