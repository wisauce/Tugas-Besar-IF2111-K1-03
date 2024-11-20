#include "store.h"
#include "ADT/arrayitems/arrayitems.h"
#include "ADT/mesinkata/mesinkata.h"
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

// void StoreRequest()

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