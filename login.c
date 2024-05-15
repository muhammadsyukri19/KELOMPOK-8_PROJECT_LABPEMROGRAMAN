#include "header.h"

// struct User {
//     char username[MAX_USERNAME_LENGTH];
//     char password[MAX_PASSWORD_LENGTH];
// };


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
        return 0;
    }
    
    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        char *username = strtok(line, ",");
        char *password = strtok(NULL, ",");
        
        if (username != NULL && password != NULL) {
            if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
                fclose(file);
                return 1;
            }
        }
    }
    
    fclose(file);
    
    return 0;

}

int main() {
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
                if (loginUser()) {
                    printf("Login berhasil!\n");
                } else {
                    printf("Username atau password salah. Login gagal.\n");
                }
                break;
            case 3:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih kembali.\n");
        }
        
        printf("\n");
    } while (choice != 3);
    
    return 0;
}