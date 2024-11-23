#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Untuk fungsi time()
#include "console.h"
#include "ADT/boolean.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arrayuser/arrayuser.h"
#include "ADT/arrayitems/arrayitems.h"
#include "games/work.h"
#include "store.h"


void handleStartMenu(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex) 
{
    mainstartmenu(itemlist, userlist);

    boolean loginActive = true;
    char loginMenuCommand[50];

    while (loginActive) 
    {
        loginMenuList();
        printf("\nMASUKKAN COMMAND: ");
        STARTWORD();
        
        int loginMenuIntCommand = WordtoInteger(currentWord);

        if (loginMenuIntCommand >= 1 && loginMenuIntCommand <= 4) 
        {
            switch (loginMenuIntCommand) 
            {
                case 1:
                    RegisterUser(userlist);
                    break;

                case 2:
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
                            mainMenu(itemlist, userlist, currentUserIndex);
                        }
                    }
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
                        handleSaveOnExit(*itemlist, *userlist);
                        thankYouLetter();
                        exit(0);
                    } 
                    
                    else if (StringCompare(saveCurrentChange, "N") == 0) 
                    {
                        thankYouLetter();
                        exit(0);
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
            WordToString(currentWord, loginMenuCommand);
            Upperstring(loginMenuCommand);

            if (StringCompare(loginMenuCommand, "HELP") == 0) 
            {
                loginHelpMenu();
            }

            else if (StringCompare(loginMenuCommand, "REGISTER") == 0) 
            {
                RegisterUser(userlist);
            } 
            
            else if (StringCompare(loginMenuCommand, "LOGIN") == 0) 
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
                        loginActive = false; // pindah ke mainmenu
                        mainMenu(itemlist, userlist, currentUserIndex);
                    }
                }
            }
            
            else if (StringCompare(loginMenuCommand, "EXIT") == 0)
            {
                char saveCurrentChange[1];
                printf("\nApakah Anda ingin menyimpan perubahan pada file ini? (Y/N) : ");
                STARTWORD();
                WordToString(currentWord, saveCurrentChange);
                Upperstring(saveCurrentChange);
                if (StringCompare(saveCurrentChange, "Y") == 0)
                {
                    handleSaveOnExit(*itemlist, *userlist);
                    thankYouLetter();
                    exit(0);
                }

                else if (StringCompare(saveCurrentChange, "N") == 0)
                {
                    thankYouLetter();
                    exit(0);
                }

                else
                {
                    printf("Masukkan input yang benar!");
                }
            } 
            
            else 
            {
                printf("Command tidak dikenali.\n");
            }
        }
    }
}

void handleLoadMenu(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex) 
{
    char filename[50];
    printf("Masukkan nama file yang ingin anda load : ");
    STARTWORD();
    WordToString(currentWord, filename);

    // memeriksa apakah file berhasil diload
    boolean success = mainloadmenu(filename, itemlist, userlist);

    if (!success) 
    {
        // kembali ke main menu.. file tidak ditemukan
        printf("\nKembali ke Welcome Menu.\n");
        welcomeMenuList();
        return;
    }

    boolean loginActive = true;
    char loginMenuCommand[50];

    while (loginActive) 
    {
        loginMenuList();
        printf("\nMASUKKAN COMMAND: ");
        STARTWORD();
        
        int loginMenuIntCommand = WordtoInteger(currentWord);

        if (loginMenuIntCommand >= 1 && loginMenuIntCommand <= 4) 
        {
            switch (loginMenuIntCommand) 
            {
                case 1:
                    RegisterUser(userlist);
                    break;

                case 2:
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
                            mainMenu(itemlist, userlist, currentUserIndex);
                        }
                    }
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
                        handleSaveOnExit(*itemlist, *userlist);
                        
                        exit(0);
                    } 
                    
                    else if (StringCompare(saveCurrentChange, "N") == 0) 
                    {
                        thankYouLetter();
                        exit(0);
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
            WordToString(currentWord, loginMenuCommand);
            Upperstring(loginMenuCommand);

            if (StringCompare(loginMenuCommand, "HELP") == 0) 
            {
                loginHelpMenu();
            }

            else if (StringCompare(loginMenuCommand, "REGISTER") == 0) 
            {
                RegisterUser(userlist);
            } 
            
            else if (StringCompare(loginMenuCommand, "LOGIN") == 0) 
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
                        loginActive = false; // pindah ke mainmenu
                        mainMenu(itemlist, userlist, currentUserIndex);
                    }
                }
            }
            
            else if (StringCompare(loginMenuCommand, "EXIT") == 0)
            {
                char saveCurrentChange[1];
                printf("\nApakah Anda ingin menyimpan perubahan pada file ini? (Y/N) : ");
                STARTWORD();
                WordToString(currentWord, saveCurrentChange);
                Upperstring(saveCurrentChange);
                if (StringCompare(saveCurrentChange, "Y") == 0)
                {
                    handleSaveOnExit(*itemlist, *userlist);
                    thankYouLetter();
                    exit(0);
                }

                else if (StringCompare(saveCurrentChange, "N") == 0)
                {
                    thankYouLetter();
                    exit(0);
                }

                else
                {
                    printf("Masukkan input yang benar!");
                }
            } 
            
            else 
            {
                printf("Command tidak dikenali.\n");
            }
        }
    }
}

