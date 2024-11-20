#ifndef __BARANG_H__
#define __BARANG_H__

#define BARANG_NAMA_MAX_LENGTH 150

typedef struct {
    int harga;
    char nama[BARANG_NAMA_MAX_LENGTH];
} Barang;

Barang CreateBarang(char* nama, int harga);

#endif