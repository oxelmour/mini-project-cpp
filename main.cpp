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
        cout << "\n[!] Maaf, penyimpanan transaksi sudah penuh!" << endl;
    }else{
        cout << "\n========================================" << endl;
        cout << "       TAMBAH TRANSAKSI BARU           " << endl;
        cout << "========================================" << endl;
        
        cout << "Masukkan Jenis (pemasukan/pengeluaran) : " ;
        cin >> d[totalTransaksi].jenis;

        cin.ignore();
        cout << "Masukkan Kategori                      : " ;
        getline(cin,d[totalTransaksi].kategori);

        // cin.ignore();
        cout << "Masukkan Nominal (Rp)                  : ";
        cin >> d[totalTransaksi].jumlah;

        cin.ignore();
        cout << "Masukkan Tanggal                       : ";
        getline(cin,d[totalTransaksi].tanggal);

        totalTransaksi++;
        cout << "\n[v] Transaksi berhasil disimpan!" << endl;
    }


    cout << endl << endl << endl << endl;
}

void tampilkanTransaksi(Transaksi d[]){
    cout << "\n========================================" << endl;
    cout << "           DAFTAR TRANSAKSI            " << endl;
    cout << "========================================" << endl;

    if(totalTransaksi == 0){
        cout << "        Belum ada data transaksi.       " << endl;
        cout << "========================================" << endl;
    }else{
        for(int i = 0 ; i < totalTransaksi;i++){
            cout << "No. " << i+1 << endl;
            cout << "----------------------------------------" << endl;
            cout << "Jenis    : " << d[i].jenis << endl;
            cout << "Kategori : " << d[i].kategori << endl;
            cout << "Nominal  : Rp " << d[i].jumlah << endl;
            cout << "Tanggal  : " << d[i].tanggal << endl;
            cout << "----------------------------------------" << endl;
        }
    }


    cout << endl << endl << endl << endl;
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
    
    cout << "\n========================================" << endl;
    cout << "           LAPORAN KEUANGAN            " << endl;
    cout << "========================================" << endl;
    cout << " Total Pemasukan   : Rp " << totalPemasukan << endl;
    cout << " Total Pengeluaran : Rp " << totalPengeluaran << endl;
    cout << "----------------------------------------" << endl;
    cout << " SALDO AKHIR       : Rp " << (totalPemasukan - totalPengeluaran) << endl;
    cout << "========================================" << endl;


    cout << endl << endl << endl << endl;
}

void filterTransaksi() {
    if (totalTransaksi == 0) {
        cout << "\n[!] Belum ada transaksi untuk difilter." << endl;
        return;
    }

    string filter;
    cout << "\n========================================" << endl;
    cout << "           FILTER TRANSAKSI            " << endl;
    cout << "========================================" << endl;
    cout << "Tampilkan (pemasukan/pengeluaran) : ";
    cin >> filter;

    cout << "\n>>> HASIL FILTER: " << filter << " <<<" << endl;

    bool ada = false;
    for (int i = 0; i < totalTransaksi; i++) {
        if (daftar[i].jenis == filter) {
            ada = true;
            cout << "----------------------------------------" << endl;
            cout << "No. " << i+1 << endl;
            cout << "Kategori : " << daftar[i].kategori << endl;
            cout << "Nominal  : Rp " << daftar[i].jumlah << endl;
            cout << "Tanggal  : " << daftar[i].tanggal << endl;
        }
    }

    if (!ada) {
        cout << "\n[!] Tidak ada transaksi dengan jenis '" << filter << "'" << endl;
    } else {
        cout << "----------------------------------------" << endl;
    }


    cout << endl << endl << endl << endl;
}

void cariTransaksi() {
    if (totalTransaksi == 0) {
        cout << "\n[!] Belum ada transaksi untuk dicari." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "            CARI TRANSAKSI             " << endl;
    cout << "========================================" << endl;
    cout << "Cari berdasarkan:" << endl;
    cout << "[1] Jenis (pemasukan/pengeluaran)" << endl;
    cout << "[2] Kategori" << endl;
    cout << "[3] Tanggal(1-30)" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Pilih (1-3): ";

    int p;
    cin >> p;

    cin.ignore(); // bersihkan buffer

    string kunci;
    cout << "Masukkan kata kunci : ";
    getline(cin, kunci);

    bool ada = false;

    cout << "\n>>> HASIL PENCARIAN <<<" << endl;

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
            cout << "----------------------------------------" << endl;
            cout << "No. " << i + 1 << endl;
            cout << "Jenis    : " << daftar[i].jenis << endl;
            cout << "Kategori : " << daftar[i].kategori << endl;
            cout << "Nominal  : Rp " << daftar[i].jumlah << endl;
            cout << "Tanggal  : " << daftar[i].tanggal << endl;
        }
    }

    if (!ada) {
        cout << "\n[!] Tidak ditemukan data dengan kata kunci '" << kunci << "'" << endl;
    } else {
        cout << "----------------------------------------" << endl;
    }

    cout << endl << endl << endl << endl;
}

void menu() {
    cout << " =======================================" << endl;
    cout << "|      APLIKASI MONEY MANAGEMENT       |" << endl;
    cout << " =======================================" << endl;
    cout << "| 1. Tambah Transaksi                   |" << endl;
    cout << "| 2. Lihat Semua Transaksi              |" << endl;
    cout << "| 3. Lihat Total Uang                   |" << endl;
    cout << "| 4. Filter Transaksi                   |" << endl;
    cout << "| 5. Cari Transaksi                     |" << endl;
    cout << "| 0. Keluar                             |" << endl; 
    cout << " =======================================" << endl;

    cout << endl << endl << endl << endl;
}

// entry point program
int main() {
    int pilihan;

    do {
        cout << endl;
        menu();
        cout << "Pilih Menu [0-5]: ";
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

    cout << "\nTerima kasih telah menggunakan aplikasi ini." << endl;
    return 0;
}


