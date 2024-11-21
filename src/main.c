#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"
#include "ADT/boolean.h"
#include "ADT/arraydinamis/arraydin.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arrayuser/arrayuser.h"
#include "ADT/arrayitems/arrayitems.h"

int main() {
    ListofUsers userlist;
    ListofItems itemlist;
    MakeEmpty(&userlist);  // Inisialisasi list pengguna
    MakeListOfItems(&itemlist); // Inisialisasi list item

    boolean endProgram = false;
    char mainMenuCommand[50];

    // Welcome message
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

    printf("--------Kelompok 3 K1---------                                                 \n");                      
    printf("       Welcome to Purrmart                                                      \n");                           
    printf("     PILIH MENU: START/LOAD/EXIT                                            \n");

        while (!endProgram) {
        printf("\nMASUKKAN COMMAND: ");
        STARTWORD();
        WordToString(currentWord, mainMenuCommand);
        Upperstring(mainMenuCommand);

        if (StringCompare(mainMenuCommand, "START") == 0) 
        {
            handleStartMenu(&itemlist, &userlist); // Akan menangani START
        } 
        
        else if (StringCompare(mainMenuCommand, "LOAD") == 0) 
        {
            handleLoadMenu(&itemlist, &userlist); // Akan menangani LOAD
        } 
        
        else if (StringCompare(mainMenuCommand, "EXIT") == 0) 
        {
            char savefilename [50];
            printf("Masukkan nama file save yang akan Anda simpan : ");
            Save(savefilename, itemlist, userlist);
            endProgram = true;
            printf("Terima kasih telah menggunakan PURRMART.\n");
        } 
        
        else 
        {
            printf("Command tidak dikenali. Silakan coba lagi.\n");
        }
    }
    return 0;
}
