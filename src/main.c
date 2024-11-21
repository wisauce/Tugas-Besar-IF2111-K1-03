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

int main()
{

    ListofUsers userlist;
    ListofItems itemlist;
    MakeEmpty(&userlist);  // Inisialisasi list pengguna
    MakeListOfItems(&itemlist); // Inisialisasi list item
    int currentUserIndex = -1;
    Load("default_config.txt", &itemlist, &userlist);


    boolean endProgram = false;
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
    printf("        START/LOAD(?)                                                         \n");
    
    while (!endProgram) 
    {
        char command[50];
        printf("\nMASUKKAN COMMAND: ");
        STARTWORD();
        WordToString(currentWord, command);
        Upperstring(command); // Ubah string ke huruf besar

        if (StringCompare(command, "REGISTER") == 0) 
        {
            RegisterUser(&userlist);
            Save("default_config.txt", itemlist, userlist);
        } 

        else if (StringCompare(command, "LOGIN") == 0) 
        {
            if (currentUserIndex != -1) 
            {
                printf("Logout terlebih dahulu sebelum login dengan akun lain.\n");
            } 
            
            else if (LoginUser(userlist, &currentUserIndex))
            {
                printf("Selamat datang!\n");
            }
        } 
        
        else if (StringCompare(command, "LOGOUT") == 0) 
        {
            LogoutUser(&currentUserIndex);
        }

        else if (StringCompare(command, "EXIT") == 0) 
        {
            endProgram = true;
            printf("Program selesai.\n");
        }

        else if (StringCompare(command, "SAVE") == 0)
        {
            Save("default_config.txt", itemlist, userlist);
        }

        else printf("Command tidak dikenali!\n");
    }
}
