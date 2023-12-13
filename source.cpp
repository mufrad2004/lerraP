#include "header.h"

// ? Buat List
void buatListDokter(listDokter &l) {
    l.first = NULL;
}
void buatListPasien(listPasien &l){
    l.first = NULL;
}

// ? Buat Elemen
adrDokter buatElmDokter(InfoDokter data){
    adrDokter p = new elmDokter;
    p->info = data;
    p->nextDokter = NULL;
    p->nextRelasi = NULL;
    return p;    
}

adrPasien buatElmPasien(InfoPasien data){
    adrPasien p = new elmPasien;
    p->info = data;
    p->nextPasien = NULL;
    return p;
}

adrRelasi buatElmRelasi(InfoRelasi data){
    adrRelasi p = new elmRelasi;
    p->info = data;
    p->nextPasien = NULL;
    p->nextRelasi = NULL;
    return p;
}

// ? 1. Insert data parent dari depan/belakang (5)
void insertDokter(listDokter &l , adrDokter p){
    // ? insert first
    if (l.first == NULL){
        l.first = p;
    }else {
        p->nextDokter = l.first;
        l.first = p;
    }
}

// ? 2. Show all data parent (5)
void showAllDokter(listDokter l){
    adrDokter p = l.first;
    int i = 1;
    if (l.first == NULL) {
        cout << "List Dokter Kosong" <<endl;
    }else {
        while(p != NULL){
            cout << "Dokter " << i << " : " << endl; 
            cout << "   -Nama   : " << p->info.nama << endl;
            cout << "   -Kode   : " << p->info.kode << endl;
            cout << "   -Umur   : " << p->info.umur << endl;
            cout << "   -Bidang : " << p->info.bidang << endl;
            i++;
            p = p->nextDokter;
        }
    }
}

void showAllPasien(listPasien l){
    adrPasien p = l.first;
    int i = 1;
    if(l.first ==NULL){
        cout << "List Pasien Kosong" << endl;
    }else {
        while(p != NULL){
            cout << "Pasien " << i << " : " << endl; 
            cout << "   -Nama   : " << p->info.nama << endl;
            cout << "   -Nik   : " << p->info.nik << endl;
            cout << "   -Usia   : " << p->info.usia << endl;
            i++;
            p = p->nextPasien;
        }
    }
}

// ? 3. Menghapus data parent beserta relasinya (15)
void deleteDokter(listDokter &l , adrDokter &p, string namaDokter){
    adrDokter prec = l.first;
    p = cariDokter(l, namaDokter);
    if (p == NULL) {
        cout << "Data dokter tidak ditemukan" << endl;
    } else {
        if (p == l.first) {
            deleteFirstDokter(l, p);
        } else if (p->nextDokter == NULL) {
            deleteLastDokter(l, p);
        } else {
            while (prec->nextDokter != p) {
                prec = prec->nextDokter;
            }
            deleteAfterDokter(l, prec, p);
        }
    }
}

void deleteFirstDokter(listDokter &l, adrDokter &p){
    p = l.first;
    l.first =  p->nextDokter;
    p->nextDokter = NULL;
    delete(p);
}

void deleteLastDokter(listDokter &l, adrDokter &p){
    adrDokter q = l.first;
    while (q->nextDokter != NULL) {
        q = q->nextDokter;
    }
    p = q->nextDokter;
    q->nextDokter = NULL;
    delete(p);
}

void deleteAfterDokter(listDokter &l, adrDokter prec, adrDokter &p){
    p = prec->nextDokter;
    prec->nextDokter = p->nextDokter;
    p->nextDokter = NULL;
    delete(p);
}

// ? 4. Mencari data parent (5)
adrDokter cariDokter(listDokter l, string namaDokter){
    adrDokter p;
    if (l.first == NULL){
        p = NULL;
    }else {
        p = l.first;
        while(p != NULL && p->info.nama != namaDokter){
            p = p->nextDokter;
        }
    }
    return p;
}

// ? 5. Mencari data child (5)
adrPasien cariPasien(listPasien l, string namaPasien){
    adrPasien p;
    if (l.first == NULL){
        p = NULL;
    }else {
        p = l.first;
        while(p != NULL && p->info.nama != namaPasien){
            p = p->nextPasien;
        }
    }
    return p;
}

// ? 6. Menambahkan data child (5)
void insertPasien(listPasien &l , adrPasien p){
    // ? insert last
    adrPasien q ;
    if(l.first == NULL){
        l.first = p;
    }else {
        q = l.first;
        while(q->nextPasien != NULL){
            q = q->nextPasien;
        }
        q->nextPasien = p;
    }
}

// ? 7. Menghubungkan data parent ke data child (5)
void insertRelasi(listDokter &l, adrDokter p, adrRelasi q){
    // ? Insert Last
    adrRelasi r = p->nextRelasi;
    if (r == NULL){
        p->nextRelasi = q;
    } else {
        while(r->nextRelasi != NULL){
            r = r->nextRelasi;
        }
        r->nextRelasi = q;        
    }
}

