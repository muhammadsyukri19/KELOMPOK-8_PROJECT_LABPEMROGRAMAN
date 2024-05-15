#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BARANG 100
#define MAX_LOGIN 100

// Deklarasi struktur data untuk barang
typedef struct Barang {
  int id;
  char nama[50];
  int harga;
  int stok;
} Barang;

//Deklarasi struktur data untuk user/kasir
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Deklarasi fungsi
// void menuUtama();
// void menuBarang();
//void login();
void registerUser();
void loginUser();
void tambahBarang();
void hapusBarang();
// void lihatDaftarBarang();
void lihatBarang();
//void lakukanPembayaran();
//void simpanDataKeFile();
//void bacaDataDariFile();

// Deklarasi variabel global
Barang barang[100]; // Array untuk menyimpan data barang
int jumlahBarang = 0; // Jumlah barang yang terdaftar
char namaPengguna[50]; // Nama pengguna yang sedang login