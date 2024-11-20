#include "../boolean.h"

#ifndef ARRAY_USER_H
#define ARRAY_USER_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/
#define MAX_USER_LEN 100

/* Definisi elemen dan koleksi objek */

typedef struct {
  char name[MAX_USER_LEN];
  char password[MAX_USER_LEN];
  int money;
} User;

typedef struct
	{
		User TI [IdxMax-IdxMin+1]; /* memori tempat penyimpan elemen (container) */
		int Neff; /* banyaknya elemen efektif */
	} ListofUsers;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah ListofUsers, cara deklarasi dan akses: */
/* Deklarasi : T : ListofUsers */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (ListofUsers *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (ListofUsers T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl ();
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
int GetFirstIdx ();
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
int GetLastIdx (ListofUsers T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
User GetElmt (ListofUsers T, int i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (ListofUsers Tin, ListofUsers *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetEl (ListofUsers *T, int i, User v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeff (ListofUsers *T, int N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (int i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (ListofUsers T, int i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsUsersEmpty (ListofUsers T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsUsersFull (ListofUsers T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

void InsertLastUser(ListofUsers *userlist, User user);

void DeleteLastUser(ListofUsers *T);

// /* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
// void TulisIsi (ListofUsers T);
// /* Proses : Menuliskan isi tabel dengan traversal */
// /* I.S. T boleh kosong */
// /* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
// /* Jika isi tabel [1,2,3] maka akan diprint
// 0:1
// 1:2
// 2:3
// */
// /* Jika T kosong : Hanya menulis "Tabel kosong" */

// /* ********** OPERATOR ARITMATIKA ********** */
// /* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
// ListofUsers PlusTab (ListofUsers T1, ListofUsers T2);
// /* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
// /* Mengirimkan T1 + T2 */
// ListofUsers MinusTab (ListofUsers T1, ListofUsers T2);
// /* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
// /* Mengirimkan T1 - T2 */

// /* ********** NILAI EKSTREM ********** */
// User ValMax (ListofUsers T);
// /* Prekondisi : Tabel T tidak kosong */
// /* Mengirimkan nilai maksimum tabel */

// User ValMin (ListofUsers T);
// /* Prekondisi : Tabel T tidak kosong */
// /* Mengirimkan nilai minimum tabel */

// /* *** Mengirimkan indeks elemen bernilai ekstrem *** */
// int IdxMaxTab (ListofUsers T);
// /* Prekondisi : Tabel T tidak kosong */
// /* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */

// int IdxMinTab (ListofUsers T);
// /* Prekondisi : Tabel tidak kosong */
// /* Mengirimkan indeks i */
// /* dengan elemen ke-i nilai minimum pada tabel */

#endif