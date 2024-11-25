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
#include "games/quantum_w0rdl3/quantum_w0rdl3.h"

void handleStartMenu(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex, Queue *q, boolean *returnToLogin) 
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
            if (loginMenuIntCommand == 1) RegisterUser(userlist);
            
            else if (loginMenuIntCommand == 2)
            {
                if (*currentUserIndex != -1) 
                {
                    printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", GetElmt(*userlist, *currentUserIndex).name);
                } 

                else if (LoginUser(*userlist, currentUserIndex)) 
                {
                    printf("Selamat datang di PURRMART!\n");
                    loginActive = false;
                    mainMenu(itemlist, userlist, currentUserIndex, q, returnToLogin);

                    if(*returnToLogin) loginActive = true;
                }
            }

            else if (loginMenuIntCommand == 3) 
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
            }

            else if (loginMenuIntCommand == 4) welcomeHelpMenu();

            else printf("Command tidak dikenali. Silakan coba lagi.\n");
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
                        loginActive = false;
                        mainMenu(itemlist, userlist, currentUserIndex, q, returnToLogin);

                        if (*returnToLogin) loginActive = true;
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

void handleLoadMenu(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex, Queue *q, boolean *returnToLogin) 
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
            if (loginMenuIntCommand == 1) RegisterUser(userlist);
            
            else if (loginMenuIntCommand == 2)
            {
                if (*currentUserIndex != -1) 
                {
                    printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", GetElmt(*userlist, *currentUserIndex).name);
                } 

                else if (LoginUser(*userlist, currentUserIndex)) 
                {
                    printf("Selamat datang di PURRMART!\n");
                    loginActive = false;
                    mainMenu(itemlist, userlist, currentUserIndex, q, returnToLogin);

                    if(*returnToLogin) loginActive = true;
                }
            }

            else if (loginMenuIntCommand == 3) 
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
            }

            else if (loginMenuIntCommand == 4) welcomeHelpMenu();

            else printf("Command tidak dikenali. Silakan coba lagi.\n");
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
                        loginActive = false;
                        mainMenu(itemlist, userlist, currentUserIndex, q, returnToLogin);

                        if (*returnToLogin) loginActive = true;
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

