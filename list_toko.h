#ifndef LIST_TOKO_H_INCLUDED
#define LIST_TOKO_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef string infotype;
typedef struct elmToko *adrToko;

struct elmToko{
    infotype info;
    adrToko next;
    adrToko prev;
};

struct listToko{
    adrToko first;
    adrToko last;
};

adrToko alokasi(infotype x);
adrToko findElm(listToko L, infotype x);
void printInfo(listToko L);

void createList(listToko &L);
void insertFirst(listToko &L, adrToko P);
void insertLast(listToko &L, adrToko P);
void insertAfter(adrToko Prec, adrToko P);
void deleteFirst(listToko &L, adrToko &P);
void deleteLast(listToko &L, adrToko &P);
void deleteAfter(adrToko Prec, adrToko &P);

#endif // LIST_TOKO_H_INCLUDED
