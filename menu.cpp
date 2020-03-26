#include "list_toko.cpp"
#include "list_barang.cpp"
#include "list_relasi.cpp"
#include <stdlib.h>
#include <string>

listBarang LBarang;
listToko LToko;
listRelasi LRelasi;

adrBarang PBarang;
adrToko PToko;
adrRelasi PRelasi;

void pilihMenu(int menu){
    string toko;
    string barang;
    getline(cin, toko);
    switch(menu){
    case 1:
        cout << "TAMBAH DATA TOKO" << endl;
        cout << "Masukan nama toko: ";
        getline(cin, toko);
        PToko = alokasi(toko);
        insertFirst(LToko, PToko);
        cout << "Data Berhasil Ditambahkan!" << endl;
    break;
    case 2:
        cout << "TAMBAH DATA BARANG" << endl;
        cout << "Masukan nama barang: ";
        getline(cin, barang);
        PBarang = alokasiBarang(barang);
        insertLast(LBarang, PBarang);
        cout << "Data Berhasil Ditambahkan!" << endl;
    break;
    case 3:
        cout << "TAMBAH DATA RELASI" << endl;
        cout << "Masukan nama barang: ";
        getline(cin, barang);
        PBarang = findElm(LBarang, barang);
        cout << endl;
        cout << "Masukan nama toko: ";
        getline(cin, toko);
        PToko = findElm(LToko, toko);
        cout << endl;
        PRelasi = alokasi(PBarang, PToko);
        insertFirst(LRelasi,PRelasi);
        cout << "Data Berhasil Ditambahkan!" << endl;
    break;
    case 4:
        cout << endl;
        cout << "Masukan nama toko: ";
        getline(cin, toko);
        deleteDataToko(LRelasi, LToko, PToko, PRelasi, toko);
        printInfo(LToko);
        printInfo(LRelasi);
    break;
    case 5:
        deleteLast(LBarang, PBarang);
        deleteFirst(LBarang, PBarang);
        printInfo(LBarang);
        printInfo(LRelasi);
    break;
    case 6:
        cout << endl;
        cout << "DATA SEMUA TOKO dan BARANG DAGANGANNYA" << endl;
        cout << "======================================" << endl;
        printInfo(LRelasi);
    break;
    case 7:
        cout << endl;
        cout << "Masukan nama toko: ";
        getline(cin, toko);
        cout << endl;
        cout << "DATA " << toko << " dan BARANG DAGANGANNYA" << endl;
        cout << "======================================" << endl;
        printInfoByToko(LRelasi, toko);
    break;
    case 8:
        cout << endl;
        cout << "Masukan nama barang: ";
        getline(cin, barang);
        cout << endl;
        cout << "DATA TOKO DENGAN BARANG " << barang << endl;
        cout << "======================================" << endl;
        printInfoByItem(LRelasi, barang);
    break;
    case 9:
        //tampil data toko terlengkap dan tidak lengkap
    break;
    case 10:
        cout << "End Program...";
        exit(3);
    break;
    }
}

void viewMenu(){
    int menu;
    cout << endl;
    cout << "========================================" << endl;
    cout << "     ===   Data Penjualan    ===    " << endl;
    cout << "    ===   Ruko Apa Adanya   ===    " << endl;
    cout << "========================================" << endl;
    cout << "1. Tambah Data Toko." << endl;
    cout << "2. Tambah Data Barang." << endl;
    cout << "3. Tambah Data Relasi." << endl;
    cout << "4. Hapus Data Toko." << endl;
    cout << "5. Hapus Data Barang." << endl;
    cout << "6. Tampil Semua Data Toko." << endl;
    cout << "7. Tampil Data Toko Tertentu." << endl;
    cout << "8. Tampil Data Barang Tertentu." << endl;
    cout << "9. Tampil Toko Terlengkap dan Tidak Lengkap." << endl;
    cout << "10. Keluar." << endl;
    cout << "Menu? ";
    cin >> menu;
    pilihMenu(menu);
}

void init(){
    printInfo(LBarang);
    PBarang = alokasiBarang("Pepsoden");
    insertFirst(LBarang, PBarang);
    printInfo(LBarang);
    PBarang = alokasiBarang("Seniker");
    insertLast(LBarang, PBarang);
    printInfo(LBarang);
    PBarang = alokasiBarang("Silper Kuinn");
    insertFirst(LBarang, PBarang);
    printInfo(LBarang);

    printInfo(LToko);
    PToko = alokasi("Maju Jaya Dloee");
    insertFirst(LToko, PToko);
    printInfo(LToko);
    PToko = alokasi("Toto Toko");
    insertLast(LToko, PToko);
    printInfo(LToko);
    PToko = alokasi("Toko Dani");
    insertLast(LToko, PToko);
    printInfo(LToko);
    PToko = alokasi("Danhil Menn");
    insertFirst(LToko, PToko);
    printInfo(LToko);

    PBarang = findElm(LBarang, "Seniker");
    PToko = findElm(LToko, "Toto Toko");
    PRelasi = alokasi(PBarang, PToko);
    insertFirst(LRelasi,PRelasi);
    printInfo(LRelasi);
    PBarang = findElm(LBarang, "Seniker");
    PToko = findElm(LToko, "Danhil Menn");
    PRelasi = alokasi(PBarang, PToko);
    insertLast(LRelasi,PRelasi);
    printInfo(LRelasi);
    PBarang = findElm(LBarang, "Pepsoden");
    PToko = findElm(LToko, "Maju Jaya Dloee");
    PRelasi = alokasi(PBarang, PToko);
    insertFirst(LRelasi,PRelasi);
    printInfo(LRelasi);PBarang = findElm(LBarang, "Silper Kuinn");
    PToko = findElm(LToko, "Toto Toko");
    PRelasi = alokasi(PBarang, PToko);
    insertLast(LRelasi,PRelasi);
    printInfo(LRelasi);
}

void createListNow(){
    createList(LBarang);
    createList(LToko);
    createList(LRelasi);
}
