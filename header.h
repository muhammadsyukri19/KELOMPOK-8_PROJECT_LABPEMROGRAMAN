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
void menuUtama();
void login();
void menuPilihan();
void tambahBarang();
void hapusBarang();
void lihatDaftarBarang();
void lakukanPembayaran();
void simpanDataKeFile();
void bacaDataDariFile();

// Deklarasi variabel
Barang barang[100]; // Array untuk menyimpan data barang
int jumlahBarang = 0; // Jumlah barang yang terdaftar
char namaPengguna[50]; // Nama pengguna yang sedang login
