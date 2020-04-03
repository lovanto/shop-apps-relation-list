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
    string tmax[10];
    string aToko[10];
    int aCountToko[10];
    int count, max;
    int i=0;

    P = first(LT);
    if(first(LT) != NULL){
        while(P != NULL) {
            aToko[i] = info(P);
            P = next(P);
            i++;
        }

        int k = 0;
        Q = first(L);
        while(next(Q) != first(L)){
            aCountToko[k] = 0;
            k++;
            Q = next(Q);
        }
        aCountToko[k] = 0;

        for(int j=0; j<i; j++){
            Q = first(L);
            while(next(Q) != first(L)){
                if(info(toko(Q)) == aToko[j]){
                    aCountToko[j]++;
                }
                k++;
                Q = next(Q);
            }
            if(info(toko(Q)) == aToko[j]){
                aCountToko[j]++;
            }
        }
        cout << endl;

        max = -1;
        for(int j=0; j<i; j++){
            count = aCountToko[j];
            if(count >= max){
                max = count;
            }
        }

        k=-1;
        for(int j=0; j<i; j++){
            if(aCountToko[j] == max){
                k++;
                tmax[k] = aToko[j];
            }
        }

        cout << "Toko dengan barang paling lengkap : ";
        for(int j=0; j<=k; j++){
            cout << tmax[j];
            if(j<k){
                cout << ", ";
            }
        }
        cout << " sebanyak " << max << " barang." << endl;
    } else {
        cout << "Tidak ada toko." << endl;
    }
}

void minJual(listToko LT, listRelasi L){
    adrToko P;
    adrRelasi Q;
    string tmin[10];
    string aToko[10];
    int aCountToko[10];
    int count, min;
    int i=0;

    P = first(LT);
    if(first(LT) != NULL){
        while(P != NULL) {
            aToko[i] = info(P);
            P = next(P);
            i++;
        }

        int k = 0;
        Q = first(L);
        while(next(Q) != first(L)){
            aCountToko[k] = 0;
            k++;
            Q = next(Q);
        }
        aCountToko[k] = 0;

        for(int j=0; j<i; j++){
            Q = first(L);
            while(next(Q) != first(L)){
                if(info(toko(Q)) == aToko[j]){
                    aCountToko[j]++;
                }
                k++;
                Q = next(Q);
            }
            if(info(toko(Q)) == aToko[j]){
                aCountToko[j]++;
            }
        }
        cout << endl;

        min = 9;
        for(int j=0; j<i; j++){
            count = aCountToko[j];
            if(count <= min){
                min = count;
            }
        }

        k=-1;
        for(int j=0; j<i; j++){
            if(aCountToko[j] == min){
                k++;
                tmin[k] = aToko[j];
            }
        }

        cout << "Toko dengan barang paling sedikit : ";
        for(int j=0; j<=k; j++){
            cout << tmin[j];
            if(j<k){
                cout << ", ";
            }
        }
        cout << " sebanyak " << min << " barang." << endl;
    } else {
        cout << "Tidak ada toko." << endl;
    }
}

void printInfoBestAndWorst(listToko LT, listRelasi L){
    if(first(L) == NULL){
        cout << "Tidak ada toko dan barang dalam list.";
    } else {
        maxJual(LT,L);
        minJual(LT,L);
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
