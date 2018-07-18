#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include <fstream>
#include "CreateData.h"
#include "ReadData.h"

using namespace std;

void ReadData::showDataPenyewa() {
    for (int i = 0; i< jml; i++) {
		cout << "Nama Anda : " << nama[i] << endl;
		cout << "Tanggal Main : " << tanggal[i] << endl;
		cout << "Jam Main : " << jam[i] << endl;
		cout << "Lama Main : " << lama[i] << endl;
		// Menghitung total bayar dengan biaya /jam adalah Rp.90.000,-
		 total = lama[i] * 90000;
		cout << "Total Bayar : " << total << endl;
    }
}
