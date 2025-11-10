# Workflow per feature

## 1.Tambah Transaksi

<b>Tujuan:</b> Menyimpan transaksi baru ke array.

<b>Workflow:</b>

1. User pilih menu 1 di tampilan utama.
2. Program cek apakah totalTransaksi < MAX_TRANSAKSI.
    - Kalau penuh → tampil pesan error, balik ke menu.
3. Kalau masih ada slot:
    - Program minta input:
        - Jenis (pemasukan / pengeluaran)
        - Kategori (pakai getline() karena bisa ada spasi)
        - Jumlah (integer)
        - Tanggal
4. Data dimasukkan ke daftar[totalTransaksi].
5. totalTransaksi ditambah 1.
6. Tampilkan pesan “Transaksi berhasil ditambahkan.”
7. Kembali ke menu utama.

## 2.Lihat Semua Transaksi
<b>Tujuan:</b> Menampilkan semua data transaksi yang tersimpan.
<b>Workflow:</b>

1. User pilih menu 2.
2. Program cek apakah totalTransaksi == 0.
    - Kalau iya → tampilkan pesan “Belum ada transaksi.”
3. Kalau ada:
    - Loop dari i = 0 sampai i < totalTransaksi.
    - Tampilkan data transaksi ke-i dalam format:
        ```
        No. [jenis] kategori - Rpjumlah (tanggal)
        ```
4. Setelah semua tampil, kembali ke menu utama.

## 3.Lihat Total Uang

<b>Tujuan:</b> Menghitung total pemasukan, pengeluaran, dan saldo akhir.

<b>Workflow:</b>

1. User pilih menu 3.

2. Inisialisasi totalPemasukan dan totalPengeluaran ke 0.

3. Loop seluruh array transaksi:
    - Jika jenis == "pemasukan", tambahkan ke totalPemasukan.
    - Jika jenis == "pengeluaran", tambahkan ke totalPengeluaran.
4. Hitung saldo = totalPemasukan - totalPengeluaran.
5. Tampilkan hasil dalam format:
    ```
    Total Pemasukan   : Rp...
    Total Pengeluaran : Rp...
    Saldo Akhir       : Rp...
    ```
6. Kembali ke menu utama.

## 4. Filter Transaksi (pemasukan/pengeluaran)

<b>Tujuan:</b> Menampilkan hanya transaksi berdasarkan jenis.

<b>Workflow:</b>

1. User pilih menu 4.

2. Program minta input “pemasukan” atau “pengeluaran”.

3. Loop seluruh data:

Jika daftar[i].jenis == filter, tampilkan data tersebut.

4. Jika tidak ada yang cocok, tampilkan pesan “Tidak ada transaksi dengan jenis itu.”

5. Kembali ke menu utama.

## 5. Cari Transaksi Berdasarkan Kategori

<b>Tujuan:</b> 

<b>Workflow:</b>

1. User pilih menu 5.

2. Program minta input kata kunci kategori (pakai getline).

3. Loop semua transaksi:
    - Cek apakah daftar[i].kategori.find(keyword) != string::npos.
    - Kalau cocok, tampilkan datanya.

4. Jika tidak ditemukan satu pun, tampilkan pesan “Tidak ada transaksi dengan kategori itu.”

5. Kembali ke menu utama.

## 6. Menu Navigasi (Program Utama)

<b>Tujuan:</b> Mengontrol seluruh alur program dengan loop dan percabangan.

<b>Workflow:</b>

1. Program jalan, tampilkan menu utama:
    ```markdown
    1. Tambah Transaksi
    2. Lihat Semua Transaksi
    3. Lihat Total Uang
    4. Filter Transaksi
    5. Cari Transaksi
    6. Keluar
    ```
2. User masukkan angka pilihan.
3. Program baca pilihan dan jalankan switch-case:
    - 1 → tambahTransaksi()
    - 2 → tampilkanTransaksi()
    - 3 → tampilkanTotal()
    - 4 → filterTransaksi()
    - 5 → cariTransaksi()
    - 6 → keluar dari loop.

4. Setelah fungsi selesai dijalankan, program kembali ke menu sampai user pilih 6.

5. Program tampilkan pesan “Program selesai.” dan berhenti.