#ifndef W0RDL3_H
#define W0RDL3_H

#define W0RDL3_MAX_TRIES 6
#define W0RDL3_WORD_LENGTH 5
#define W0RDL3_MAX_WORDS 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/arrayuser/arrayuser.h"

extern const char wordBank[W0RDL3_MAX_WORDS][W0RDL3_WORD_LENGTH + 1];

char upper(char c);
boolean compare(const char* str1, const char* str2, int length);
void wordl3_copy(char* dest, const char* src, int length);
int length2(const char* str);
void checkGuess(const char* target, const char* guess, char* result);
void read(char* buffer);
int w0rdl3(ListofUsers *userlist, int *currentUserIndex);

#endif
