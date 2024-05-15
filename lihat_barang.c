#include "header.h"

void lihatBarang() {

    int jumlah_barang;
    printf("Masukkan jumlah barang: ");
    scanf("%d", &jumlah_barang);
    getchar(); // Consume the newline character

    // Memasukkan data barang
    Barang barang[MAX_BARANG];
    for (int i = 0; i < jumlah_barang; i++) {
        printf("Masukkan nama barang ke-%d: ", i + 1);
        scanf(" %[^\n]s", barang[i].nama);
        getchar(); // Consume the newline character
        printf("Masukkan harga barang ke-%d: ", i + 1);
        scanf(" %d", &barang[i].harga);
        getchar(); // Consume the newline character
        printf("Masukkan stok barang ke-%d: ", i + 1);
        scanf(" %d", &barang[i].stok);
        getchar(); // Consume the newline character
    }

    // Menampilkan data barang
    printf("\nData Barang:\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(" No         Nama Barang                 Harga                Stok\n");
    printf("------------------------------------------------------------------------------------\n");
    for (int i = 0; i < jumlah_barang; i++) {
        printf("%-13d%-28s%-23d%\n", i + 1, barang[i].nama, barang[i].harga, barang[i].stok);
    }
    printf("------------------------------------------------------------------------------------\n");
}

int main(){
    lihatBarang();
    return 0;

}