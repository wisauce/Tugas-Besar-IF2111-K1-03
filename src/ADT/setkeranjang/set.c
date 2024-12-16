#include <stdio.h>
#include "set.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptySet(Set *S) {
    (*S).Count = NilSet;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxElSet */
/* Ciri Set kosong : count bernilai NilSet */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S) {
    return (S.Count == NilSet);
}
/* Mengirim true jika Set S kosong */
/* Ciri Set kosong : count bernilai NilSet */

boolean IsFullSet(Set S) {
    return (S.Count == MaxElSet);
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxElSet */

/* ********** Operator Dasar Set ********* */
void InsertSetElmt(Set *S, infotypeSet Elmt) {
    if (!IsMemberSet(*S, Elmt)) {
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void DeleteSetElmt(Set *S, infotypeSet Elmt) {
    // Kamus Lokal
    int i, j;
    boolean found;

    // Algoritma
    found = false;
    i = 0;

    // Cari elemen yang akan dihapus
    while (i < (*S).Count && !found) {
        if (isStringSame((*S).Elements[i].TabWord, Elmt.TabWord)) {
            found = true;
        } else {
            i++;
        }
    }

    // Jika elemen ditemukan, geser elemen-elemen setelahnya ke kiri
    if (found) {
        for (j = i; j < (*S).Count - 1; j++) {
            (*S).Elements[j] = (*S).Elements[j + 1];
        }
        // Kurangi jumlah elemen dalam Set
        (*S).Count--;
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberSet(Set S, infotypeSet Elmt) {
    int i = 0;
    boolean found = false;
    while (i < S.Count && !found) {
        if (isStringSame(S.Elements[i].TabWord, Elmt.TabWord)) {
            found = true;
        }
        i++;
    }
    return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */
