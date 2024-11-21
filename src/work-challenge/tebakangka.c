#include "tebakAngka.h"

int tebakAngka() {
    srand(time(NULL));
    int r = rand() % 101; 
    int masukan;
    int duit = 500;
    int i = 0;

    printf("Uji keberuntungan Anda dengan menebak angka!\n");
    //printf("Cheat: %d\n", r);
    printf("Tebakan angka: ");

    STARTLINE();  
    masukan = wordtoint(currentWord);  

    while (masukan != r && i < 9) {
        if (masukan < r) {
            printf("Lebih besar\n");
        } else if (masukan > r) {
            printf("Lebih kecil\n");
        }
        i++;
        printf("Tebakan: ");
        
        STARTLINE();  // Membaca input baris berikutnya
        masukan = wordtoint(currentWord);
        duit = duit - 50;
    }

    if (duit > 0 && masukan == r) {
        printf("Tebakanmu benar! +");
        printf("%d rupiah telah ditambahkan ke akun anda.\n", duit);
    } else {
        duit = 0;
        printf("Anda tidak beruntung wkwkw. +");
        printf("%d rupiah telah ditambahkan ke akun anda.\n", duit);
    }
    return duit;
}


