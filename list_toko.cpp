#include "list_toko.h"

adrToko alokasi(infotype x){
    adrToko P = new elmToko;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

adrToko findElm(listToko L, infotype x){
    if(first(L) == NULL){
        cout << "List Barang Kosong!" << endl;
        return NULL;
    }else{
        adrToko P = first(L);
        while(P != NULL){
            if(info(P) == x){
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}

void printInfo(listToko L){
    if(first(L) == NULL){
        cout << "List Kosong!" << endl;
    }else{
        adrToko P = first(L);
        int i = 1;
        cout << " == Data Toko == " << endl;
        while(P != NULL) {
            cout << i << ". " << info(P) << "." << endl;
            P = next(P);
            i++;
        }
        cout << endl;
    }
}

void createList(listToko &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirst(listToko &L, adrToko P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(listToko &L, adrToko P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfter(adrToko Prec, adrToko P){

}

void deleteFirst(listToko &L, adrToko &P){
    if(first(L) == NULL){
        cout << "List Kosong!" << endl;
    }else if(next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(first(L));
        info(P) = "";
        prev(P) = NULL;
        next(P) = NULL;
    }
}

void deleteLast(listToko &L, adrToko &P){
    if(first(L) == NULL){
        cout << "List Kosong!" << endl;
    }else if(next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
    }else{
        P = first(L);
        while(next(P)!= last(L)){
            P = next(P);
        }
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = NULL;
        info(P) = "";
        prev(P) = NULL;
        next(P) = NULL;
    }
}

void deleteAfter(adrToko Prec, adrToko &P){
    if(Prec == NULL){
        cout << "Tidak Ditemukan!" << endl;
    }else if(next(Prec) == NULL){
        cout << "Tidak Ada Data Untuk Dihapus!" << endl;
    }else{
        P = Prec;
        Prec = prev(P);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        info(P) = "";
        prev(P) = NULL;
        next(P) = NULL;
    }
}
