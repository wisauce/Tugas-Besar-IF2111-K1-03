#include "wishlist.h"
#include <stdio.h>
#include "../ADT/mesinkata/mesinkata.h"

int StringCompareS(const char *str1, const char *str2)
{
    // Iterasi melalui kedua string
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
        {
            // Jika karakter tidak cocok, kembalikan perbedaan NilLLai ASCII
            return (unsigned char)*str1 - (unsigned char)*str2;
        }
        str1++;
        str2++;
    }

    // Jika salah satu string berakhir, kembalikan perbedaan panjang
    return *str1 - *str2;
}

int main() {
    Word W1, W2;
    int x, y;

    // Wishlist dibuat make data random aja dulu awalnya
    List wishlist;
    CreateEmptyLL(&wishlist);
    InsVLast(&wishlist, "Ayam Goreng Besthal");
    InsVLast(&wishlist, "Kegeprek");
    InsVLast(&wishlist, "AGR");
    InsVLast(&wishlist, "Lalabu");

    // PrintInfoLL(wishlist); printf("\n");

    while (true) {
        printf("Current wishlist: "); PrintInfoLL(wishlist); printf("\n");
        printf("\nMASUKKAN COMMAND: ");
        scan("%c %c %d %d", &W1, &W2, &x, &y);

        if (StringCompareS("QUIT", wordToString(W1)) == 0) break;
        else if (StringCompareS("WISHLIST", wordToString(W1)) == 0) {
            if (StringCompareS("REMOVE", wordToString(W2)) == 0) {
                // Kalo gaada angka berarti masuknya remove by name
                if (x == -9999) WishlistRemoveByName(&wishlist);
                if (x == -9990) printf("Penghapusan barang WISHLIST gagal dilakukan, command tidak valid!\n"); // Ini harusnya ke WISHLIST REMOVE <i>, dihandle di level console dengan dapet hasil -9990 (udah hardcode dari scan() mesinkata)
                // Kalo bukan berarti remove by index
                else WishlistRemoveByIndex(&wishlist, x);
            }

            else if (StringCompareS("CLEAR", wordToString(W2)) == 0) {
                WishlistClear(&wishlist);
            }

            else if (StringCompareS("SWAP", wordToString(W2)) == 0) {
                if (x == -9990 || y == -990) printf("Penukaran barang WISHLIST gagal dilakukan, command tidak valid!\n"); // Ini harusnya ke WISHLIST REMOVE <i>, dihandle di level console dengan dapet hasil -9990 (udah hardcode dari scan() mesinkata)
                else WishlistSwap(&wishlist, x, y);
            }
        }
    }
}