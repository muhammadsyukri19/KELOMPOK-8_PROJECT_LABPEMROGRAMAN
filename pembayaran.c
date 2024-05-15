#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk melakukan pembayaran
void pembayaran() {
    FILE *file = fopen("products.txt", "r");

    if (file != NULL) {
        struct Product product;
        float total = 0;
        while (fscanf(file, "%s %d %f", product.name, &product.quantity, &product.price) != EOF) {
            total += product.quantity * product.price;
        }
        fclose(file);
        printf("Total pembayaran: %.2f\n", total);
    } else {
        printf("Gagal membuka file.\n");
    }
}
