#ifndef DICT_H
#define DICT_H
#include <stdio.h>
#define ARRLEN(x) (sizeof(x) / sizeof((x)[0]))
FILE* selectFile();
void generateMenu();
int userChoice();
void createDictionary(FILE *fp);
void printDictionary();
void wordSearch();
void sortDictionary();
void exportDictionary();
void importDictionary();
void encodeDictionary();
void decodeDictionary();
FILE *checkFile(const char* filename, const char* mode);
#endif // DICT_H
