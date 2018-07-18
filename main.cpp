#include <iostream>
#include <string>
#include <limits>
#include <stdlib.h>
#include <fstream>

using namespace std;


int getMenuUtama();

struct Penyewa{
    char nama[10][10];
    char tanggal[10][10];
    char jam[10][10];
    int lamaMain[10];
    int totalBayar;
    int jml;
}data;

class menuSatu{
public:
        
    void inputSatu() {
        cout << "Masukkan jumlah penyewa : ";
        cin >> data.jml;
        for(int i=0; i<data.jml;i++) {
            cout << "Nama Penyewa : ";
            cin >> data.nama[i];
            cout << "Tanggal Main (dd/mm/yy) : ";
            cin >> data.tanggal[i];
            cout << "Jam (xx:xx) : ";
            cin >> data.jam[i];
            cout << "Lama Main (/jam): ";
            cin >> data.lamaMain[i];
            cin.get();
        }

    }
};

class menuDua: public menuSatu{
public:
    void showData() {
        for(int j=0; j<data.jml;j++) {
            cout << "Nama Anda :" << data.nama[j] << endl;
            cout << "Tanggal Main" << data.tanggal[j] << endl;
            cout << "Jam Main : " << data.jam[j] << endl;
            cout << "Lama Main : " << data.lamaMain[j] << endl;
            // Menghitung total bayar dengan biaya /jam adalah Rp.90.000,-
            data.totalBayar = data.lamaMain[j] * 90000;
            cout << "Total Bayar : " << data.totalBayar << endl;
        }    
    }    
};

int main() {

    /*
    * ==============
    *   Menu Utama
    * ==============
    */
    int pilihan = getMenuUtama();
    string lanjut;

    menuSatu obj1;
    menuDua tampilData;

    while(pilihan != 4) {
        switch(pilihan) {    
        case 1:            
            system("cls");
            cout << "====================" << endl;
            cout << "  Isi Data Penyewa  " << endl;
            cout << "====================" << endl;
            obj1.inputSatu();
            break;
        case 2:
            system("cls");
            cout << "================" << endl;
            cout << "  Data Penyewa  " << endl;
            cout << "================" << endl;
            tampilData.showData();
            break;
        case 3:
            system("cls");
            cout << "Data penyewa terhapus!" << endl;                        
            break;           
        default:
            cout << "\n== Anda salah pilih ==" << endl;
            break;
        }

        balikLanjut:
        cout << "\n\nLanjutkan?(y/n) : ";
        cin >> lanjut;
        if((lanjut=="y") || (lanjut=="Y")) {
            lanjut = getMenuUtama();
        }
        else if((lanjut=="n") || (lanjut=="N")) {
            system("cls");
            cout << "===============" << endl;
            cout << "  Terimakasih  " << endl;
            cout << "===============" << endl;
            exit(0);
        }
        else {
            goto balikLanjut;
        }
    }
}    

int getMenuUtama() {
    int input;

    system("cls");
    cout << "=====================" << endl;
    cout << "  SEWA FUTSAL IF-04  " << endl;
    cout << "=====================" << endl;
    cout << "1. Sewa Lapangan" << endl;
    cout << "2. Tampilkan Penyewa" << endl;
    cout << "3. Hapus Penyewa" << endl;
    cout << "4. Keluar" << endl;
    cout << "=====================" << endl;
    cout << "Masukkan Pilihan [1-4] : ";
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    return input;
}