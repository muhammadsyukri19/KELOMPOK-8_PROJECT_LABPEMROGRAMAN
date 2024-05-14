#include "header.h"
void hapusBarang() {
  if (jumlahBarang == 0) {
    printf("\nTidak ada barang yang tersedia untuk dihapus.\n");
    return;
  }

  printf("\n**Hapus Barang**\n");
  lihatDaftarBarang(); #include "header.h"
void hapusBarang() {
  if (jumlahBarang == 0) {
    printf("\nTidak ada barang yang tersedia untuk dihapus.\n");
    return;
  }

  printf("\n**Hapus Barang**\n");
  lihatDaftarBarang(); 

  int pilihanHapus;
  printf("Pilih nomor barang yang ingin dihapus: ");
  scanf("%d", &pilihanHapus);

  if (pilihanHapus > 0 && pilihanHapus <= jumlahBarang) {
    // Pindahkan elemen array setelah elemen yang dihapus
    for (int i = pilihanHapus - 1; i < jumlahBarang - 1; i++) {
      barang[i] = barang[i + 1];
    }

    jumlahBarang--;
    printf("\nBarang telah dihapus dengan sukses!\n");

    simpanDataKeFile(); // Simpan perubahan data ke file
  } else {
    printf("\nPilihan tidak valid. Silakan masukkan nomor barang yang benar.\n");
  }
}


  int pilihanHapus;
  printf("Pilih nomor barang yang ingin dihapus: ");
  scanf("%d", &pilihanHapus);

  if (pilihanHapus > 0 && pilihanHapus <= jumlahBarang) {
    // Pindahkan elemen array setelah elemen yang dihapus
    for (int i = pilihanHapus - 1; i < jumlahBarang - 1; i++) {
      barang[i] = barang[i + 1];
    }

    jumlahBarang--;
    printf("\nBarang telah dihapus dengan sukses!\n");

    simpanDataKeFile(); // Simpan perubahan data ke file
  } else {
    printf("\nPilihan tidak valid. Silakan masukkan nomor barang yang benar.\n");
  }
}
