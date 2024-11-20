#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "console.h"
#include "ADT/boolean.h"
#include "ADT/mesinkarakter/mesinkarakter.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/arrayuser/arrayuser.h"
#include "ADT/arrayitems/arrayitems.h"

// Konversi Word menjadi integer
int WordtoInteger(Word word) {
    int sum = 0;
    for (int i = 0; i < word.Length; i++) {
        sum += (word.TabWord[i] - '0');
        sum *= 10;
    }
    return sum / 10; // Mengembalikan nilai akhir
}

int StringCompare(const char *str1, const char *str2) {
    // Iterasi melalui kedua string
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            // Jika karakter tidak cocok, kembalikan perbedaan nilai ASCII
            return (unsigned char)*str1 - (unsigned char)*str2;
        }
        str1++;
        str2++;
    }

    // Jika salah satu string berakhir, kembalikan perbedaan panjang
    return (unsigned char)*str1 - (unsigned char)*str2;
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
    printf("DEBUG: Username yang dimasukkan: %s\n", username);

    printf("Masukkan password: ");
    STARTWORD();
    WordToString(currentWord, password);
    printf("DEBUG: Password yang dimasukkan: %s\n", password);
}


boolean LoginUser(ListofUsers userlist, int *currentUserIndex) {
    char username[100], password[100];
    InputLogin(username, password);

    // Ubah username dan password input menjadi huruf besar utk perbandingan
    Upperstring(username);
    Upperstring(password);

    for (int i = 0; i < NbElmt(userlist); i++) {
        User user = GetElmt(userlist, i);
        if (StringCompare(username, user.name) == 0 && StringCompare(password, user.password) == 0) {
            *currentUserIndex = i;
            printf("Login berhasil sebagai %s dengan uang %d.\n", user.name, user.money);
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
    CopyWord();

    int iteration = WordtoInteger(currentWord);
    printf("DEBUG: Total items: %d\n", iteration);

    // Load items
    Item item;
    for (int i = 0; i < iteration; i++) {
        ADV();
        ADVWORD();
        item.price = WordtoInteger(currentWord);
        ADVWORD();
        WordToString(currentWord, item.name);
        printf("DEBUG: Loaded item %d: %s, price: %d\n", i + 1, item.name, item.price);
        InsertItemAt(itemlist, item, i);
    }

    ADV();
    CopyWord();
    iteration = WordtoInteger(currentWord);
    printf("DEBUG: Total users: %d\n", iteration);

    // Load users
    User user;
    for (int i = 0; i < iteration; i++) {
        ADV();
        ADVWORD();
        user.money = WordtoInteger(currentWord);

        ADVWORD();
        WordToString(currentWord, user.name);

        ADVWORD();
        WordToString(currentWord, user.password);

        printf("DEBUG: Loaded user %d: %s, password: %s, money: %d\n", i + 1, user.name, user.password, user.money);
        SetEl(userlist, i, user);
    }
}

// Fungsi untuk save data
void Save(char *filename, ListofItems itemlist, ListofUsers userlist) {
    boolean success;
    WRITEFILE(filename, &success);
    printInt(LengthListOfItems(itemlist));

    for (int i = 0; i < LengthListOfItems(itemlist); i++) {
        printNewLine();
        printInt(GetItem(itemlist, i).price);
        printBlank();

        int idx = 0;
        while (GetItem(itemlist, i).name[idx] != '\0') {
            printChar(GetItem(itemlist, i).name[idx]);
            idx++;
        }
    }

    printNewLine();
    printInt(NbElmt(userlist));
    for (int i = 0; i < NbElmt(userlist); i++) {
        printNewLine();
        printInt(GetElmt(userlist, i).money);
        printBlank();

        int idx = 0;
        while (GetElmt(userlist, i).name[idx] != '\0') {
            printChar(GetElmt(userlist, i).name[idx]);
            idx++;
        }

        printBlank();
        idx = 0;
        while (GetElmt(userlist, i).password[idx] != '\0') {
            printChar(GetElmt(userlist, i).password[idx]);
            idx++;
        }
    }
}
