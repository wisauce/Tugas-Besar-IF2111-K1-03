#include "../../console.h"
#include "../../art/art.h"
#include "tebakangka.h"

int tebakAngka(ListofUsers *userlist, int *currentUserIndex) {
    clearterminal();
    artTebak();
    srand(time(NULL));
    int r = rand() % 101; 
    int masukan;
    int duit = 500;
    int i = 0;
    User *currentUser = &userlist->TI[*currentUserIndex];
    if (currentUser->money < 200) 
    {
        printf("Saldo Anda tidak cukup untuk bermain Tebak Angka.\n");
        return 0;
    }

    printf("SELAMAT DATANG DI TEBAK ANGKA!\n\nBIAYA BERMAIN SEBESAR 200 TELAH DIKURANGI DARI SALDO ANDA! SEMOGA ANDA MENANG!\n\n");
    currentUser->money -= 200;
    printf("Uji keberuntungan Anda dengan menebak angka!\n");
    printf("Cheat: %d\n", r);
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
        
        STARTLINE();  
        masukan = wordtoint(currentWord);
        duit = duit - 50;
    }


    if (duit > 0 && masukan == r) {
        printf("Tebakanmu benar! +");
        currentUser->money += duit;
        printf("%d rupiah telah ditambahkan ke akun anda.\n", duit);
    } else {
        duit = 0;
        printf("Anda tidak beruntung wkwkw. +");
        printf("%d rupiah telah ditambahkan ke akun anda.\n", duit);
    }
    return duit;
}

// int main() {
//     int hasil = tebakAngka();
//     printf("Skor akhir: %d\n", hasil);
//     return 0;
// }
