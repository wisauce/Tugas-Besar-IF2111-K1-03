#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"
#include "../boolean.h"

boolean EOP;
char currentChar;
static FILE *pita = NULL;
static int retval;

void RESETPITA() // supaya kata yang udah dipanggil ga kecetak lagi
{
    if (pita != NULL)
    {
        rewind(pita);
    }
}

void START()
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */
{
    RESETPITA();
    pita = stdin;

    EOP = false;
    ADV();
}

void STARTFILE(char *filename, boolean *success)
{
    static char path[200] = "saves/"; // Mengacu folder `saves` di dalam direktori kerja
    int idx = 0;
    int newIdx = 6; // Panjang string "saves/"

    // Gabungkan `filename` ke dalam `path`
    while (filename[idx] != '\0')
    {
        path[newIdx] = filename[idx];
        newIdx++;
        idx++;
    }
    path[newIdx] = '\0'; // Tambahkan null terminator di akhir string

    // printf("DEBUG: Full file path = %s\n", path);  Debugging path file

    // Buka file
    pita = fopen(path, "r");
    if (pita == NULL)
    {
        // printf("ERROR: File not found at path: %s\n", path);
        *success = false;
    }
    else
    {
        // printf("SUCCESS: File opened at path: %s\n", path);
        *success = true;
        ADV(); // Baca karakter pertama
    }
}

void WRITEFILE(char *filename, boolean *success) {
    static char path[200] = "saves/";
    int idx = 0;
    int newIdx = 6;

    while (filename[idx] != '\0') {
        path[newIdx] = filename[idx];
        newIdx++;
        idx++;
    }
    path[newIdx] = '\0';

    // Debugging path
    // printf("DEBUG: Path file untuk menulis = %s\n", path);

    pita = fopen(path, "w");
    if (pita == NULL) {
        *success = false;
        printf("ERROR: Gagal membuka file untuk menulis: %s\n", path);
    } else {
        *success = true;
    }
}

void ADV()
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */
{
    retval = fscanf(pita, "%c", &currentChar);
    if (currentChar == MARK)
        EOP = true;
    else
        EOP = false;
}

char GetCC()
/* Mengirimkan currentChar */
{
    return currentChar;
}

boolean IsEOP()
/* Mengirimkan true jika currentChar = MARK */
{
    return currentChar == MARK;
}

void printChar(char c) {
    fprintf(pita,"%c",c);
}

void printInt(int n) {
    fprintf(pita,"%d",n);
}

void printNewLine() {
    fprintf(pita,"\n");
}

void printBlank() {
    fprintf(pita," ");
}
