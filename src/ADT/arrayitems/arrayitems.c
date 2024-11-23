#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "arrayitems.h"
#include "../mesinkata/mesinkata.h"
#include "../../console.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ListofItems kosong dengan ukuran InitialSize
 */
ListofItems MakeListOfItems() {
    ListofItems array;
    array.A = (Item *) malloc(InitialSize * sizeof(Item));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

void DeallocateListOfItems(ListofItems *array) {
    free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsItemsEmpty(ListofItems array) {
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthListOfItems(ListofItems array) {
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Item GetItem(ListofItems array, int i) {
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetItemCapacity(ListofItems array) {
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 * Jika array penuh, maka array akan diperbesar sebanyak InitialSize.
 */
void InsertItemAt(ListofItems *array, Item el, int i) {
    int length = LengthListOfItems(*array);
    int capacity = GetItemCapacity(*array);

    if (length == capacity) {
        int desiredCapacity = capacity + InitialSize;
        Item *arr = (Item *) malloc(desiredCapacity * sizeof(Item));
        for (int a = 0; a < length; a++) {
            arr[a] = GetItem(*array, a);
        }
        free(array->A);
        
        array->A = arr;
        array->Capacity = desiredCapacity;
    }

    for (int a = length - 1; a >= i; a--) {
        array->A[a + 1] = array->A[a];
    }

    array->A[i] = el;
    array->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLastItem(ListofItems *array, Item el) {
    int insertAt = LengthListOfItems(*array);
    InsertItemAt(array, el, insertAt);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirstItem(ListofItems *array, Item el) {
    InsertItemAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteItemAt(ListofItems *array, int i) {
    int length = LengthListOfItems(*array);
    for (int a = i; a < length - 1; a++) {
        array->A[a] = array->A[a + 1];
    }
    array->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ListofItems
 * Prekondisi: array tidak kosong
 */
void DeleteLastItem(ListofItems *array) {
    int deleteAt = LengthListOfItems(*array) - 1;
    DeleteItemAt(array, deleteAt);
}

/**
 * Fungsi untuk menghapus elemen pertama ListofItems
 * Prekondisi: array tidak kosong
 */
void DeleteFirstItem(ListofItems *array) {
    DeleteItemAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ListofItems.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
// void PrintArrayDin(ListofItems array) {
//     if (IsEmpty(array)) {
//         printf("[]\n");
//     } else {
//         printf("[");
//         for (int i = 0; i < array.Neff; i++) {
//             printf("%d", array.A[i]);
//             if (i < array.Neff - 1) {
//                 printf(", ");
//             }
//         }
//         printf("]\n");
//     }
// }

/**
 * Fungsi untuk melakukan reverse suatu ListofItems.
 * Prekondisi: array terdefinisi
 */
void ReverseListOfItems(ListofItems *array) {
    int length = LengthListOfItems(*array);
    for (int i = 0; i < length / 2; i++) {
        Item temp = array->A[i];
        array->A[i] = array->A[length - i - 1];
        array->A[length - i - 1] = temp;
    }
}

/**
 * Fungsi untuk melakukan copy suatu ListofItems.
 * Prekondisi: array terdefinisi
 */
ListofItems CopyListOfItems(ListofItems array) {
    ListofItems copy = MakeListOfItems();
    for (int i = 0; i < array.Neff; i++) {
        InsertLastItem(&copy, array.A[i]);
    }
    return copy;
}


/**
 * Fungsi untuk melakukan search suatu ListofItems.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
// int SearchArrayDin(ListofItems array, Item el) {
//     for (int i = 0; i < array.Neff; i++) {
//         if (array.A[i] == el) {
//             return i;
//         }
//     }
//     return -1;
// }

boolean isItemIn(ListofItems items, char *name)
{
    boolean found = false;
    int i = 0;
    while (!found && i != items.Neff)
    {
        if (StringCompare(name, items.A[i].name) == 0)
        {
            printf("!!!!DEBUG: Membandingkan '%s' dengan '%s'\n", name, items.A[i].name);
            found = true;
        }
        i++;
    }
    return found;
}

int idxOfItem(ListofItems items, char *name)
{
    boolean found = false;
    int i = 0;
    while (!found && i != items.Neff)
    {
        if (isStringSame(name, items.A[i].name))
        {
            found = true;
        }
        else
            i++;
    }
    return i;
}
