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
    // tableData(fp);
	frequency(fp);
	// changeCharacter(fp);
	// numericalStatistics(fp);
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
	/*freq= (float)(user_count/all_count*100.0);
	printf("\nSearched symbol frequency: %f%c\n", freq, '%');*/
	printf("%.2f%c\n", (user_count/all_count), '%');	
}
void changeCharacter(FILE *fp) {
    rewind(fp);
	int pos = 0;
	char c, swap1, swap2;
	char new_file_data[1000] = {};
	printf("Swap symbol:");
	scanf(" %c", &swap1);
	printf("With symbol:");
	scanf(" %c", &swap2);
	while((c=fgetc(fp)) != EOF) {
		if (c==swap1)
		{
			new_file_data[pos] = swap2;
			pos++;
		} else {
			new_file_data[pos] = c;
			pos++;
		}
	}
	FILE *fp1;
	fp1 = fopen("output.txt", "w");
	fprintf(fp1, "%s", new_file_data);
	fclose(fp1);
}
void numericalStatistics(FILE *fp) {
    rewind(fp);
	char c;
	char *p;
	char number[30];
	int numbers[100];
	int numbers_pos = 0, number_pos = 0, numbers_count = 0;
	while((c=fgetc(fp)) != EOF) {
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
					numbers[numbers_pos] = strtol(number, &p, 10); //atoi(number)
					numbers_pos++;
					numbers_count ++;
					memset(number, 0, sizeof(number));
					number_pos = 0;
					break;
				}
			}
		}
	}

	int max = 0, min = numbers[0], sum = 0;
	for (int i = 0; i < numbers_count; i++)
	{
		if (max < numbers[i])
		{
			max = numbers[i];
		} else if (min > numbers[i]) {
			min = numbers[i];
		}
		if (sum < INT_MAX)
		{
			sum+=numbers[i];
		}
	}
	printf("max: %d, min: %d\n", max, min);
	printf("Avg: %d\n", sum/numbers_count);

}
