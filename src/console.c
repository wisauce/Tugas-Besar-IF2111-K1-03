#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Untuk fungsi time()
#include "console.h"
#include "ADT/boolean.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arrayuser/arrayuser.h"
#include "ADT/arrayitems/arrayitems.h"
#include "games/w0rdl3/w0rdl3.h"
#include "games/work/work.h"
#include "ADT/queue/queue.h"
#include "games/tebakangka/tebakangka.h"
#include "games/bioweapon/bioweapon.h"
#include "cart/cart.h"
#include "games/quantum_w0rdl3/quantum_w0rdl3.h"
#include "ADT/setkeranjang/set.h"
#include "ADT/stack/stack.h"
#include "art/art.h"
#include "wishlist/wishlist.h"
#include "ADT/linkedlist/linkedlist.h"
#include "profile/profile.h"

boolean loginActive = true;

void clearterminal()
{
    system("cls");
}

boolean isAllDigit(char *str) 
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
        i++;
    }
    return true;
}

void parseInput(char *input, char *command, char *parameter1, char *remaining) 
{
    int i = 0, j = 0;

    while (input[i] == ' ') i++;

    while (input[i] != '\0' && input[i] != ' ') {
        command[j++] = input[i++];
    }
    command[j] = '\0';

    while (input[i] == ' ') i++;

    j = 0;
    while (input[i] != '\0' && input[i] != ' ') {
        parameter1[j++] = input[i++];
    }
    parameter1[j] = '\0';

    while (input[i] == ' ') i++;

    j = 0;
    while (input[i] != '\0') {
        remaining[j++] = input[i++];
    }
    remaining[j] = '\0';

    Upperstring(command);
    Upperstring(parameter1);
}

void game_load(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex, Queue *q, boolean *returnToLogin, Stack *historystack, Set *keranjang, List *wishlist)
{
    char loginMenuCommand[50];
    loginMenuList();
    printf("\nMASUKKAN COMMAND: ");
    STARTWORD();
    WordToString(currentWord, loginMenuCommand);
    Upperstring(loginMenuCommand);

    if (StringCompare(loginMenuCommand, "HELP") == 0 || StringCompare(loginMenuCommand, "5") == 0) loginHelpMenu();

    else if (StringCompare(loginMenuCommand, "REGISTER") == 0 || StringCompare(loginMenuCommand, "1") == 0) RegisterUser(userlist);
    
    else if (StringCompare(loginMenuCommand, "LOGIN") == 0 || StringCompare(loginMenuCommand, "2") == 0) 
    {
        if (*currentUserIndex != -1) 
        {
            printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", GetElmt(*userlist, *currentUserIndex).name);
        } 
        else 
        {
            if (LoginUser(*userlist, currentUserIndex)) 
            {
                printf("Selamat datang di PURRMART!\n");
                loginActive = false;
                mainMenu(itemlist, userlist, currentUserIndex, q, returnToLogin, historystack, keranjang, wishlist);

                if (*returnToLogin) loginActive = true;
            }
        }
    }

    else if (StringCompare(loginMenuCommand, "LOGOUT") == 0 || StringCompare(loginMenuCommand, "3") == 0) 
    {
        if (*currentUserIndex == -1) printf("Anda belum login! Silakan LOGIN terlebih dahulu.\n");
        
        else 
        {
            printf("Anda telah logout.\n");
            *currentUserIndex = -1; 
            loginActive = false;
            welcomeMenuList();
        }
    } 
    
    else if (StringCompare(loginMenuCommand, "EXIT") == 0 || StringCompare(loginMenuCommand, "4") == 0)
    {
        char saveCurrentChange[1];
        printf("\nApakah Anda ingin menyimpan perubahan pada file ini? (Y/N) : ");
        STARTWORD();
        WordToString(currentWord, saveCurrentChange);
        Upperstring(saveCurrentChange);
        if (StringCompare(saveCurrentChange, "Y") == 0)
        {
            Word filenameWord;
            printf("Masukkan nama file untuk menyimpan: ");
            STARTWORD();
            handleSaveOnExit(*itemlist, *userlist, filenameWord);
            thankYouLetter();
            exit(0);
        }

        else if (StringCompare(saveCurrentChange, "N") == 0)
        {
            thankYouLetter();
            exit(0);
        }

        else printf("Masukkan input yang benar!");
    } 
    
    else printf("Command tidak dikenali.\n");
}

