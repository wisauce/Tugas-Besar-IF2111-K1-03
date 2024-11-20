#include <stdlib.h>
#include "arrayitems.h"
#include "../mesinkata/mesinkata.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ListofItems kosong dengan ukuran InitialSize
 */
ListofItems MakeArrayDin()
{
    ListofItems array;
    array.A = (Item *)malloc(InitialSize * sizeof(Item));
    array.Capacity = InitialSize;
    array.Neff = 0;
    return array;
}

void DeallocateArrayDin(ListofItems *array)
{
    free(array->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsItemsEmpty(ListofItems array)
{
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ListofItems array)
{
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Item Get(ListofItems array, int i)
{
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ListofItems array)
{
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 * Jika array penuh, maka array akan diperbesar sebanyak InitialSize.
 */
void InsertAt(ListofItems *array, Item el, int i)
{
    int length = Length(*array);
    int capacity = GetCapacity(*array);

    if (length == capacity)
    {
        int desiredCapacity = capacity + InitialSize;
        Item *arr = (Item *)malloc(desiredCapacity * sizeof(Item));
        for (int a = 0; a < length; a++)
        {
            arr[a] = Get(*array, a);
        }
        free(array->A);

        array->A = arr;
        array->Capacity = desiredCapacity;
    }

    for (int a = length - 1; a >= i; a--)
    {
        array->A[a + 1] = array->A[a];
    }

    array->A[i] = el;
    array->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ListofItems *array, Item el)
{
    int insertAt = Length(*array);
    InsertAt(array, el, insertAt);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ListofItems *array, Item el)
{
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ListofItems *array, int i)
{
    int length = Length(*array);
    for (int a = i; a < length - 1; a++)
    {
        array->A[a] = array->A[a + 1];
    }
    array->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ListofItems
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ListofItems *array)
{
    int deleteAt = Length(*array) - 1;
    DeleteAt(array, deleteAt);
}

/**
 * Fungsi untuk menghapus elemen pertama ListofItems
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ListofItems *array)
{
    DeleteAt(array, 0);
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
void ReverseArrayDin(ListofItems *array)
{
    int length = Length(*array);
    for (int i = 0; i < length / 2; i++)
    {
        Item temp = array->A[i];
        array->A[i] = array->A[length - i - 1];
        array->A[length - i - 1] = temp;
    }
}

/**
 * Fungsi untuk melakukan copy suatu ListofItems.
 * Prekondisi: array terdefinisi
 */
ListofItems CopyArrayDin(ListofItems array)
{
    ListofItems copy = MakeArrayDin();
    for (int i = 0; i < array.Neff; i++)
    {
        InsertLast(&copy, array.A[i]);
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
        if (isStringSame(name, items.A[i].name))
        {
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