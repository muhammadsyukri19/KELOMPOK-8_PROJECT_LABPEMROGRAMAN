#include "header.h"

void lihatDaftarBarang() {
    if (jumlahBarang == 0) {
        printf("\nTidak ada barang yang tersedia.\n");
        return;
    }

    printf("\n**Daftar Barang**\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("%d. %s - Harga: Rp%d, Stok: %d\n", i + 1, barang[i].nama, barang[i].harga, barang[i].stok);
    }
}