void handleStartMenu(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex, Queue *q, boolean *returnToLogin, Stack *historystack, Set *keranjang, List *wishlist) 
{
    mainstartmenu(itemlist, userlist);
    boolean loginActive = true;

    while (loginActive) game_load(itemlist, userlist, currentUserIndex, q, returnToLogin, historystack, keranjang, wishlist);
}

void handleLoadMenu(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex, Queue *q, boolean *returnToLogin, Stack *historystack, Set *keranjang, List *wishlist, char *filename) 
{
    boolean success = mainloadmenu(filename, itemlist, userlist);

    if (!success) 
    {
        printf("\nKembali ke Welcome Menu.\n");
        welcomeMenuList();
        return;
    }

    boolean loginActive = true;

    while (loginActive) game_load(itemlist, userlist, currentUserIndex, q, returnToLogin, historystack, keranjang, wishlist);
}

void mainMenu(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex, Queue *q, boolean *returnToLogin, Stack *historystack, Set *keranjang, List *wishlist) 
{
    boolean mainMenuActive = true;
    clearterminal();
    mainMenuList();

    while (mainMenuActive) 
    {

        char fullInput[100];      
        char mainMenuCommand[50];         
        char parameter1[50];
        char remaining[100];

        printf("\nMASUKKAN COMMAND: ");
        STARTLINE();
        WordToString(currentWord, fullInput);

        parseInput(fullInput, mainMenuCommand, parameter1, remaining);

        if (StringCompare(mainMenuCommand, "HELP") == 0) mainHelpMenu();

        else if (StringCompare(mainMenuCommand, "PROFILE") == 0) Profile(*userlist, *currentUserIndex);

        else if (StringCompare(mainMenuCommand, "WORK") == 0) 
        {
            Upperstring(parameter1);

            if (parameter1[0] == '\0') performWork(userlist, currentUserIndex);

            else if (StringCompare(parameter1, "CHALLENGE") == 0)
            {
                boolean challengeActive = true;
                while (challengeActive) 
                {
                    workChallengeList();
                    char workChallengeCommand[50];
                    STARTLINE();
                    WordToString(currentWord, workChallengeCommand);
                    Upperstring(workChallengeCommand);

                    if (StringCompare(workChallengeCommand, "TEBAK ANGKA") == 0 || StringCompare(workChallengeCommand, "1") == 0) 
                    {
                        tebakAngka(userlist, currentUserIndex);
                    }
                    else if (StringCompare(workChallengeCommand, "W0RDL3") == 0 || StringCompare(workChallengeCommand, "2") == 0) 
                    {
                        w0rdl3(userlist, currentUserIndex);
                    }
                    else if (StringCompare(workChallengeCommand, "QUANTUM W0RDL3") == 0 || StringCompare(workChallengeCommand, "3") == 0) 
                    {
                        QUANTUMW0RDL3(userlist, currentUserIndex);
                    }
                    else if (StringCompare(workChallengeCommand, "0") == 0 || StringCompare(workChallengeCommand, "KELUAR") == 0) 
                    {
                        printf("Keluar dari WORK CHALLENGE...\n");
                        challengeActive = false;
                    }
                    else printf("Masukkan pilihan yang valid (1-3 atau 0 untuk keluar)!\n");
                }
            }
        }   

        else if (StringCompare(mainMenuCommand, "STORE") == 0)
        {
            Upperstring (parameter1);

            if (StringCompare(parameter1, "LIST") == 0) StoreList(*itemlist);
            
            else if (StringCompare(parameter1, "REQUEST") == 0) StoreRequest(itemlist, q);

            else if (StringCompare(parameter1, "SUPPLY") == 0) StoreSupply(itemlist, q);

            else if (StringCompare(parameter1, "REMOVE") == 0) StoreRemove(itemlist);

            else printf("Masukkan command yang benar!\n");
        }


        else if (StringCompare(mainMenuCommand, "LOGOUT") == 0) 
        {
            printf("Anda telah logout.\n");
            *currentUserIndex = -1; 
            *returnToLogin = true;
            mainMenuActive = false; 
        } 

        else if (StringCompare(mainMenuCommand, "SAVE") == 0) 
        {
            int cmd_length = stringLength(parameter1);
            if (parameter1[0] == '\0')
            {
                printf("Input yang Anda masukkan salah!\n");
                printf("Format: SAVE <filename>\n");
            }

            else if (parameter1[cmd_length-4] != '.' || parameter1[cmd_length-3] != 't' || parameter1[cmd_length-2] != 'x' ||
                    parameter1[cmd_length-1] != 't') printf("Masukkan format yang benar! Gunakan .txt\n");

            else Save(parameter1, *itemlist, *userlist);
        }
        
        else if (StringCompare(mainMenuCommand, "CART") == 0) 
        {
            Upperstring(parameter1);

            if (StringCompare(parameter1, "ADD") == 0) 
            {
                if (remaining[0] == '\0') 
                {
                    printf("Input yang Anda berikan salah!\nGunakan Format: CART ADD <nama barang> <jumlah>\n");
                    return;
                }

                char itemName[50];
                int quantity = 0;

                // Split remaining menjadi nama barang dan jumlah
                splitNameQuantity(remaining, itemName, &quantity);

                if (quantity <= 0) 
                {
                    printf("Jumlah barang harus lebih dari 0!\n");
                    return;
                }

                if (!isItemInStore(*itemlist, itemName)) printf("Barang tidak ada di store!\n");
                else 
                {
                    infotypeSet item = CreateWord(itemName);
                    AddCart(keranjang, item, quantity);
                    printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", quantity, itemName);
                }
            } 
            
            else if (StringCompare(parameter1, "REMOVE") == 0) 
            {
                if (remaining[0] == '\0') 
                {
                    printf("Input yang Anda berikan salah!\nGunakan Format: CART REMOVE <nama barang> <jumlah>\n");
                    return;
                }

                char itemName[50];
                int quantity = 0;

                // Split remaining menjadi nama barang dan jumlah
                splitNameQuantity(remaining, itemName, &quantity);

                if (quantity <= 0) 
                {
                    printf("Jumlah barang harus lebih dari 0!\n");
                    return;
                }

                infotypeSet item = CreateWord(itemName);
                if (IsMemberSet(*keranjang, item)) 
                {
                    RemoveCart(keranjang, item, quantity);
                    printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", quantity, itemName);
                } 
                
                else printf("Barang tidak ditemukan di keranjang!\n");
            } 
            
            else if (StringCompare(parameter1, "PAY") == 0) 
            {
                CartPay(keranjang, userlist, currentUserIndex, historystack, itemlist);
            }
            
            else if (StringCompare(parameter1, "SHOW") == 0) 
            {
                ShowCart(keranjang, itemlist);
            }
            
            else printf("Command tidak valid.\n");
        }
            
        else if (StringCompare(mainMenuCommand, "WISHLIST") == 0) 
        {
            Upperstring(parameter1);

            if (StringCompare(parameter1, "ADD") == 0) 
            {
                char itemName[50];
                printf("Masukkan nama barang yang ingin ditambahkan ke wishlist: ");
                STARTLINE();
                WordToString(currentWord, itemName);
                WishlistAdd(itemName, wishlist, *itemlist);
            } 
            
            else if (StringCompare(parameter1, "SWAP") == 0)
            {
                if (remaining[0] == '\0') 
                {
                    printf("Input yang Anda berikan salah!\n");
                    printf("Masukkan posisi pertama dan kedua dengan format: WISHLIST SWAP <posisi pertama> <posisi kedua>\n");
                    return;
                }

                int i = 0, j = 0;
                char firstPart[50], secondPart[50];

                while (remaining[i] != '\0' && remaining[i] != ' ') firstPart[j++] = remaining[i++];
                firstPart[j] = '\0';

                while (remaining[i] == ' ') i++;

                j = 0;
                while (remaining[i] != '\0') secondPart[j++] = remaining[i++];
                secondPart[j] = '\0';

                if (isAllDigit(firstPart) && isAllDigit(secondPart)) 
                {
                    int pos1 = atoi(firstPart);
                    int pos2 = atoi(secondPart);

                    if (pos1 <= 0 || pos2 <= 0) 
                    {
                        printf("Masukkan posisi dengan angka positif!\n");
                        return;
                    }

                    WishlistSwap(wishlist, pos1, pos2);
                } 

                else printf("Posisi harus berupa angka positif! Format: WISHLIST SWAP <posisi1> <posisi2>\n");
            } 
            
            else if (StringCompare(parameter1, "REMOVE") == 0)
            {
                if (remaining[0] == '\0') WishlistRemoveByName(wishlist);

                else if (isAllDigit(remaining)) 
                {
                    int index = atoi(remaining);
                    if (index <= 0) 
                    {
                        printf("Index harus berupa angka positif!\n");
                        return;
                    }

                    WishlistRemoveByIndex(wishlist, index);
                } 

                else printf("Index harus berupa angka! Format: WISHLIST REMOVE <index>\n");
            }

            else if (StringCompare(parameter1, "CLEAR") == 0) WishlistClear(wishlist);

            else if (StringCompare(parameter1, "SHOW") == 0) WishlistShow(*wishlist);
            
            else printf("Masukkan command yang benar!\n");
        }

        else if (StringCompare(mainMenuCommand, "HISTORY") == 0) 
        {
            if (parameter1[0] == '\0') printf("Perintah HISTORY membutuhkan angka. Contoh: HISTORY 6\n");
            else if (isAllDigit(parameter1)) 
            {
                int N = atoi(parameter1);
                if (N > 0) History(*historystack, N);
                else printf("Masukkan angka positif setelah HISTORY.\n");
            }

            else printf("Parameter1 setelah HISTORY harus berupa angka!\n");
        }
        
        else if (StringCompare(mainMenuCommand, "EXIT") == 0)
        {
            char saveCurrentChange[1];
            printf("\nApakah Anda ingin menyimpan perubahan pada file ini? (Y/N) : ");
            STARTWORD();
            WordToString(currentWord, saveCurrentChange);
            Upperstring(saveCurrentChange);
            if (StringCompare(saveCurrentChange, "Y") == 0)
            {
                Word filenameWord;
                printf("Masukkan nama file untuk menyimpan: ");
                STARTWORD();
                handleSaveOnExit(*itemlist, *userlist, filenameWord);
                thankYouLetter();
                exit(0);
            }

            else if (StringCompare(saveCurrentChange, "N") == 0)
            {
                thankYouLetter();
                exit(0);
            }

            else printf("Masukkan input yang benar!");
        }

        else if (StringCompare(mainMenuCommand, "BACK") == 0 || StringCompare(mainMenuCommand, "<<<") == 0)
        {
            *returnToLogin = true;
            mainMenuActive = false;
        }

        else if (StringCompare(mainMenuCommand, "BIOWEAPON") == 0) bioweapon();

        else printf("Command tidak dikenali. Silakan coba lagi.\n");  
    }
}

