
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

#define MAX_PRODUK 50
#define PANJANG_NAMA 50

// ==========================================
// DEKLARASI ARRAY DAN VARIABEL GLOBAL
// ==========================================

char namaProduk[MAX_PRODUK][PANJANG_NAMA];

long long harga[MAX_PRODUK];
int stok[MAX_PRODUK];
int terjual[MAX_PRODUK];

int jumlahProduk = 5;
long long totalPendapatan = 0;

// ==========================================
// FUNGSI INPUT
// ==========================================

long long inputAngka(const char *pesan,
                     long long minimum,
                     long long maksimum) {
    char buffer[100];
    char *akhir;
    long long nilai;

    while (1) {
        printf("%s", pesan);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Input tidak valid!\n");
            continue;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        errno = 0;
        nilai = strtoll(buffer, &akhir, 10);

        while (isspace((unsigned char)*akhir)) {
            akhir++;
        }

        if (akhir == buffer || *akhir != '\0' ||
            errno == ERANGE ||
            nilai < minimum || nilai > maksimum) {
            printf("Input tidak valid! Masukkan angka %lld sampai %lld.\n",
                   minimum, maksimum);
        } else {
            return nilai;
        }
    }
}

void inputNama(char *nama, int ukuran) {
    while (1) {
        printf("Masukkan nama produk: ");

        if (fgets(nama, ukuran, stdin) == NULL) {
            nama[0] = '\0';
            continue;
        }

        if (strchr(nama, '\n') == NULL) {
            int karakter;
            while ((karakter = getchar()) != '\n' &&
                   karakter != EOF);
            printf("Nama terlalu panjang!\n");
            continue;
        }

        nama[strcspn(nama, "\n")] = '\0';

        if (strlen(nama) == 0) {
            printf("Nama tidak boleh kosong!\n");
            continue;
        }

        return;
    }
}

// ==========================================
// DATA AWAL PRODUK
// ==========================================

void dataAwal() {
    strcpy(namaProduk[0], "Nasi Goreng");
    harga[0] = 15000;
    stok[0] = 20;
    terjual[0] = 0;

    strcpy(namaProduk[1], "Mie Goreng");
    harga[1] = 12000;
    stok[1] = 25;
    terjual[1] = 0;

    strcpy(namaProduk[2], "Es Teh");
    harga[2] = 5000;
    stok[2] = 30;
    terjual[2] = 0;

    strcpy(namaProduk[3], "Roti Bakar");
    harga[3] = 10000;
    stok[3] = 15;
    terjual[3] = 0;

    strcpy(namaProduk[4], "Air Mineral");
    harga[4] = 4000;
    stok[4] = 40;
    terjual[4] = 0;
}

// ==========================================
// FUNGSI MENAMPILKAN PRODUK
// ==========================================

void tampilkanProduk() {
    int i;

    printf("\n");
    printf("===============================================================\n");
    printf("                  DAFTAR PRODUK KANTIN\n");
    printf("===============================================================\n");

    printf("%-5s %-20s %-15s %-10s %-10s\n",
           "No", "Nama Produk", "Harga", "Stok", "Terjual");

    printf("---------------------------------------------------------------\n");

    for (i = 0; i < jumlahProduk; i++) {
        printf("%-5d %-20s Rp%-13lld %-10d %-10d\n",
               i + 1, namaProduk[i], harga[i],
               stok[i], terjual[i]);
    }

    printf("===============================================================\n");
}

// ==========================================
// FUNGSI TAMBAH PRODUK
// ==========================================

void tambahProduk() {
    if (jumlahProduk >= MAX_PRODUK) {
        printf("\nKapasitas produk sudah penuh!\n");
        return;
    }

    printf("\n===== TAMBAH PRODUK BARU =====\n");

    inputNama(namaProduk[jumlahProduk], PANJANG_NAMA);

    harga[jumlahProduk] = inputAngka(
        "Masukkan harga produk: Rp", 0, LLONG_MAX);

    stok[jumlahProduk] = (int)inputAngka(
        "Masukkan jumlah stok: ", 0, INT_MAX);

    terjual[jumlahProduk] = 0;

    jumlahProduk++;

    printf("\nProduk berhasil ditambahkan!\n");
}

