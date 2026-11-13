
# SISTEM MONITORING STOK DAN PENJUALAN KANTIN KAMPUS

## 1. IDENTITAS MAHASISWA

| Keterangan | Identitas |
|---|---|
| Nama | Mega Lestari |
| NIM | C2583207042 |
| Kelas | PTI 3A |
| Program Studi | Pendidikan Teknologi Informasi |
| Fakultas | Fakultas Keguruan dan Ilmu Pendidikan |
| Universitas | Universitas Muhammadiyah Tasikmalaya |
| Mata Kuliah | Algoritma dan Pemrograman Lanjutan |
| Dosen Pengampu | Taofik Muhammad, M.Kom |

---

## 2. DESKRIPSI PROYEK

Sistem Monitoring Stok dan Penjualan Kantin Kampus merupakan aplikasi berbasis console yang dibuat menggunakan bahasa pemrograman C.

Program ini bertujuan untuk membantu pengelola kantin dalam mengelola data produk, memantau stok barang, melakukan transaksi penjualan, mencari produk, mengurutkan data, dan membuat laporan penjualan.

Program menggunakan Array sebagai struktur data utama untuk menyimpan nama produk, harga, stok, jumlah produk terjual, dan pendapatan setiap produk.

Data hanya disimpan sementara selama program berjalan dan tidak menggunakan database atau file eksternal.

---

## 3. TUJUAN PEMBUATAN PROGRAM

1. Menerapkan konsep Array satu dimensi dan dua dimensi.
2. Mengelola data produk kantin kampus.
3. Menambahkan dan mengubah data produk.
4. Melakukan transaksi pembelian beberapa produk.
5. Menghitung subtotal dan total pembayaran.
6. Memperbarui stok setelah transaksi berhasil.
7. Menampilkan laporan penjualan.
8. Menentukan produk yang paling banyak terjual.
9. Menerapkan pencarian dan pengurutan data.
10. Menerapkan validasi input pengguna.

---

## 4. FITUR PROGRAM

Program memiliki 10 menu utama:

| No. | Menu | Keterangan |
|---|---|---|
| 1 | Lihat Daftar Produk | Menampilkan nama, harga, dan stok produk. |
| 2 | Tambah Produk | Menambahkan produk baru. |
| 3 | Ubah Produk | Mengubah harga dan stok produk. |
| 4 | Transaksi Penjualan | Melakukan transaksi beberapa produk. |
| 5 | Tambah Stok | Menambahkan stok produk. |
| 6 | Cari Produk | Mencari produk berdasarkan nama. |
| 7 | Urutkan Produk | Mengurutkan harga dan jumlah penjualan. |
| 8 | Laporan Penjualan | Menampilkan laporan hasil penjualan. |
| 9 | Cek Stok Menipis | Menampilkan produk dengan stok kurang dari 5. |
| 0 | Keluar | Mengakhiri program. |

---

## 5. PENERAPAN ARRAY

Array digunakan sebagai struktur data utama dengan kapasitas maksimal 50 produk.

### A. Array Karakter Dua Dimensi

Digunakan untuk menyimpan nama produk.

```c
char namaProduk[50][100];
```

### B. Array Satu Dimensi

Array harga:

```c
long long hargaProduk[50];
```

Array stok:

```c
int stokProduk[50];
```

Array jumlah terjual:

```c
int jumlahTerjual[50];
```

Array pendapatan:

```c
long long pendapatanProduk[50];
```

Jumlah produk aktif:

```c
int jumlahProduk = 5;
```

### C. Data Produk Awal

| No. | Nama Produk | Harga | Stok |
|---|---|---:|---:|
| 1 | Nasi Goreng | Rp15.000 | 20 |
| 2 | Mie Goreng | Rp12.000 | 15 |
| 3 | Es Teh | Rp5.000 | 30 |
| 4 | Air Mineral | Rp4.000 | 25 |
| 5 | Roti Bakar | Rp10.000 | 10 |

---

## 6. KONSEP ALGORITMA DAN PEMROGRAMAN

Program menerapkan beberapa konsep berikut:

### A. Percabangan

Menggunakan `if`, `else`, dan `switch` untuk menentukan pilihan menu serta memeriksa kondisi transaksi.

### B. Perulangan

Menggunakan `for` dan `do-while` untuk mengolah data produk, transaksi, pencarian, dan pengurutan.

### C. Fungsi

Program dibagi menjadi beberapa fungsi, yaitu:

- `dataAwal()`
- `tampilProduk()`
- `tambahProduk()`
- `ubahProduk()`
- `transaksiPenjualan()`
- `tambahStok()`
- `cariProduk()`
- `urutkanProduk()`
- `laporanPenjualan()`
- `cekStokMenipis()`

### D. Searching

Menggunakan Linear Search untuk mencari produk berdasarkan nama.

### E. Sorting

Menggunakan Bubble Sort untuk:
- Mengurutkan harga dari termurah ke termahal.
- Mengurutkan jumlah produk terjual dari terbanyak ke paling sedikit.

### F. Validasi Input