void mainMenu(ListofItems *itemlist, ListofUsers *userlist, int *currentUserIndex, Queue *q, boolean *returnToLogin) 
{
    boolean mainMenuActive = true;
    char mainMenuCommand[50];

    while (mainMenuActive) 
    {
        mainMenuList();
        printf("\nMASUKKAN COMMAND:  ");
        STARTLINE();

        int mainMenuIntCommand = WordtoInteger(currentWord);

        if (mainMenuIntCommand >= 1 && mainMenuIntCommand <= 11)
        {
            if (mainMenuIntCommand == 1) performWork(userlist, currentUserIndex);

            else if (mainMenuIntCommand == 2)
            {
                workChallengeList();
                char workChallengeCommand[50];
                printf("\nAPA CHALLENGE YANG HENDAK KAMU MAINKAN: ");
                STARTLINE();

                int workChallengeCommandInt = WordtoInteger(currentWord);

                if (workChallengeCommandInt >=1 && workChallengeCommandInt <= 3)
                {
                    if (workChallengeCommandInt == 1)
                    {
                        tebakAngka(userlist, currentUserIndex);
                    }

                    else if (workChallengeCommandInt == 2)
                    {
                        w0rdl3(userlist, currentUserIndex);
                    }

                    else if (workChallengeCommandInt == 3)
                    {
                        QUANTUMW0RDL3(userlist, currentUserIndex);          
                    }

                    else printf("Masukkan pilihan yang benar!\n");
                }
                
                else
                {
                    WordToString(currentWord, workChallengeCommand);
                    Upperstring(workChallengeCommand);

                    if (StringCompare(workChallengeCommand, "TEBAK ANGKA") == 0)
                    {
                        tebakAngka(userlist, currentUserIndex);
                    }

                    else if (StringCompare(workChallengeCommand, "W0RDL3") == 0)
                    {
                        w0rdl3(userlist, currentUserIndex);
                    }

                    else if (StringCompare(workChallengeCommand, "QUANTUM W0RDL3") == 0)
                    {
                        QUANTUMW0RDL3(userlist, currentUserIndex);
                    }

                    else printf("Masukkan pilihan yang benar!\n");
                }
            }

            else if (mainMenuIntCommand == 3) StoreList(*itemlist);
                    
            else if (mainMenuIntCommand == 4) StoreRequest(itemlist, q);
            
            else if (mainMenuIntCommand == 5) StoreSupply(itemlist, q); 
                    
            else if (mainMenuIntCommand == 6) StoreRemove(itemlist);
                    
            else if (mainMenuIntCommand == 7)
            {
                printf("Anda telah logout.\n");
                *currentUserIndex = -1;
                *returnToLogin = true;
                mainMenuActive = false;
                
            } 

            else if (mainMenuIntCommand == 8) handleSaveOnExit(*itemlist, *userlist);

            else if (mainMenuIntCommand == 9)
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

            else if (mainMenuIntCommand == 10) mainHelpMenu();

            else if (mainMenuIntCommand == 11) 
            {
            
                bioweapon();
            }

            else printf("Command tidak dikenali. Silakan coba lagi.\n");
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
                workChallengeList();
                char workChallengeCommand[50];
                printf("\nAPA CHALLENGE YANG HENDAK KAMU MAINKAN: ");
                STARTLINE();

                int workChallengeCommandInt = WordtoInteger(currentWord);

                if (workChallengeCommandInt >=1 && workChallengeCommandInt <= 3)
                {
                    if (workChallengeCommandInt == 1)
                    {
                    
                        tebakAngka(userlist, currentUserIndex);
                    }

                    else if (workChallengeCommandInt == 2)
                    {
                    
                        w0rdl3(userlist, currentUserIndex);
                    }

                    else if (workChallengeCommandInt == 3)
                    {
                    
                        QUANTUMW0RDL3(userlist, currentUserIndex); 
                    }

                    else printf("Masukkan pilihan yang benar!\n");
                }
                
                else
                {
                    WordToString(currentWord, workChallengeCommand);
                    Upperstring(workChallengeCommand);

                    if (StringCompare(workChallengeCommand, "TEBAK ANGKA") == 0)
                    {
                    
                        tebakAngka(userlist, currentUserIndex);
                    }

                    else if (StringCompare(workChallengeCommand, "W0RDL3") == 0)
                    {
                    
                        w0rdl3(userlist, currentUserIndex);
                    }

                    else if (StringCompare(workChallengeCommand, "QUANTUM W0RDL3") == 0)
                    {
                    
                        QUANTUMW0RDL3(userlist, currentUserIndex);
                    }

                    else printf("Masukkan pilihan yang benar!\n");
                }
            } 
            
            else if (StringCompare(mainMenuCommand, "STORE LIST") == 0) 
            {
                StoreList(*itemlist);
            } 
            
            else if (StringCompare(mainMenuCommand, "STORE REQUEST") == 0) 
            {
                StoreRequest(itemlist, q);
            } 
            
            else if (StringCompare(mainMenuCommand, "STORE SUPPLY") == 0) 
            {
                StoreSupply(itemlist, q);
            } 

            else if (StringCompare(mainMenuCommand, "STORE REMOVE") == 0) 
            {
                StoreRemove(itemlist);
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

            else if (StringCompare(mainMenuCommand, "BACK") == 0 || StringCompare(mainMenuCommand, "<<<") == 0)
            {
                *returnToLogin = true;
                mainMenuActive = false;
            }

            else if (StringCompare(mainMenuCommand, "BIOWEAPON") == 0)
            {
        
                bioweapon();
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
    int idx = currentWord.Length-1;
    boolean valid = true;
    if (currentWord.TabWord[idx] != 't') valid = false;
    else if (currentWord.TabWord[idx-1] != 'x') valid = false;
    else if (currentWord.TabWord[idx-2] != 't') valid = false;
    else if (currentWord.TabWord[idx-3] != '.') valid = false;
    if (valid) {
        WordToString(currentWord, saveFileName);
        // Menyimpan data ke file
        Save(saveFileName, itemlist, userlist);
        printf("Program telah berhasil disimpan ke dalam file '%s'.\n", saveFileName);
    } else {
        printf("Mohon masukkan nama file yang berakhiran dengan .txt");
    }
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
    printf("EXIT -> Untuk keluar dari program\n");
    printf("BACK -> Untuk kembali ke login menu tanpa logout\n");
    printf("BIOWEAPON -> Untuk membuat senjata biologis dengan kode rahasia\n\n");
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
    printf("11. BIOWEAPON\n");
    printf("<<< BACK \n");
    printf("=========================================\n");
}

void workChallengeList() {
    printf("\n=========================================\n");
    printf("           WORK CHALLENGE LIST            \n");
    printf("=========================================\n");
    printf(" 1. TEBAK ANGKA (PLAYING COST = 200)\n");
    printf(" 2. W0RDL3 (PLAYING COST = 500)\n");
    printf(" 3. QUANTUM W0RDL3 (PLAYING COST = 750)\n");
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

void StoreRequest(ListofItems *itemlist, Queue *q) 
{
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
        
        else 
        {
            printf("Harga barang harus positif!\n");
        }

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
    
    else 
    {
        printf("Masukan tidak valid!\n");
    }
}

const char wordBank[W0RDL3_MAX_WORDS][W0RDL3_WORD_LENGTH + 1] = {
    "TRULY", "LEAKY", "LUCKY", "SLICK", "BUILD",
    "HEART", "DANCE", "PAUSE", "CROWN", "BEACH"
};

char upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

boolean compare(const char* str1, const char* str2, int length2) {
    int i;
    for (i = 0; i < length2; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

void wordl3_copy(char* dest, const char* src, int length2) {
    int i;
    for (i = 0; i < length2; i++) {
        dest[i] = src[i];
    }
    dest[length2] = '\0';
}

int length2(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void checkGuess(const char* target, const char* guess, char* result) {
    int target_count[26] = {0};
    boolean matched_exact[W0RDL3_WORD_LENGTH] = {false};
    int i, idx = 0;

    for (i = 0; i < W0RDL3_WORD_LENGTH; i++) {
        if (guess[i] != target[i]) {
            target_count[target[i] - 'A']++;
        } else {
            matched_exact[i] = true;
        }
    }

    for (i = 0; i < QUANTUM_WORD_LENGTH; i++) {
        if (matched_exact[i]) {
            result[idx++] = guess[i];
            result[idx++] = ' ';
        } else if (target_count[guess[i] - 'A'] > 0) {
            result[idx++] = guess[i];
            result[idx++] = '*';
            result[idx++] = ' ';
            target_count[guess[i] - 'A']--;
        } else {
            result[idx++] = guess[i];
            result[idx++] = '%';
            result[idx++] = ' ';
        }
    }

    if (idx > 0 && result[idx - 1] == ' ') {
        idx--;
    }
    result[idx] = '\0';
}

void read(char* buffer) {
    int i = 0;
    START();
    while (!IsEOP() && i < W0RDL3_WORD_LENGTH) {
        buffer[i] = upper(GetCC());
        ADV();
        i++;
    }
    buffer[i] = '\0';

    while (!IsEOP()) {
        ADV();
    }
}

int w0rdl3(ListofUsers *userlist, int *currentUserIndex) {
    srand(time(NULL));
    
    char ans[W0RDL3_WORD_LENGTH + 1];
    char guess[W0RDL3_WORD_LENGTH + 1];
    char results[W0RDL3_MAX_TRIES][W0RDL3_WORD_LENGTH * 3 + 1];
    int tries = 0;
    boolean won = false;
    
    wordl3_copy(ans, wordBank[rand() % W0RDL3_MAX_WORDS], W0RDL3_WORD_LENGTH);
    // printf("DEBUG: Jawaban sebenarnya adalah: %s\n", ans);

    User *currentUser = &userlist->TI[*currentUserIndex];

    if (currentUser->money < 500) 
    {
        printf("Saldo Anda tidak cukup untuk bermain W0RDL3.\n");
        return 0;
    }

    printf("WELCOME TO WORDL3! 500 COINS HAVE BEEN SPENT TO JOIN THIS CHALLENGE. GO FOR THE WIN!");
    currentUser->money -= 500;
    printf("YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n\n");
    for (int i = 0; i < W0RDL3_MAX_TRIES; i++) {
        printf("- - - - -\n");
    }
    
    while (tries < W0RDL3_MAX_TRIES) {
        printf("\nMasukan kata tebakan Anda: ");
        read(guess);
        
        if (length2(guess) != W0RDL3_WORD_LENGTH) {
            printf("Kata harus terdiri dari 5 huruf!\n");
            continue;
        }
        
        printf("Hasil:\n");
        checkGuess(ans, guess, results[tries]);
        
        for (int j = 0; j <= tries; j++) {
            printf("%s\n", results[j]);
        }
        
        for (int j = tries + 1; j < W0RDL3_MAX_TRIES; j++) {
            printf("- - - - -\n");
        }
        
        if (compare(guess, ans, W0RDL3_WORD_LENGTH)) {
            printf("\nSelamat, Anda menang! Anda mendapatkan 3000 coin!\n");
            won = true;
            return 3000;
        }
        
        tries++;
    }
    
    if (!won) {
        printf("\nBoo! Anda kalah.\n");
    }
    return 0;
}

int tebakAngka(ListofUsers *userlist, int *currentUserIndex) {
    srand(time(NULL));
    int r = rand() % 101; 
    int masukan;
    int duit = 500;
    int i = 0;
    User *currentUser = &userlist->TI[*currentUserIndex];
    if (currentUser->money < 200) 
    {
        printf("Saldo Anda tidak cukup untuk bermain Tebak Angka.\n");
        return 0;
    }

    printf("SELAMAT DATANG DI TEBAK ANGKA! BIAYA BERMAIN SEBESAR 200 TELAH DIKURANGI DARI SALDO ANDA! SEMOGA ANDA MENANG!\n");
    currentUser->money -= 200;
    printf("Uji keberuntungan Anda dengan menebak angka!\n");
    printf("Cheat: %d\n", r);
    printf("Tebakan angka: ");

    STARTLINE();  
    masukan = wordtoint(currentWord);  

    while (masukan != r && i < 9) {
        if (masukan < r) {
            printf("Lebih besar\n");
        } else if (masukan > r) {
            printf("Lebih kecil\n");
        }
        i++;
        printf("Tebakan: ");
        
        STARTLINE();  
        masukan = wordtoint(currentWord);
        duit = duit - 50;
    }


    if (duit > 0 && masukan == r) {
        printf("Tebakanmu benar! +");
        currentUser->money += duit;
        printf("%d rupiah telah ditambahkan ke akun anda.\n", duit);
    } else {
        duit = 0;
        printf("Anda tidak beruntung wkwkw. +");
        printf("%d rupiah telah ditambahkan ke akun anda.\n", duit);
    }
    return duit;
}

// int main() {
//     int hasil = tebakAngka();
//     printf("Skor akhir: %d\n", hasil);
//     return 0;
// }

int strLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void copy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

char* DNAtoRNA(const char* dna) {
    int len = strLength(dna);
    char* rna = (char*)malloc((len + 1) * sizeof(char));
    
    for (int i = 0; i < len; i++) {
        if (dna[i] == 'A') {
            rna[i] = 'U';
        } else if (dna[i] == 'T') {
            rna[i] = 'A';
        } else if (dna[i] == 'G') {
            rna[i] = 'C';
        } else if (dna[i] == 'C') {
            rna[i] = 'G';
        } else {
            rna[i] = dna[i];
        }
    }
    rna[len] = '\0';
    return rna;
}

char RNAtoProtein(const char* codon) {
    // First letter (U)
    if (codon[0] == 'U') {
        if (codon[1] == 'U') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'F';
            else return 'L';
        }
        else if (codon[1] == 'C') return 'S';
        else if (codon[1] == 'A') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'Y';
            else return '*';
        }
        else if (codon[1] == 'G') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'C';
            else if (codon[2] == 'G') return 'W';
            else return '*';
        }
    }
    // First letter (C)
    else if (codon[0] == 'C') {
        if (codon[1] == 'U') return 'L';
        else if (codon[1] == 'C') return 'P';
        else if (codon[1] == 'A') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'H';
            else return 'Q';
        }
        else if (codon[1] == 'G') return 'R';
    }
    // First letter (A)
    else if (codon[0] == 'A') {
        if (codon[1] == 'U') {
            if (codon[2] == 'G') return 'M';
            else return 'I';
        }
        else if (codon[1] == 'C') return 'T';
        else if (codon[1] == 'A') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'N';
            else return 'K';
        }
        else if (codon[1] == 'G') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'S';
            else return 'R';
        }
    }
    // First letter (G)
    else if (codon[0] == 'G') {
        if (codon[1] == 'U') return 'V';
        else if (codon[1] == 'C') return 'A';
        else if (codon[1] == 'A') {
            if (codon[2] == 'U' || codon[2] == 'C') return 'D';
            else return 'E';
        }
        else if (codon[1] == 'G') return 'G';
    }
    return 'X';
}

int checkCode(const char* protein_sequence, const char* secret_code) {
    int protein_len = strLength(protein_sequence);
    int code_len = strLength(secret_code);

    for (int i = 0; i <= protein_len - code_len; i++) {
        int match = 1;
        for (int j = 0; j < code_len; j++) {
            if (protein_sequence[i + j] != secret_code[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return 1;
        }
    }
    return 0;
}


void bioweapon() {
    char weapon_name[100];
    char dna_seq[100];
    char secret_code[20];
    
    printf("Masukan nama senjata biologis: ");
    STARTWORD();
    int i = 0;
    while (i < currentWord.Length) {
        weapon_name[i] = currentWord.TabWord[i];
        i++;
    }
    weapon_name[i] = '\0';
    printf("Masukan sekuens DNA: ");
    STARTWORD();
    i = 0;
    while (i < currentWord.Length) {
        dna_seq[i] = currentWord.TabWord[i];
        i++;
    }
    dna_seq[i] = '\0';
    printf("Masukan kode rahasia: ");
    STARTWORD();
    i = 0;
    while (i < currentWord.Length) {
        secret_code[i] = currentWord.TabWord[i];
        i++;
    }
    secret_code[i] = '\0';

    char* rna = DNAtoRNA(dna_seq);

    printf("DEBUG DNA : ");
    for (i = 0; i < strLength(dna_seq); i += 3) {
        if (i + 1 < strLength(dna_seq)) {
            if (i + 2 < strLength(dna_seq)) {
                printf("%c%c%c ", dna_seq[i], dna_seq[i + 1], dna_seq[i + 2]);
            } 
            else {
                printf("%c%c%c ", dna_seq[i], dna_seq[i + 1], ' ');
            }
        } else {
            if (i + 2 < strLength(dna_seq)) {
                printf("%c%c%c ", dna_seq[i], ' ', dna_seq[i + 2]);
            } 
            else {
                printf("%c%c%c ", dna_seq[i], ' ', ' ');
            }
        }
    }
    printf("\n");

    printf("DEBUG RNA : ");
    for (i = 0; i < strLength(rna); i += 3) {
        if (i + 1 < strLength(rna)) {
            if (i + 2 < strLength(rna)) {
                printf("%c%c%c ", rna[i], rna[i + 1], rna[i + 2]);
            } 
            else {
                printf("%c%c%c ", rna[i], rna[i + 1], ' ');
            }
        } 
        else {
            if (i + 2 < strLength(rna)) {
                printf("%c%c%c ", rna[i], ' ', rna[i + 2]);
            } 
            else {
                printf("%c%c%c ", rna[i], ' ', ' ');
            }
        }
    }
    printf("\n");

    int valid = 0;
    for (int frame = 0; frame < 3 && !valid; frame++) {
        char protein_sequence[100] = "";
        int protein_idx = 0;

        printf("DEBUG Protein Sequence (Frame %d): ", frame);
        for (i = frame; i < strLength(rna) - 2; i += 3) {
            char codon[4] = {rna[i], rna[i + 1], rna[i + 2], '\0'};
            char aa = RNAtoProtein(codon);
            if (aa != '*') {
                protein_sequence[protein_idx++] = aa;
            }
            if (aa == '*') break;
        }
        protein_sequence[protein_idx] = '\0';
        printf("%s\n", protein_sequence);

        if (checkCode(protein_sequence, secret_code)) {
            printf("DEBUG: Secret code found in protein sequence: %s\n", protein_sequence);
            valid = 1;
        }
    }

    if (valid) {
        printf("Senjata biologis '%s' mengandung kode, barang akan ditambahkan ke dalam queue!\n", weapon_name);
    } 
    else {
        printf("Kode rahasia tidak ditemukan, maka senjata biologis sudah disabotase, barang ditolak!\n");
    }

    free(rna);
}


const char word_bank[QUANTUM_MAX_WORDS][QUANTUM_WORD_LENGTH + 1] = {
    "TRULY", "LEAKY", "LUCKY", "SLICK", "BUILD",
    "HEART", "DANCE", "PAUSE", "CROWN", "BEACH"
};

char upper2(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

boolean compare2(const char* str1, const char* str2, int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

boolean checkArray(const char* word, const char* word_array[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        if (word_array[i] != NULL && compare2(word, word_array[i], QUANTUM_WORD_LENGTH)) {
            return true;
        }
    }
    return false;
}

void copy2(char* dest, const char* src, int length) {
    int i;
    for (i = 0; i < length; i++) {
        dest[i] = src[i];
    }
    dest[length] = '\0';
}

void checkGuess2(const char* target, const char* guess, char* result) {
    int target_count[26] = {0};
    boolean matched_exact[QUANTUM_WORD_LENGTH] = {false};
    int i, idx = 0;

    for (i = 0; i < QUANTUM_WORD_LENGTH; i++) {
        if (guess[i] != target[i]) {
            target_count[target[i] - 'A']++;
        } else {
            matched_exact[i] = true;
        }
    }

    for (i = 0; i < QUANTUM_WORD_LENGTH; i++) {
        if (matched_exact[i]) {
            result[idx++] = guess[i];
            result[idx++] = ' ';
        } else if (target_count[guess[i] - 'A'] > 0) {
            result[idx++] = guess[i];
            result[idx++] = '*';
            result[idx++] = ' ';
            target_count[guess[i] - 'A']--;
        } else {
            result[idx++] = guess[i];
            result[idx++] = '%';
            result[idx++] = ' ';
        }
    }

    if (idx > 0 && result[idx - 1] == ' ') {
        idx--;
    }
    result[idx] = '\0';
}

boolean read2(char* guess) {
    int count = 0;
    START();
    
    while (!IsEOP() && GetCC() == ' ') {
        ADV();
    }
    
    while (!IsEOP() && GetCC() != ' ' && count < QUANTUM_WORD_LENGTH) {
        guess[count] = upper2(GetCC());
        count++;
        ADV();
    }
    
    while (!IsEOP()) {
        ADV();
    }
    
    if (count != QUANTUM_WORD_LENGTH) {
        printf("Error: Word must be exactly 5 letters!\n");
        return false;
    }
    
    guess[QUANTUM_WORD_LENGTH] = '\0';
    return true;
}

int QUANTUMW0RDL3(ListofUsers *userlist, int *currentUserIndex) 
{
    srand(time(NULL));
    
    char target_words[QUANTUM_TARGET_WORDS][QUANTUM_WORD_LENGTH + 1];
    char current_guess[QUANTUM_WORD_LENGTH + 1];
    char results[QUANTUM_MAX_TRIES][QUANTUM_TARGET_WORDS][QUANTUM_WORD_LENGTH * 3 + 1];
    boolean word_solved[QUANTUM_TARGET_WORDS] = {false};
    int tries = 0;
    int solved_count = 0;
    User *currentUser = &userlist->TI[*currentUserIndex];

    if (currentUser->money < 750) 
    {
        printf("Saldo Anda tidak cukup untuk bermain Quantum W0rdl3.\n");
        return 0;
    }
    
    const char* selected_words[QUANTUM_TARGET_WORDS] = {NULL};
    for (int i = 0; i < QUANTUM_TARGET_WORDS; i++) {
        int idx = rand() % QUANTUM_MAX_WORDS; 
        while (checkArray(word_bank[idx], selected_words, i)) {
            idx = rand() % QUANTUM_MAX_WORDS; 
        }

        
        copy2(target_words[i], word_bank[idx], QUANTUM_WORD_LENGTH);
        selected_words[i] = target_words[i];
    }
    
    // printf("DEBUG: Target words are: %s %s %s %s\n", 
        //    target_words[0], target_words[1], target_words[2], target_words[3]);

    printf(" .-''-.                                                                        \n");
    printf("  //'` `\\|                          _..._                       __  __   ___    \n");
    printf(" '/'    '|                        .'     '.                    |  |/  `.'   `.  \n");
    printf("|'      '|                       .   .-.   .     .|            |   .-.  .-.   ' \n");
    printf("||     /||                 __    |  '   '  |   .' |_           |  |  |  |  |  | \n");
    printf(" \\'. .'/||     _    _   .:--.'.  |  |   |  | .'     |   _    _ |  |  |  |  |  | \n");
    printf("  `--'` ||    | '  / | / |   \\ | |  |   |  |'--.  .-'  | '  / ||  |  |  |  |  | \n");
    printf("        ||   .' | .' | `\" __ | | |  |   |  |   |  |   .' | .' ||  |  |  |  |  | \n");
    printf("        || />/  | /  |  .'.''| | |  |   |  |   |  |   /  | /  ||__|  |__|  |__| \n");
    printf("        ||//|   `'.  | / /   | |_|  |   |  |   |  '.'|   `'.  |                  \n");
    printf("        |'/ '   .'|  '/\\ \\._,\\ '/|  |   |  |   |   / '   .'|  '/                \n");
    printf("        |/   `-'  `--'  `--'  `\" '--'   '--'   `'-'   `-'  `--'                 \n");
    printf("                                    _______      .---...-'''-.                  \n");
    printf("                                    \\  ___ `'.   |   |\\.-''\\ \\                  \n");
    printf("       _     _                       ' |--.\\  \\  |   |       | |                \n");
    printf(" /\\    \\\\   // .-''` ''-.    .-,.--. | |    \\  ' |   |    __/ /                 \n");
    printf(" `\\\\  //\\\\ //.'          '.  |  .-. || |     |  '|   |   |_  '.                 \n");
    printf("   \\`//  \\//              ` | |  | || |     |  ||   |      `.  \\                \n");
    printf("    \\|   |/'                '| |  | || |     ' .'|   |        \\ '.               \n");
    printf("     '     |         .-.    || |  '- | |___.' /' |   |         , |               \n");
    printf("           .        |   |   .| |    /_______.'/  |   |         | |               \n");
    printf("            .       '._.'  / | |    \\_______|/   '---'        / ,'               \n");
    printf("             '._         .'  |_|                      -....--'  /                \n");
    printf("                '-....-'`                             `.. __..-'   \n");

    printf("750 COINS HAVE BEEN SPENT TO JOIN THIS CHALLENGE. GO FOR THE WIN!");
    currentUser->money -= 750;
    
    printf("You need to guess 4 different target words using a single word each try.\n");
    printf("You have 9 chances to guess all words correctly.\n");
    printf("Input format: Enter a single 5-letter word\n\n");
    
    for (int i = 0; i < QUANTUM_MAX_TRIES; i++) {
        //printf("Try %d: ", i + 1);
        for (int j = 0; j < QUANTUM_TARGET_WORDS; j++){
            printf(" - - - - -   ");
        }
        printf("\n");
    }
    
    while (tries < QUANTUM_MAX_TRIES && solved_count < QUANTUM_TARGET_WORDS) {
        printf("\nAttempt %d/%d\n", tries + 1, QUANTUM_MAX_TRIES);
        printf("Enter your guess: ");
        
        if (!read2(current_guess)) {
            continue;
        }
        
        printf("\nResults for '%s':\n\n", current_guess);
        
        for (int i = 0; i < QUANTUM_TARGET_WORDS; i++) {
            if (!word_solved[i]) {
                checkGuess2(target_words[i], current_guess, results[tries][i]);
                if (compare2(current_guess, target_words[i], QUANTUM_WORD_LENGTH)) {
                    word_solved[i] = true;
                    solved_count++;
                }
            } else {
                copy2(results[tries][i], results[tries-1][i], QUANTUM_WORD_LENGTH * 3);
            }
        }
        
        for (int i = 0; i <= tries; i++) {
            printf("Try %d: ", i + 1);
            for (int j = 0; j < QUANTUM_TARGET_WORDS; j++) {
                printf("%s  ", results[i][j]);
            }
            printf("\n");
        }
        
        for (int i = tries + 1; i < QUANTUM_MAX_TRIES; i++) {
            printf("Try %d: ", i + 1);
            for (int j = 0; j < QUANTUM_TARGET_WORDS; j++) {
                printf(" - - - - -   ");
            }
            printf("\n");
        }
        
        //printf("\nStatus:\n");
        //printf("Words solved: %d/4\n", solved_count);
        for (int i = 0; i < QUANTUM_TARGET_WORDS; i++) {
            if (word_solved[i]) {
                printf("Word %d: SOLVED!\n", i + 1);
            } else {
                printf("Word %d: Not solved yet\n", i + 1);
            }

        }
        tries++;
    }
    
    printf("\nGame Over!\n");
    printf("Words solved: %d/4\n", solved_count);
    printf("Attempts used: %d/9\n", tries);
    
    if (solved_count == QUANTUM_TARGET_WORDS) {
        printf("Congratulations! You solved all words! You've earned 15,000 coins as your reward. Enjoy your victory!\n");
        currentUser->money += 15000;
        return 15000;
    } else {
        printf("Better luck next time!\n");
        printf("The target words were: %s %s %s %s\n", 
               target_words[0], target_words[1], target_words[2], target_words[3]);
        return 0;
    }
}

// int main() {
//     int result = quantum();
//     printf("Score: %d\n", result);
//     return 0;
// }