void handleSaveOnExit(ListofItems itemlist, ListofUsers userlist, Word filenameWord) 
{
    char *filename = wordToString(filenameWord);

    int length = stringLength(filename);
    boolean valid = true;

    if (length < 4 || filename[length - 4] != '.' || filename[length - 3] != 't' || 
        filename[length - 2] != 'x' || filename[length - 1] != 't') valid = false;
    
    if (valid) 
    {
        Save(filename, itemlist, userlist);
        printf("Program telah berhasil disimpan ke dalam file '%s'.\n", filename);
    } 
    else printf("Mohon masukkan nama file yang berakhiran dengan .txt\n");

    free(filename); // Bebaskan memori setelah selesai
}

// Fungsi untuk menangani menu START
void mainstartmenu(ListofItems *itemlist, ListofUsers *userlist) 
{
    clearterminal();
    printf("\n");
    printf("     _______.___________.    ___      .______     .___________.   .___  ___.  _______ .__   __.  __    __  \n");
    printf("    /       |           |   /   \\     |   _  \\    |           |   |   \\/   | |   ____||  \\ |  | |  |  |  | \n");
    printf("   |   (----`---|  |----`  /  ^  \\    |  |_)  |   `---|  |----`   |  \\  /  | |  |__   |   \\|  | |  |  |  | \n");
    printf("    \\   \\       |  |      /  /_\\  \\   |      /        |  |        |  |\\/|  | |   __|  |  . `  | |  |  |  | \n");
    printf(".----)   |      |  |     /  _____  \\  |  |\\  \\----.   |  |        |  |  |  | |  |____ |  |\\   | |  `--'  | \n");
    printf("|_______/       |__|    /__/     \\__\\ | _| `._____|   |__|        |__|  |__| |_______||__| \\__|  \\______/  \n");
    printf("                                                                                                            \n");
    printf("\n");
    Load("default_config.txt", itemlist, userlist); // Membaca file konfigurasi default
    printf("File konfigurasi default berhasil dimuat.\n");
}

