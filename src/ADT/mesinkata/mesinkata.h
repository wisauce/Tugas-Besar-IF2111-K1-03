/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "../mesinkarakter/mesinkarakter.h"

#define MESINKAT_NMAX 150
#define BLANK ' '

typedef struct
{
   char TabWord[MESINKAT_NMAX]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

int wordtoint(Word word);

void printw(Word word, boolean newline);

void RESETCURRENTWORD();
// buat ngosongin current word

void STARTWORDFILE(char *filename);
// buat baca 1 baris langsung dari file

void ADVWORDFILE();
// buat majuin baris di dalam file

void CopyWordBlanks();
// berhentinya kalo udh kena \n, masukin baris ke currword

void STARTLINE();
// buat baca sebaris input misal kalo ada 2 kata

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void scan(char *str, Word *w1, Word *w2, int *x, int *y);
/* Implementasi dari scanf pada library stdio.h, hanya dapat menerima 3 buah tipe input, 2 Kata dan 1 int, dan setiap
   pemanggilan harus menyertakan pointer ke semua elemen walaupun elemen tersebut tidak ingin di-inputkan.
 * %c untuk Command 1 kata; %s untuk 1 buah string dengan spasi (banyak kata); %d untuk integer
 * I.S. : W1, W2, dan x sembarang, str berupa elemen tipe aja yang akan diinputkan
 * F.S. : Setidaknya salah satu dari W1, W2, atau x berisikan dengan input user

CONTOH PEMANGGILAN
 * 1. scan("%c", &W1, &W2, &x, &y)
        Akan menerima 1 buah command dan hanya ditaruh di W1, W2 dan x sembarang
        contoh: WORKS, terima,
 * 2. scan("%c %d", &W1, &W2, &x, &y)
        Akan menerima 1 buah command dan 1 buah int, command akan ditaruh di
        W1 dan integer akan ditaruh di x, W2 sembarang
        contoh: ga ada sih jaga2 aja
 * 3. scan("%s",  &W1, &W2, &x, &y)
        Akan menerima 1 buah line input yang akan ditaruh di W1, W2 dan x sembarang
        contoh: kalo mau masukin nama barang yg mau dihapus -> ayam geprek
 * 4. scan("%d",  &W1, &W2, &x, &y)
        Akan menerima 1 buah integer yang akan ditaruh di x, W1 dan W2 sembarang
        contoh: buat store supply masukin integer
 * 5. scan("", &W1, &W2, &x, &y)
        W1, W2, dan x sembarang, ngapain panggil gituan gak guna :)
*/

char *wordToString(Word kata);

boolean isStringSame(char *kata1, char *kata2);

int stringLength(char *kata);

#endif