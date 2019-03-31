#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

FILE* selectFile();
void generateMenu();
int userChoice();
void createDictionary(FILE *fp);
void printDictionary();
void wordSearch();
void sortDictionary();
void exportDictionary();
void importDictionary();
void encodeDictionary();
void decodeDictionary();
FILE* checkFile(const char* filename, const char* mode);
//void init_struct(struct initial);

typedef struct {
	int id; // ID in the dictionary
	char *content; // The word
	int count;
} word;

int main() {
	FILE* fp = NULL;
	int choice;
	struct word *words;
	words->id = 0;
	words->content = "0";
	words->count = 0;
	repeat:
	choice = userChoice();
	do
	{
		switch(choice) {
			case 1:
				fp=selectFile();
			break;
			case 2:
				if (fp==NULL)
				{
					printf("Please select a file first!");
				} else {
					createDictionary(fp);
				}
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
			case 10:
				return -1;
			break;
			default:
				goto repeat;
		}
		printf("\nPress any key to continue...");
		getch();
		goto repeat;
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

void createDictionary(FILE *fp) {
	rewind(fp);
	int c;
    char word_stack[20];
    int word_stack_iterator = 0, mempos = 0, buffer = 50;
    struct word *words;
    words = (struct word*) malloc(buffer * sizeof(struct word));
    char word_separators[] = {'.', ',', '?', '!', ':', ';', '/', ' '};
    FILE *dict;
    char *filename;
    printf("Input dictionary filename:");
    scanf("%s", filename);
    dict = fopen(filename, "w");
    fprintf(dict, "Dictionary created from: %s\n", filename);
    while((c=fgetc(fp)) != EOF) {
        for(int i = 0; i < 8; i++) {
            /*if(word_separators[i]==c) {
            	words[mempos]->id = mempos;
                words[mempos]->content = word_stack;
                words[mempos]->count += 1;
                for (int i = 0; i < 20; i++)
                {
                	word_stack[i] = ' ';
                }
                mempos++;
                word_stack_iterator = 0;
                break;
            }*/
            if (word_separators[i] == (char)c)
            {
            	fputc('\n', dict);
            	c = fgetc(fp);
            }
        }
        fputc(c, dict);
        //word_stack[word_stack_iterator] = (char) c;
    }
    free(filename);
    fclose(dict);
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
void init_struct(struct initial) {
	struct initial *words;
	words->id = 0;
	words->content = "0";
	words->count = 0;
}