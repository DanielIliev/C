#include "menu.h"
#include "my_func.h"

int menu() {
	FILE *fp = NULL;
	char filename[255];
	scanf("%251s", filename);
	fp = fopen(strcat(filename, ".txt"), "r");
	if (fp!=NULL)
	{
		printf("\n������� ��������\n");
		int choice = 0;
		while (choice != 5) {
			printf("\n1:������ ������� ��� ����������� ������� ��� �����\n");
			printf("2: ������� �� ������ ��� �����\n");
			printf("3: ������ �� ������\n");
			printf("4: ������� ����������\n");
			printf("5: �����\n");
			printf("������ ����� �: ");
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
		printf("\n������, ���������� �� �������\n");
	}
	fclose(fp);
	/*
	if (fp!=NULL)
	{
		printf("������ � ����� �� ���������\n");
		
	}
	else {
		printf("������, ���������� �� ����������");
	}
	fclose(fp);*/
	return 0;
}