// ==========================================
// FUNGSI UBAH PRODUK
// ==========================================

void ubahProduk() {
    int nomor;

    if (jumlahProduk == 0) {
        printf("Belum ada produk!\n");
        return;
    }

    tampilkanProduk();

    nomor = (int)inputAngka(
        "\nPilih nomor produk yang akan diubah: ",
        1, jumlahProduk) - 1;

    printf("\nProduk: %s\n", namaProduk[nomor]);

    printf("Harga lama : Rp%lld\n", harga[nomor]);
    harga[nomor] = inputAngka(
        "Masukkan harga baru: Rp", 0, LLONG_MAX);

    printf("Stok lama : %d\n", stok[nomor]);
    stok[nomor] = (int)inputAngka(
        "Masukkan stok baru: ", 0, INT_MAX);

    printf("\nData produk berhasil diperbarui!\n");
}

// ==========================================
// FUNGSI TAMBAH STOK
// ==========================================

void tambahStok() {
    int nomor;
    int tambahan;

    tampilkanProduk();

    nomor = (int)inputAngka(
        "\nPilih nomor produk: ", 1, jumlahProduk) - 1;

    tambahan = (int)inputAngka(
        "Masukkan jumlah stok tambahan: ", 1, INT_MAX);

    if (tambahan > INT_MAX - stok[nomor]) {
        printf("Jumlah stok melebihi batas!\n");
        return;
    }

    stok[nomor] += tambahan;

    printf("\nStok produk berhasil ditambahkan!\n");
    printf("Stok sekarang: %d\n", stok[nomor]);
}

// ==========================================
// FUNGSI PENCARIAN PRODUK
// ==========================================

void cariProduk() {
    char kataKunci[PANJANG_NAMA];
    char namaKecil[PANJANG_NAMA];
    char kunciKecil[PANJANG_NAMA];

    int i, j;
    int ditemukan = 0;

    printf("\n===== PENCARIAN PRODUK =====\n");

    inputNama(kataKunci, PANJANG_NAMA);

    for (i = 0; kataKunci[i]; i++) {
        kunciKecil[i] = tolower((unsigned char)kataKunci[i]);
    }
    kunciKecil[i] = '\0';

    for (i = 0; i < jumlahProduk; i++) {
        for (j = 0; namaProduk[i][j]; j++) {
            namaKecil[j] =
                tolower((unsigned char)namaProduk[i][j]);
        }
        namaKecil[j] = '\0';

        if (strstr(namaKecil, kunciKecil) != NULL) {
            printf("\nProduk ditemukan!\n");
            printf("Nama   : %s\n", namaProduk[i]);
            printf("Harga  : Rp%lld\n", harga[i]);
            printf("Stok   : %d\n", stok[i]);
            printf("Terjual: %d\n", terjual[i]);

            ditemukan = 1;
        }
    }

    if (!ditemukan) {
        printf("\nProduk tidak ditemukan!\n");
    }
}

// ==========================================
// FUNGSI TRANSAKSI PENJUALAN
// ==========================================

