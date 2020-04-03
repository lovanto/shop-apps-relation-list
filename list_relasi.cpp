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

    while(next(Q) != first(L)){
        if(barang(Q) == P || toko(Q) == C) {
            return Q;
        }
        Q = next(Q);
    }
    if(barang(Q) == P || toko(Q) == C) {
        return Q;
    }
    return NULL;
}

void printInfo(listRelasi L){
    if(first(L) == NULL){
        cout << "List Kosong!" << endl;
    }else{
        adrRelasi P = first(L);
        while(next(P) != first(L)) {
            if(info(toko(P)) != ""){
                if(info(barang(P)) != ""){
                    cout << info(toko(P)) << " menjual -> " << info(barang(P)) << endl;
                }
            }
            P = next(P);
        }
        if(info(toko(P)) != ""){
            if(info(barang(P)) != ""){
                cout << info(toko(P)) << " menjual -> " << info(barang(P)) << endl;
            }
        }
        cout << endl;
    }
}

void printInfoByToko(listRelasi L, string toko){
    if(first(L) == NULL){
        cout << "List Kosong!" << endl;
    }else{
        adrRelasi P = first(L);
        while(next(P) != first(L)) {
            if(info(toko(P)) == toko){
                cout << info(toko(P)) << " menjual -> " << info(barang(P)) << endl;
            }
            P = next(P);
        }
        if(info(toko(P)) == toko){
            cout << info(toko(P)) << " menjual -> " << info(barang(P)) << endl;
        }
        cout << endl;
    }
}

void printInfoByItem(listRelasi L, string barang){
    if(first(L) == NULL){
        cout << "List Kosong!" << endl;
    }else{
        adrRelasi P = first(L);
        while(next(P) != first(L)) {
            if(info(barang(P)) == barang){
                cout << info(toko(P)) << " menjual -> " << info(barang(P)) << endl;
            }
            P = next(P);
        }
        if(info(barang(P)) == barang){
            cout << info(toko(P)) << " menjual -> " << info(barang(P)) << endl;
        }
        cout << endl;
    }
}

void maxJual(listToko LT, listRelasi L){
    adrToko P;
    adrRelasi Q;
    adrToko tmax;
    int count, max;
    count = 0;
    max = 0;

    P = first(LT);
    if(first(LT) != NULL){
        while(P != NULL){
            Q = first(L);
            while(Q != NULL){
                if(info(toko(Q)) == info(P)){
                    count = count + 1;
                }
                Q = next(Q);
            }
            if(count >= max){
                max = count;
                tmax = P;
            }
            P = next(P);
        }
        cout<<"Toko dengan barang paling lengkap : " <<info(tmax)<<" sebanyak "<<max<<" barang."<< endl;
    } else {
        cout<<"Tidak ada toko."<< endl;
    }
    }

void minJual(listToko LT, listRelasi L){
    adrToko P;
    adrRelasi Q;
    adrToko tmin;
    int count, min;
    count = 0;
    min = 0;

    P = first(LT);
    if(first(LT) != NULL){
        while(P != NULL){
            Q = first(L);
            while(Q != NULL){
                if(info(toko(Q)) == info(P)){
                    count = count + 1;
                }
                Q = next(Q);
            }
            if(count <= min){
                min = count;
                tmin = P;
            }
            P = next(P);
        }
        cout<<"Toko dengan barang paling sedikit : " <<info(tmin)<<" sebanyak "<<min<<" barang."<< endl;
    } else {
        cout<<"Tidak ada toko."<< endl;
    }
}

void printInfoBestAndWorst(listToko LT, listRelasi L){
    if(first(L) = NULL){
        cout<<"Tidak ada toko dan barang dalam list.";
    } else {
        maxJual(LT,L);
        minJual(LT,L);
    }
    /*adrRelasi P = first(LR);
    int countRel = 0;
    while(next(P) != first(LR)){
        countRel++;
        P = next(P);
    }
    countRel++;
    cout << countRel << endl; */
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
    if(Prec = NULL){
        cout<<"Tidak ditemukan.";
        P = NULL;
    } else {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteDataToko(listRelasi &LR, listToko &LT, adrToko &PToko, adrRelasi &PRelasi, infotype T){
    adrToko R = first(LT);
    while(R != NULL){
        if(info(R) == T){
            if(R == first(LT)){
                deleteFirst(LT, PToko);
            }else if(R == last(LT)){
                deleteLast(LT, PToko);
            }else{
                adrToko S = findElm(LT, T);
                deleteAfter(S, PToko);
            }
        }
        R = next(R);
    }
}

void deleteDataBarang(listRelasi &LR, listBarang &LB, adrBarang &PBarang, adrRelasi &PRelasi, infotype T){
    adrBarang R = first(LB);
    while(R != NULL){
        if(info(R) == T){
            if(R == first(LB)){
                deleteFirst(LB, PBarang);
            }else if(R == last(LB)){
                deleteLast(LB, PBarang);
            }else{
                adrBarang S = findElm(LB, T);
                deleteAfter(LB, S, PBarang);
            }
        }
        R = next(R);
    }
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
        next(P) = NULL;
        next(Q) = first(L);
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
        adrRelasi Q = first(L);
        while(next(P)!= first(L)){
            Q = P;
            P = next(P);
        }
        next(P) = NULL;
        next(Q) = first(L);
    }
}

void deleteAfter(adrRelasi Prec, adrRelasi &P){

}
