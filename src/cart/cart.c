#include <stdio.h>
#include "cart.h"
#include "../ADT/setkeranjang/set.h"
#include "../ADT/boolean.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../console.h"
#include "../ADT/arrayitems/arrayitems.h"
#include "../ADT/stack/stack.h"

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

void trimString(char *str) {
    int start = 0;
    int end = 0;
    while (str[start] == ' ') {
        start++;
    }

    while (str[start] != '\0') {
        str[end++] = str[start++];
    }

    while (end > 0 && str[end - 1] == ' ') {
        end--;
    }

    str[end] = '\0';
}


boolean isStringSameIgnoreCase(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        char c1 = (*str1 >= 'A' && *str1 <= 'Z') ? *str1 + 32 : *str1;
        char c2 = (*str2 >= 'A' && *str2 <= 'Z') ? *str2 + 32 : *str2;

        if (c1 != c2) {
            return false;
        }
        str1++;
        str2++;
    }
    return *str1 == '\0' && *str2 == '\0';
}
boolean isItemInStore(ListofItems itemlist, const char *itemName) {
    for (int i = 0; i < itemlist.Neff; i++) {
        if (isStringSameIgnoreCase(itemlist.A[i].name, itemName)) {
            return true;
        }
    }
    return false;
}

void PrintItemList(ListofItems itemlist) {
    if (itemlist.Neff == 0) {
        printf("Itemlist kosong!\n");
        return;
    }

    printf("\nIsi itemlist:\n");
    printf("==============================\n");
    for (int i = 0; i < itemlist.Neff; i++) {
        printf("%d. Nama: %s, Harga: %d\n", i + 1, itemlist.A[i].name, itemlist.A[i].price);
    }
    printf("==============================\n");
}

void CopyString(char *dest, const char *src, int maxLen) {
    int i = 0;
    while (src[i] != '\0' && i < maxLen - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Pastikan string hasil copy null-terminated
}

void AddCart(Set *S, infotypeSet Elmt, int quantity) {
    if (IsMemberSet(*S, Elmt)) {
        // Jika elemen sudah ada, tambahkan jumlah
        for (int i = 0; i < S->Count; i++) {
            if (isStringSame(S->Elements[i].TabWord, Elmt.TabWord)) {
                S->Elements[i].Length += quantity;
                return;
            }
        }
    } else if (!IsFullSet(*S)) {
        // Jika elemen belum ada dan set belum penuh, tambahkan elemen
        InsertSetElmt(S, Elmt);
        S->Elements[S->Count - 1].Length = quantity;
    } else {
        printf("Keranjang sudah penuh! Tidak dapat menambahkan barang baru.\n");
    }
}

void ShowCart(Set *keranjang, ListofItems *itemlist) {
    if (IsEmptySet(*keranjang)) 
    {
        printf("\nKeranjang kamu kosong!\n");
        return;
    }

    printf("\nIsi keranjang belanja :\n\n");
    printf("=============================================\n");
    printf("%-10s %-20s %-10s\n", "Kuantitas", "Nama Barang", "Total Harga");
    printf("=============================================\n");

    int totalBiaya = 0;

    for (int i = 0; i < keranjang->Count; i++) {
        int harga = 0;

        for (int j = 0; j < itemlist->Neff; j++) {
            if (isStringSameIgnoreCase(itemlist->A[j].name, keranjang->Elements[i].TabWord)) {
                harga = itemlist->A[j].price;
                break;
            }
        }

        int itemTotal = harga * keranjang->Elements[i].Length;
        totalBiaya += itemTotal;

        printf("%-10d %-20s %-10d\n",
               keranjang->Elements[i].Length,
               keranjang->Elements[i].TabWord,
               itemTotal);
    }

    printf("=============================================\n");
    printf("%-31s %-10d\n", "TOTAL BIAYA", totalBiaya);
    printf("=============================================\n\n");
}

void RemoveCart(Set *S, infotypeSet Elmt, int quantity) {
    if (IsMemberSet(*S, Elmt)) {
        for (int i = 0; i < S->Count; i++) {
            if (isStringSame(S->Elements[i].TabWord, Elmt.TabWord)) {
                if (S->Elements[i].Length > quantity) {
                    S->Elements[i].Length -= quantity;
                } else {
                    DeleteSetElmt(S, Elmt);
                }
                return;
            }
        }
    } else {
        printf("Barang tidak ditemukan di keranjang!\n");
    }
}

// Fungsi custom strcspn untuk mencari panjang segmen awal yang tidak mengandung karakter tertentu
size_t strcspn(const char *str1, const char *str2) {
    size_t i = 0;

    // Loop melalui setiap karakter di str1
    while (str1[i] != '\0') {
        // Periksa apakah karakter saat ini ada di str2
        for (size_t j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                return i;  // Mengembalikan posisi karakter pertama yang cocok
            }
        }
        i++;
    }

    return i;  // Mengembalikan panjang penuh jika tidak ada karakter yang cocok
}