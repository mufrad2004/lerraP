#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

struct InfoDokter {
    string nama, kode, bidang;
    int umur;
};

struct InfoPasien {
    string nama, nik;
    int usia;
};

struct InfoRelasi {
    string obat;
};

typedef struct elmDokter *adrDokter;
typedef struct elmRelasi *adrRelasi;
typedef struct elmPasien *adrPasien;

struct elmDokter {
    InfoDokter info;
    adrDokter nextDokter;
    adrRelasi nextRelasi;
};

struct elmRelasi {
    InfoRelasi info;
    adrRelasi nextRelasi;
    adrPasien nextPasien;
};

struct elmPasien{
    InfoPasien info;
    adrPasien nextPasien;
};


struct listDokter{
    adrDokter first;
};

struct listPasien{
    adrPasien first;
};

// ? Buat List
void buatListDokter(listDokter &l);
void buatListPasien(listPasien &l);

// ? Buat Elemen
adrDokter buatElmDokter(InfoDokter data);
adrPasien buatElmPasien(InfoPasien data);
adrRelasi buatElmRelasi(InfoRelasi data);

// ? 1. Insert data parent dari depan/belakang (5)
void insertDokter(listDokter &l , adrDokter p);

// ? 2. Show all data parent (5)
void showAllDokter(listDokter l);
void showAllPasien(listPasien l);

// ? 3. Menghapus data parent beserta relasinya (15)
void deleteDokter(listDokter &l , adrDokter &p, string nama);
void deleteFirstDokter(listDokter &l, adrDokter &p);
void deleteLastDokter(listDokter &l, adrDokter &p);
void deleteAfterDokter(listDokter &l, adrDokter prec, adrDokter &p);

// ? 4. Mencari data parent (5)
adrDokter cariDokter(listDokter l, string nama);

// ? 5. Mencari data child (5)
adrPasien cariPasien(listPasien l, string namaPasien);

// ? 6. Menambahkan data child (5)
void insertPasien(listPasien &l , adrPasien p);

// ? 7. Menghubungkan data parent ke data child (5)
void insertRelasi(listDokter &l, adrDokter p, adrRelasi q);

//!------------------------------------------------------------------------------------------------------------------------

// ? 8. Menampilkan seluruh data parent beserta childnya (15)
void showAll(listDokter l);

// ? 9. Mencari data child pada parent tertentu (10)
adrRelasi CariChildXDokter(listDokter l, string namaDokter, string namaPasien);

// ? 10. Menghapus data child pada parent tertentu beserta relasinya (15)
void deleteFirstRelasi(adrDokter l,adrRelasi &r);
void deleteLastRelasi(adrDokter l ,adrRelasi &r);
void deleteAfterRelasi( adrDokter l,adrRelasi prec,adrRelasi &r);
void deleteFirstPasien(listPasien &l , adrPasien &p);
void deleteLastPasien(listPasien &l , adrPasien &p);
void deleteAfterPasien(listPasien &l, adrPasien prec , adrPasien &p);



void deleteChildXDokterX(listDokter &l, string namaPasien , string namaDokter, adrRelasi &r);
void deletePasienX(listDokter &l1, listPasien &l2, string nama);

// ? 11. Menghitung jumlah data child dari parent tertentu (5)
int JmlPasienDokterX(listDokter l, string namaDokter);


// ? Tampilan Menu
void clearTerminal();

void judul();

int menuTugas();

void inputDokter(listDokter &l);
void inputPasien(listPasien &l);
void inputDataRelasi(listDokter &l1 , listPasien l2);


#endif