void transaksiPenjualan() {
    int keranjang[MAX_PRODUK] = {0};

    int nomor;
    int jumlah;
    int i;
    int lanjut;

    long long subtotal;
    long long total = 0;

    printf("\n===== TRANSAKSI PENJUALAN =====\n");

    if (jumlahProduk == 0) {
        printf("Belum ada produk!\n");
        return;
    }

    while (1) {
        tampilkanProduk();

        nomor = (int)inputAngka(
            "\nPilih nomor produk (0 untuk selesai): ",
            0, jumlahProduk);

        if (nomor == 0) {
            break;
        }

        nomor--;

        printf("Produk dipilih: %s\n", namaProduk[nomor]);
        printf("Stok tersedia : %d\n",
               stok[nomor] - keranjang[nomor]);

        if (stok[nomor] - keranjang[nomor] <= 0) {
            printf("Stok produk tidak mencukupi!\n");
            continue;
        }

        jumlah = (int)inputAngka(
            "Masukkan jumlah pembelian: ",
            1, stok[nomor] - keranjang[nomor]);

        keranjang[nomor] += jumlah;

        printf("Produk berhasil dimasukkan ke keranjang!\n");

        lanjut = (int)inputAngka(
            "\nTambah produk lainnya? (1=Ya, 0=Tidak): ",
            0, 1);

        if (lanjut == 0) {
            break;
        }
    }

    // Menghitung total transaksi

    for (i = 0; i < jumlahProduk; i++) {
        if (keranjang[i] > 0) {
            if (harga[i] > 0 &&
                keranjang[i] > (LLONG_MAX - total) / harga[i]) {
                printf("Total transaksi terlalu besar!\n");
                return;
            }

            subtotal = harga[i] * keranjang[i];
            total += subtotal;
        }
    }

    if (total == 0) {
        printf("\nTransaksi dibatalkan karena tidak ada produk.\n");
        return;
    }

    if (totalPendapatan > LLONG_MAX - total) {
        printf("Total pendapatan melebihi batas!\n");
        return;
    }

    // Menampilkan rincian transaksi

    printf("\n");
    printf("====================================================\n");
    printf("               STRUK PEMBELIAN\n");
    printf("====================================================\n");

    printf("%-20s %-8s %-12s\n",
           "Produk", "Jumlah", "Subtotal");

    printf("----------------------------------------------------\n");

    for (i = 0; i < jumlahProduk; i++) {
        if (keranjang[i] > 0) {
            subtotal = harga[i] * keranjang[i];

            printf("%-20s %-8d Rp%-10lld\n",
                   namaProduk[i], keranjang[i], subtotal);
        }
    }

    printf("----------------------------------------------------\n");
    printf("TOTAL PEMBAYARAN : Rp%lld\n", total);

    // Memperbarui stok dan jumlah produk terjual

    for (i = 0; i < jumlahProduk; i++) {
        if (keranjang[i] > 0) {
            stok[i] -= keranjang[i];
            terjual[i] += keranjang[i];
        }
    }

    totalPendapatan += total;

    printf("====================================================\n");
    printf("Transaksi berhasil!\n");
    printf("Stok dan jumlah penjualan telah diperbarui.\n");
}

// ==========================================
// FUNGSI CEK STOK MENIPIS
// ==========================================

void cekStokMenipis() {
    int i;
    int ditemukan = 0;

    printf("\n===== DAFTAR STOK MENIPIS =====\n");

    for (i = 0; i < jumlahProduk; i++) {
        if (stok[i] < 5) {
            printf("%d. %s - Stok: %d\n",
                   i + 1, namaProduk[i], stok[i]);

            ditemukan = 1;
        }
    }

    if (!ditemukan) {
        printf("Tidak ada produk dengan stok kurang dari 5.\n");
    }
}

// ==========================================
// FUNGSI LAPORAN PENJUALAN
// ==========================================

void laporanPenjualan() {
    int i;
    int totalUnit = 0;
    int terlaris = 0;

    printf("\n");
    printf("====================================================\n");
    printf("               LAPORAN PENJUALAN\n");
    printf("====================================================\n");

    printf("%-20s %-15s\n", "Nama Produk", "Jumlah Terjual");

    printf("----------------------------------------------------\n");

    for (i = 0; i < jumlahProduk; i++) {
        printf("%-20s %-15d\n",
               namaProduk[i], terjual[i]);

        totalUnit += terjual[i];

        if (terjual[i] > terjual[terlaris]) {
            terlaris = i;
        }
    }

    printf("----------------------------------------------------\n");

    printf("Total Unit Terjual : %d\n", totalUnit);
    printf("Total Pendapatan   : Rp%lld\n", totalPendapatan);

    if (totalUnit > 0) {
        printf("Produk Terlaris    : %s\n",
               namaProduk[terlaris]);

        printf("Jumlah Terjual     : %d unit\n",
               terjual[terlaris]);
    } else {
        printf("Produk Terlaris    : Belum ada penjualan\n");
    }

    printf("====================================================\n");
}

