#ifndef ROUTE_H
#define ROUTE_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct route {
	int id;
	char country[50];
	short season;
	float price;
	struct route* next;
}route;
void create_route();
void modify_route();
void fetch_routes_by_country();
void fetch_routes_by_season();
#endif