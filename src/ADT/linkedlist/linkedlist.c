/* File : linkedlist.c */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "../../console.h"
#include "../mesinkata/mesinkata.h"

/* Definisi list : */
/* List kosong : First(L) = NilLL */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=NilLL */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLL(List L)
{
    // KAMUS LOKAL

    // ALGORITMA
    return (First(L) == NilLL);
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLL(List *L)
{
    // KAMUS LOKAL

    // ALGORITMA
    First(*L) = NilLL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi(infotype X)
{
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = (address)malloc(sizeof(ElmtList));
    if (P != NilLL)
    {
        Info(P) = (char *)malloc(LINKEDLIST_MAX_LEN * sizeof(char));
        stringCopy(Info(P), X);
        Next(P) = NilLL;
        return P;
    }
    return NilLL;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NilLL, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=NilLL */
/* Jika alokasi gagal, mengirimkan NilLL */

void Dealokasi(address *P)
{
    // KAMUS LOKAL

    // ALGORITMA
    free(Info(*P));
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search(List L, infotype X)
{
    // KAMUS LOKAL
    address P;
    boolean found;

    // ALGORITMA
    found = false;
    P = First(L);
    while (P != NilLL && !found)
    {
        if (StringCompare(Info(P), X) == 0)
            found = true;
        else
            P = Next(P);
    }

    if (found)
        return P;
    else
        return NilLL;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan NilLL */

address AddrOfIdx(List L, int idx)
{
    // KAMUS LOKAL
    address P;
    int i = 0;

    // ALGORITMA
    P = First(L);
    while (P != NilLL && i < idx)
    {
        i++;
        P = Next(P);
    }
    return P;
}
/* PREKONDISI: Idx berada di dalam list */
/* Mencari alamat idx di dalam L */

/****************** PRIMITIF BERDASARKAN NilLLAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst(List *L, infotype X)
{
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = Alokasi(X);
    if (P != NilLL)
        InsertFirstLL(L, P);
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan NilLLai X jika alokasi berhasil */
void InsVLast(List *L, infotype X)
{
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = Alokasi(X);
    if (P != NilLL)
        InsertLastLL(L, P);
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilLLai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(List *L, infotype *X)
{
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    DelFirst(L, &P);
    stringCopy(*X, Info(P));
    Dealokasi(&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: NilLLai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast(List *L, infotype *X)
{
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    DelLast(L, &P);
    stringCopy(*X, Info(P));
    Dealokasi(&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: NilLLai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstLL(List *L, address P)
{
    // KAMUS LOKAL

    // ALGORITMA
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfterLL(List *L, address P, address Prec)
{
    // KAMUS LOKAL

    // ALGORITMA
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastLL(List *L, address P)
{
    // KAMUS LOKAL
    address last;

    // ALGORITMA
    if (IsEmptyLL(*L))
        InsertFirstLL(L, P);
    else
    {
        last = First(*L);
        while (Next(last) != NilLL)
        {
            last = Next(last);
        }

        InsertAfterLL(L, P, last);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(List *L, address *P)
{
    // KAMUS LOKAL

    // ALGORITMA
    *P = First(*L);
    if (Next(First(*L)) == NilLL)
    {
        CreateEmptyLL(L);
        return;
    }
    First(*L) = Next(First(*L));
    Next(*P) = NilLL;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP(List *L, infotype X)
{
    // KAMUS LOKAL
    address P, prev, temp;
    boolean found;

    // ALGORITMA
    P = First(*L);
    prev = NilLL;
    found = false;

    while (P != NilLL && !found)
    {
        if (StringCompare(Info(P), X) == 0)
            found = true;
        else
        {
            prev = P;
            P = Next(P);
        }
    }

    if (found)
    {
        if (prev == NilLL)
            DelFirst(L, &temp);
        else
            DelAfter(L, &temp, prev);
        Dealokasi(&temp);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast(List *L, address *P)
{
    // KAMUS LOKAL
    address last, prev;

    // ALGORITMA
    last = First(*L);
    prev = NilLL;
    while (Next(last) != NilLL)
    {
        prev = last;
        last = Next(last);
    }
    if (prev == NilLL)
        DelFirst(L, P);
    else
        DelAfter(L, P, prev);
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter(List *L, address *Pdel, address Prec)
{
    // KAMUS LOKAL
    address temp;
    boolean found;

    // ALGORITMA
    found = false;
    temp = First(*L);
    while (temp != NilLL && !found)
    {
        if (temp == Prec)
            found = true;
        else
            temp = Next(temp);
    }

    *Pdel = Next(temp);
    Next(temp) = Next(Next(temp));
    Next(*Pdel) = NilLL;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoLL(List L)
{
    // KAMUS LOKAL
    address P;

    // ALGORITMA
    P = First(L);
    int idx = 1;
    while (P != NilLL)
    {
        printf("%d ",idx);
        printf("%s\n", Info(P));
        P = Next(P);
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen berNilLLai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtLL(List L)
{
    // KAMUS LOKAL
    address P;
    int cnt = 0;

    // ALGORITMA
    P = First(L);
    while (P != NilLL)
    {
        cnt++;
        P = Next(P);
    }
    return cnt;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */