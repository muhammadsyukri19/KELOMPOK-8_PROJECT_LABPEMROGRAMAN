#include "header.h"

void menuPilihan() {
    int pilihan;

    do {
        printf("\n**Sistem Kasir Sederhana**\n");
        printf("1. Tambah Barang\n");
        printf("2. Hapus Barang\n");
        printf("3. Lihat Daftar Barang\n");
        printf("4. Pembayaran\n");
        printf("5. Logout\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahBarang();
                break;
            case 2:
                hapusBarang();
                break;
            case 3:
                lihatDaftarBarang();
                break;
            case 4:
                lakukanPembayaran();
                break;
            case 5:
                strcpy(namaPengguna, ""); // Logout, reset nama pengguna
                printf("\nAnda telah logout.\n");
                break;
            default:
                printf("\nPilihan tidak valid. Silakan masukkan pilihan yang benar.\n");
        }
    } while (pilihan != 5); // Kembali ke menu utama setelah logout
}