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
#include "ADT/queue/queue.h"
#include "games/work.h"

int main() {
    ListofUsers userlist;
    ListofItems itemlist;
    MakeEmpty(&userlist);  // Inisialisasi list pengguna
    MakeListOfItems(&itemlist); // Inisialisasi list item
    Queue q;
    CreateQueue(&q);
    int currentUserIndex = -1; // Inisialisasi user index -1 menandakan belum login
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
    welcomeMenuList();

    while (!endProgram) {
        printf("\nMASUKKAN COMMAND: ");
        STARTWORD();

        int mainMenuIntCommand = WordtoInteger(currentWord);

        if (mainMenuIntCommand >= 1 && mainMenuIntCommand <= 4) 
        {
            switch (mainMenuIntCommand) 
            {
                case 1:
                    handleStartMenu(&itemlist, &userlist, &currentUserIndex, &q);
                    break;

                case 2:
                    handleLoadMenu(&itemlist, &userlist, &currentUserIndex, &q);
                    break;

                case 3: 
                {
                    char saveCurrentChange[10];
                    printf("\nApakah Anda ingin menyimpan perubahan pada file ini? (Y/N) : ");
                    STARTWORD();
                    WordToString(currentWord, saveCurrentChange);
                    Upperstring(saveCurrentChange);
                    if (StringCompare(saveCurrentChange, "Y") == 0) 
                    {
                        handleSaveOnExit(itemlist, userlist);
                        thankYouLetter();
                        endProgram = true;
                        break;
                    } 
                    
                    else if (StringCompare(saveCurrentChange, "N") == 0) 
                    {
                        thankYouLetter();
                        endProgram = true;
                        break;
                    } 
                    
                    else 
                    {
                        printf("Masukkan input yang benar!\n");
                    }
                    break;
                }

                case 4:
                    welcomeHelpMenu();
                    break;

                default:
                    printf("Command tidak dikenali. Silakan coba lagi.\n");
                    break;
            }
        } 
        
        else 
        {
            WordToString(currentWord, mainMenuCommand);
            Upperstring(mainMenuCommand);

            if (StringCompare(mainMenuCommand, "START") == 0) 
            {
                handleStartMenu(&itemlist, &userlist, &currentUserIndex, &q);
            } 
            
            else if (StringCompare(mainMenuCommand, "LOAD") == 0) 
            {
                handleLoadMenu(&itemlist, &userlist, &currentUserIndex, &q);
            } 
            
            else if (StringCompare(mainMenuCommand, "HELP") == 0) 
            {
                welcomeHelpMenu();
            } 
            
            else if (StringCompare(mainMenuCommand, "EXIT") == 0) 
            {
                char saveCurrentChange[10];
                printf("\nApakah Anda ingin menyimpan perubahan pada file ini? (Y/N) : ");
                STARTWORD();
                WordToString(currentWord, saveCurrentChange);
                Upperstring(saveCurrentChange);
                if (StringCompare(saveCurrentChange, "Y") == 0) {
                    handleSaveOnExit(itemlist, userlist);
                    thankYouLetter();
                    endProgram = true;
                } else if (StringCompare(saveCurrentChange, "N") == 0) {
                    thankYouLetter();
                    endProgram = true;
                } else {
                    printf("Masukkan input yang benar!\n");
                }
            } 
            
            else 
            {
                printf("Command tidak dikenali. Silakan coba lagi.\n");
            }
        }
    }

    return 0;
}
