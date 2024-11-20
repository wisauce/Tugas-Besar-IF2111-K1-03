#include <stdio.h>
#include "start.h"
#include "load.c"   // Untuk fungsi Load
#include "ADT/arrayitems/arrayitems.h"  // Untuk ListofItems
#include "ADT/arrayuser/arrayuser.h"    // Untuk ListofUsers

void start() {
    // Nama file konfigurasi default
    const char *config_file = "config.txt";

    // Struktur data untuk menyimpan hasil pembacaan file
    ListofItems itemlist;
    ListofUsers userlist;

    // Inisialisasi list kosong
    CreateEmptyItems(&itemlist);
    CreateEmptyUsers(&userlist);

    // Membaca file konfigurasi
    boolean success;
    FILE *file = fopen(config_file, "r");
    if (file) {
        fclose(file);  // File tersedia, lanjutkan membaca menggunakan fungsi Load
        Load((char *)config_file, &itemlist, &userlist);
        printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");

        // Menampilkan hasil load untuk verifikasi (opsional)
        printf("Daftar barang:\n");
        for (int i = 0; i < Length(itemlist); i++) {
            printf("- %s: %d\n", Get(itemlist, i).name, Get(itemlist, i).price);
        }

        printf("\nDaftar pengguna:\n");
        for (int i = 0; i < NbElmt(userlist); i++) {
            printf("- %s (Saldo: %d)\n", GetElmt(userlist, i).name, GetElmt(userlist, i).money);
        }

    } else {
        printf("Gagal membaca file konfigurasi. Pastikan file '%s' tersedia.\n", config_file);
    }
}
