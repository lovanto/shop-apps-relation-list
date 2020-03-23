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

struct List_child{
    adrToko first;
    adrToko last;
};

#endif // LIST_TOKO_H_INCLUDED
