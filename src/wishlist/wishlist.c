#include "wishlist.h"
#include "../ADT/linkedlist/linkedlist.h"
#include "../ADT/mesinkata/mesinkata.h"
#include <stdio.h>
#include "../ADT/arrayitems/arrayitems.h"

void WishlistAdd(infotype newitem,List * wishlist, ListofItems itemlist) {
    address p = Search(*wishlist,newitem);
    if (p != NilLL) {
        if (isItemIn(itemlist,newitem)) {
            InsVLast(wishlist, newitem);\
            printf("%s berhasil dimasukkan ke dalam wishlist!", newitem);
        } else {
            printf("maaf, %s tidak ada di dalam toko...\n", newitem);
        }
    } else {
        printf("maaf, %s sudah berada di dalam wishlist...\n",newitem);
    }
}

void WishlistShow(List Wishlist) {
    printf("berikut ini adalah barang-barang dalam wishlist-mu:\n");
    PrintInfoLL(Wishlist);
}

void WishlistRemoveByIndex(List *wishlist, int index) {
    // Terimanya 1st indexing jadi kita convert dulu ke 0th indexing
    index--;
    if (IsEmptyLL(*wishlist)) printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
    else if (index < 0) printf("Penghapusan barang WISHLIST gagal dilakukan, posisi tidak valid!\n");
    else
    {
        address temp = AddrOfIdx(*wishlist, index);
        if (temp != NilLL)
        {
            printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", index);
            DelP(wishlist, Info(temp));
        }
        else
        {
            printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", index);
        }
    }
}

void WishlistRemoveByName(List *wishlist)
{
    Word W1, W2;
    int x, y;
    printf("Nama barang yang akan dihapus: ");
    scan("%s", &W1, &W2, &x, &y);

    address temp = Search(*wishlist, wordToString(W1));

    if (temp != NilLL)
    {
        DelP(wishlist, wordToString(W1));
        printf("%s berhasil dihapus dari WISHLIST!\n", wordToString(W1));
    }
    else
    {
        printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", wordToString(W1));
    }
}

void WishlistClear(List *wishlist){
    address P;
    
    if (IsEmptyLL(*wishlist)){
        printf("Wishlist telah dikosongkan.\n");
        return;
    }
    while (!IsEmptyLL(*wishlist)){
        DelFirst(wishlist, &P);
        Dealokasi(&P);
    }
    printf("Wishlist telah dikosongkan.\n");
}

void WishlistSwap(List *wishlist, int pos1, int pos2){
    address P1, P2, Prev1, Prev2;
    address curr;
    int count = NbElmtLL(*wishlist);
    

    if (IsEmptyLL(*wishlist) || count == 1){
        if (count == 1){
            printf("Gagal menukar posisi %s!\n", Info(First(*wishlist)));
        }
        return;
    }
    
    if (pos1 < 1 || pos2 < 1 || pos1 > count || pos2 > count){
        printf("Posisi tidak valid!\n");
        return;
    }

    P1 = First(*wishlist);
    P2 = First(*wishlist);
    Prev1 = NilLL;
    Prev2 = NilLL;
    curr = First(*wishlist);
    
    for (int i = 1; i < pos1; i++){
        Prev1 = curr;
        curr = Next(curr);
    }
    P1 = curr;
    
    curr = First(*wishlist);
    
    for (int i = 1; i < pos2; i++){
        Prev2 = curr;
        curr = Next(curr);
    }
    P2 = curr;
    
    char* info1 = Info(P1);
    char* info2 = Info(P2);
    
    if (Next(P1) == P2){
        if (Prev1 == NilLL){
            First(*wishlist) = P2;
        } else {
            Next(Prev1) = P2;
        }
        Next(P1) = Next(P2);
        Next(P2) = P1;
    } else if (Next(P2) == P1){
        if (Prev2 == NilLL){
            First(*wishlist) = P1;
        } else {
            Next(Prev2) = P1;
        }
        Next(P2) = Next(P1);
        Next(P1) = P2;
    } else {
        address tempNext = Next(P1);
        
        if (Prev1 == NilLL){
            First(*wishlist) = P2;
        } else {
            Next(Prev1) = P2;
        }
        
        if (Prev2 == NilLL){
            First(*wishlist) = P1;
        } else {
            Next(Prev2) = P1;
        }
        
        Next(P1) = Next(P2);
        Next(P2) = tempNext;
    }
    
    printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", info1, info2);
}
