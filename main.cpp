#include "list_toko.cpp"
#include "list_barang.cpp"
#include "list_relasi.cpp"
#include <stdlib.h>

listBarang LBarang;
listToko LToko;
listRelasi LRelasi;

adrBarang PBarang;
adrToko PToko;
adrRelasi PRelasi;

void pilihMenu(int menu){
    string toko;
    string barang;
    switch(menu){
    case 1:
        cout << "TAMBAH DATA TOKO" << endl;
        cout << "Masukan nama toko: ";
        cin >> toko;
        PToko = alokasi(toko);
        insertFirst(LToko, PToko);
        cout << "Data Berhasil Ditambahkan!" << endl;
    break;
    case 2:
        cout << "TAMBAH DATA BARANG" << endl;
        cout << "Masukan nama barang: ";
        cin >> barang;
        PBarang = alokasiBarang(barang);
        insertLast(LBarang, PBarang);
        cout << "Data Berhasil Ditambahkan!" << endl;
    break;
    case 3:
        cout << "TAMBAH DATA RELASI" << endl;
        cout << "Masukan nama barang: ";
        cin >> barang;
        PBarang = findElm(LBarang, barang);
        cout << endl;
        cout << "Masukan nama toko: ";
        cin >> toko;
        PToko = findElm(LToko, toko);
        cout << endl;
        PRelasi = alokasi(PBarang, PToko);
        insertFirst(LRelasi,PRelasi);
        cout << "Data Berhasil Ditambahkan!" << endl;
    break;
    case 4:
        //hapus data toko
    break;
    case 5:
        //hapus data barang
    break;
    case 6:
        printInfo(LRelasi);
    break;
    case 7:
        //tampil seluruh data barang oleh toko tertentu
    break;
    case 8:
        //tampil seluruh data toko dan barang tertentu
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
    cout << endl;
}

int main()
{
    createList(LBarang);
    createList(LToko);
    createList(LRelasi);
    viewMenu();

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
    PToko = findElm(LToko, "Danhil Menn");
    PRelasi = alokasi(PBarang, PToko);
    insertFirst(LRelasi,PRelasi);
    printInfo(LRelasi);

    return 0;
}
