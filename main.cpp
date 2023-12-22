#include "header.h"


// ? Main program (10)
int main(){
    judul();
    int pilihan;
    listDokter ld;
    listPasien lp;
    string namaDokter;
    string namaPasien;
    adrDokter hapusDokter,d;
    adrPasien p;
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
        }else if (pilihan ==11){
            // Cari Pasien
            cout << "-----------------------------------------------------------" << endl;
            showAllPasien(lp);
            cout << "-----------------------------------------------------------" << endl;
            cout << "Masukkan nama Pasien : " ;
            cin >> namaPasien;
            p = cariPasien(lp,namaPasien);
            if (p != NULL){
                cout << "Data pasien " << namaPasien << " : " << endl;
                cout << "   -Nama   : " << p->info.nama << endl;
                cout << "   -Nik   : " << p->info.nik << endl;
                cout << "   -Usia   : " << p->info.usia << endl;
            }else {
                cout << "Pasien dengan nama" << namaPasien << " tidak ditemukan " << endl;
            }
        }else if (pilihan ==12){
            // Cari Dokter
            cout << "-----------------------------------------------------------" << endl;
            showAllDokter(ld);
            cout << "-----------------------------------------------------------" << endl;
            cout << "Masukkan nama Dokter : " ;
            cin >> namaDokter;
            d = cariDokter(ld,namaDokter);
            if (d != NULL){
                cout << "Data dokter " << namaDokter << " : " << endl;
                cout << "   -Nama   : " << d->info.nama << endl;
                cout << "   -Kode   : " << d->info.kode << endl;
                cout << "   -Umur   : " << d->info.umur << endl;
                cout << "   -Bidang : " << d->info.bidang << endl;
            }else {
                cout << "Dokter dengan nama " << namaDokter << " tidak ditemukan" << endl;
            }
        }
        cout << endl;
        pilihan = menuTugas();
    }

    return 0;
}