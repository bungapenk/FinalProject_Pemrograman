#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include <fstream>
#include <vector>
#include <conio.h>
#include "CreateVector.h"

using namespace std;

void CreateVector::printVector() {
      arr[] = {25,10,53,64,65,96,17};

      //melakukan inisialisasi vector dengan array
      vector<int> vtr(arr, arr + sizeof(arr)/sizeof(int));

      cout << endl;
      cout << "========================" << endl;
      cout << "        GAME ANGKA      " << endl;
      cout << "    (Berbasis Vector)   " << endl;
      cout << "========================" << endl;
      cout << " Program mengenal Angka " << endl;
      cout << "------------------------" << endl;
      cout << "Isi Angka : ";
      for(int i = 0; i < vtr.size(); i++)
      {
            cout<<vtr[i]<<"  ";
      }
      cout << endl;
      cout<< "\nUkuran Angka             : "<<vtr.size()<<endl;
      cout<< "Kapasitas Angka          : "<<vtr.capacity()<<endl;
      cout<< "Angka Terdepan    : "<<vtr.front()<<endl;
      cout<< "Angka Terbelakang : "<<vtr.back()<<endl;
      cout<< "Elemen ke-5        : "<<vtr.at(4)<<endl;

      cout << endl;
      cout << "\n  Mengatur Ulang Ukuran Angka " << endl;
      cout << "------------------------------" << endl;
      vtr.resize(10,0);

      cout<<"Angka berubah jadi : ";
      for(int i = 0; i < vtr.size(); i++)
      {
            cout<<vtr[i]<<"  ";
      }
      cout << endl;
      cout << "\nUkuran Angka sekarang    : "<<vtr.size() << endl;
      cout << "Kapasitas Angka sekarang : "<<vtr.capacity() << endl;

      cout << endl;
      cout << "\n  Menghapus Enam Angka Pertama  " << endl;
      cout << "----------------------------------" << endl;

      vtr.erase(vtr.begin(), vtr.begin()+6);
      cout<<"Isi Angka Sekarang Jadi : ";
      for(int i = 0; i < vtr.size(); i++)
      {
            cout<<vtr[i]<<"  ";
      }

      _getche();
}
