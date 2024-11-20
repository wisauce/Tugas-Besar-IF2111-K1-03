#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "console.h"
#include "ADT/boolean.h"
#include "ADT/arraydinamis/arraydin.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arrayuser/arrayuser.h"
#include "ADT/arrayitems/arrayitems.h"
#include "start.h" // Header untuk fungsi start
#include "help.h"  // Header untuk fungsi help

int main()
{
    ListofUsers userlist;
    ListofItems itemlist;

    MakeEmpty(&userlist);        // Inisialisasi list pengguna
    MakeListOfItems(&itemlist);  // Inisialisasi list barang

    int currentUserIndex = -1;   // Index pengguna saat ini (-1 berarti belum login)
    boolean endProgram = false;  // Status program (false = masih berjalan)

    printf(" .+\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+. \n");
    printf("(                                                                                 )\n");
    printf(" )      __    __       _                                    _                    ( \n");
    printf("(      / / /\\ \\ \\ ___ | |  ___  ___   _ __ ___    ___      | |_  ___              )\n");
    printf(" )     \\ \\/  \\/ // _ \\| | / __|/ _ \\ | '_ ` _ \\  / _ \\     | __|/ _ \\            ( \n");
    printf("(       \\  /\\  /|  __/| || (__| (_) || | | | | ||  __/     | |_| (_) |            )\n");
    printf(" )       \\/  \\/  \\___||_| \\___|\\___/ |_| |_| |_| \\___|      \\__|\\___/            ( \n");
    printf("(                                                                                 )\n");
    printf(" )        ___                                             _                      ( \n");
    printf("(        / _ \\ _   _  _ __  _ __  _ __ ___    __ _  _ __ | |_                     )\n");
    printf(" )      / /_)/| | | || '__|| '__|| '_ ` _ \\  / _` || '__|| __|                   ( \n");
    printf("(      / ___/ | |_| || |   | |   | | | | | || (_| || |   | |_                     )\n");
    printf(" )     \\/      \\__,_||_|   |_|   |_| |_| |_| \\__,_||_|    \\__|                   ( \n");
    printf("(                                                                                 )\n");
    printf(" )                                                                               ( \n");
    printf("(                                                                                 )\n");
    printf(" \"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+.\"+. \"  \n");

    printf("--------Kelompok 3 K1---------\n");
    printf("       Welcome to Purrmart    \n");

    while (!endProgram)
    {
        char command[50];
        printf("\nMASUKKAN COMMAND: ");
        STARTWORD();                     // Membaca input dari pengguna
        WordToString(currentWord, command);
        Upperstring(command);            // Ubah input ke huruf besar

        if (StringCompare(command, "START") == 0)
        {
            start(&userlist, &itemlist); // Memuat konfigurasi default
        }
        else if (StringCompare(command, "HELP") == 0)
        {
            // Tampilkan bantuan berdasarkan status
            if (currentUserIndex == -1) {
                // Jika tidak ada pengguna yang login
                help(2); // Login Menu Help
            } else {
                // Jika ada pengguna yang login
                help(3); // Main Menu Help
            }
        }
        else if (StringCompare(command, "REGISTER") == 0)
        {
            RegisterUser(&userlist);                       // Registrasi pengguna baru
            Save("default_config.txt", itemlist, userlist); // Simpan perubahan
        }
        else if (StringCompare(command, "LOGIN") == 0)
        {
            if (currentUserIndex != -1)
            {
                printf("Logout terlebih dahulu sebelum login dengan akun lain.\n");
            }
            else if (LoginUser(userlist, &currentUserIndex))
            {
                printf("Selamat datang, %s!\n", GetElmt(userlist, currentUserIndex).name);
            }
        }
        else if (StringCompare(command, "LOGOUT") == 0)
        {
            LogoutUser(&currentUserIndex); // Logout pengguna
        }
        else if (StringCompare(command, "SAVE") == 0)
        {
            Save("default_config.txt", itemlist, userlist); // Simpan data ke file
            printf("Data berhasil disimpan.\n");
        }
        else if (StringCompare(command, "EXIT") == 0)
        {
            endProgram = true; // Keluar dari program
            printf("Program selesai. Sampai jumpa!\n");
        }
        else
        {
            printf("Command tidak dikenali! Coba masukkan HELP untuk daftar command.\n");
        }
    }

    return 0;
}
