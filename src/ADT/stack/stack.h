/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include"src/ADT/boolean.h"

#define NilStack -1
#define MaxStackEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef char* infostack;
typedef int addressstack;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infostack T[MaxStackEl]; /* tabel penyimpan elemen */
  addressstack TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxStackEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

// typedef struct {
//   ElType buffer[CAPACITY]; /* tabel penyimpan elemen */
//   int idxTop;              /* alamat TOP: elemen puncak */
// } Stack;

// /* ********* AKSES (Selektor) ********* */
// /* Jika s adalah Stack, maka akses elemen : */
// #define IDX_TOP(s) (s).idxTop
// #define     TOP(s) (s).buffer[(s).idxTop]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxStackEl */
/* jadi indeksnya antara 0.. MaxStackEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */


/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infostack X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infostack* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

int LengthStack(Stack S);
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika stack kosong. */

Stack ReverseStack(Stack *S);
/* I.S. S terdefinisi */
/* F.S. Elemen stack S dibalik : */

#endif