Program melakukan validasi terhadap:
- Pilihan menu yang tidak tersedia.
- Nomor produk yang tidak ditemukan.
- Harga dan stok bernilai negatif.
- Jumlah pembelian nol atau negatif.
- Pembelian melebihi stok tersedia.
- Kapasitas produk mencapai 50 data.

---

## 7. STRUKTUR FILE REPOSITORY

```text
Proyek-Array-C-NIM/
│
├── sistem_kantin.c
│
├── README.md
│
└── screenshot/
    ├── 01-daftar-gambar1.jpeg
    ├── 02-tambah-gambar2.jpeg
    ├── 03-transaksi-gambar3.jpeg
    ├── 04-pembaruan-gambar4.jpeg
    ├── 05-stok-tidak-gamar5.jpeg
    ├── 06-laporan-gambar6.jpeg
    ├── 07-pengurutan-gambar7.jpeg
    └── 08-pencarian-gambar8.jpeg
```

---

## 8. CARA MENGOMPILASI DAN MENJALANKAN PROGRAM

### A. Persiapan

Pastikan komputer sudah memiliki:
- Visual Studio Code.
- Compiler GCC.
- Terminal atau Command Prompt.

### B. Kompilasi Program

Buka terminal pada folder proyek, kemudian ketik:

```bash
gcc sistem_kantin.c -o sistem_kantin
```

### C. Menjalankan Program

Untuk Windows:

```bash
sistem_kantin.exe
```

Untuk Linux:

```bash
./sistem_kantin
```

Jika proses kompilasi berhasil, program akan menampilkan menu utama Sistem Monitoring Stok dan Penjualan Kantin Kampus.

---

## 9. DOKUMENTASI PENGUJIAN PROGRAM

| No. | Skenario | Input atau Tindakan | Hasil yang Diharapkan | Bukti Screenshot |
| :---: | :--- | :--- | :--- | :---: |
| 1 | *Tambah produk* | Memilih menu 2, memasukkan produk baru Burger, harga 11000, stok 15 | Produk Burger berhasil disimpan dan muncul dalam daftar produk (Menu 1) | ![gambar1.jpeg](gambar1.jpeg) |
| 2 | *Transaksi* | Memilih menu 4, membeli produk makanan yang ada pada menu dalam 1 transaksi | Subtotal tiap barang dan total pembayaran terhitung dengan akurat pada struk | ![gambar2.jpeg](gambar2.jpeg) |
| 3 | *Pembaruan stok* | Memeriksa data produk (Menu 1) setelah menyelesaikan transaksi pada skenario 2 | Stok Nasi Goreng, Es Teh & Gorengan berkurang, jumlah terjual bertambah | ![gambar3.jpeg](gambar3.jpeg) |
| 4 | *Stok tidak cukup* | Memilih menu 4, membeli burger sejumlah 12 unit (melebihi stok yang ada ) | Transaksi ditolak dengan pesan peringatan; jumlah stok barang tetap/tidak berubah | ![gambar4.jpeg](gambar4.jpeg) |
| 5 | *Laporan* | Memilih menu 8 (Laporan Penjualan) | Total unit terjual, total pendapatan kantin, & produk terlaris dihitung dengan benar | ![gamar5.jpeg](gamar5.jpeg) |
| 6 | *Pengurutan* | Memilih menu 7, urutkan berdasarkan harga termurah dan jumlah penjualan terbanyak  | Urutan posisi produk pada daftar berubah sesuai dengan metode pengurutan yang dipilih (Jumlah penjualan terbanyak) | ![gambar6.jpeg](gambar6.jpeg) |
| 7 | *Pencarian dan stok* | Memilih menu dan (Cek stok < 5) | Menampilkan hasil pencarian produk dan daftar peringatan barang bersisa < 5 | ![gambar7.jpe](gambar7.jpeg) & ![gambar8.jpeg](gambar8.jpeg) |

---

## 10. KESIMPULAN

Berdasarkan pembuatan proyek ini, dapat disimpulkan bahwa bahasa pemrograman C dapat digunakan untuk membuat aplikasi pengelolaan stok dan penjualan kantin kampus.

Penerapan array membantu menyimpan data produk secara terstruktur, sedangkan fungsi, percabangan, perulangan, pencarian, dan pengurutan membantu menjalankan setiap fitur program.

Program ini diharapkan dapat mempermudah pengelolaan produk, pemantauan stok, transaksi penjualan, dan pembuatan laporan penjualan kantin kampus.

Data hanya tersimpan selama program berjalan dan akan kembali ke data awal ketika program dijalankan ulang.

---

## 11. PENUTUP

Proyek Sistem Monitoring Stok dan Penjualan Kantin Kampus dibuat untuk memenuhi tugas proyek praktikum mata kuliah Algoritma dan Pemrograman Lanjutan.

Program ini merupakan penerapan materi pemrograman bahasa C yang telah dipelajari, khususnya penggunaan array, fungsi, percabangan, perulangan, pencarian, pengurutan, dan validasi input.

**Universitas Muhammadiyah Tasikmalaya**  
**Program Studi Pendidikan Teknologi Informasi**  
**Tahun Akademik 2026/2027**

