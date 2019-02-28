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
	//numericalStatistics(fp);
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
	freq= (float)user_count/all_count*100.0;
	printf("\nSearched symbol frequency: %f%c\n", freq, '%');
}
void changeCharacter(FILE *fp) {
    rewind(fp);
	int pos = 0;
	char c, swap1, swap2;
	char new_file_data[BUFFER] = {};
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
	char numbers[BUFFER];
	int num_arr_pos = 0;
	while((c=fgetc(fp)) != EOF) {
		if (c>='0' && c<='9')
		{
			numbers[num_arr_pos] = c;
			num_arr_pos++;
			while(1) {
				c=fgetc(fp);
				if (c>='0' && c<='9')
				{
					numbers[num_arr_pos] = c;
					num_arr_pos++;
				} else {
					numbers[num_arr_pos] = ' ';
					num_arr_pos++;
					break;
				}
			}
		}
	}

}