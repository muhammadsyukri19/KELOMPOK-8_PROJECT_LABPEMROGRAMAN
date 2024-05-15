#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tambahBarang() {
    if (jumlahBarang >= 100) {
        printf("\nStok barang sudah penuh. Tidak dapat menambahkan barang baru.\n");
        return;
    }

    printf("\n**Tambah Barang Baru**\n");
    printf("Nama Barang: ");
    scanf("%s", barang[jumlahBarang].nama);
    printf("Harga Barang: ");
    scanf("%d", &barang[jumlahBarang].harga);
    printf("Stok Barang: ");
    scanf("%d", &barang[jumlahBarang].stok);

    jumlahBarang++;
    printf("\nBarang baru telah ditambahkan dengan sukses!\n");

    simpanDataKeFile(); // Simpan perubahan data ke file
}