void mainMenu(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex) 
{
    boolean mainMenuActive = true;
    char mainMenuCommand[50];

    while (mainMenuActive) 
    {
        mainMenuList();
        printf("\nMASUKKAN COMMAND:  ");
        STARTLINE();

        int mainMenuIntCommand = WordtoInteger(currentWord);

        if (mainMenuIntCommand >= 1 && mainMenuIntCommand <= 10)
        {
            switch (mainMenuIntCommand)
            {
                case 1:
                    performWork(userlist, currentUserIndex);
                    break;

                case 2:
                    printf("WORK CHALLENGE...\n");
                    break;

                case 3:
                    StoreList(*itemlist);
                    break;

                case 4:
                    printf("STORE REQUEST...\n");
                    break;

                case 5:
                    printf("STORE SUPPLY...\n");
                    break;

                case 6:
                    StoreRemove(itemlist);
                    break;

                case 7:
                {
                    printf("Anda telah logout.\n");
                    *currentUserIndex = -1; // Set status menjadi tidak ada pengguna yang login
                    mainMenuActive = false; // Kembali ke Login Menu
                    break;
                } 

                case 8:
                    handleSaveOnExit(*itemlist, *userlist);
                    break;

                case 9:
                {
                    char saveCurrentChange[1];
                    printf("\nApakah Anda ingin menyimpan perubahan pada file ini? (Y/N) : ");
                    STARTWORD();
                    WordToString(currentWord, saveCurrentChange);
                    Upperstring(saveCurrentChange);
                    if (StringCompare(saveCurrentChange, "Y") == 0)
                    {
                        handleSaveOnExit(*itemlist, *userlist);
                        thankYouLetter();
                        exit(0);
                    }

                    else if (StringCompare(saveCurrentChange, "N") == 0)
                    {
                        thankYouLetter();
                        exit(0);
                    }

                    else
                    {
                        printf("Masukkan input yang benar!");
                    }
                    break;
                }

                case 10:
                    mainHelpMenu();
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

            if (StringCompare(mainMenuCommand, "HELP") == 0) 
            {
                mainHelpMenu();
            } 

            else if (StringCompare(mainMenuCommand, "WORK") == 0) 
            {
                performWork(userlist, currentUserIndex);
            } 

            else if (StringCompare(mainMenuCommand, "WORK CHALLENGE") == 0) 
            {
                printf("Anda telah memilih WORK CHALLENGE. Lakukan pekerjaan...\n");
                // WORK CHALLENGE
            } 
            
            else if (StringCompare(mainMenuCommand, "STORE LIST") == 0) 
            {
                StoreList(*itemlist);
            } 
            
            else if (StringCompare(mainMenuCommand, "STORE REQUEST") == 0) 
            {
                printf("Menampilkan daftar barang di toko...\n");
                // STORE LIST
            } 
            
            else if (StringCompare(mainMenuCommand, "STORE SUPPLY") == 0) 
            {
                printf("Menampilkan daftar barang di toko...\n");
                // STORE LIST
            } 

            else if (StringCompare(mainMenuCommand, "STORE REMOVE") == 0) 
            {
                StoreRemove(itemlist);
            }
            
            else if (StringCompare(mainMenuCommand, "LOGOUT") == 0) 
            {
                printf("Anda telah logout.\n");
                *currentUserIndex = -1; // Set status menjadi tidak ada pengguna yang login
                mainMenuActive = false; // Kembali ke Login Menu
            } 

            else if (StringCompare(mainMenuCommand, "SAVE") == 0) 
            {
                handleSaveOnExit(*itemlist, *userlist);
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
                    handleSaveOnExit(*itemlist, *userlist);
                    thankYouLetter();
                    exit(0);
                }

                else if (StringCompare(saveCurrentChange, "N") == 0)
                {
                    thankYouLetter();
                    exit(0);
                }

                else
                {
                    printf("Masukkan input yang benar!");
                }
            }  
            
            else 
            {
                printf("Command tidak dikenali. Silakan coba lagi.\n");
            }
        }
    }
}

