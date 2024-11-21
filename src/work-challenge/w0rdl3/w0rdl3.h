#ifndef W0RDL3_H
#define W0RDL3_H

#define MAX_TRIES 5
#define WORD_LENGTH 5
#define MAX_WORDS 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"

extern const char wordBank[MAX_WORDS][WORD_LENGTH + 1];

char upper(char c);
boolean compare(const char* str1, const char* str2, int length);
void copy(char* dest, const char* src, int length);
int length(const char* str);
void checkGuess(const char* target, const char* guess, char* result);
void read(char* buffer);
int w0rdl3();

#endif
