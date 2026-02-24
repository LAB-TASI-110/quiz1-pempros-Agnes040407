#include <stdio.h>
#include <string.h>

#define MAX 100

// Struktur data pelanggan
struct Pelanggan {
    char nama[50];
    char no_hp[20];
    char alamat[100];
};

int main() {
    struct Pelanggan data[MAX];
    int jumlah = 0;
    int pilihan;
    char cari[50];
    int ditemukan;

    do {
        printf("\n=== SISTEM PENDATAAN PELANGGAN LAUNDRY DEL ===\n");
        printf("1. Tambah Data Pelanggan\n");
        printf("2. Lihat Data Pelanggan\n");
        printf("3. Cari Data Pelanggan\n");
        printf("4. Ubah Data Pelanggan\n");
        printf("5. Hapus Data Pelanggan\n");
        printf("6. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar(); // bersihkan buffer

        if (pilihan == 1) {
            // Tambah data
            printf("Nama        : ");
            fgets(data[jumlah].nama, 50, stdin);
            data[jumlah].nama[strcspn(data[jumlah].nama, "\n")] = 0;

            printf("No HP       : ");
            fgets(data[jumlah].no_hp, 20, stdin);
            data[jumlah].no_hp[strcspn(data[jumlah].no_hp, "\n")] = 0;

            printf("Alamat      : ");
            fgets(data[jumlah].alamat, 100, stdin);
            data[jumlah].alamat[strcspn(data[jumlah].alamat, "\n")] = 0;

            jumlah++;
            printf("Data pelanggan berhasil ditambahkan.\n");

        } else if (pilihan == 2) {
            // Lihat data
            if (jumlah == 0) {
                printf("Belum ada data pelanggan.\n");
            } else {
                for (int i = 0; i < jumlah; i++) {
                    printf("\nPelanggan ke-%d\n", i + 1);
                    printf("Nama   : %s\n", data[i].nama);
                    printf("No HP  : %s\n", data[i].no_hp);
                    printf("Alamat : %s\n", data[i].alamat);
                }
            }

        } else if (pilihan == 3) {
            // Cari data
            printf("Masukkan nama pelanggan: ");
            fgets(cari, 50, stdin);
            cari[strcspn(cari, "\n")] = 0;

            ditemukan = 0;
            for (int i = 0; i < jumlah; i++) {
                if (strcmp(data[i].nama, cari) == 0) {
                    printf("\nData ditemukan:\n");
                    printf("Nama   : %s\n", data[i].nama);
                    printf("No HP  : %s\n", data[i].no_hp);
                    printf("Alamat : %s\n", data[i].alamat);
                    ditemukan = 1;
                }
            }

            if (!ditemukan) {
                printf("Data pelanggan tidak ditemukan.\n");
            }

        } else if (pilihan == 4) {
            // Ubah data
            printf("Masukkan nama pelanggan yang ingin diubah: ");
            fgets(cari, 50, stdin);
            cari[strcspn(cari, "\n")] = 0;

            ditemukan = 0;
            for (int i = 0; i < jumlah; i++) {
                if (strcmp(data[i].nama, cari) == 0) {
                    printf("Nama baru   : ");
                    fgets(data[i].nama, 50, stdin);
                    data[i].nama[strcspn(data[i].nama, "\n")] = 0;

                    printf("No HP baru  : ");
                    fgets(data[i].no_hp, 20, stdin);
                    data[i].no_hp[strcspn(data[i].no_hp, "\n")] = 0;

                    printf("Alamat baru : ");
                    fgets(data[i].alamat, 100, stdin);
                    data[i].alamat[strcspn(data[i].alamat, "\n")] = 0;

                    printf("Data pelanggan berhasil diubah.\n");
                    ditemukan = 1;
                }
            }

            if (!ditemukan) {
                printf("Data pelanggan tidak ditemukan.\n");
            }

        } else if (pilihan == 5) {
            // Hapus data
            printf("Masukkan nama pelanggan yang ingin dihapus: ");
            fgets(cari, 50, stdin);
            cari[strcspn(cari, "\n")] = 0;

            ditemukan = 0;
            for (int i = 0; i < jumlah; i++) {
                if (strcmp(data[i].nama, cari) == 0) {
                    for (int j = i; j < jumlah - 1; j++) {
                        data[j] = data[j + 1];
                    }
                    jumlah--;
                    printf("Data pelanggan berhasil dihapus.\n");
                    ditemukan = 1;
                    break;
                }
            }

            if (!ditemukan) {
                printf("Data pelanggan tidak ditemukan.\n");
            }

        } else if (pilihan == 6) {
            printf("Program selesai. Terima kasih.\n");
        } else {
            printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 6);

    return 0;
}