void handleSaveOnExit(ListofItems itemlist, ListofUsers userlist) 
{
    char saveFileName[50];

    // Meminta input nama file save
    printf("Masukkan nama file untuk menyimpan state (contoh: savefile.txt): ");
    STARTWORD();
    WordToString(currentWord, saveFileName);

    // Menyimpan data ke file
    Save(saveFileName, itemlist, userlist);
    printf("Program telah berhasil disimpan ke dalam file '%s'.\n", saveFileName);
}

void thankYouLetter()
{
    printf("  _______  _    _            _   _  _  __ __     __ ____   _    _                       \n");
    printf(" |__   __|| |  | |    /\\    | \\ | || |/ / \\ \\   / // __ \\ | |  | |                      \n");
    printf("    | |   | |__| |   /  \\   |  \\| || ' /   \\ \\_/ /| |  | || |  | |                      \n");
    printf("    | |   |  __  |  / /\\ \\  | . ` ||  <     \\   / | |  | || |  | |                      \n");
    printf("    | |   | |  | | / ____ \\ | |\\  || . \\     | |  | |__| || |__| |                      \n");
    printf("    |_|   |_|  |_|/_/    \\_\\|_| \\_||_|\\_\\    |_|   \\____/  \\____/                       \n");
    printf("                                                                                        \n");
    printf("                                                                                        \n");
    printf("  ______  ____   _____      _____  _    _   ____    ____    _____  _____  _   _   _____ \n");
    printf(" |  ____|/ __ \\ |  __ \\    / ____|| |  | | / __ \\  / __ \\  / ____||_   _|| \\ | | / ____|\n");
    printf(" | |__  | |  | || |__) |  | |     | |__| || |  | || |  | || (___    | |  |  \\| || |  __ \n");
    printf(" |  __| | |  | ||  _  /   | |     |  __  || |  | || |  | | \\___ \\   | |  | . ` || | |_ |\n");
    printf(" | |    | |__| || | \\ \\   | |____ | |  | || |__| || |__| | ____) | _| |_ | |\\  || |__| |\n");
    printf(" |_|     \\____/ |_|  \\_\\   \\_____||_|  |_| \\____/  \\____/ |_____/ |_____||_| \\_| \\_____|\n");
    printf("                                                                                        \n");
    printf("                                                                                        \n");
    printf("  _____   _    _  _____   _____   __  __            _____  _______                      \n");
    printf(" |  __ \\ | |  | ||  __ \\ |  __ \\ |  \\/  |    /\\    |  __ \\|__   __|                     \n");
    printf(" | |__) || |  | || |__) || |__) || \\  / |   /  \\   | |__) |  | |                        \n");
    printf(" |  ___/ | |  | ||  _  / |  _  / | |\\/| |  / /\\ \\  |  _  /   | |                        \n");
    printf(" | |     | |__| || | \\ \\ | | \\ \\ | |  | | / ____ \\ | | \\ \\   | |                        \n");
    printf(" |_|      \\____/ |_|  \\_\\|_|  \\_\\|_|  |_|/_/    \\_\\|_|  \\_\\  |_|                        \n");
    printf("                                                                                        \n");
    printf("                                                                                        \n");
}
void welcomeMenuList()
{
    printf("\n=========================================\n");
    printf("               WELCOME MENU                \n");
    printf("=========================================\n");
    printf(" 1. START\n");
    printf(" 2. LOAD\n");
    printf(" 3. EXIT\n");
    printf(" 4. HELP\n");
    printf("=========================================\n");
}