// ? 8. Menampilkan seluruh data parent beserta childnya (15)
void showAll(listDokter l){
    adrDokter p;
    adrRelasi q;
    int i = 1;
    int j;
    if (l.first == NULL){
        cout << "List Dokter Kosong" <<endl;
    }else {
        p = l.first;
        while(p != NULL){
            cout << "Dokter " << i << " : " << endl; 
            cout << "   -Nama   : " << p->info.nama << endl;
            cout << "   -Kode   : " << p->info.kode << endl;
            cout << "   -Umur   : " << p->info.umur << endl;
            cout << "   -Bidang : " << p->info.bidang << endl;
            cout << "   -Pasien yang ditangani : " << endl;
            q = p->nextRelasi;
            j = 1;
            while(q != NULL){
                cout << "       -Pasien " << j << " : " << endl;
                cout << "           -Nama   : " << q->nextPasien->info.nama << endl;
                cout << "           -NIK    : " << q->nextPasien->info.nik << endl;
                cout << "           -Usia   : " << q->nextPasien->info.usia << endl;
                cout << "           -Obat   : " << q->info.obat << endl;
                j++;
                q = q->nextRelasi;
            }
            i++;
            p = p->nextDokter;
        }
    }
}

// ? 9. Mencari data child pada parent tertentu (10)
adrRelasi CariChildXDokter(listDokter l, string namaDokter, string namaPasien){
    adrDokter p = cariDokter(l, namaDokter);
    adrRelasi q = p->nextRelasi;
    if (p == NULL) {
        cout << "Data dokter tidak ditemukan" << endl;
    } else {
        while (q != NULL) {
            if (q->nextPasien->info.nama == namaPasien) {
                return q;
            }
            q = q->nextRelasi;
        }
    }
    return NULL;
}

// ? 10. Menghapus data child pada parent tertentu beserta relasinya (15)
void deleteFirstRelasi(adrDokter p, adrRelasi &r){
    r = p->nextRelasi;
    p->nextRelasi = r->nextRelasi;
    r->nextRelasi = NULL;
    delete(r);
}

void deleteLastRelasi(adrDokter p, adrRelasi &r){
    adrRelasi q = p->nextRelasi;
    while (q->nextRelasi->nextRelasi != NULL) {
        q = q->nextRelasi;
    }
    r = q->nextRelasi;
    q->nextRelasi = NULL;
    delete(r);
}

void deleteAfterRelasi(adrDokter p, adrRelasi prec, adrRelasi &r){
    r = prec->nextRelasi;
    prec->nextRelasi = r->nextRelasi;
    r->nextRelasi = NULL;
    delete(r);
}

void deleteChildXDokterX(listDokter &l, string namaPasien , string namaDokter, adrRelasi &q){
    adrDokter p = cariDokter(l, namaDokter);
    adrRelasi prec;
    if (l.first == NULL){
        cout << "List Dokter Kosong " << endl;
    }else {
        if (p->nextRelasi == NULL){
            cout << "Dokter tidak memiliki pasien"<<endl;
        }else {
            q = p->nextRelasi;

            while(q != NULL && q->nextPasien->info.nama != namaPasien){
                q = q->nextRelasi;
            }

            if (q == NULL){
                // ? Kalo gk ketemu
                cout << "Tidak ada nama pasien " << namaPasien << endl;
                
            }else {
                // ? Kalo ketemu

                if (q == p->nextRelasi) {
                    deleteFirstRelasi(p, q);
                }else if (q->nextRelasi == NULL){
                    deleteLastRelasi(p, q);
                }else {
                    prec = p->nextRelasi;
                    while(prec->nextRelasi != q){
                        prec = prec->nextRelasi;
                    }
                    deleteAfterRelasi(p, prec, q);
                }
            }
        }
    }
}

// ? 11. Menghitung jumlah data child dari parent tertentu (5)
int JmlPasienDokterX(listDokter l, string namaDokter){
    adrDokter p = cariDokter(l, namaDokter);
    adrRelasi q;
    int jml = 0;
    q = p->nextRelasi;
    if (q == NULL) {
        jml == 0;
    }else {
        while (q != NULL){
            jml++;
            q = q->nextRelasi;
        }
    }
    return jml;
}



void clearTerminal(){
    system("clear");
}

void judul(){
    cout << "-----------------------------------------------------------" << endl;
    cout << "           TUGAS BESAR STRUKTUR DATA" << endl;
    cout << "       PROGRAM HISTORI REKAM MEDIS DOKTER" << endl;
    cout << "-----------------------------------------------------------" << endl;
}

