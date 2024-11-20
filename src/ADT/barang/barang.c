#include "barang.h"

Barang CreateBarang(char *nama, int harga)
{
    Barang barang;
    int i = 0;
    while (nama[i] != '\0')
    {
        barang.nama[i] = nama[i];
        i++;
    }
    barang.nama[i] = '\0';
    barang.harga = harga;

    return barang;
}