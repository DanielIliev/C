#include <stdio.h>
#include <stdlib.h>

struct word {
	int position; // Position in the dictionary
	char content[30]; // The word
	int count; // Frequency in the file
};

int main() {
	FILE *fp;
	char user_file[255];
	int opened = 0, buffer = 50;
	struct word *words;
	words = (void*) malloc(buffer * sizeof(words));
	printf("%d", sizeof(words));
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

void readData(FILE *fp) {
    char c;
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
}