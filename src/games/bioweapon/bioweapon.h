#ifndef BIOWEAPON_H
#define BIOWEAPON_H

#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/mesinkata/mesinkata.h"
#include "../../ADT/mesinkarakter/mesinkarakter.h"
#include "../../ADT/queue/queue.h"

int strLength(const char* str);
void copy(char* dest, const char* src);
char* DNAtoRNA(const char* dna);
char RNAtoProtein(const char* codon);
int checkCode(const char* protein_sequence, const char* secret_code);
void bioweapon();

#endif
