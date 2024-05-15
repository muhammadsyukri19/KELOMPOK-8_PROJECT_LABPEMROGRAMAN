#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAX_BARANG 100 // jumlah maksimal barang yang dapat disimpan

void tambahBarang() {
    int jumlahBarang = 0;
    if (jumlahBarang >= 100) {
        printf("\nStok barang sudah penuh. Tidak dapat menambahkan barang baru.\n");
        return;
    }

    FILE *file = fopen("barang.txt", "a");
    if (file == NULL) {
        printf("Terjadi kesalahan! Gagal membuka file.\n");
        exit(1);
    }

    printf("\n*Tambah Barang Baru*\n");
    printf("Nama Barang: ");
    scanf("%s", barang[jumlahBarang].nama); 
    fprintf(file, "%s\t", barang[jumlahBarang].nama);
    printf("Harga Barang: ");
    scanf("%d", &barang[jumlahBarang].harga);
    fprintf(file, "%d\t", barang[jumlahBarang].harga);
    printf("Stok Barang: ");
    scanf("%d", &barang[jumlahBarang].stok);
    fprintf(file, "%d\n", barang[jumlahBarang].stok);

    jumlahBarang++;
    printf("\nBarang baru telah ditambahkan dengan sukses!\n");
    
    fclose(file);
}

int main() {
    int choice;

    while (1) {
        printf("\nPilih operasi:\n");
        printf("1. Tambah barang\n");
        printf("2. Keluar\n");
        printf("> ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                tambahBarang();
                break;
            case 2:
                exit(0);
            default:
                printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
