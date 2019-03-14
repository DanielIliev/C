#include "my_func.h"

void tableData(FILE *fp);
void frequency(FILE *fp);
void changeCharacter(FILE *fp);
void numericalStatistics(FILE *fp);

struct symbol {
	char symb;
	int pos;
	int count;
};

struct symbol symbols[255];

int my_func(FILE *fp) {
    tableData(fp);
	frequency(fp);
	changeCharacter(fp);
	numericalStatistics(fp);
	if (fclose(fp)==0)
	{
		printf("File closed... exiting");
	}
}

void tableData(FILE *fp) {
	char c;
	int i;
	for (i = 0; i <= 255; i++)
	{
		symbols[i].symb = (char)i;
		symbols[i].pos = i;
		symbols[i].count = 0;
	}
	while((c=fgetc(fp))!=EOF) {
		for (i = 0; i <= 255; i++)
		{
			if (symbols[i].symb==c)
			{
				symbols[i].count++;
			}
		}
	}
	printf("SYMBOL|ASCII_DEC|ASCII_HEX|COUNT\n");
	for (i = 0; i <= 255; i++)
	{
		if (symbols[i].count != 0)
		{
			printf("%c\t%d\t%x\t%d\n", symbols[i].symb, symbols[i].pos, symbols[i].pos, symbols[i].count);
		}
	}
}

void frequency(FILE *fp) {
    rewind(fp);
	char c, user_c;
	int user_count = 0, all_count = 0;
	float freq=0;
	printf("Input searched symbol:");
	scanf(" %c", &user_c);
	while((c=fgetc(fp)) != EOF) {
		if (c==user_c)
		{
			user_count++;
		}
		all_count++;
	}
	printf("%.2f%%\n", (float)user_count/all_count*100.0);
}

void changeCharacter(FILE *fp) {
    rewind(fp);
	int pos = 0, buffer = 100;
	char c, swap1, swap2;
	char *newdata;
	newdata = (char *) calloc(buffer, sizeof(char));
	if (newdata==NULL)
	{
		printf("Memory allocation in changeCharacter failed");
	}
	printf("Swap symbol:");
	scanf(" %c", &swap1);
	printf("With symbol:");
	scanf(" %c", &swap2);
	while((c=fgetc(fp)) != EOF) {
		if (pos==buffer)
		{
			buffer+=50;
			newdata = (void*) realloc(newdata, buffer*sizeof(char));
		}
		newdata[pos] = c;
		pos++;
	}
	for (int i = 0; i < pos; i++)
	{
		if (newdata[i]==swap1)
		{
			newdata[i]=swap2;
		}
	}
	FILE *fp1;
	fp1 = fopen("output.txt", "w");
	fprintf(fp1, "%s", newdata);
	fclose(fp1);
	free(newdata);
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
	int max = 0, min = numbers[0], sum = 0, begin, end, columns, step = 0;
	char interval_grab[16];
	printf("Set interval start: ");
	scanf("%16s", &interval_grab);
	begin = atoi(interval_grab);
	printf("Set interval end: ");
	scanf("%16s", &interval_grab);
	end = atoi(interval_grab);
	printf("Set number of columns for the file: ");
	scanf("%d", &columns);
	FILE *interval;
	interval = fopen("interval.txt", "w");
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
		if (numbers[i] >= begin) {
			if (numbers[i] <= end)
			{
				sprintf(number, "%d", numbers[i]);
				fprintf(interval, "%s ", number);
				step++;
				if (step>=columns)
				{
					fprintf(interval, "%s", "\n");
					step=0;
				}
			}
		}
	}
	fclose(interval);
	printf("Max: %d, Min: %d\n", max, min);
	printf("Avg: %d\n", sum/mempos+1);
	free(numbers);
}