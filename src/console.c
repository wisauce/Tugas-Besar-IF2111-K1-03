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
        // Validasi jika karakter bukan angka
        if (word.TabWord[i] < '0' || word.TabWord[i] > '9') {
            printf("ERROR: Invalid number format in Word at character '%c'\n", word.TabWord[i]);
            return -1; // Kembalikan -1 jika ada karakter bukan angka
        }
        sum = sum * 10 + (word.TabWord[i] - '0');
    }
    return sum;
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
    printf("DEBUG: Username yang dimasukkan: %s\n", username);

    printf("Masukkan password: ");
    STARTWORD();
    WordToString(currentWord, password);
    printf("DEBUG: Password yang dimasukkan: %s\n", password);
}


boolean LoginUser(ListofUsers userlist, int *currentUserIndex) {
    char username[100], password[100];
    InputLogin(username, password);

    printf("DEBUG: Username yang diinputkan: '%s', Password yang diinputkan: '%s'\n", username, password);

    for (int i = 0; i < NbElmt(userlist); i++) {
        User user = GetElmt(userlist, i);

        printf("DEBUG: Username dari file: '%s', Password dari file: '%s'\n", user.name, user.password);

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
    printf("DEBUG: Word read for items = ");
    printw(currentWord, true);

    int itemCount = WordtoInteger(currentWord);
    if (itemCount < 0) {
        printf("ERROR: Invalid item count\n");
        return;
    }
    printf("DEBUG: Total items = %d\n", itemCount);

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

        printf("DEBUG: Loaded item %d: name = %s, price = %d\n", i + 1, itemName, price);

        // Tambahkan item ke list
        Item newItem;
        newItem.price = price;
        StringCopy(newItem.name, itemName);
        InsertItemAt(itemlist, newItem, i);
    }

    // Baca jumlah users
    ADV();
    CopyWord();
    printf("DEBUG: Word read for users = ");
    printw(currentWord, true);

    int userCount = WordtoInteger(currentWord);
    if (userCount < 0) {
        printf("ERROR: Invalid user count\n");
        return;
    }
    printf("DEBUG: Total users = %d\n", userCount);

    // Parsing users
    for (int i = 0; i < userCount; i++) {
        ADV(); // Pindah ke baris berikutnya

        if (EOP) {
            printf("DEBUG: EOF reached while parsing user %d\n", i + 1);
            break;
        }
        // Baca uang user
        ADVWORD();
        int money = WordtoInteger(currentWord);
        if (money < 0) {
            printf("ERROR: Invalid money format for user %d\n", i + 1);
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

        printf("DEBUG: Loaded user %d: name = %s, password = %s, money = %d\n",
            i + 1, userName, password, money);

        // Tambahkan user ke list
        User newUser;
        newUser.money = money;
        StringCopy(newUser.name, userName);
        StringCopy(newUser.password, password);


        printf("DEBUG: Adding user to list: name = %s, password = %s, money = %d\n",
        newUser.name, newUser.password, newUser.money);

        // Tambahkan ke list
        InsertLastUser(userlist, newUser);
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
