#ifndef listRelasi_H_INCLUDED
#define listRelasi_H_INCLUDED

#include "listRelasi.h"
#include "list_child.h"
#include "list_parent.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmRelasi *adrRelasi;

struct elmRelasi{
    adrRelasi next;
    adrToko toko;
    adrBarang barang;
};

struct listRelasi{
    adrRelasi first;
};

adrRelasi alokasi( adrBarang P, adrToko C);
adrRelasi findElm(listRelasi L, adrBarang P, adrToko C);
void printInfo(listRelasi L);

void createList(listRelasi &L);
void insertFirst(listRelasi &L, adrRelasi P);
void insertLast(listRelasi &L, adrRelasi P);
void insertAfter(adrRelasi Prec, adrRelasi P);
void deleteFirst(listRelasi &L, adrRelasi &P);
void deleteLast(listRelasi &L, adrRelasi &P);
void deleteAfter(adrRelasi Prec, adrRelasi &P);

#endif // listRelasi_H_INCLUDED
