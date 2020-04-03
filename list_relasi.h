#ifndef listRelasi_H_INCLUDED
#define listRelasi_H_INCLUDED

#include "list_barang.h"
#include "list_toko.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define toko(P) P->toko
#define barang(P) P->barang

typedef struct elmRelasi *adrRelasi;

struct elmRelasi{
    adrRelasi next;
    adrToko toko;
    adrBarang barang;
};

struct listRelasi{
    adrRelasi first;
};

adrRelasi alokasi(adrBarang P, adrToko C);
adrRelasi findElm(listRelasi L, adrBarang P, adrToko C);
void printInfo(listRelasi L);
void printInfoByToko(listRelasi L, string toko);
void printInfoByItem(listRelasi L, string barang);
void printInfoBestAndWorst(listToko LT, listRelasi L);

void createList(listRelasi &L);
void insertFirst(listRelasi &L, adrRelasi P);
void insertLast(listRelasi &L, adrRelasi P);
void insertAfter(adrRelasi Prec, adrRelasi P);
void deleteFirst(listRelasi &L, adrRelasi &P);
void deleteLast(listRelasi &L, adrRelasi &P);
void deleteAfter(adrRelasi Prec, adrRelasi &P);
void deleteDataToko(listRelasi &LR, listToko &LT, adrToko &PToko, adrRelasi &PRelasi, infotype T);
void deleteDataBarang(listRelasi &LR, listBarang &LB, adrBarang &PBarang, adrRelasi &PRelasi, infotype T);

void maxJual(listToko LT, listRelasi L);
void minJual(listToko LT, listRelasi L);


#endif // listRelasi_H_INCLUDED
