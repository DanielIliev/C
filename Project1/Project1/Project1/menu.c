#include "menu.h"
#include "my_func.h"

int menu() {
	FILE *fp = NULL;
	char filename[255];
	scanf("%251s", filename);
	fp = fopen(strcat(filename, ".txt"), "r");
	if (fp!=NULL)
	{
		printf("\nНалични операции\n");
		int choice = 0;
		while (choice != 5) {
			printf("\n1:Изведи таблица със съдържаните символи във файла\n");
			printf("2: Честота на символ във файла\n");
			printf("3: Замяна на символ\n");
			printf("4: Числови статистики\n");
			printf("5: Изход\n");
			printf("Вашият избор е: ");
			scanf("%d", &choice);
			switch (choice) {
			case 1:
				my_func(fp, choice);
				break;
			case 2:
				my_func(fp, choice);
				break;
			case 3:
				my_func(fp, choice);
				break;
			case 4:
				my_func(fp, choice);
				break;
			case 5:
				break;
			}
		}
	}
	else {
		printf("\nГрешка, програмата се затваря\n");
	}
	fclose(fp);
	/*
	if (fp!=NULL)
	{
		printf("Файлът е готов за обработка\n");
		
	}
	else {
		printf("Грешка, програмата се прекратява");
	}
	fclose(fp);*/
	return 0;
}