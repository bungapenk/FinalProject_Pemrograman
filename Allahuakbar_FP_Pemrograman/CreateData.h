#ifndef CREATEDATA_H
#define CREATEDATA_H


class CreateData
{
int id;
    public:

        char nama[10][10];
        char tanggal[10][10];
        char jam[10][10];
        int lama[10];
        int jml;
        int total;

        void addDataPenyewa();
        void outputPenyewa();
        int getID();


};

#endif // CREATEDATA_H
