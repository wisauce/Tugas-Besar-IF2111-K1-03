#ifndef __ARRAY_ITEMS__
#define __ARRAY_ITEMS__

// Boolean
#define boolean unsigned char
#define true 1
#define false 0
#define MAX_ITEM_LEN 100

#define InitialSize 10

typedef struct {
  char name[MAX_ITEM_LEN];
  int price;
} Item;


typedef struct {
    Item *A;
    int Capacity;
    int Neff;
} ListofItems;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ListofItems kosong dengan ukuran InitialSize
 */
ListofItems MakeListOfItems();

/** 
 * Destruktor
 * I.S. ListofItems terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateListOfItems(ListofItems *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsItemsEmpty(ListofItems array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int LengthListOfItems(ListofItems array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Item GetItem(ListofItems array, int i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetItemCapacity(ListofItems array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertItemAt(ListofItems *array, Item el, int i);

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLastItem(ListofItems *array, Item el);

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirstItem(ListofItems *array, Item el);

/**
 * Fungsi untuk menghapus elemen di index ke-i ListofItems
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteItemAt(ListofItems *array, int i);

/**
 * Fungsi untuk menghapus elemen terakhir ListofItems
 * Prekondisi: array tidak kosong
 */
void DeleteLastItem(ListofItems *array);

/**
 * Fungsi untuk menghapus elemen pertama ListofItems
 * Prekondisi: array tidak kosong
 */
void DeleteFirstItem(ListofItems *array);

/**
 * Fungsi untuk melakukan print suatu ListofItems.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */

/**
 * Fungsi untuk melakukan reverse suatu ListofItems.
 * Prekondisi: array terdefinisi
 */
void ReverseListOfItems(ListofItems *array);

/**
 * Fungsi untuk melakukan copy suatu ListofItems.
 * Prekondisi: array terdefinisi
 */
ListofItems CopyListOfItems(ListofItems array);

/**
 * Fungsi untuk melakukan search suatu ListofItems.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
// int SearchArrayDin(ListofItems array, Item el);

boolean isItemIn(ListofItems items, char *name);
// buat cari apakah nama barang ada di toko

int idxOfItem(ListofItems items, char *name);

#endif
