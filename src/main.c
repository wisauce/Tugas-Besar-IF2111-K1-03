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
#include "games/work/work.h"
#include "ADT/stack/stack.h"
#include "ADT/setkeranjang/set.h"
#include "art/art.h"
#include "ADT/linkedlist/linkedlist.h"

int main() {
    ListofUsers userlist;
    ListofItems itemlist;
    Stack historystack; // Stack untuk menyimpan riwayat
    MakeEmpty(&userlist);  // Inisialisasi list pengguna
    MakeListOfItems(&itemlist); // Inisialisasi list item
    CreateEmptyStack(&historystack); // Inisialisasi stack riwayat
    Set keranjang;
    CreateEmptySet (&keranjang);
    Queue q;
    CreateQueue(&q);
    List wishlist; // Linked list untuk menyimpan wishlist
    CreateEmptyLL(&wishlist); // Inisialisasi wishlist
    int currentUserIndex = -1; // Inisialisasi user index -1 menandakan belum login
    boolean endProgram = false;
    boolean returnToLogin = false;
    char fullInput[100];
    char mainMenuCommand[50];
    char parameter1[50];
    char remaining[50];

    welcomeMessage();
    welcomeMenuList();

    while (!endProgram) 
    {
        printf("\nMASUKKAN COMMAND: ");
        STARTLINE();
        WordToString(currentWord, fullInput);

        parseInput(fullInput, mainMenuCommand, parameter1, remaining);

        if (StringCompare(mainMenuCommand, "START") == 0 || StringCompare(mainMenuCommand, "1") == 0)
        {
            handleStartMenu(&itemlist, &userlist, &currentUserIndex, &q, &returnToLogin, &historystack, &keranjang, &wishlist);
        } 

        else if (StringCompare(mainMenuCommand, "LOAD") == 0 || StringCompare(mainMenuCommand, "2") == 0) 
        {
            if (parameter1[0] == '\0')
            {
                printf("Input yang Anda masukkan salah!\nGunakan Format: LOAD <filename>\n");
            }
            
            else handleLoadMenu(&itemlist, &userlist, &currentUserIndex, &q, &returnToLogin, &historystack, &keranjang, &wishlist, parameter1);
        } 
        
        else if (StringCompare(mainMenuCommand, "EXIT") == 0 || StringCompare(mainMenuCommand, "3") == 0) 
        {
            char saveCurrentChange[10];
            printf("\nApakah Anda ingin menyimpan perubahan pada file ini? (Y/N) : ");
            STARTWORD();
            WordToString(currentWord, saveCurrentChange);
            Upperstring(saveCurrentChange);
            if (StringCompare(saveCurrentChange, "Y") == 0) 
            {
                Word filenameWord;
                printf("Masukkan nama file untuk menyimpan: ");
                STARTWORD();
                handleSaveOnExit(itemlist, userlist, filenameWord);
                thankYouLetter();
                endProgram = true;
            } 
            
            else if (StringCompare(saveCurrentChange, "N") == 0) 
            {
                thankYouLetter();
                endProgram = true;
            } 
            
            else printf("Masukkan input yang benar!\n");
        }

        else if (StringCompare(mainMenuCommand, "HELP") == 0 || StringCompare(mainMenuCommand, "4") == 0) welcomeHelpMenu();
        
        else printf("Command tidak dikenali. Silakan coba lagi.\n");
    }

    return 0;
}
