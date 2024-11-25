#ifndef QUANTUM_W0RDL3_H
#define QUANTUM_W0RDL3_H


#define QUANTUM_MAX_TRIES 9
#define QUANTUM_WORD_LENGTH 5
#define QUANTUM_MAX_WORDS 10
#define QUANTUM_TARGET_WORDS 4  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "mesinkarakter.h"
//#include "mesinkata.h"
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/arrayuser/arrayuser.h"

extern const char wordBank[QUANTUM_MAX_WORDS][QUANTUM_WORD_LENGTH + 1];


char upper2(char c);
boolean compare2(const char* str1, const char* str2, int length);
boolean checkArray(const char* word, const char* word_array[], int array_size);
void copy2(char* dest, const char* src, int length);
void checkGuess2(const char* target, const char* guess, char* result);
boolean read2(char* buffer);
int QUANTUMW0RDL3(ListofUsers *userlist, int *currentUserIndex);

#endif