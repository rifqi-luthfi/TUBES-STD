#include "header.h"
#include "relasi.h"
#include "barang.h"

bool isEmptyBarang(ListBarang L){
    return (first(L) == NULL && last(L) == NULL);
}
void createListBarang(ListBarang &L){
    first(L) = NULL;
    last(L) = NULL ;
}

void dealokasiBarang(addressBarang &P){
    delete P ;
}

void alokasiBarang(Barang Data, addressBarang &P){
    P = new elmListBarang;
    info(P) = Data;
    next(P) = NULL;
}

void inputBarang(ListBarang &L){
    int harga;
    addressBarang P;
    Barang Data;
    cout<<"Masukkan data barang yang ingin dijual :"<<endl;
    cout<<"________________________________________"<<endl;
    cout<<endl;
	cout<<"Nama Barang : ";
	getline(cin, Data.nama);
	cout<<endl;
	cout<<"Ukuran Barang : ";
	getline(cin,Data.size);
    cout<<endl;
    cout<<"Harga Barang : ";
    cin>>Data.harga;
    cin.ignore();
    cout<<endl;
    alokasiBarang(Data,P);
    insertFirstBarang(L,P);
    system("cls");
}

void insertFirstBarang(ListBarang &L, addressBarang P){
    if(isEmptyBarang(L)){
        first(L) = P ;
        last(L) = P ;
    }
    else{
        next(P) = first(L);
        first(L) = P ;
    }
}

void insertLastBarang(ListBarang &L, addressBarang P) {
     if(!isEmptyBarang(L)){
        next(last(L)) = P ;
        last(L) = P ;
    }
    else{
        insertFirstBarang(L,P);
    }
}

void deleteFirstBarang(ListBarang &L, addressBarang &P){
    if(first(L) != NULL && last(L) != NULL){
        if(first(L) == last(L)){
            P = first(L) ;
            first(L) = NULL;
            last(L) = NULL;
        }
        else{
            P = first(L);
            first(L) = next(P);
            next(P) = NULL;
        }
    }
}


void deleteLastBarang(ListBarang &L, addressBarang &P){
    addressBarang x;
    if(first(L) != NULL && last(L) != NULL){
        x = first(L);
        while(next(x) != last(L)){
            x = next(x);
        }
        P = next(x);
        last(L) = x;
        next(x) = NULL;
    }
    else{
        deleteFirstBarang(L,P);
    }
}

void deleteBarang(ListBarang &L, addressBarang &Prec, addressBarang &P){
    addressBarang x;
    if(P!=NULL){
        if (P==first(L)){
            deleteFirstBarang(L,P);
        }
        else if (P==last(L)){
            deleteLastBarang(L,P);
        }
        else {
            x = first(L);
            while(next(x) != Prec){
                x = next(x);
            }
            P = Prec;
            next(x) = next(P);
            next(P) = NULL;
        }
    }
}

void urutkanbarang(ListBarang & L){
    addressBarang PBarang,JBarang,maksimal;
    Barang Temp;
    PBarang=first(L);
    while (next(PBarang) != NULL){
        maksimal=PBarang;
        JBarang=next(PBarang);
        while(JBarang != NULL ){
            if (info(maksimal).harga< info(JBarang).harga){
                maksimal=JBarang;
            }
            JBarang=next(JBarang);
        }
    Temp=info(maksimal);
    info(maksimal)=info(PBarang);
    info(PBarang)=Temp;
    PBarang=next(PBarang);
    }
}

void printInfoBarang(ListBarang L) {
    addressBarang P;
    int i=1;
    int jmlh = 0 ;
    P = first(L);
    if (first(L) != NULL) {
        cout<<" ____________________________________"<<endl;
        cout<<"| Berikut List Barang Yang Tersedia  |"<<endl;
        cout<<"|____________________________________| "<<endl;
        cout<<endl;
        do {
            cout<<i<<".]\tNama Barang : "<<info(P).nama;
            cout<<"\tSize Barang : \t"<<info(P).size;
            cout<<"\tHarga Barang : "<<info(P).harga<<endl;
            // cout<<"--------------------------------"<<endl;
            i++;
            jmlh++ ;
            P = next(P);
        } while (P != NULL);
        cout<<"Jumlah Barang = ";
        cout<<jmlh<<endl;
    } else {
        cout<<"-----------------"<<endl;
        cout<<"| Barang Kosong |"<<endl;
        cout<<"-----------------"<<endl;
    }
}
void SelectionBarang(ListBarang &L){
    addressBarang PBar,PHelp,maks;
    Barang Temp;

    PBar=first(L);
    if (PBar==NULL){
        cout<<"Barang kosong"<<endl;
    }
    else{
        while(next(PBar)!=NULL){
            maks=PBar;
            PHelp=next(PBar);
            while (PHelp!=NULL){
                if (info(maks).harga>info(PHelp).harga){
                    maks=PHelp;
                }
                PHelp=next(PHelp);
            }
        Temp = info(maks);
        info(maks) = info(PBar);
        info(PBar) = Temp;
        PBar = next(PBar);
        }
    }
}

addressBarang searchDataBarang(ListBarang L, Barang DataNama, Barang DataSize){
  addressBarang P ;
    P = first(L);
    while(P != NULL){
        if(info(P).nama == DataNama.nama && info(P).size == DataSize.size){
            return P;
        }
        P = next(P);
    }
    return NULL;
}
