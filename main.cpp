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
void tambahTransaksi();
void tampilkanTransaksi();
void tampilkanTotal();
void filterTransaksi();
void cariTransaksi();
void menu();

// entry point program
int main() {
    menu();
    return 0;
}

// Implementasi kode 
void tambahTransaksi() {

}

void tampilkanTransaksi() {

}

void tampilkanTotal() {

}

void filterTransaksi() {

}

void cariTransaksi() {

}

void menu() {

}
