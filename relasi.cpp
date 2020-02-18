#include"relasi.h"

void alokasiRel(addressRel &P ,addressUser User, addressBarang Barang){
    P = new elmListRel;
    nextUser(P)=User;
    nextBarang(P)=Barang;
    next(P)=NULL;
    prev(P)=NULL;
}
void dealokasiRel(addressRel &P){
    delete P;
    P=NULL;
}
void createListRel(ListRel &L){
    first(L)=NULL;
    last(L)=NULL;
}
void insertLastRel(ListRel &L,addressRel P){
    if (first(L)==NULL && last(L)==NULL){
        first(L)=P;
        last(L)=P;
    }
    else{
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}
void deleteFirstRel(ListRel &L, addressRel &P){
    if (first(L) != NULL && last(L)!=NULL) {
        P = first(L);
        if (first(L)==last(L)){
            first(L)=NULL;
            last(L)=NULL;
        }
        else {
            first(L)=next(P);
            prev(first(L))=NULL;
            next(P)=NULL;
        }
    }
}
void deleteLastRel(ListRel &L, addressRel &P){
    if (first(L)!=NULL && last(L)!=NULL){
        if(first(L)==last(L)){
            deleteFirstRel(L,P);
        }
        else{
            P=last(L);
            last(L)=prev(P);
            prev(P)=NULL;
            next(last(L))=NULL;
        }
    }
}

void deleteRel(ListRel &L, addressRel &P){
    if(P!=NULL){
        if (P==first(L)){
            deleteFirstRel(L,P);
        }
        else if (P==last(L)){
            deleteLastRel(L,P);
        }
        else {
            next(prev(P))=next(P);
            prev(next(P))=prev(P);
            next(P)=NULL;
            prev(P)=NULL;
        }
    }
}

void printInfoRelasi(ListUser LUser, ListRel LRel){
    addressUser PUser;
    addressRel PRel;
    int total =  0;
    bool status = false;
    PUser=first(LUser);
    if(PUser==NULL){
        cout<<"-------------------------------"<<endl;
        cout<<"| Belum ada user yang membeli |"<<endl;
        cout<<"-------------------------------"<<endl;
    }
    while(PUser!=NULL){
        cout<<"Nama User : "<<info(PUser).nama<<endl;
        PRel = first(LRel);
        int i = 1 ;
        if(PRel != NULL){
            while(PRel != NULL){
                if(nextUser(PRel) == PUser){
                    cout<<i<<".) Nama Barang : "<<info(nextBarang(PRel)).nama<<endl;
                    cout<<" .) Size : "<<info(nextBarang(PRel)).size<<endl;
                    cout<<" .) Harga : "<<info(nextBarang(PRel)).harga<<endl;
                    total = total + info(nextBarang(PRel)).harga;
                }
                PRel = next(PRel);
                i++ ;
            }
            cout<<"Total Harga : Rp."<<total<<endl;
            cout<<"-------------------------"<<endl;
        }
        else{
            cout<<"----------------------"<<endl;
            cout<<"| User Belum Membeli |"<<endl;
            cout<<"----------------------"<<endl;
        }
        PUser = next(PUser);
    }
}

void membuatRelasi(ListRel &L, addressBarang PBarang, addressUser PUser){
    addressRel PRel;
    bool found = false;

    PRel = first(L);
    while(PRel != NULL){
        if(nextBarang(PRel) == PBarang){
            found = true;
        }
        else{
            PRel = next(PRel);
        }
    }
    if(found == true){
        cout<<"Barang Sudah Di Booking"<<endl;
    }
    else{
        alokasiRel(PRel,PUser,PBarang);
        insertLastRel(L,PRel);
        cout<<info(nextBarang(PRel)).nama<<" Berhasil Di Beli"<<endl;
        cout<<endl;
        cout<<"Terima kasih atas kepercayaan saudara "<<info(nextUser(PRel)).nama<<" telah berbelanja disini ^_^ "<<endl;
    }
}

void Pembelian(ListBarang &LBarang, ListRel &LRelasi, ListUser LUser, addressUser PUser){
    addressBarang PBarang,PRec;
    addressRel PRelasi;
    Barang DataBarangNama, DataBarangSize;
    User Data;
    system("cls");
    char input ;
    bool found = false;
    printInfoBarang(LBarang);
    PBarang = first(LBarang);
    if(PBarang == NULL){
        cout<<"Maaf, Tidak Dapat Melakukan Transaksi Barang Kosong"<<endl;
    }
    else{
        cout<<endl;
        cout<<"Silahkan Memasukkan Data Untuk Melakukan Pembelian Barang"<<endl;
        cout<<endl;
        cout<<"Nama Barang : ";
        getline(cin,DataBarangNama.nama);
        cout<<"Size Barang : ";
        getline(cin,DataBarangSize.size);
        PBarang = searchDataBarang(LBarang,DataBarangNama,DataBarangSize);
        PRelasi = first(LRelasi);
        if(PBarang == NULL){
            cout<<"Maaf, Barang Tidak Ada"<<endl;
        }
        else{
            bool found = false;
            do{
                cout<<"Anda yakin ingin membeli ?"<<endl;
                cout<<"1. Yakin"<<endl;
                cout<<"2. Tidak Jadi"<<endl;
                input = getch();
                switch(input){
                    case '1' :
                        membuatRelasi(LRelasi,PBarang,PUser);
                        cout<<"Nama Barang : ";
                        cout<<info(PBarang).nama<<endl;
                        cout<<"Size        : ";
                        cout<<info(PBarang).size<<endl;
                        cout<<"Harga       : ";
                        cout<<info(PBarang).harga<<endl;
                        PRec = PBarang;
                        deleteBarang(LBarang,PRec,PBarang);
                        found = true;
                        cin.ignore();
                        break;
                    case '2' :
                        cout<<"Okay Terima Kasih"<<endl;
                        found = true;
                        break;
                }
            }while(found != true);
        }
    }
    cout<<"Enter";
    getch();
    system("cls");
}

void printInfoPembeli(ListUser LUser, ListRel LRel,addressUser PUser){
    addressRel PRel;
    bool status = false;
    if(PUser==NULL){
        cout<<"-------------------------------"<<endl;
        cout<<"| Belum ada user yang membeli |"<<endl;
        cout<<"-------------------------------"<<endl;
    }
    else{
        cout<<"Nama User : "<<info(PUser).nama<<endl;
        PRel = first(LRel);
        int i = 1 ;
        long total = 0;
        if(PRel != NULL){
            while(PRel != NULL){
                if(nextUser(PRel) == PUser){
                cout<<i<<".) Nama Barang : "<<info(nextBarang(PRel)).nama<<endl;
                cout<<" .) Size : "<<info(nextBarang(PRel)).size<<endl;
                cout<<" .) Harga : "<<info(nextBarang(PRel)).harga<<endl;
                total = total + info(nextBarang(PRel)).harga;
                i++;
                }
                PRel = next(PRel);
            }
            cout<<"Total Harga : Rp."<<total<<endl;
            cout<<"-------------------------"<<endl;
        }
        else{
            cout<<"----------------------"<<endl;
            cout<<"| User Belum Membeli |"<<endl;
            cout<<"----------------------"<<endl;
        }
    }
}
