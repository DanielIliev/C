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
    /*tableData(fp);
	frequency(fp);
	changeCharacter(fp);*/
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
	printf("%.2f%%", (float)user_count/all_count*100.0);
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
	char c;
	char number[15];
	int *numbers;
	int numbers_pos = 0, number_pos = 0, buffer = 10;
	numbers = (int *) calloc(buffer, sizeof(int));
	if (numbers==NULL)
	{
		printf("Memory allocation in numericalStatistics failed");
	}
	while((c=fgetc(fp)) != EOF) {
		if (numbers_pos==buffer)
		{
			buffer+=50;
			numbers = (void *) realloc(numbers, buffer*sizeof(int));
		}
		if (c>='0' && c<='9')
		{
			number[number_pos] = c;
			number_pos++;
			while(1) {
				c=fgetc(fp);
				if (c>='0' && c<='9')
				{
					number[number_pos] = c;
					number_pos++;
				} else {
<<<<<<< HEAD
					numbers[numbers_pos] = atoi(number);
=======
					numbers[numbers_pos] = strtol(number, &p, 10); //atoi(number)
>>>>>>> fcdab287e8fe29ac2f66af060003b82ae3c857d7
					numbers_pos++;
					number_pos = 0;
					break;
				}
			}
		}
	}
/*
	int max = 0, min = numbers[0], sum = 0, begin = 0, end = 0;
	printf("Set interval start: ");
	scanf("%15d", begin);
	printf("Set interval end: ");
	scanf("%15d", end);
	printf("%d %d", begin, end);
	FILE *interval;
	interval = fopen("interval.txt", "w");
	for (int i = 0; i < numbers_pos; i++)
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
	printf("max: %d, min: %d\n", max, min);
<<<<<<< HEAD
	printf("Avg: %d\n", sum/numbers_pos);
	free(numbers);
	fclose(interval);*/
	free(numbers);
}
=======
	printf("Avg: %d\n", sum/numbers_count);

}
>>>>>>> fcdab287e8fe29ac2f66af060003b82ae3c857d7
