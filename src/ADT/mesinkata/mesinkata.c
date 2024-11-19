#include "mesinkata.h"
#include <stdio.h>

/* State Mesin Kata */
boolean EndWord;
Word currentWord;

void printw(Word word, boolean newline)
{
    for (int i = 0; i < word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
    }
    if (newline)
        printf("\n");
}

void RESETCURRENTWORD()
// buat ngosongin current word
{
    currentWord.Length = 0;
}

void STARTWORDFILE(char *filename)
// buat baca 1 baris langsung dari file
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
void ADVWORDFILE()
// buat majuin baris di dalam file
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
void CopyWordBlanks()
// berhentinya kalo udh kena \n, masukin baris ke currword
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

void STARTLINE()
// buat baca sebaris input misal kalo ada 2 kata
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
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

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
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

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
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */