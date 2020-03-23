#ifndef LIST_BARANG_H_INCLUDED
#define LIST_BARANG_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

typedef string infotype;
typedef struct elmBarang *adrBarang;

struct elmBarang {
    infotype info;
    adrBarang next;
};

struct listBarang {
    adrBarang first;
};

adrBarang alokasiBarang(infotype x);
adrBarang findElm(listBarang L, infotype x);
void printInfo(listBarang L);

void createList(listBarang &L);
void insertFirst(listBarang &L, adrBarang P);
void insertAfter(listBarang &L, adrBarang Prec, adrBarang P);
void insertLast(listBarang &L, adrBarang P);
void deleteFirst(listBarang &L, adrBarang &P);
void deleteLast(listBarang &L, adrBarang &P);
void deleteAfter(listBarang &L, adrBarang Prec, adrBarang &P);

#endif // LIST_BARANG_H_INCLUDED