// Fungsi untuk menangani menu LOAD
boolean mainloadmenu(char *filename, ListofItems *itemlist, ListofUsers *userlist) {
    clearterminal();
    printf("\n");
    printf(" __        ______        ___       _______     .___  ___.  _______ .__   __.  __    __  \n");
    printf("|  |      /  __  \\      /   \\     |       \\    |   \\/   | |   ____||  \\ |  | |  |  |  | \n");
    printf("|  |     |  |  |  |    /  ^  \\    |  .--.  |   |  \\  /  | |  |__   |   \\|  | |  |  |  | \n");
    printf("|  |     |  |  |  |   /  /_\\  \\   |  |  |  |   |  |\\/|  | |   __|  |  . `  | |  |  |  | \n");
    printf("|  `----.|  `--'  |  /  _____  \\  |  '--'  |   |  |  |  | |  |____ |  |\\   | |  `--'  | \n");
    printf("|_______| \\______/  /__/     \\__\\ |_______/    |__|  |__| |_______||__| \\__|  \\______/  \n");
    printf("                                                                                         \n");
    printf("\n");
    boolean success;
    STARTFILE(filename, &success);
    if (success) {
        Load(filename, itemlist, userlist);
        printf("File %s berhasil dimuat.\n", filename);
    } else {
        printf("File %s tidak ditemukan.\n", filename);
    }
    return success;
}

