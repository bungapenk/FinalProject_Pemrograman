#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include <fstream>
#include "CreateData.h"
#include "ReadData.h"

using namespace std;

int getOption();
void saveData();
void readData();
void searchData(int idDicari);
void deleteData(int idDicari);


int main()
{
    /*cout << "Menulis ke file ....." << endl;
    saveData();
    */

    cout << "\n\nMembaca dari file ....." << endl;
    readData();

    cout << "\n\nMencari Data ....\n";
    searchData(0);

    cout << "\n\nMenghapus Data ....\n";
    deleteData(0);

    /*
	* ==============
	*   Menu Utama
	* ==============
	*/
    /*
	int pilihan = getOption();
	char is_continue;

	enum option{CREATE=1, READ, UPDATE, DELETE, FINISH};

	while (pilihan != FINISH) {

		switch (pilihan) {
				case CREATE:
					system("cls");
					cout << "=======================" << endl;
					cout << "  Tambah Data Penyewa  " << endl;
					cout << "=======================" << endl;
					CreateData obj1;
                    obj1.addDataPenyewa();
					break;
				case READ:
					system("cls");
					cout << "================" << endl;
					cout << "  Data Penyewa  " << endl;
					cout << "================" << endl;
					CreateData obj2;
                    obj2.outputPenyewa();
					break;
				case UPDATE:
					system("cls");
					cout << "=====================" << endl;
					cout << "  Ubah Data Penyewa  " << endl;
                    cout << "=====================" << endl;
					break;
				case DELETE:
					system("cls");
					cout << "======================" << endl;
					cout << "  Hapus Data Penyewa  " << endl;
					cout << "======================" << endl;
					break;
				default:
					system("cls");
					cout << "====================" << endl;
					cout << "  Anda salah pilih  " << endl;
					cout << "====================" << endl;
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
	cout << "===============" << endl;
	cout << "  Terimakasih  " << endl;
	cout << "===============" << endl;

	cin.get();
	*/
	return 0;
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

char fileName[30] = "filePenyewa.dat";

// menulis objek ke dalam file
void saveData () {
    CreateData obj1;
    obj1.addDataPenyewa();

    //proses simpan objek ke dalam file
    ofstream f;
    f.open(fileName, ios::binary | ios::app);
    f.write((char*)&obj1, sizeof(obj1) );
    f.close();
}

void readData() {
    CreateData obj1;
    ifstream f;
    f.open(fileName, ios::binary);

    while( f.read( (char*)&obj1, sizeof(obj1)) ) {
        obj1.outputPenyewa();
    }

    f.close();
}

void searchData(int idDicari) {
    CreateData obj1, idKetemu;
    int ketemu = 0;
    ifstream f;
    f.open( fileName, ios::binary );

    cout << "Masukkan ID yang dicari : ";
    cin >> idDicari;
    while( f.read( (char*)&obj1, sizeof(obj1) ) ) {
        // kalau nama ketemu
            if(obj1.getID() == idDicari) {
                idKetemu = obj1;
                ketemu = 1;

                break;
            }
    }

    if(ketemu == 0) {
        cout << "\n\nID yang dicari " << idDicari << " tidak ditemukan \n";
    }
    else{
        cout << "\nID yang dicari " << idDicari << " ditemukan :\n";
        idKetemu.outputPenyewa();
    }

    f.close();
}


void updateData(int idDicari) {
    CreateData obj1;
    fstream f;
    f.open( fileName, ios::in || ios::out )
}


void deleteData(int idDicari) {
    CreateData obj1;

    ifstream fi;
    fi.open(fileName, ios::binary);

    ofstream fo;
    fo.open("tmp.dat", ios::out | ios::binary);

    int ketemu = 0;

    cout << "Masukkan ID yang ingin dihapus : ";
    cin >> idDicari;
    while(fi.read( (char*)&obj1, sizeof(obj1) )) {
        if(obj1.getID() != idDicari) {
            fo.write( (char*) &obj1, sizeof(obj1) );
        }
        else{
            ketemu = 1;
        }
    }

    fi.close();
    fo.close();

    remove(fileName);
    rename("tmp.dat", fileName);

    if(ketemu == 1) {
        cout << "Data Penyewa dengan ID " << idDicari << " telah dihapus!\n";
    }

    else{
        cout << "Data Penyewa dengan ID " << idDicari << " tidak ditemukan\n";
    }
}

