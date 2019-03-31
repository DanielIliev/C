#include "my_func.h"

struct symbol {
	char symb;
	int pos;
	int count;
};

struct symbol symbols[255];

void tableData(FILE *fp);
void frequency(FILE *fp);
void changeCharacter(FILE *fp);
void numericalStatistics(FILE *fp);

int my_func(FILE *fp, int choice) {
	switch (choice)
	{
	case 1:
		tableData(fp);
		break;
	case 2:
		frequency(fp);
		break;
	case 3:
		changeCharacter(fp);
		break;
	case 4:
		numericalStatistics(fp);
		break;
	default:
		break;
	}
	return 0;
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
	for (i = 0; i <= 255; i++)
	{
		printf("%c\n", symbols[i].symb);
	}
	/*while ((c = fgetc(fp)) != EOF) {
		for (i = 0; i <= 255; i++)
		{
			if (symbols[i].symb == c)
			{
				symbols[i].count++;
			}
		}
	}
	printf("|символ|ASCII_DEC|ASCII_HEX|БРОИ|\n");
	for (i = 0; i <= 255; i++)
	{
		if (symbols[i].count != 0)
		{
			printf("%c\t%d\t%x\t%d\n", symbols[i].symb, symbols[i].pos, symbols[i].pos, symbols[i].count);
		}
	}*/
}
void frequency(FILE *fp) {
	rewind(fp);
	char c, user_c;
	int user_count = 0, all_count = 0;
	float freq = 0;
	printf("Въведете търсеният символ:");
	scanf(" %c", &user_c);
	while ((c = fgetc(fp)) != EOF) {
		if (c == user_c)
		{
			user_count++;
		}
		all_count++;
	}
	printf("%.2f%%\n", (float)user_count / all_count*100.0);
}

void changeCharacter(FILE *fp) {
	rewind(fp);
	int pos = 0, buffer = 100;
	char swap1, swap2;
	int c;
	printf("Замени символът:");
	scanf(" %c", &swap1);
	printf("Със:");
	scanf(" %c", &swap2);
	FILE *fp1;
	fp1 = fopen("output.txt", "w");
	while ((c = fgetc(fp)) != EOF) {
		if (c==swap1)
		{
			fputc((int)swap1, fp1);
		}
		else {
			fputc(c, fp1);
		}
	}
	fclose(fp1);
}

void numericalStatistics(FILE *fp) {
	rewind(fp);
	int *numbers;
	int mempos = 0, buffer = 50;
	numbers = (int *)calloc(buffer, sizeof(int));
	if (numbers == NULL)
	{
		printf("Грешка при заделянето на памет");
	}
	char c;
	char number[15];
	int numpos = 0;
	FILE *negatives;
	negatives = fopen("negatives.txt", "w");
	while ((c = fgetc(fp)) != EOF) {
		if (mempos == buffer)
		{
			buffer += 50;
			numbers = (void *)realloc(numbers, buffer*sizeof(int));
		}
		if (c >= '0' && c <= '9')
		{
			number[numpos] = c;
			numpos++;
			c = fgetc(fp);
			while (1) {
				if (c >= '0' && c <= '9')
				{
					number[numpos] = c;
					numpos++;
					c = fgetc(fp);
				}
				else break;
			}
			numbers[mempos] = atoi(number);
			mempos++;
			numpos = 0;
			for (int i = 0; i < 15; i++)
			{
				number[i] = ' ';
			}
		}
		else if (c == '-') {
			c = fgetc(fp);
			if (c >= '0' && c <= '9')
			{
				number[0] = '-';
				numpos++;
				number[numpos] = c;
				numpos++;
				c = fgetc(fp);
				while (1) {
					if (c >= '0' && c <= '9')
					{
						number[numpos] = c;
						numpos++;
						c = fgetc(fp);
					}
					else if (numpos >= 15) break;
					else break;
				}
				numbers[mempos] = atoi(number);
				mempos++;
				numpos = 0;
				fprintf(negatives, "%c ", '0');
				for (int i = 0; i < 15; i++)
				{
					number[i] = ' ';
				}
			}
		}
	}
	fclose(negatives);
	int max = 0, min = numbers[0], sum = 0, begin, end, columns, step = 0;
	char interval_grab[16];
	printf("Начало на интервал: ");
	scanf("%16s", &interval_grab);
	begin = atoi(interval_grab);
	printf("Край на интервал: ");
	scanf("%16s", &interval_grab);
	end = atoi(interval_grab);
	printf("Бройка колони за файлът: ");
	scanf("%d", &columns);
	FILE *interval;
	interval = fopen("interval.txt", "w");
	for (int i = 0; i < mempos; i++)
	{
		if (max < numbers[i])
		{
			max = numbers[i];
		}
		else if (min > numbers[i]) {
			min = numbers[i];
		}
		if (sum >= INT_MAX) {
			printf("Сумата на числата надхвърля възможният размер, последно зачислена сума= %d\n", sum);
			break;
		}
		else {
			sum += numbers[i];
		}
		if (numbers[i] >= begin) {
			if (numbers[i] <= end)
			{
				sprintf(number, "%d", numbers[i]);
				fprintf(interval, "%s ", number);
				step++;
				if (step >= columns)
				{
					fprintf(interval, "%s", "\n");
					step = 0;
				}
			}
		}
	}
	fclose(interval);
	if (mempos!=0)
	{
		printf("Максимум: %d, Минимум: %d\n", max, min);
		printf("Средно аритметично: %d\n", sum / mempos + 1);
	}
	free(numbers);
}