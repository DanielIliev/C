#include "dict.h"

typedef struct {
    int id;
    char content[25];
    int count;
}dict;
dict words[500];

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
		if(atoi(input) == 0) {
            goto badInput;
		} else {
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
    switch(c) {
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

int checkWord(char word[]) {
    int mempos=-1;
    for(unsigned int i=0; i<ARRLEN(words); i++) {
        if(strcmp(words[i].content, word) == 0) {
            mempos=words[i].id;
        }
    }
    return mempos;
}

void createDictionary(FILE *fp) {
    int c=0,word_iter=0,mempos=0;
    char *word = NULL;
    word = (char*) calloc(25, sizeof(char));
    do {
        c = fgetc(fp);
        if(checkSeparator(c) == 0) {
            word[word_iter] = c;
            word_iter++;
        } else {
            printf("%s\n", word);
            /*if(checkWord(word) != -1) {
                words[mempos].id = mempos;
                strcpy(words[mempos].content, word);
                words[mempos].count=1;
                mempos++;
            }
            word = (void*) realloc(word, ARRLEN(word)*sizeof(char));
            word_iter=0;*/
        }
    } while(c!=EOF);
}

void printDictionary() {
    for(unsigned int i = 0; i<10; i++) {
        printf("ID: %d, Content: %s, Count: %d\n", words[i].id, words[i].content, words[i].count);
    }
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
