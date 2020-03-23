#include "list_relasi.h"

adrRelasi alokasi(adrBarang P, adrToko C){
    adrRelasi Q = new elmRelasi;
    toko(Q) = C;
    barang(Q) = P;
    next(Q) = NULL;
    return Q;
}

adrRelasi findElm(listRelasi L, adrBarang P, adrToko C){
    adrRelasi Q = first(L);
    while(Q != NULL) {
        if(barang(Q)==P && toko(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void printInfo(listRelasi L){
    if(first(L) == NULL){
        cout << "List Kosong!" << endl;
    }else{
        adrRelasi P = first(L);
        while(next(P) != first(L)) {
            cout<<info(barang(P))<<" -> "<<info(toko(P))<<endl;
            P = next(P);
        }
        cout<<info(barang(P))<<" -> "<<info(toko(P))<<endl;
        cout << endl;
    }
}

void createList(listRelasi &L){
    first(L) = NULL;
}

void insertFirst(listRelasi &L, adrRelasi P){
    if(first(L) == NULL){
        first(L) = P;
        next(P) = first(L);
    }else{
        adrRelasi Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(P) = first(L);
        first(L) = P;
        next(Q) = first(L);
    }
}

void insertLast(listRelasi &L, adrRelasi P){
    if(first(L) == NULL){
        first(L) = P;
        next(P) = first(L);
    }else{
        adrRelasi Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
}

void insertAfter(adrRelasi Prec, adrRelasi P){

}

void deleteFirst(listRelasi &L, adrRelasi &P){
    if(first(L) == NULL){
        cout << "List Kosong!" << endl;
    }else if(next(first(L)) == NULL){
        first(L) = NULL;
        next(P) = NULL;
    }else{
        P = first(L);
        adrRelasi Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        first(L) = next(P);
        next(Q) = first(L);
        next(P) = NULL;

    }
}

void deleteLast(listRelasi &L, adrRelasi &P){
    if(first(L) == NULL){
        cout << "List Kosong!" << endl;
    }else if(next(first(L)) == NULL){
        first(L) = NULL;
        next(P) = NULL;
    }else{
        P = first(L);
        while(next(P)!= first(L)){
            P = next(P);
        }
        next(next(P)) = NULL;
        next(P) = first(L);
    }
}

void deleteAfter(adrRelasi Prec, adrRelasi &P){

}
