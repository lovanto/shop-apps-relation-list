#include "list_toko.cpp"
#include "list_barang.cpp"
#include "list_relasi.cpp"

listBarang LBarang;
listToko LToko;
listRelasi LRelasi;

adrBarang PBarang;
adrToko PToko;
adrRelasi PRelasi;

void pilihMenu(int menu){
    string inputUser;
    switch(menu){
    case 1:
        cout << "Masukan nama toko: ";
        cin >> inputUser;
        PToko = alokasi(inputUser);
        insertFirst(LToko, PToko);
        cout << "Data Berhasil Ditambahkan!" << endl;
    break;
    case 2:
        cout << "Masukan nama barang: ";
        cin >> inputUser;
        PBarang = alokasiBarang(inputUser);
        insertLast(LBarang, PBarang);
        cout << "Data Berhasil Ditambahkan!" << endl;
    break;
    case 3:

    break;
    case 4:

    break;
    case 5:

    break;
    case 6:

    break;
    case 7:

    break;
    case 8:

    break;
    case 9:

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
    cout << "9. Keluar." << endl;
    cout << "Menu? ";
    cin >> menu;
    pilihMenu(menu);
    cout << endl;
    cout << endl;
}

int main()
{
    createList(LBarang);
    createList(LToko);
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
