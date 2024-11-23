#ifndef BIOWEAPON_H
#define BIOWEAPON_H

#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "queue.h"

int strLength(const char* str);
void copy(char* dest, const char* src);
char* DNAtoRNA(const char* dna);
char RNAtoProtein(const char* codon);
int checkCode(const char* protein_sequence, const char* secret_code);
void bioweapon();

#endif
