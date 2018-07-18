#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include <fstream>
#include "CreateData.h"

using namespace std;

void CreateData::addDataPenyewa() {
    cout << "-------------------------------------" << endl;
    cout << "Masukkan jumlah penyewa : ";
    cin >> jml;
    cout << "Nomor yang anda suka [ID] : ";
    cin >> id;
	for (int i = 0; i< jml; i++) {
		cout << "Nama Penyewa : ";
		cin >> nama[i];
		cout << "Tanggal Main (dd/mm/yy) : ";
		cin >> tanggal[i];
		cout << "Jam (xx:xx) : ";
		cin >> jam[i];
		cout << "Lama Main (/jam) : ";
		cin >> lama[i];
	}
	cout << "-------------------------------------" << endl;
}

void CreateData::outputPenyewa() {
    cout << "-------------------------------------" << endl;
    cout << "Nomor yang anda suka [ID] : " << id << endl;
	for (int i = 0; i< jml; i++) {
		cout << "Nama Anda : " << nama[i] << endl;
		cout << "Tanggal Main : " << tanggal[i] << endl;
		cout << "Jam Main : " << jam[i] << endl;
		cout << "Lama Main : " << lama[i] << endl;
		// Menghitung total bayar dengan biaya /jam adalah Rp.90.000,-
		 total = lama[i] * 90000;
		cout << "Total Bayar : " << total << endl;
    }
    cout << "-------------------------------------\n" << endl;
}

int CreateData::getID() {
    return id;
}
