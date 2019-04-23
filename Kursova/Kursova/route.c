#include "route.h"

route *head = NULL;
route *current = NULL;

/*int is_unique(int id) {
	int unique = -1;
	current = head;
	while (current != NULL) if (current->id == id) unique = 0;
	return unique;
}
int is_season(int season) {
	int ok = -1;
	current = head;
	while (current != NULL) if (current->season >= 1 && current->season <= 4) season = 0;
}*/
void create_route() {
	system("cls");

	current = (route*)malloc(sizeof(route));
	unique:
	printf("Route ID (e.g. 123): ");
	scanf("%d", &(current->id));
	/*if (is_unique(current->id) == -1) {
		printf("\nID already exists\n");
		goto unique;
	}*/
	printf("Route country (e.g. Bulgaria): ");
	scanf("%50s", current->country);
	season:
	printf("Route season (1-spring, 2-summer, 3-autumn, 4-winter): ");
	scanf("%d", &(current->season));
	/*if (is_season(current->season) == -1) {
		printf("\nInput is not a valid season number\n");
		goto season;
	}*/
	printf("Route price (e.g. 123.321): ");
	scanf("%f", &(current->price));
	current->next = head;
	head = current;

}
void deleteRoute(route **head_ref) {
	route *temp = *head_ref;
	if (temp != NULL) {
		*head_ref = temp->next;
		free(temp);
		return;
	}
}
void modify_route() {
	system("cls");
	route *iterator = head, *prev=NULL;
	int found = 0;
	/*char id[50];
	printf("Route ID: ");
	scanf("%s", id);*/
	int choice = 0;
	while (iterator != NULL) {
		printf("%d\n", iterator->next);
		iterator = iterator->next;
	}
	free(iterator);
	free(prev);
	
}
void fetch_routes_by_country() {
	system("cls");
	route *iterator = head;
	char country[50];
	printf("\nRoute country: ");
	scanf("%50s", country);
	while (iterator != NULL) {
		if ((strcmp(iterator->country, country)) == 0) {
			printf("\nID: %d ", iterator->id);
			printf("Country: %s ", iterator->country);
			printf("Season: %d ", iterator->season);
			printf("Price: %.2f\n", iterator->price);
		}
		iterator = iterator->next;
	}
	free(iterator);
}
void fetch_routes_by_season() {
	system("cls");
	route *iterator = head;
	while (iterator != NULL) {
		printf("\nID: %d ", iterator->id);
		printf("Country: %s ", iterator->country);
		printf("Season: %d ", iterator->season);
		printf("Price: %.2f\n", iterator->price);
		iterator = iterator->next;
	}
	free(iterator);
}