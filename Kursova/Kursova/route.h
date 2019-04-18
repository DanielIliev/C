#ifndef ROUTE_H
#define ROUTE_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct route {
	int id;
	char country[50];
	short season;
	float price;
	struct route* next;
}route;
route *create_route();
void modify_route(route *head);
void fetch_routes_by_country(route *head);
void fetch_routes_by_season(route *head);
#endif