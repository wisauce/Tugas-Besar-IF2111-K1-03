#include "store.h"
#include "ADT/arrayitems/arrayitems.h"
#include "ADT/mesinkata/mesinkata.h"
#include "ADT/queue/queue.h"
#include <stdio.h>

void StoreList(ListofItems items)
{
    if (items.Neff != 0)
    {
        printf("List barang yang ada di toko :\n");
        for (int i = 0; i < items.Neff; i++)
        {
            printf("- %s\n", items.A[i].name);
        }
    }
    else
        printf("TOKO KOSONG\n");
}

void StoreRequest(ListofItems *items, Queue *q)
{
    Word W1, W2;
    int x, y;
    printf("Nama barang yang diminta: ");
    scan("%s", &W1, &W2, &x, &y);

    if (isItemIn(*items, wordToString(W1)))
    {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    }
    else if (isIn(*q, wordToString(W1)))
    {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
    }
    else
    {
        enqueue(q, wordToString(W1));
        printf("Barang dah dimasukin coy\n");
    }
}

void StoreSupply(ListofItems *items, Queue *q)
{
    Word W1, W2;
    int x, y;
    printf("Apakah kamu ingin menambahkan barang %s: ", HEAD(*q));
    scan("%s", &W1, &W2, &x, &y);
    if (isStringSame(wordToString(W1), "Terima"))
    {
        printf("Harga barang: ");
        scan("%d", &W1, &W2, &x, &y);
        if (x > 0)
        {
            Item barang;
            dequeue(q, barang.name);
            barang.price = x;

            InsertLastItem(items, barang);
            printf("%s dengan harga %d telah ditambahkan ke toko.\n", barang.name, barang.price);
        }
    }
    else if (isStringSame(wordToString(W1), "Tunda"))
    {

        Item barang;
        dequeue(q, barang.name);
        enqueue(q, barang.name);
        printf("%s dikembalikan ke antrian.\n", barang.name);
    }
    else if (isStringSame(wordToString(W1), "Tolak"))
    {
        Item barang;
        dequeue(q, barang.name);
        printf("%s dihapuskan dari antrian.\n", barang.name);
    }
    else
    {
        printf("Masukan tidak valid\n");
    }
}

void StoreRemove(ListofItems *items)
{
    Word W1, W2;
    int x, y;
    printf("Nama barang yang akan dihapus: ");
    scan("%s", &W1, &W2, &x, &y);

    if (isItemIn(*items, wordToString(W1)))
    {
        int idx = idxOfItem(*items, wordToString(W1));
        DeleteAt(items, idx);
        printf("%s telah berhasil dihapus.\n", wordToString(W1));
    }
    else
    {
        printf("Toko tidak menjual %s\n", wordToString(W1));
    }
}