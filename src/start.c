#include <stdio.h>
#include <stdlib.h>
#include "start.h"
#include "load.c" // Untuk fungsi Load

void start(ListofUsers *userlist, ListofItems *itemlist) {
    // Nama file konfigurasi default
    const char *config_file = "default_config.txt";

    // Validasi keberadaan file
    FILE *file = fopen(config_file, "r");
    if (file) {
        fclose(file); // File tersedia, lanjutkan membaca menggunakan Load
        Load((char *)config_file, itemlist, userlist);
        printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");

        // Menampilkan hasil load untuk verifikasi (opsional)
        printf("\nDaftar barang:\n");
        for (int i = 0; i < Length(*itemlist); i++) {
            printf("- %s: %d\n", Get(*itemlist, i).name, Get(*itemlist, i).price);
        }

        printf("\nDaftar pengguna:\n");
        for (int i = 0; i < NbElmt(*userlist); i++) {
            printf("- %s (Saldo: %d)\n", GetElmt(*userlist, i).name, GetElmt(*userlist, i).money);
        }
    } else {
        printf("Gagal membaca file konfigurasi. Pastikan file '%s' tersedia.\n", config_file);
    }
}
