#include <iostream>
#include <string>
using namespace std;

const int MAX_TRANSAKSI = 100;

struct Transaksi {
    string jenis;     
    string kategori; // pemasukan atau pengeluaran
    int jumlah;
    string tanggal;
};

// global static array
Transaksi daftar[MAX_TRANSAKSI];

int totalTransaksi = 0;

// Deklarasi terkait fitur fitur yang dibuat
void tambahTransaksi(Transaksi d[]) {
    if(totalTransaksi == MAX_TRANSAKSI){
        cout << "Maaf transaksi sudah penuh!";
    }else{
        cout << "Masukkan jenis transaksi (pemasukan/pengeluaran) :" ;
        cin >> d[totalTransaksi].jenis;

        cin.ignore();
        cout << "Masukkan kategori barang" ;
        getline(cin,d[totalTransaksi].kategori);

        cin.ignore();
        cout << "Masukkan nominal : ";
        cin >> d[totalTransaksi].jumlah;

        cout << "Masukkan Tanggal :";
        getline(cin,d[totalTransaksi].tanggal);

        totalTransaksi++;
    }

}

void tampilkanTransaksi(Transaksi d[]){
    if(totalTransaksi == 0){
        cout << "Belum ada transaksi." << endl;
    }else{
        for(int i = 0 ; i < totalTransaksi;i++){
            cout << "No " << i+1 << " [ " << d[i].jenis << " ]" << "Kategori " << d[i].kategori << "- Rp " << d[i].jumlah << " ( " << d[i].tanggal << " )" << endl;
        }
    }
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
            tambahTransaksi(daftar);
            break;

            case 2:
            tampilkanTransaksi(daftar);
            break;

            case 3:
            tampilkanTotal();
            break;

            //case 4:
void filterTransaksi() {
    if (totalTransaksi == 0) {
        cout << "Belum ada transaksi." << endl;
        return;
    }

    string filter;
    cout << "=== Filter Transaksi ===";
    cout << "Transaksi Apa? (Pemasukan/Pengeluaran): ";
    cin >> filter;

    cout << "HASIL FILTER (" << filter << "):";

    bool ada = false;
    for (int i = 0; i < totalTransaksi; i++) {
        if (daftar[i].kategori == filter) {
            ada = true;

            cout << "No " << i+1
                 << " | " << daftar[i].jenis
                 << " | Rp " << daftar[i].jumlah
                 << " | " << daftar[i].tanggal << endl;
        }
    }

    if (!ada) {
        cout << "Tidak ada transaksi kategori '" << filter << "'" endl;
    }
}

            
            break;

            case 5:
            cariTransaksi();
            break;
        }


    } while (pilihan <= 5 && pilihan != 0);

    return 0;
}