// Konversi Word menjadi integer
int WordtoInteger(Word word) 
{
    int sum = 0;
    for (int i = 0; i < word.Length; i++) 
    {
        // Validasi jika karakter bukan angka
        if (word.TabWord[i] < '0' || word.TabWord[i] > '9') 
        {
            // printf("ERROR: Invalid number format in Word at character '%c'\n", word.TabWord[i]);
            return -1; // Kembalikan -1 jika ada karakter bukan angka
        }
        sum = sum * 10 + (word.TabWord[i] - '0');
    }
    return sum;
}

int StringCompare(const char *str1, const char *str2) 
{
    // Iterasi melalui kedua string
    while (*str1 && *str2) 
    {
        if (*str1 != *str2) 
        {
            // Jika karakter tidak cocok, kembalikan perbedaan nilai ASCII
            return (unsigned char)*str1 - (unsigned char)*str2;
        }
        str1++;
        str2++;
    }
    // Jika salah satu string berakhir, kembalikan perbedaan panjang
    return *str1 - *str2;
} 

// Ubah string menjadi uppercase
void Upperstring(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32; // Ubah huruf kecil menjadi huruf besar
        }
    }
}

void WordToString(Word word, char *str) 
{
    for (int i = 0; i < word.Length; i++) 
    {
        str[i] = word.TabWord[i];
    }
    str[word.Length] = '\0'; // Tambahkan null terminator
}

