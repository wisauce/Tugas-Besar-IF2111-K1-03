#include <stdio.h>
#include "set.h"
#include "../mesinkata/mesinkata.h"
#include "../mesinkarakter/mesinkarakter.h"


Word CreateWord(char *str) {
    Word newWord;
    int i = 0;

    while (str[i] != '\0' && i < MaxElSet - 1) { 
        newWord.TabWord[i] = str[i];
        i++;
    }
    newWord.TabWord[i] = '\0'; 
    newWord.Length = i;

    return newWord;
}


int main() {
    Set keranjang;
    infotypeSet word1, word2, word3;

    CreateEmptySet(&keranjang);

    word1 = CreateWord("AK47");
    word2 = CreateWord("Pisang");
    word3 = CreateWord("Mobil");

    InsertSetElmt(&keranjang, word1);
    InsertSetElmt(&keranjang, word2);
    InsertSetElmt(&keranjang, word3);

    printf("Isi Keranjang setelah penambahan elemen:\n");
    for (int i = 0; i < keranjang.Count; i++) {
        printw(keranjang.Elements[i],true);
    }

    return 0;
}
