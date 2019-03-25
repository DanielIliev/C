#include <stdio.h>
#include <stdlib.h>

struct word {
	int position; // Position in the dictionary
	char content[30]; // The word
	int count; // Frequency in the file
};

/*int buffer = 50;
void generateDictionary();

void generateDictionary() {
	struct word *words;
	words = (word *words) malloc(words, buffer*sizeof(struct word));
}*/

int main() {
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
	char c;
	while((c=fgetc(fp)) != EOF) {
		printf("%c", c);
	}
	if (fclose(fp) == 0)
	{
		printf("File closed... exiting");
	}
	return 0;
}