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
    int totalPemasukan = 0;
    int totalPengeluaran = 0;

    for (int i = 0; i < totalTransaksi; i++){
        if (daftar[i].jenis == "pemasukan"){
            totalPemasukan += daftar[i].jumlah;
        } else if (daftar[i].jenis == "pengeluaran"){
            totalPengeluaran += daftar[i].jumlah;
        }
    }
    cout << "Total Pemasukan: Rp " << totalPemasukan << endl;
    cout << "Total Pengeluaran: Rp " << totalPengeluaran << endl;
    cout << "Saldo Akhir: Rp " << (totalPemasukan - totalPengeluaran) << endl;
}

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

void cariTransaksi() {
    if (totalTransaksi == 0) {
        cout << "Belum ada transaksi." << endl;
        return;
    }

    cout << "=== Cari Transaksi ===" << endl;
    cout << "Cari berdasarkan:" << endl;
    cout << "1. Jenis" << endl;
    cout << "2. Kategori" << endl;
    cout << "3. Tanggal" << endl;
    cout << "Pilih: ";

    int p;
    cin >> p;

    cin.ignore(); // bersihkan buffer

    string kunci;
    cout << "Masukkan kata kunci : ";
    getline(cin, kunci);

    bool ada = false;

    cout << "\nHASIL PENCARIAN:" << endl;

    for (int i = 0; i < totalTransaksi; i++) {

        bool cocok = false;

        if (p == 1)
            cocok = (daftar[i].jenis == kunci);
        else if (p == 2)
            cocok = (daftar[i].kategori == kunci);
        else if (p == 3)
            cocok = (daftar[i].tanggal == kunci);

        if (cocok) {
            ada = true;
            cout << "No " << i + 1
                 << " | " << daftar[i].jenis
                 << " | " << daftar[i].kategori
                 << " | Rp " << daftar[i].jumlah
                 << " | " << daftar[i].tanggal
                 << endl;
        }
    }

    if (!ada) {
        cout << "Tidak ada transaksi dengan kata kunci '" << kunci << "'" << endl;
    }
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


