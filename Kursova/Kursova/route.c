#include "route.h"

route *create_route() {
	system("cls");
	int initial_size = 3;
	route *head = NULL;
	route *current = NULL;
	route *iterator = NULL;

	for (int i = 0; i < initial_size; i++) {
		printf("ROUTE %d\n", i + 1);
		current = (route*)malloc(sizeof(route));
		printf("Please enter unique route id: ");
		scanf("%d", &(current->id));
		printf("Please enter country name: ");
		scanf("%s", &current->country);
		printf("Please enter a season(1-spring, 2-summer, 3-autumn, 4-winter): ");
		scanf("%d", &(current->season));
		printf("Please enter the price (e.g 10.00): ");
		scanf("%f", &(current->price));
		current->next = NULL;

		if (head == NULL) {
			head = current;
		}
		else {
			//while (iterator->next != NULL) iterator = iterator->next;
			current->next = current;
		}
	}
	return head;
}
void modify_route(route *head) {
	route *current = head;
	if (current == NULL) {
		printf("There are no routes created");
	}
	else {

	}
}
void fetch_routes_by_country(route *head) {
	system("cls");
	route *current = head;
	if (current == NULL) {
		printf("There are no routes created");
	}
	else if (current->next == NULL) {
		printf("ROUTE 1\n");
		printf("Route ID: %d ", current->id);
		printf("Route Country: %d ", current->country);
		printf("Route Season: %d ", current->season);
		printf("Route Price: %.2f", current->price);
	}
	else {
		while (current->next != NULL) {
			printf("\nROUTE %d:\n");
			printf("Route ID: %d ", current->id);
			printf("Route Country: %d ", current->country);
			printf("Route Season: %d ", current->season);
			printf("Route Price: %.2f", current->price);
			current = current->next;
		}
	}
}
void fetch_routes_by_season(route *head) {
	route *current = head;
	if (current == NULL) {
		printf("There are no routes created");
	}
	else {

	}
}