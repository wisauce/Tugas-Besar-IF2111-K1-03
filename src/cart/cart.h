#ifndef CART_H
#define CART_H

#include <stdio.h>
#include "cart.h"
#include "../ADT/setkeranjang/set.h"
#include "../ADT/boolean.h"
#include "../ADT/mesinkata/mesinkata.h"
#include "../ADT/mesinkarakter/mesinkarakter.h"
#include "../console.h"
#include "../ADT/arrayitems/arrayitems.h"
#include "../ADT/stack/stack.h"

Word CreateWord(char *str);

void trimString(char *str);

boolean isStringSameIgnoreCase(const char *str1, const char *str2);

boolean isItemInStore(ListofItems itemlist, const char *itemName);

void CopyString(char *dest, const char *src, int maxLen);

void ShowCart(Set *keranjang, ListofItems *itemlist);

size_t strcspn(const char *str1, const char *str2);

void PrintItemList(ListofItems itemlist);
/* Menambahkan barang ke dalam keranjang */
/* I.S. keranjang mungkin kosong, keranjang tidak penuh*/
/* F.S. Barang menjadi bagian dari elemen keranjang.*/
void AddCart(Set *S, infotypeSet Elmt, int quantity);

/* Menghapus barang dari keranjang */
/* I.S. keranjang tidak kosong, barang mungkin ada atau tidak ada di dalam keranjang */
/* F.S. Barang berkurang atau dihapus dari keranjang */
void RemoveCart(Set *S, infotypeSet Elmt, int quantity);

/* Menangani pembayaran keranjang */
/* I.S. Keranjang tidak kosong, uang pengguna diperiksa */
/* F.S. Jika berhasil, uang berkurang, barang dicatat di riwayat pembelian */
void CartPay(Set *keranjang, ListofUsers *userlist, int *currentUserIndex, ListofItems *itemlist);

#endif /* CART_H */
