#include<stdio.h>
#include <stdlib.h>
#include"stack.h"
/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxStackEl */
/* jadi indeksnya antara 0.. MaxStackEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == NilStack);
}
boolean IsFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) ==  MaxStackEl -1);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infostack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)++;
    InfoTop(*S) = X;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infostack* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    Top(*S)--;
    free(*X);
}

int LengthStack(Stack S)
{
    return Top(S) + 1;
}

Stack ReverseStack(Stack *S)
/* I.S. S terdefinisi */
/* F.S. Elemen stack S dibalik : */
{
    int i;
    Stack S1;
    infostack X;
    CreateEmptyStack(&S1);
    int n = LengthStack(*S);
    for (i = 0; i < n; i++)
    {
        Push(&S1, InfoTop(*S));
        Pop(S, &X); 
    }
    
    return S1;
}