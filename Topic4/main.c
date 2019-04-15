#include "dict.h"

int main()
{
    /*word *words;
	words = (word*) malloc (50*sizeof(word));
	words[0].id = 0;
	strcpy(words[0].content,"Tosho");
	words[0].count = 1;
	printf("%d %s %d", words[0].id, words[0].content, words[0].count);*/
    FILE* fp = NULL;
	int choice;
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
			    printf("Closing program...");
				exit(0);
			break;
			default:
				exit(0);
		}
		printf("\nPress any key to continue...");
		getch();
		goto repeat;
	} while (1);
	return 0;
}
