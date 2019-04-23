#include "dict.h"

int main()
{
	FILE* fp = NULL;
	int choice;
repeat:
	choice = userChoice();
	do
	{
		switch (choice) {
		case 1:
			fp = selectFile();
			break;
		case 2:
			if (fp == NULL)
			{
				printf("Please select a file first!");
			}
			else {
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