// ==========================================
// FUNGSI PENGURUTAN PRODUK
// ==========================================

void tukarProduk(int a, int b) {
    char tempNama[PANJANG_NAMA];
    long long tempHarga;
    int tempStok, tempTerjual;

    strcpy(tempNama, namaProduk[a]);
    strcpy(namaProduk[a], namaProduk[b]);
    strcpy(namaProduk[b], tempNama);

    tempHarga = harga[a];
    harga[a] = harga[b];
    harga[b] = tempHarga;

    tempStok = stok[a];
    stok[a] = stok[b];
    stok[b] = tempStok;

    tempTerjual = terjual[a];
    terjual[a] = terjual[b];
    terjual[b] = tempTerjual;
}

void urutkanProduk() {
    int pilihan;
    int i, j;

    printf("\n===== MENU PENGURUTAN =====\n");
    printf("1. Urutkan berdasarkan harga termurah\n");
    printf("2. Urutkan berdasarkan penjualan terbanyak\n");
    printf("0. Kembali\n");

    pilihan = (int)inputAngka(
        "Pilih menu: ", 0, 2);

    if (pilihan == 0) {
        return;
    }

    // Bubble Sort

    for (i = 0; i < jumlahProduk - 1; i++) {
        for (j = 0; j < jumlahProduk - i - 1; j++) {

            if ((pilihan == 1 &&
                 harga[j] > harga[j + 1]) ||
                (pilihan == 2 &&
                 terjual[j] < terjual[j + 1])) {

                tukarProduk(j, j + 1);
            }
        }
    }

    printf("\nProduk berhasil diurutkan!\n");

    tampilkanProduk();
}

// ==========================================
// FUNGSI MENU UTAMA
// ==========================================

void menuUtama() {
    printf("\n");
    printf("===============================================\n");
    printf("       SISTEM MONITORING KANTIN KAMPUS\n");
    printf("===============================================\n");
    printf("1. Lihat Daftar Produk\n");
    printf("2. Tambah Produk\n");
    printf("3. Ubah Produk\n");
    printf("4. Transaksi Penjualan\n");
    printf("5. Tambah Stok\n");
    printf("6. Cari Produk\n");
    printf("7. Urutkan Produk\n");
    printf("8. Laporan Penjualan\n");
    printf("9. Cek Stok Menipis\n");
    printf("0. Keluar\n");
    printf("===============================================\n");
}

// ==========================================
// PROGRAM UTAMA
// ==========================================

int main() {
    int pilihan;

    // Memasukkan data awal
    dataAwal();

    printf("\n");
    printf("===============================================\n");
    printf("  SELAMAT DATANG DI SISTEM KANTIN KAMPUS\n");
    printf("===============================================\n");

    do {
        menuUtama();

        pilihan = (int)inputAngka(
            "Masukkan pilihan menu: ", 0, 9);

        switch (pilihan) {

            case 1:
                tampilkanProduk();
                break;

            case 2:
                tambahProduk();
                break;

            case 3:
                ubahProduk();
                break;

            case 4:
                transaksiPenjualan();
                break;

            case 5:
                tambahStok();
                break;

            case 6:
                cariProduk();
                break;

            case 7:
                urutkanProduk();
                break;

            case 8:
                laporanPenjualan();
                break;

            case 9:
                cekStokMenipis();
                break;

            case 0:
                printf("\nTerima kasih telah menggunakan program!\n");
                printf("Program selesai.\n");
                break;

            default:
                printf("\nPilihan menu tidak tersedia!\n");
        }

    } while (pilihan != 0);

    return 0;
}
