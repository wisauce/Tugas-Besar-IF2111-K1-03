#ifndef W0RDL3_H
#define W0RDL3_H


#define MAX_TRIES 9
#define WORD_LENGTH 5
#define MAX_WORDS 10
#define TARGET_WORDS 4  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "mesinkarakter.h"
//#include "mesinkata.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"

extern const char wordBank[MAX_WORDS][WORD_LENGTH + 1];


char upper(char c);
boolean compare(const char* str1, const char* str2, int length);
boolean checkArray(const char* word, const char* word_array[], int array_size);
void copy(char* dest, const char* src, int length);
void checkGuess(const char* target, const char* guess, char* result);
boolean read(char* buffer);
int quantum();

#endif
