#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BARANG 100
#define MAX_LOGIN 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

// Deklarasi struktur data untuk barang
typedef struct Barang {
  char nama[50];
  int harga;
  int stok;
} Barang;

//Deklarasi struktur data untuk user/kasir
struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};


void registerUser();
int loginUser();
void tambahBarang();
void hapusBarang();
void lihatBarang();


// Deklarasi variabel global
Barang barang[100]; // Array untuk menyimpan data barang
int jumlahBarang = 0; // Jumlah barang yang terdaftar
char namaPengguna[50]; // Nama pengguna yang sedang login
