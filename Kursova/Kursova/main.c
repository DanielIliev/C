#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "route.h"

int user_choice();
void generate_menu();

int main(void) {
	route *head = NULL;
	int choice;
	repeat:
	choice = user_choice();
	do
	{
		switch (choice) {
			case 1:
				head = create_route();
				break;
			case 2:
				modify_route(head);
				break;
			case 3:
				fetch_routes_by_country(head);
				break;
			case 4:
				fetch_routes_by_season(head);
				break;
			case 5:
				exit(0);
				break;
		}
		printf("\nPress any key...");
		_getch();
		goto repeat;
	} while (1);
	return 0;
}

void generate_menu() {
	printf("\nPROGRAM ROUTES\n");
	printf("1) Create route\n");
	printf("2) Modify route\n");
	printf("3) Fetch routes by country\n");
	printf("4) Fetch routes by season\n");
	printf("5) Exit\n");
}

int user_choice() {
	char input[30];
	int choice;
	do
	{
	badInput:
		system("cls");
		generate_menu();
		printf("Select your choice:");
		scanf("%30s", input);
		if (atoi(input) == 0) {
			goto badInput;
		}
		else {
			choice = atoi(input);
		}
	} while (choice < 1 || choice > 5);
	return choice;
}