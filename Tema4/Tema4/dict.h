#ifndef DICT_H
#define DICT_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ARRLEN(x) (sizeof(x) / sizeof((x)[0]))
typedef struct dict {
	int id;
	char content[25];
	int count;
	struct dict *next;

}dict;
dict *head = NULL;
dict *current = NULL;
void generateMenu();
FILE *selectFile();
int userChoice();
void createDictionary(FILE *fp);
void printDictionary();
void wordSearch();
void sortDictionary();
void exportDictionary();
void importDictionary();
void encodeDictionary();
void decodeDictionary();
#endif // DICT_H
