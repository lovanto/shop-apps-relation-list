#include "list_toko.cpp"
#include "list_barang.cpp"
#include "list_relasi.cpp"

int main()
{
    listBarang LBarang;
    //listToko LToko;
    //listRelasi LRelasi;

    adrBarang PBarang;
    //adrToko PToko;
    //adrRelasi PRelasi;

    createList(LBarang);
    printInfo(LBarang);
    PBarang = alokasiBarang("Pepsoden");
    insertFirst(LBarang, PBarang);
    printInfo(LBarang);
    PBarang = alokasiBarang("Seniker");
    insertFirst(LBarang, PBarang);
    printInfo(LBarang);
    PBarang = alokasiBarang("Silper Kuinn");
    insertFirst(LBarang, PBarang);
    printInfo(LBarang);

    return 0;
}
