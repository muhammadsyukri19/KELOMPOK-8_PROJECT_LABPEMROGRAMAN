#include "header.h"

void registerUser() {
    #define MAX_USERNAME_LENGTH 50
    #define MAX_PASSWORD_LENGTH 50
    
    struct User {
        char username[MAX_USERNAME_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
    };
    
    struct User user;
    
    printf("Username: ");
    fgets(user.username, sizeof(user.username), stdin);
    user.username[strcspn(user.username, "\n")] = '\0';
    
    printf("Password: ");
    fgets(user.password, sizeof(user.password), stdin);
    user.password[strcspn(user.password, "\n")] = '\0';
    
    FILE *file = fopen("data_akun_kasir.txt", "a");  
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    
    fprintf(file, "%s,%s\n", user.username, user.password);
    fclose(file);
    
    printf("Registrasi berhasil!\n");
}

int main() {
    // Membaca data barang dari file saat program dijalankan
    bacaDataDariFile();

    // Menampilkan menu utama
    menuUtama();

    return 0;
}

int loginUser() {
    #define MAX_USERNAME_LENGTH 50
    #define MAX_PASSWORD_LENGTH 50
    
    struct User {
        char username[MAX_USERNAME_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
    };
    struct User user;
    
    printf("Username: ");
    fgets(user.username, sizeof(user.username), stdin);
    user.username[strcspn(user.username, "\n")] = '\0';
    
    printf("Password: ");
    fgets(user.password, sizeof(user.password), stdin);
    user.password[strcspn(user.password, "\n")] = '\0';
    
    FILE *file = fopen("data_akun_kasir.txt", "r");   
    if (file == NULL) {
        printf("Gagal membuka file.\n");
    
    }
    
    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        char *username = strtok(line, ",");
        char *password = strtok(NULL, ",");
        
        if (username != NULL && password != NULL) {
            if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
                fclose(file);
            }
        }
    }
    
    fclose(file);

}

void menuUtama() {
    int choice;
    
    do {
        printf("=== Program Login ===\n");
        printf("1. Registrasi\n");
        printf("2. Login\n");
        printf("3. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);
        getchar();  // Menghapus karakter newline (\n) setelah membaca angka
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();  
                menuPilihan();
                break;
            case 3:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih kembali.\n");
        }
        
        printf("\n");
    } while (choice != 3);
    
}



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

void tambahBarang() {
    if (jumlahBarang >= 100) {
        printf("\nStok barang sudah penuh. Tidak dapat menambahkan barang baru.\n");
        return;
    }

    printf("\n**Tambah Barang Baru**\n");
    printf("Nama Barang: ");
    scanf("%s", barang[jumlahBarang].nama);
    printf("Harga Barang: ");
    scanf("%d", &barang[jumlahBarang].harga);
    printf("Stok Barang: ");
    scanf("%d", &barang[jumlahBarang].stok);

    jumlahBarang++;
    printf("\nBarang baru telah ditambahkan dengan sukses!\n");

    simpanDataKeFile(); // Simpan perubahan data ke file
}

void hapusBarang() {
    if (jumlahBarang == 0) {
        printf("\nTidak ada barang yang tersedia untuk dihapus.\n");
        return;
    }

    printf("\n**Hapus Barang**\n");
    lihatDaftarBarang(); // Tampilkan daftar barang

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

void simpanDataKeFile() {
    FILE *fp = fopen("data_barang.txt", "w"); // Buka file dalam mode penulisan (w)

    if (fp == NULL) {
        printf("\nError: Gagal membuka file untuk menyimpan data.\n");
        return;
    }

    // Simpan jumlah barang
    fprintf(fp, "%d\n", jumlahBarang);

    // Simpan data barang per baris
    for (int i = 0; i < jumlahBarang; i++) {
        fprintf(fp, "%s %d %d\n", barang[i].nama, barang[i].harga, barang[i].stok);
    }

    fclose(fp); // Tutup file
    printf("\nData barang telah disimpan ke file dengan sukses.\n");
}

void bacaDataDariFile() {
    FILE *fp = fopen("data_barang.txt", "r"); // Buka file dalam mode pembacaan (r)

    if (fp == NULL) {
        printf("\nTidak ada file data barang yang ditemukan. Memulai dengan data kosong.\n");
        jumlahBarang = 0;
        return;
    }

    // Baca jumlah barang
    fscanf(fp, "%d", &jumlahBarang);

     // Baca data barang per baris
  for (int i = 0; i < jumlahBarang; i++) {
    fscanf(fp, "%s %d %d", barang[i].nama, &barang[i].harga, &barang[i].stok);
  }

  fclose(fp); // Tutup file
  printf("\nData barang berhasil dibaca dari file.\n");
}
