#ifndef DICT_H
#define DICT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ARRLEN(x) (sizeof(x) / sizeof((x)[0]))
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
