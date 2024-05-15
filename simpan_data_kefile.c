#include "header.h"
void simpanDataKeFile() {
    FILE *fp = fopen("data_barang.txt", "w"); // Buka file dalam mode penulisan (w)

    if (fp == NULL) {
        printf("\nError: Gagal membuka file untuk menyimpan data.\n");
        return;
    }

    // Simpan jumlah barang
    fprintf(fp, "%d\n", jumlahBarang);

    // Simpan data barang per baris
    for (int i = 0; i < jumlahBarang; i++) {
        fprintf(fp, "%s %d %d\n", barang[i].nama, barang[i].harga, barang[i].stok);
    }

    fclose(fp); // Tutup file
    printf("\nData barang telah disimpan ke file dengan sukses.\n");
}