int menuTugas(){
    int pilihan;
    cout << "1. Masukkan Data Dokter" << endl;
    cout << "2. Masukkan Data Pasien" <<endl;
    cout << "3. Masukkan Data Relasi" << endl;
    cout << "4. Tampilkan Seluruh Dokter" << endl;
    cout << "5. Tampilkan Seluruh Pasien" << endl;
    cout << "6. Tampilkan Seluruh Data Histori" << endl;
    cout << "7. Hapus Data Dokter" << endl;
    cout << "8. Hapus Data Child Pada Dokter X" << endl;
    cout << "9. Jumlah Pasien Dokter X" << endl;
    cout << "10. Delete Pasien" << endl;
    cout << "0. Exit"<< endl;
    cout << "-----------------------------------------------------------" << endl;
    cin >> pilihan;
    
    return pilihan;
}

void inputDokter(listDokter &l){
    InfoDokter data;
    adrDokter p;
    int i, n;
    cout << "Berapa Data Dokter yang ingin diinput? ";
    cin >> n;
    for (i = 1; i <= n; i++) {
        cout << "Masukkan nama Dokter " << ": ";
        cin >> data.nama;
        cout << "Masukkan kode Dokter " << ": ";
        cin >> data.kode;
        cout << "Masukkan umur Dokter " << ": ";
        cin >> data.umur;
        cout << "Masukkan bidang Dokter " << ": ";
        cin >> data.bidang;
        p = buatElmDokter(data);
        insertDokter(l, p);
        cout << endl;
    }
}


void inputPasien(listPasien &l){
    InfoPasien data;
    adrPasien p;
    int jmlData;
    cout << "Berapa Data Pasien Yang Ingin Diinput ? ";
    cin >> jmlData;
    for(int i =1 ; i<= jmlData ; i++ ){
        cout << "Data Pasien ke-" << i << " : " << endl;
        cout << "   -Masukkan Nama Pasien : ";
        cin >> data.nama;
        cout << "   -Masukkan Nik Pasien : ";
        cin >> data.nik;
        cout << "   -Masukkan Umur Pasien : ";
        cin >> data.usia;
        p = buatElmPasien(data);
        insertPasien(l,p);
        cout << endl;
    }
}

void inputDataRelasi(listDokter &l1 , listPasien l2){
    adrDokter p;
    adrRelasi q;
    adrPasien r;
    string namaDokter, namaPasien;
    InfoRelasi data;
    int jmlInput;
    cout << "Berapa Data Relasi Yang Ingin Diinput ? ";
    cin >> jmlInput;
    for(int i = 1 ; i <= jmlInput; i++){
        cout << "-----------------------------------------------------------" << endl;
        showAllDokter(l1);
        cout << "-----------------------------------------------------------" << endl;
        cout << "Masukkan Nama Dokter : ";
        cin >> namaDokter;
        p = cariDokter(l1,namaDokter);

        cout << "-----------------------------------------------------------" << endl;
        showAllPasien(l2);
        cout << "-----------------------------------------------------------" << endl;
        cout << "Masukkan Nama Pasien : ";
        cin >> namaPasien;
        r = cariPasien(l2,namaPasien);

        cout << "Masukkan Nama Obat : " ;
        cin >> data.obat;


        q = buatElmRelasi(data);
        q->nextPasien = r;
        insertRelasi(l1, p, q);
        cout << endl;
    }
}



void deleteFirstPasien(listPasien &l , adrPasien &p){
    p = l.first;
    l.first = p->nextPasien;
    p->nextPasien = NULL;
    delete(p);
}
void deleteLastPasien(listPasien &l , adrPasien &p){
    adrPasien q;
    q= l.first;
    while(q->nextPasien->nextPasien != NULL){
        q = q->nextPasien;
    }
    p = q->nextPasien;
    q->nextPasien = NULL;
    delete(p);
}


void deleteAfterPasien(listPasien &l, adrPasien prec , adrPasien &p){
    p = prec->nextPasien;
    prec->nextPasien = NULL;
    delete(p);
}


void deletePasienX(listDokter &l1, listPasien &l2, string nama){
    adrDokter p ;
    adrPasien q = cariPasien(l2,nama);
    adrPasien prec2;
    adrRelasi r,prec;
    if (q == NULL){
        cout << "Pasien " << nama << " tidak ditermukan" << endl;
    }else {
        p = l1.first;
        while(p != NULL){
            r = p->nextRelasi;
            prec = r;
            while(r != NULL){
                if (r->nextPasien == q){
                    if (r == p->nextRelasi){
                        deleteFirstRelasi(p,r);
                        prec = p->nextRelasi;
                        r = prec;
                    }else if (r->nextRelasi == NULL){
                        deleteLastRelasi(p,r);
                        r = prec->nextRelasi;
                    }else {
                        deleteAfterRelasi(p,prec,r);
                        r = prec->nextRelasi;
                    }
                } else {
                    prec = r;
                    r = r->nextRelasi;
                }
            }
            p = p->nextDokter;
        }

        if (q == l2.first){
            deleteFirstPasien(l2, q);
        }else if (q->nextPasien == NULL){
            deleteLastPasien(l2,q);
        } else {
            deleteAfterPasien(l2, prec2, q);
        }
    }



}
