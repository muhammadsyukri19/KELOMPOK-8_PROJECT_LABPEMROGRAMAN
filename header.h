#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deklarasi struktur data untuk barang
typedef struct Barang {
  char nama[50];
  int harga;
  int stok;
} Barang;

// Deklarasi fungsi
void tambahBarang();
void lakukanPembayaran();
