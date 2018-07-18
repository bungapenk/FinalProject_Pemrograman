#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;

struct Penyewa {
	int pk;
	string nama;
	string tanggal;
	string jam;
	string lama;
};


int getOption();
void checkDatabase(fstream &data);
void writeData(fstream &data, int posisi, Penyewa &inputPenyewa);
int getDataSize(fstream &data);
Penyewa readData(fstream &data, int posisi);
void addDataPenyewa(fstream &data);
void displayDataPenyewa(fstream &data);


int main() {

	fstream data;

	checkDatabase(data);


	int pilihan = getOption();
	char is_continue;

	enum option{CREATE=1, READ, UPDATE, DELETE, FINISH};

	while (pilihan != FINISH) {

		switch (pilihan) {
				case CREATE:
					system("cls");
					cout << "===================" << endl;
					cout << "Tambah Data Penyewa" << endl;
					cout << "===================" << endl;
					addDataPenyewa(data);
					break;
				case READ:
					system("cls");
					cout << "============" << endl;
					cout << "Data Penyewa" << endl;
					cout << "============" << endl;
					displayDataPenyewa(data);
					break;
				case UPDATE:
					system("cls");
					cout << "=================" << endl;
					cout << "Ubah Data Penyewa" << endl;
						cout << "=================" << endl;
					break;
				case DELETE:
					system("cls");
					cout << "==================" << endl;
					cout << "Hapus Data Penyewa" << endl;
					cout << "==================" << endl;
					break;
				default:
					system("cls");
					cout << "================" << endl;
					cout << "Anda salah pilih" << endl;
					cout << "================" << endl;
					break;
			}

			label_continue:

			cout << "Lanjutkan? (y/n) : ";
			cin >> is_continue;
			if ((is_continue == 'y') || (is_continue == 'Y')) {
				pilihan = getOption();
			}
			else if ((is_continue == 'n') || (is_continue == 'N')) {
				system("cls");
				cout << "===========" << endl;
				cout << "Terimakasih" << endl;
				cout << "===========" << endl;
				break;
			}
			else {
				goto label_continue;
			}

	}
	system("cls");
	cout << "===========" << endl;
	cout << "Terimakasih" << endl;
	cout << "===========" << endl;

	cin.get();
	return 0;
}


void checkDatabase(fstream &data) {
	data.open("data.bin", ios::out | ios::in | ios::binary);

	// check file ada atau tidak
	if (data.is_open()) {
		cout << "Database ditemukan" << endl;
	}
	else {
		cout << "Database tidak ditemukan. Buat database baru" << endl;
		data.close();
		data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
	}
}


int getOption() {
	int input;

	system("cls");
	cout << "\n=======================" << endl;
	cout << "SEWA FUTSAL DENGAN CRUD" << endl;
	cout << "=======================" << endl;
	cout << "1. Tambah Data Penyewa" << endl;
	cout << "2. Lihat Data Penyewa" << endl;
	cout << "3. Ubah Data Penyewa" << endl;
	cout << "4. Hapus Data Penyewa" << endl;
	cout << "5. Keluar Program" << endl;
	cout << "=======================" << endl;
	cout << "Masukkan Pilihan [1-5] : ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return input;
}

void writeData(fstream &data, int posisi, Penyewa &inputPenyewa) {
	data.seekp((posisi - 1)*sizeof(Penyewa), ios::beg);
	data.write(reinterpret_cast<char*>(&inputPenyewa), sizeof(Penyewa));
}


int getDataSize(fstream &data) {
	int start, end;
	data.seekg(0, ios::beg);
	start = data.tellg();
	data.seekg(0, ios::end);
	end = data.tellg();
	return (end - start) / sizeof(Penyewa);
}


Penyewa readData(fstream &data, int posisi) {
	Penyewa readPenyewa;
	data.seekg((posisi - 1) * sizeof(Penyewa), ios::beg);
	data.read(reinterpret_cast<char*>(&readPenyewa), sizeof(Penyewa));
	return readPenyewa;
}


void addDataPenyewa(fstream &data) {

	Penyewa inputPenyewa, lastPenyewa;

	int size = getDataSize(data);

	cout << "Ukuran Data : " << size << endl;

	if (size == 0) {
		inputPenyewa.pk = 1;
	}
	else {
		lastPenyewa = readData(data,size);
		cout << "pk = " << lastPenyewa.pk << endl;
		inputPenyewa.pk = lastPenyewa.pk + 1;
	}


	// readData(data, size);

	cout << "Nama : ";
	getline(cin, inputPenyewa.nama);
	cout << "Tanggal main : ";
	getline(cin, inputPenyewa.tanggal);
	cout << "Jam main: ";
	getline(cin, inputPenyewa.jam);
	cout << "Lama main : ";
	getline(cin, inputPenyewa.lama);

	writeData(data, size+1, inputPenyewa);
}


void displayDataPenyewa(fstream &data) {
	int size = getDataSize(data);
	Penyewa showPenyewa;
	cout << "No.\tpk.\tNama.\tTanggal.\tJam.\tLama.\t" << endl;
	for (int i=1; i<=size; i++) {
		showPenyewa = readData(data,i);
		cout << i << "\t";
		cout << showPenyewa.pk << "\t";
		cout << showPenyewa.nama << "\t";
		cout << showPenyewa.tanggal << "\t";
		cout << showPenyewa.jam << "\t";
		cout << showPenyewa.lama << endl;
	}
}
