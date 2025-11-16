#include <iostream>
#include <string>
using namespace std;

const int MAX_TRANSAKSI = 100;

struct Transaksi {
    string jenis;     
    string kategori;
    int jumlah;
    string tanggal;
};

// global static array
Transaksi daftar[MAX_TRANSAKSI];
int totalTransaksi = 0;

// Deklarasi terkait fitur fitur yang dibuat
void tambahTransaksi() {
    cout << "Fitur transaksi" << endl;
}

void tampilkanTransaksi(){
    cout << "Fitur Menampilkan Transaksi" << endl;
}

void tampilkanTotal() {
    cout << "Fitur Menampilkan Total Uang" << endl;
}

void filterTransaksi() {
    cout << "Fitur Filter Transaksi" << endl;
}

void cariTransaksi() {
    cout << "Fitur Mencari Transaksi" << endl;
}

void menu() {
    cout << " ==============================" << endl;
    cout << "|     SILAHKAN PILIH MENU      |" << endl;
    cout << " ==============================" << endl << endl;
    cout << "1. Tambah Trensaksi" << endl;
    cout << "2. Lihat Semua Transaksi" << endl;
    cout << "3. Lihat Total Uang" << endl;
    cout << "4. Filter Transaksi" << endl;
    cout << "5. Cari Transaksi" << endl;
    cout << "0. Keluar" << endl; 
}

// entry point program
int main() {
    int pilihan;

    do {
        cout << endl << endl;
        menu();
        cout << endl << endl;
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
            tambahTransaksi();
            break;

            case 2:
            tampilkanTransaksi();
            break;

            case 3:
            tampilkanTotal();
            break;

            case 4:
            filterTransaksi();
            break;

            case 5:
            cariTransaksi();
            break;
        }


    } while (pilihan <= 5 && pilihan != 0);

    return 0;
}



