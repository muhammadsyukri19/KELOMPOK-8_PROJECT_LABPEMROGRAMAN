#include "header.h"

void lakukanPembayaran() {
    if (jumlahBarang == 0) {
        printf("\nTidak ada barang yang tersedia untuk dibeli.\n");
        return;
    }

    int totalPembayaran = 0;
    int jumlahBeli;

    lihatDaftarBarang(); // Tampilkan daftar barang

    printf("\n**Proses Pembayaran**\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("Masukkan jumlah beli %s: ", barang[i].nama);
        scanf("%d", &jumlahBeli);

        if (jumlahBeli > barang[i].stok) {
            printf("\nStok %s tidak mencukupi. Maksimal pembelian: %d\n", barang[i].nama, barang[i].stok);
            continue;
        }

        totalPembayaran += barang[i].harga * jumlahBeli;
        barang[i].stok -= jumlahBeli; // Kurangi stok barang yang dibeli
    }

    printf("\nTotal pembayaran: Rp%d\n", totalPembayaran);

    int uangBayar;
    printf("Uang yang dibayarkan: Rp");
    scanf("%d", &uangBayar);

    if (uangBayar < totalPembayaran) {
        printf("\nUang yang dibayarkan kurang. Transaksi dibatalkan.\n");
    } else {
        printf("\nKembalian: Rp%d\n", uangBayar - totalPembayaran);
        printf("\nTerima kasih telah berbelanja!\n");

        simpanDataKeFile(); // Simpan perubahan data ke file
    }
}
