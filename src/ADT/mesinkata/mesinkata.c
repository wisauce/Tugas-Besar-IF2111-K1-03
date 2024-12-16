#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>

/* State Mesin Kata */
boolean EndWord;
Word currentWord;

/* Mengembalikan nilai integer dari Word W */
int wordtoint(Word word)
{
    int res = 0;
    for (int i = 0; i < word.Length; i++)
    {
        res = res * 10 + (word.TabWord[i] - '0');
    }
    return res;
}

void printw(Word word, boolean newline)
{
    for (int i = 0; i < word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
    }
    if (newline)
        printf("\n");
}

/** Mengembalikan panjang currentWord menjadi 0 */
void RESETCURRENTWORD()
{
    currentWord.Length = 0;
}

/**
 * Mulai membaca dari file di dalam "saves/<filename>"
 * currentWord adalah baris pertama dari file. Pembacaan selanjutnya dilakukan dengan ADVWORDFILE()
 * I.S. : currentWord sembarang
 * F.S. : currentWord adalah baris pertama dalam file dan EndWord = false jika belum sampai akhir file
 *
 */
void STARTWORDFILE(char *filename)
{
    boolean success;
    RESETCURRENTWORD();
    STARTFILE(filename, &success);
    if (success)
    {
        if (currentChar == MARK)
            EndWord = true;
        else
        {
            EndWord = false;
            CopyWordBlanks();
        }
    }
}

/**
 * Membaca baris selanjutnya dalam file
 * currentWord adalah baris selanjutnya dari file. Pembacaan selanjutnya dilakukan dengan ADVWORDFILE()
 * I.S. : currentWord sembarang
 * F.S. : currentWord adalah baris selanjutnya dalam file dan EndWord = false jika belum sampai akhir file
 *
 *
 * Cara penggunaan:
 *
 * STARTWORDFILE("save1.txt"); # Membaca baris pertama dari "save1.txt"
 * ADVWORDFILE();              # Membaca baris kedua dari "save1.txt"
 *
 */
void ADVWORDFILE()
{
    ADV();
    RESETCURRENTWORD(); // biar currwrd ga ketimpa
    EndWord = false;
    if (currentChar == MARK)
        EndWord = true;
    else
    {
        EndWord = false;
        CopyWordBlanks();
    }
}

/* Mengakuisisi kata, menyimpan dalam currentWord
 * I.S. : currentChar adalah karakter pertama dari kata
 * F.S. : currentWord berisi kata yang sudah diakuisisi;
 *        currentChar = MARK;
 *        currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
 *        Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void CopyWordBlanks()
{
    int len = 0;
    while (!EOP)
    {
        if (len < MESINKAT_NMAX)
        {
            currentWord.TabWord[len] = currentChar;
            len++;
        }
        ADV();
    }
    currentWord.Length = len;
}

/**
 * Membaca 1 baris dari masukan pengguna (termasuk spasi / BLANK)
 * I.S. : currentChar sembarang
 * F.S. : EndWord = true, dan currentChar = MARK;
 *        atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
 *        currentChar karakter pertama sesudah karakter terakhir kata */
void STARTLINE()
{
    RESETCURRENTWORD();
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
        EndWord = true;
    else
    {
        EndWord = false;
        CopyWordBlanks();
    }
}

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
        ADV();
}

/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
void STARTWORD()
{
    RESETCURRENTWORD();
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
        EndWord = true;
    else
    {
        EndWord = false;
        CopyWord();
    }
}

/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
void ADVWORD()
{
    RESETCURRENTWORD();
    if (EOP)
        EndWord = true;
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void CopyWord()
{
    int len = 0;
    while (!EOP && (currentChar != BLANK))
    {
        if (len < MESINKAT_NMAX)
        {
            currentWord.TabWord[len] = currentChar;
            len++;
        }
        ADV();
    }
    currentWord.Length = len;
}

void scan(char *str, Word *w1, Word *w2, int *x, int *y)
{
    boolean first = false;

    (*w1).Length = 0;
    (*w2).Length = 0;

    while (*str != '\0')
    {
        if (*str == '%')
        {
            str++;
            if (*str == 'c')
            {
                if (!first)
                {
                    STARTWORD();
                    (*w1) = currentWord;
                    first = true;
                }
                else
                {
                    ADVWORD();
                    (*w2) = currentWord;
                }
            }

            else if (*str == 's')
            {
                STARTLINE();
                (*w1) = currentWord;
            }

            if (*str == 'd')
            {
                if (!first)
                {
                    STARTWORD();
                    (*x) = wordtoint(currentWord);
                    first = true;
                }
                else
                {
                    ADVWORD();
                    (*y) = wordtoint(currentWord);
                }
            }
        }
        else
            str++;
    }
    RESETPITA();
}

char *wordToString(Word kata)
{
    char *str = (char *)malloc(MESINKAT_NMAX * sizeof(char));
    for (int i = 0; i < kata.Length; i++)
    {
        str[i] = kata.TabWord[i];
    }
    str[kata.Length] = '\0';
    return str;
}

boolean isStringSame(char *kata1, char *kata2)
{
    boolean same = true;
    int lengthkata1 = stringLength(kata1);
    int lengthkata2 = stringLength(kata2);
    int i = 0;

    if (lengthkata1 != lengthkata2)
    {
        same = false;
    }
    else
    {
        while (same && i != lengthkata1)
        {
            if (kata1[i] != kata2[i])
                same = false;
            i++;
        }
    }
    return same;
}

int stringLength(char *kata)
{
    int length = 0;

    while (kata[length] != '\0')
    {
        length++;
    }
    return length;
}

void stringCopy(char *kataOut, char *kataIn)
{
    int i = 0;
    while (kataIn[i] != '\0')
    {
        kataOut[i] = kataIn[i];
        i++;
    }
    kataOut[i] = '\0';
}