// Salin string source ke destination
void StringCopy(char *destination, const char *source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

void InputLogin(char *username, char *password) {
    clearterminal();
    artLogin();
    printf("Masukkan username: ");
    STARTWORD();
    WordToString(currentWord, username);
    // printf("DEBUG: Username yang dimasukkan: %s\n", username);

    printf("Masukkan password: ");
    STARTWORD();
    WordToString(currentWord, password);
    // printf("DEBUG: Password yang dimasukkan: %s\n", password);
}

boolean LoginUser(ListofUsers userlist, int *currentUserIndex) {
    char username[100], password[100];
    InputLogin(username, password);

    // printf("DEBUG: Username yang diinputkan: '%s', Password yang diinputkan: '%s'\n", username, password);

    for (int i = 0; i < NbElmt(userlist); i++) {
        User user = GetElmt(userlist, i);

        // printf("DEBUG: Username dari file: '%s', Password dari file: '%s'\n", user.name, user.password);

        if (StringCompare(username, user.name) == 0 && StringCompare(password, user.password) == 0) {
            *currentUserIndex = i;
            printf("Login berhasil sebagai %s dengan uang %d.\n\n", user.name, user.money);
            return true;
        }
    }

    printf("Login gagal. Username atau password salah.\n");
    return false;
}

// Fungsi untuk register
void RegisterUser(ListofUsers *userlist) {
    clearterminal();
    artRegister();
    char username[100], password[100];

    printf("Masukkan username baru: ");
    STARTWORD();
    WordToString(currentWord, username);

    if (currentWord.Length == 0) {
        printf("Username tidak boleh kosong.\n");
        return;
    }

    printf("Masukkan password baru: ");
    STARTWORD();
    WordToString(currentWord, password);

    if (currentWord.Length == 0) {
        printf("Password tidak boleh kosong.\n");
        return;
    }

    for (int i = 0; i < NbElmt(*userlist); i++) {
        if (StringCompare(username, GetElmt(*userlist, i).name) == 0) {
            printf("Username sudah ada, silakan gunakan username lain.\n");
            return;
        }
    }

    User newUser;
    newUser.money = 1000; // Uang awal
    StringCopy(newUser.name, username);
    StringCopy(newUser.password, password);
    InsertLastUser(userlist, newUser);

    printf("Pendaftaran berhasil untuk username: %s\n", username);
}

void Load(char *filename, ListofItems *itemlist, ListofUsers *userlist) {
    boolean success;
    STARTFILE(filename, &success);
    if (!success) {
        printf("ERROR: Failed to open file %s\n", filename);
        return;
    }

    // Baca jumlah items
    CopyWord();
    // printf("DEBUG: Word read for items = ");
    // printw(currentWord, true);

    int itemCount = WordtoInteger(currentWord);
    if (itemCount < 0) {
        // printf("ERROR: Invalid item count\n");
        return;
    }
    // printf("DEBUG: Total items = %d\n", itemCount);

    // Parsing items
    for (int i = 0; i < itemCount; i++) {
        ADV(); // Pindah ke baris berikutnya

        // Baca harga item
        ADVWORD();
        int price = WordtoInteger(currentWord);
        if (price < 0) {
            printf("ERROR: Invalid price format at item %d\n", i + 1);
            continue;
        }

        // Baca nama item (bisa memiliki spasi)
        ADVWORD();
        char itemName[100];
        int nameLength = 0; // Panjang nama item yang akan ditulis
        for (int j = 0; j < currentWord.Length; j++) {
            itemName[nameLength++] = currentWord.TabWord[j];
        }

        while (!EOP && currentChar != '\n') { // Proses nama hingga akhir baris
            itemName[nameLength++] = ' '; // Tambahkan spasi
            ADVWORD();
            for (int j = 0; j < currentWord.Length; j++) {
                itemName[nameLength++] = currentWord.TabWord[j];
            }
        }
        itemName[nameLength] = '\0'; // Tambahkan null terminator

        // printf("DEBUG: Loaded item %d: name = %s, price = %d\n", i + 1, itemName, price);

        // Tambahkan item ke list
        Item newItem;
        newItem.price = price;
        StringCopy(newItem.name, itemName);
        InsertItemAt(itemlist, newItem, i);
    }

    // Baca jumlah users
    ADV();
    CopyWord();
    // printf("DEBUG: Word read for users = ");
    // printw(currentWord, true);

    int userCount = WordtoInteger(currentWord);
    if (userCount < 0) {
        // printf("ERROR: Invalid user count\n");
        return;
    }
    // printf("DEBUG: Total users = %d\n", userCount);

    // Parsing users
    for (int i = 0; i < userCount; i++) {
        ADV(); // Pindah ke baris berikutnya

        if (EOP) {
            // printf("DEBUG: EOF reached while parsing user %d\n", i + 1);
            break;
        }
        // Baca uang user
        ADVWORD();
        int money = WordtoInteger(currentWord);
        if (money < 0) {
            // printf("ERROR: Invalid money format for user %d\n", i + 1);
            continue;
        }

        // Baca nama user
        ADVWORD();
        char userName[100];
        WordToString(currentWord, userName);

        // Baca password user
        ADVWORD();
        char password[100];
        WordToString(currentWord, password);

        // printf("DEBUG: Loaded user %d: name = %s, password = %s, money = %d\n",
            // i + 1, userName, password, money);

        // Tambahkan user ke list
        User newUser;
        newUser.money = money;
        StringCopy(newUser.name, userName);
        StringCopy(newUser.password, password);


        // printf("DEBUG: Adding user to list: name = %s, password = %s, money = %d\n",
        // newUser.name, newUser.password, newUser.money);

        // Tambahkan ke list
        InsertLastUser(userlist, newUser);
    }
}

// Fungsi untuk save data
void Save(char *filename, ListofItems itemlist, ListofUsers userlist) 
{
    boolean success;

    // Buka file untuk ditulis menggunakan WRITEFILE
    WRITEFILE(filename, &success);
    if (!success) {
        printf("ERROR: Tidak dapat membuka file %s untuk menyimpan.\n", filename);
        return;
    }

    // Tulis jumlah item ke file
    printInt(LengthListOfItems(itemlist));
    printNewLine();

    // Tulis setiap item
    for (int i = 0; i < LengthListOfItems(itemlist); i++) {
        Item item = GetItem(itemlist, i);
        printInt(item.price); // Tulis harga item
        printBlank();         // Tulis spasi
        int idx = 0;
        while (item.name[idx] != '\0') { // Tulis nama item karakter per karakter
            printChar(item.name[idx]);
            idx++;
        }
        printNewLine(); // Akhiri dengan baris baru
    }

    // Tulis jumlah pengguna ke file
    printInt(NbElmt(userlist));
    printNewLine();

    // Tulis setiap pengguna
    for (int i = 0; i < NbElmt(userlist); i++) {
        User user = GetElmt(userlist, i);
        printInt(user.money); // Tulis uang pengguna
        printBlank();         // Tulis spasi

        int idx = 0;
        while (user.name[idx] != '\0') { // Tulis nama pengguna karakter per karakter
            printChar(user.name[idx]);
            idx++;
        }
        printBlank(); // Tulis spasi antara nama dan password

        idx = 0;
        while (user.password[idx] != '\0') { // Tulis password pengguna karakter per karakter
            printChar(user.password[idx]);
            idx++;
        }
        printNewLine(); // Akhiri dengan baris baru
    }
    
    printf("Data berhasil disimpan ke file saves/%s\n", filename);
}

void performWork(ListofUsers *userlist, int *currentUserIndex) {
    clearterminal();
    artWork();
    printf("\n=== DAFTAR PEKERJAAN ===\n");
    for (int i = 0; i < totalJobs; i++) 
    {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", i + 1, jobList[i].name, jobList[i].income, jobList[i].duration);
    }
    printf("========================\n");

    int choice;
    printf("Masukkan nomor pekerjaan yang dipilih: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > totalJobs) {
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
        return;
    }

    Job selectedJob = jobList[choice - 1];

    time_t startTime = time(NULL); 
    for (int i = 0; i < selectedJob.duration; i++) 
    {
        printf(".");
        fflush(stdout); 
        while (time(NULL) == startTime + i) {
            // Tunggu hingga waktu detik berikutnya
        }
    }

    User *currentUser = &userlist->TI[*currentUserIndex];
    currentUser->money += selectedJob.income;

    printf("\n\nPekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", selectedJob.income);
}

void StoreList(ListofItems itemlist) {
    clearterminal();
    artSList();
    if (itemlist.Neff != 0) {
        printf("\n=========================================\n");
        printf("           DAFTAR BARANG DI TOKO         \n");
        printf("=========================================\n");
        for (int i = 0; i < itemlist.Neff; i++) {
            printf(" %2d. %-30s\n", i + 1, itemlist.A[i].name);
        }
        printf("=========================================\n");
    } else {
        printf("\n=========================================\n");
        printf("          TOKO SAAT INI KOSONG           \n");
        printf("=========================================\n");
    }
}

void StoreRemove(ListofItems *itemlist)
{
    clearterminal();
    artSRmv();
    Word W1, W2;
    int x, y;
    printf("Nama barang yang akan dihapus: ");
    scan("%s", &W1, &W2, &x, &y);

    if (isItemIn(*itemlist, wordToString(W1)))
    {
        int idx = idxOfItem(*itemlist, wordToString(W1));
        DeleteItemAt(itemlist, idx);
        printf("%s telah berhasil dihapus.\n", wordToString(W1));
    }
    else
    {
        printf("Toko tidak menjual %s\n", wordToString(W1));
    }
}

void StoreRequest(ListofItems *itemlist, Queue *q) 
{
    clearterminal();
    artSReq();
    char itemName[100]; 
    printf("Nama barang yang diminta: ");
    STARTLINE(); 
    WordToString(currentWord, itemName); 

    // printf("DEBUG: Input barang adalah '%s'\n", itemName);

    if (isItemIn(*itemlist, itemName)) 
    {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    }

    else if (isIn(*q, itemName)) 
    {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
    }
    // Jika tidak ada, tambahkan ke antrean
    else 
    {
        enqueue(q, itemName);
        printf("Barang %s dah dimasukin di antrian coyy!\n", itemName);
    }
}

void StoreSupply(ListofItems *itemlist, Queue *q) 
{
    clearterminal();
    artSSply();
    if (isEmpty(*q)) 
    {
        printf("Tidak ada barang di antrian untuk diproses.\n");
        return;
    }

    char *barangName = NULL; 
    char supplyResponse[10];     
    int price;

    printf("Apakah kamu ingin menambahkan barang %s? (Terima/Tunda/Tolak) : ", HEAD(*q));
    STARTWORD(); 
    WordToString(currentWord, supplyResponse);
    Upperstring(supplyResponse); 

    if (StringCompare(supplyResponse, "TERIMA") == 0) 
    {
        printf("Harga barang: ");
        STARTWORD(); 
        price = WordtoInteger(currentWord);

        if (price > 0) 
        {
            dequeue(q, &barangName); 
            Item barang;
            StringCopy(barang.name, barangName); 
            barang.price = price;               
            InsertLastItem(itemlist, barang);  
            printf("%s dengan harga %d telah ditambahkan ke toko.\n", barang.name, barang.price);
            free(barangName); 
        } 
        
        else printf("Harga barang harus positif!\n");
    } 
    
    else if (StringCompare(supplyResponse, "TUNDA") == 0) 
    {
        dequeue(q, &barangName); 
        enqueue(q, barangName); 
        printf("%s dikembalikan ke antrian.\n", barangName);
        free(barangName); 
    } 
    
    else if (StringCompare(supplyResponse, "TOLAK") == 0) 
    {
        dequeue(q, &barangName); 
        printf("%s dihapuskan dari antrian.\n", barangName);
        free(barangName); 
    } 
    
    else printf("Masukan tidak valid!\n");
}

void splitNameQuantity(char *input, char *name, int *quantity) 
{
    int i = 0, j = 0;

    while (input[i] != '\0' && (input[i] < '0' || input[i] > '9')) {
        name[j++] = input[i++];
    }
    name[j - 1] = '\0';

    *quantity = atoi(&input[i]);
}

/* Fungsi untuk menampilkan riwayat pembelian */
void History(Stack S, int N) {
    if (IsEmptyStack(S)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }

    printf("Riwayat pembelian barang:\n");

    int count = 0;
    for (int i = Top(S); i >= 0 && count < N; i--) 
    {
        // printf("DEBUG: Stack[%d] = %s\n", i, S.T[i]);
        printf("%d. %s\n", count + 1, S.T[i]);
        count++;
    }

    printf("\n<<< Command mati. Kembali ke main menu\n");
}

void CartPay(Set *keranjang, ListofUsers *userlist, int *currentUserIndex, Stack *historyStack, ListofItems *itemlist) 
{
    if (IsEmptySet(*keranjang)) 
    {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    int totalBiaya = 0;

    for (int i = 0; i < keranjang->Count; i++) {
        char *namaBarang = keranjang->Elements[i].TabWord;
        int kuantitas = keranjang->Elements[i].Length;

        int harga = 0;
        for (int j = 0; j < itemlist->Neff; j++) {
            if (isStringSameIgnoreCase(namaBarang, itemlist->A[j].name)) {
                harga = itemlist->A[j].price;
                break;
            }
        }

        if (harga > 0) totalBiaya += harga * kuantitas;
    }

    ShowCart(keranjang, itemlist);

    printf("Total biaya yang harus dikeluarkan adalah %d. Apakah jadi dibeli? (Ya/Tidak): ", totalBiaya);
    char konfirmasi[10];
    STARTWORD();
    WordToString(currentWord, konfirmasi);
    Upperstring(konfirmasi);

    if (StringCompare(konfirmasi, "YA") == 0) {
        User *currentUser = &userlist->TI[*currentUserIndex];

        if (currentUser->money >= totalBiaya) 
        {
            currentUser->money -= totalBiaya;

            for (int i = 0; i < keranjang->Count; i++) {
                char historyEntry[100] = "";
                char buffer[20];
                char *namaBarang = keranjang->Elements[i].TabWord;

                StringCopy(historyEntry, namaBarang);
                StringCopy(historyEntry + stringLength(historyEntry), "  -  ");
                itoa(totalBiaya, buffer, 10);
                StringCopy(historyEntry + stringLength(historyEntry), buffer);

                char *entry = malloc(stringLength(historyEntry) + 1);
                StringCopy(entry, historyEntry);
                Push(historyStack, entry);
            }

            printf("Pembelian berhasil! Total %d telah dibayar.\n", totalBiaya);
            CreateEmptySet(keranjang);
        }
        
        else printf("Uang kamu hanya %d, tidak cukup untuk membayar %d.\n", currentUser->money, totalBiaya);

    } 
    else if (StringCompare(konfirmasi, "TIDAK") == 0) printf("Pembayaran dibatalkan. Kembali ke menu utama.\n");

    else printf("Input tidak valid! Pembayaran dibatalkan.\n");
}