// Menampilkan welcome help menu
void welcomeHelpMenu() 
{
    printf("\n\n");
    printf("=====[ Welcome Help Menu PURRMART ]=====\n");
    printf("START -> Untuk masuk sesi baru\n");
    printf("LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf("EXIT -> Untuk keluar dari program\n\n");
}

// Menampilkan login help menu
void loginHelpMenu() {
    printf("\n\n");
    printf("=====[ Login Help Menu PURRMART ]=====\n");
    printf("REGISTER -> Untuk melakukan pendaftaran akun baru\n");
    printf("LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
    printf("EXIT -> Untuk keluar dari program\n\n");
}

void loginMenuList() {
    printf("\n=========================================\n");
    printf("               LOGIN MENU                \n");
    printf("=========================================\n");
    printf(" 1. REGISTER\n");
    printf(" 2. LOGIN\n");
    printf(" 3. EXIT\n");
    printf(" 4. HELP\n");
    printf("=========================================\n");
}

// Menampilkan main menu
void mainHelpMenu() {
    printf("\n\n");
    printf("=====[ Main Help Menu PURRMART ]=====\n");
    printf("WORK -> Untuk bekerja\n");
    printf("WORK CHALLENGE -> Untuk mengerjakan challenge\n");
    printf("STORE LIST -> Untuk melihat barang-barang di toko\n");
    printf("STORE REQUEST -> Untuk meminta penambahan barang\n");
    printf("STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
    printf("STORE REMOVE -> Untuk menghapus barang\n");
    printf("LOGOUT -> Untuk keluar dari sesi\n");
    printf("SAVE -> Untuk menyimpan state ke dalam file\n");
    printf("EXIT -> Untuk keluar dari program\n\n");
}

// Menampilkan main menu
void mainMenuList() {
    printf("\n=========================================\n");
    printf("               MAIN MENU                 \n");
    printf("=========================================\n");
    printf(" 1. WORK\n");
    printf(" 2. WORK CHALLENGE\n");
    printf(" 3. STORE LIST\n");
    printf(" 4. STORE REQUEST\n");
    printf(" 5. STORE SUPPLY\n");
    printf(" 6. STORE REMOVE\n");
    printf(" 7. LOGOUT\n");
    printf(" 8. SAVE\n");
    printf(" 9. EXIT\n");
    printf("10. HELP\n");
    printf("=========================================\n");
}

// Fungsi untuk menangani menu START
void mainstartmenu(ListofItems *itemlist, ListofUsers *userlist) 
{
    printf("\n\n");
    printf("===== START MENU =====\n");
    Load("default_config.txt", itemlist, userlist); // Membaca file konfigurasi default
    printf("File konfigurasi default berhasil dimuat.\n");
}

// Fungsi untuk menangani menu LOAD
boolean mainloadmenu(char *filename, ListofItems *itemlist, ListofUsers *userlist) {
    printf("\n\n");
    printf("===== LOAD MENU =====\n");
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

// Fungsi untuk logout
void LogoutUser(int *currentUserIndex) {
    if (*currentUserIndex == -1) {
        printf("Tidak ada pengguna yang sedang login.\n");
    } else {
        printf("Logout berhasil.\n");
        *currentUserIndex = -1;
    }
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
void Save(char *filename, ListofItems itemlist, ListofUsers userlist) {
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
    if (*currentUserIndex == -1) {
        printf("Tidak ada pengguna yang sedang login. Silakan login terlebih dahulu.\n");
        return;
    }

    // Tampilkan daftar pekerjaan
    printf("\n=== DAFTAR PEKERJAAN ===\n");
    for (int i = 0; i < totalJobs; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", 
            i + 1, jobList[i].name, jobList[i].income, jobList[i].duration);
    }
    printf("========================\n");

    // Input pilihan pekerjaan
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

    // Update uang pengguna
    User *currentUser = &userlist->TI[*currentUserIndex];
    currentUser->money += selectedJob.income;

    printf("\n\nPekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", selectedJob.income);
}

void StoreList(ListofItems itemlist) {
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

// void StoreRequest()

void StoreRemove(ListofItems *itemlist)
{
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

