#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

FILE *menu();
void readDirectory();
FILE *readFile();

void numericalStatistics(FILE *fp);

int main() {
	FILE *fp;
	fp = menu();
	fclose(fp);
	return 0;
}


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

void numericalStatistics(FILE *fp) {
    rewind(fp);
	int *numbers;
	int mempos = 0, buffer = 50;
	numbers = (int *) calloc(buffer, sizeof(int));
	if (numbers==NULL)
	{
		printf("Memory allocation in numericalStatistics failed");
	}
	char c;
	char number[15];
	int numpos=0;
	FILE *negatives;
	negatives = fopen("negatives.txt", "w");
	while((c=fgetc(fp)) != EOF) {
		if (mempos==buffer)
		{
			buffer+=50;
			numbers = (void *) realloc(numbers, buffer*sizeof(int));
		}
		if (c>='0' && c<='9')
		{
			number[numpos] = c;
			numpos++;
			c=fgetc(fp);
			while(1) {
				if (c>='0' && c<='9')
				{
					number[numpos] = c;
					numpos++;
					c=fgetc(fp);
				} else break;
			}
			numbers[mempos] = atoi(number);
			mempos++;
			numpos=0;
			for (int i = 0; i < 15; i++)
			{
				number[i]=' ';
			}
		} else if(c=='-') {
			c=fgetc(fp);
			if (c>='0' && c<='9')
			{
				number[0] = '-';
				numpos++;
				number[numpos] = c;
				numpos++;
				c=fgetc(fp);
				while(1) {
					if (c>='0' && c<='9')
					{
						number[numpos] = c;
						numpos++;
						c=fgetc(fp);
					} else if (numpos>=15) break;
					else break;
				}
				numbers[mempos] = atoi(number);
				mempos++;
				numpos=0;
				fprintf(negatives, "%c ", '0');
				for (int i = 0; i < 15; i++)
				{
					number[i]=' ';
				}
			}
		}
	}
	fclose(negatives);
	int max = 0, min = numbers[0], sum = 0;
	for (int i = 0; i < mempos; i++)
	{
		if (max < numbers[i])
		{
			max = numbers[i];
		} else if (min > numbers[i]) {
			min = numbers[i];
		}
		if (sum>=INT_MAX) {
			printf("Sum of elements exceeds integer max value, last value: %d\n", sum);
			break;
		} else {
			sum+=numbers[i];
		}
	}
	printf("Max: %d, Min: %d\n", max, min);
	printf("Avg: %d\n", sum/mempos);
	FILE *interval;
	interval = fopen("interval.txt", "w");
	char interval_grab[16];
	int begin, end, columns;
	printf("Set interval start: ");
	scanf("%16s", &interval_grab);
	begin = atoi(interval_grab);
	printf("Set interval end: ");
	scanf("%16s", &interval_grab);
	end = atoi(interval_grab);
	printf("Set number of columns for the file: ");
	scanf("%d", &columns);
	int  step = 1;
	for (int i = 0; i < mempos; i++)
	{
		if ((numbers[i] >= begin) && (numbers[i] <=end))
		{
			sprintf(number, "%d", numbers[i]);
			if (step>=columns)
			{
				fprintf(interval, "%s\n", number);
				step = 1;
			}
			fprintf(interval, "%s ", number);
			step++;
		}
	}
	// When you see a negative write it in a file as 0
	fclose(interval);
	free(numbers);
}