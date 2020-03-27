#include "list_barang.h"

adrBarang alokasiBarang(infotype x){
    adrBarang P = new elmBarang;
    info(P) = x;
    next(P) = NULL;
    return P;
}

adrBarang findElm(listBarang L, infotype x){
    if(first(L) == NULL){
        cout << "List Barang Kosong!" << endl;
        return NULL;
    }else{
        adrBarang P = first(L);
        while(P != NULL){
            if(info(P) == x){
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}

void printInfo(listBarang L){
    if(first(L) == NULL){
        cout << "List Kosong!" << endl;
    }else{
        adrBarang P = first(L);
        int i = 1;
        cout << " == Data Barang == " << endl;
        while(P != NULL) {
            cout << i << ". " << info(P) << "." << endl;
            P = next(P);
            i++;
        }
        cout << endl;
    }
}

void createList(listBarang &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirst(listBarang &L, adrBarang P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void insertAfter(listBarang &L, adrBarang Prec, adrBarang P){
    if(Prec = NULL){
        cout<<"Tidak ditemukan."<< endl;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertLast(listBarang &L, adrBarang P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        last(L) = P;
        next(P) = NULL;
    }
}

void deleteFirst(listBarang &L, adrBarang &P){
    if(first(L) == NULL){
        cout << "List Kosong!" << endl;
    }else if(next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        info(P) = "";
        next(P) = NULL;
    }
}

void deleteLast(listBarang &L, adrBarang &P){
    if(first(L) == NULL){
        cout << "List Kosong!" << endl;
    }else if(next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
    }else{
        P = last(L);
        adrBarang Q = first(L);
        while(next(Q) != last(L)){
            Q = next(Q);
        }
        next(Q) = NULL;
        last(L) = Q;
        info(P) = "";
        next(P) = NULL;
    }
}

void deleteAfter(listBarang &L, adrBarang Prec, adrBarang &P){
     if(Prec == NULL){
        cout << "Tidak Ditemukan!" << endl;
    }else if(next(Prec) == NULL){
        cout << "Tidak Ada Data Untuk Dihapus!" << endl;
    }else{
        P = Prec;
        Prec = first(L);
        while(next(Prec) != P){
            Prec = next(Prec);
        }
        next(Prec) = next(P);
        next(P) = NULL;
        info(P) = "";
    }
}
