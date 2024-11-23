#include "arrayuser.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty(ListofUsers *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong */
{
    T->Neff = 0; // Set banyak elemen efektif menjadi 0
}	

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (ListofUsers T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	return T.Neff;
}

/* *** Daya tampung container *** */
int MaxNbEl ()
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
int GetFirstIdx ()
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
	return 1;
}
int GetLastIdx (ListofUsers T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
	return T.Neff;
}

/* *** Menghasilkan sebuah elemen *** */
User GetElmt (ListofUsers T, int i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
	return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (ListofUsers Tin, ListofUsers *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
{
	(*Tout).Neff = Tin.Neff;
	for(int i = IdxMin; i <= Tin.Neff; i++){
		(*Tout).TI[i] = Tin.TI[i];
	}
}

void SetEl (ListofUsers *T, int i, User v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
	(*T).TI[i] = v;
	if ((*T).Neff < i){
		(*T).Neff = i+1;
	}
}

void SetNeff (ListofUsers *T, int N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
	(*T).Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (int i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	if ((i >= IdxMin) && (i <= IdxMax)){
		return true;
	} else {
		return false;
	}
}

boolean IsIdxEff (ListofUsers T, int i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	if ((i >= IdxMin) && (i <= T.Neff)){
		return true;
	} else {
		return false;
	}
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsUsersEmpty (ListofUsers T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	if (T.Neff > 0){
		return false;
	} else {
		return true;
	}
}
/* *** Test tabel penuh *** */
boolean IsUsersFull (ListofUsers T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	if (T.Neff == IdxMax){
		return true;
	} else {
		return false;
	}
}

void InsertLastUser(ListofUsers *T, User user) {
    if (T->Neff < IdxMax - IdxMin + 1) { // Validasi kapasitas
        T->TI[T->Neff] = user; // Tambahkan user ke elemen terakhir
        T->Neff++;             // Tambah jumlah elemen efektif
    } else {
        printf("Error: List sudah penuh.\n");
    }
}

void DeleteLastUser(ListofUsers *T)
/* I.S. T tidak kosong */
/* F.S. Elemen terakhir dihapus */
{
    if (T->Neff > 0) {
        T->Neff--; // Kurangi jumlah elemen efektif
    } else {
        printf("Error: List kosong.\n");
    }
}



/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
// void TulisIsi (ListofUsers T)
// /* Proses : Menuliskan isi tabel dengan traversal */
// /* I.S. T boleh kosong */
// /* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
// /* Jika isi tabel [1,2,3] maka akan diprint
// 0:1
// 1:2
// 2:3
// */
// /* Jika T kosong : Hanya menulis "Tabel kosong" */
// {
// 	int i;
// 	if (IsEmpty(T)) {
// 		printf("Tabel kosong\n");
// 	} else {
// 		for (i = IdxMin; i <= T.Neff; i++) {
// 			printf("%d:%d\n", i, T.TI[i]);
// 		}
// 	}
// }

// /* ********** OPERATOR ARITMATIKA ********** */
// /* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
// ListofUsers PlusTab (ListofUsers T1, ListofUsers T2)
// /* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
// /* Mengirimkan T1 + T2 */
// {
// 	ListofUsers THasil;
// 	int i;

// 	THasil.Neff = T1.Neff;
// 	for (i = IdxMin; i <= T1.Neff; i++) {
// 		THasil.TI[i] = T1.TI[i] + T2.TI[i];
// 	}
// 	return THasil;
// }
// ListofUsers MinusTab (ListofUsers T1, ListofUsers T2)
// /* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
// /* Mengirimkan T1 - T2 */
// {
// 	ListofUsers THasil;
// 	int i;

// 	THasil.Neff = T1.Neff;
// 	for (i = IdxMin; i <= T1.Neff; i++) {
// 		THasil.TI[i] = T1.TI[i] - T2.TI[i];
// 	}
// 	return THasil;
// }
// /* ********** NILAI EKSTREM ********** */
// User ValMax (ListofUsers T)
// /* Prekondisi : Tabel T tidak kosong */
// /* Mengirimkan nilai maksimum tabel */
// {
// 	int i;
// 	User maxVal = T.TI[IdxMin];
// 	for (i = IdxMin + 1; i <= T.Neff; i++) {
// 		if (maxVal < T.TI[i]) {
// 			maxVal = T.TI[i];
// 		}
// 	}
// 	return maxVal;
// }

// User ValMin (ListofUsers T)
// /* Prekondisi : Tabel T tidak kosong */
// /* Mengirimkan nilai minimum tabel */
// {
// 	int i;
// 	User minVal = T.TI[IdxMin];
// 	for (i = IdxMin + 1; i <= T.Neff; i++) {
// 		if (minVal > T.TI[i]) {
// 			minVal = T.TI[i];
// 		}
// 	}
// 	return minVal;
// }

// /* *** Mengirimkan indeks elemen bernilai ekstrem *** */
// int IdxMaxTab (ListofUsers T)
// /* Prekondisi : Tabel T tidak kosong */
// /* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
// {
// 	int i;
// 	User maxVal = T.TI[IdxMin];
// 	int idx = IdxMin;
// 	for (i = IdxMin + 1; i <= T.Neff; i++) {
// 		if (maxVal < T.TI[i]) {
// 			maxVal = T.TI[i];
// 			idx = i;
// 		}
// 	}
// 	return idx;
// }

// int IdxMinTab (ListofUsers T)
// /* Prekondisi : Tabel tidak kosong */
// /* Mengirimkan indeks i */
// /* dengan elemen ke-i nilai minimum pada tabel */
// {
// 	int i;
// 	User minVal = T.TI[IdxMin];
// 	int idx = IdxMin;
// 	for (i = IdxMin + 1; i <= T.Neff; i++) {
// 		if (minVal > T.TI[i]) {
// 			minVal = T.TI[i];
// 			idx = i;
// 		}
// 	}
// 	return idx;
// }
