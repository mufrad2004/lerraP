#include "header.h"


// ? Main program (10)
int main(){
    judul();
    int pilihan;
    listDokter ld;
    listPasien lp;
    string namaDokter;
    string namaPasien;
    adrDokter hapusDokter;
    adrRelasi hapusRelasi;
    buatListDokter(ld);
    buatListPasien(lp);


    pilihan = menuTugas();
    while (pilihan != 0) {
        judul();
        if (pilihan == 1) {
            // Masukkan data dokter
            inputDokter(ld);
        } else if (pilihan == 2) {
            // Masukkan data pasien
            inputPasien(lp);
        } else if (pilihan == 3) { 
            // Masukkan data Relasi
            inputDataRelasi(ld, lp);
        } else if (pilihan == 4) {
            // Show All Dokter
            showAllDokter(ld);
        } else if (pilihan == 5) {
            // Show All Pasien
            showAllPasien(lp);
        } else if (pilihan == 6) {
            // Show All Data Histori
            showAll(ld);
        } else if (pilihan == 7) {
            // Hapus Data Dokter
            cout << "-----------------------------------------------------------" << endl;
            showAllDokter(ld);
            cout << "-----------------------------------------------------------" << endl;
            cout << "Masukkan Nama Dokter Yang Ingin Dihapus : ";
            cin >> namaDokter;
            deleteDokter(ld, hapusDokter, namaDokter);
        } else if (pilihan == 8) {
            // Hapus Data Pasien pada Dokter X
            cout << "-----------------------------------------------------------" << endl;
            showAllPasien(lp);
            cout << "-----------------------------------------------------------" << endl;
            cout << "Masukkan Nama Pasien : ";
            cin >> namaPasien;

            cout << "-----------------------------------------------------------" << endl;
            showAllDokter(ld);
            cout << "-----------------------------------------------------------" << endl;
            cout << "Masukkan Nama Dokter : ";
            cin >> namaDokter;
            deleteChildXDokterX(ld, namaPasien, namaDokter, hapusRelasi);

            if (hapusRelasi != NULL){
                cout << "Relasi Berhasil Dihapus" <<endl;
            }
        } else if (pilihan == 9) {
            // Jumlah Pasien Dokter X
            cout << "-----------------------------------------------------------" << endl;
            showAllDokter(ld);
            cout << "-----------------------------------------------------------" << endl;
            cout << "Masukkan Nama Dokter : ";
            cin >> namaDokter;
            cout << "Jumlah Pasien Dokter " << namaDokter << " : "<< JmlPasienDokterX(ld, namaDokter)  << " pasien"<< endl;
        }else if (pilihan == 10){
            cout << "Masukkan nama pasien : " ;
            cin >> namaPasien;
            deletePasienX(ld,lp,namaPasien); 
        }
        cout << endl;
        pilihan = menuTugas();
    }
}