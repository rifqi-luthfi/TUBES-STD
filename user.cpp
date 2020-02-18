#include "header.h"
#include "relasi.h"
#include "user.h"

bool isEmptyUser(ListUser L){
    return (first(L) == NULL && last(L) == NULL);
}

void createListUser(ListUser &L){
    first(L) = NULL;
    last(L) = NULL ;
}

void alokasiUser(User Data, addressUser &P){
    P = new elmListUser ;
    info(P) = Data ;
    next(P) = NULL;
    prev(P) = NULL;
}

void dealokasiUser(addressUser &P){
    delete P ;
}

void printInfoUser(ListUser L){
    int i= 1;
    addressUser P;
    P = first(L);
    if(P == NULL){
        cout<<"Tidak Mempunyai User"<<endl;
    }
    else{
        cout<<" _______________________________"<<endl;
        cout<<"|Berikut User Yang Terdaftar    |"<<endl;
        cout<<"|_______________________________|"<<endl;
        cout<<endl;
        while(P != NULL){
            cout<<i<<".)\tNama : "<<info(P).nama<<endl;
            cout<<"\tAlamat : "<<info(P).alamat<<endl;
            cout<<"\tNomor Telepon : "<<info(P).telp<<endl;
            cout<<"\tEmail : "<<info(P).email<<endl;
            cout<<"-----------------------------------------"<<endl;
            P = next(P);
            i++;
        }
    }
}

void insertFirstUser(ListUser &L, addressUser P){
    if(isEmptyUser(L)){
        first(L) = P ;
        last(L) = P ;
    }
    else{
        next(P) = first(L);
        prev(first(L)) = P ;
        first(L) = P ;
    }
}

void insertAfterUser(ListUser &L, addressUser &Prec, addressUser &P){
    if(!isEmptyUser(L) && Prec == last(L)){
        next(Prec) = P ;
        prev(P) = Prec ;
        last(L) = P ;
    }
    else if(!isEmptyUser(L)){
        prev(P) = Prec;
        next(P) = next(Prec);
        prev(next(Prec)) = P ;
        next(Prec) = P ;
    }
    else{
        cout<<"ListUser kosong"<<endl;
    }
}

void insertLastUser(ListUser &L, addressUser P){
    if(!isEmptyUser(L)){
        next(last(L)) = P ;
        prev(P) = last(L);
        last(L) = P ;
    }
    else{
        insertFirstUser(L,P);
    }
}

void deleteFirstUser(ListUser &L, addressUser &P){
    if(!isEmptyUser(L)){
        if(first(L) == last(L)){
            P = first(L) ;
            first(L) = NULL;
            last(L) = NULL;
        }
        else{
            P = first(L);
            first(L) = next(first(L));
            prev(first(L)) = NULL;
        }
    }
}

void deleteLastUser(ListUser &L, addressUser &P){
    if(!isEmptyUser(L)){
        P = last(L);
        last(L)= prev(P) ;
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
    else{
        deleteFirstUser(L,P);
    }
}

void deleteUser(ListUser &L, addressUser &P){
    if(P!=NULL){
        if (P==first(L)){
            deleteFirstUser(L,P);
        }
        else if (P==last(L)){
            deleteLastUser(L,P);
        }
        else {
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P)=NULL;
            prev(P)=NULL;
        }
    }
}

addressUser searchDataUser (ListUser L, User Data){
    addressUser P ;
    P = first(L);
    while(P != NULL){
        if(info(P).nama == Data.nama){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

addressUser searchDataUserPassword (ListUser L, User DataNama, User DataPassword){
    addressUser P ;
    P = first(L);
    while(P != NULL){
        if(info(P).nama == DataNama.nama && info(P).password == DataPassword.password){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void mencariUser(ListUser L, User Data){
    addressUser P ;
    cout<<"Masukan Nama : ";
    cin>>Data.nama;
    P = searchDataUser(L,Data);
    if(P == NULL){
        cout<<"Data Tidak Di Temukan"<<endl;
    }
    else if(info(P).nama == Data.nama){
        cout<<"Nama          : "<<info(P).nama<<endl;
        cout<<"Alamat        : "<<info(P).alamat<<endl;
        cout<<"Nomor Telepon : "<<info(P).telp<<endl;
        cout<<"Email         : "<<info(P).email<<endl;
    }
    cout<<"Enter";
    getch();
    system("cls");
}

void menghapusUser(ListUser &L, User Data){
    addressUser P ;
    printInfoUser(L);
    P = first(L);
    if(P != NULL){
        cout<<"Masukan UserName / ID : ";
        cin>>Data.nama;
        P = searchDataUser(L,Data);
        if(P == NULL){
            cout<<"Data User Tidak Di Temukan"<<endl;
        }
        else{
            cout<<"Data User Dengan Nama Tersebut Berhasil Di Hapus"<<endl;
            deleteUser(L,P);
        }
    }
    else{
        cout<<"Tidak Ada User Yang Dapat Di Hapus"<<endl;
    }
}

void registrasi(ListUser &LUser){
    addressUser PUser ;
    User DataUser;
    cout<<"____________________________________________________________"<<endl;
    cout<<"|Untuk melakukan registrasi ,silahkan isi ketentuan berikut:|"<<endl;
    cout<<"|___________________________________________________________|"<<endl;
    cout<<endl;
    cout<<"Masukan UserName / ID : ";
    getline(cin,DataUser.nama);
    cout<<endl;
    PUser = searchDataUser(LUser,DataUser);
    if(PUser == NULL && DataUser.nama != "admin"){
        cout<<"Masukan Password : ";
        getline(cin,DataUser.password);
        cout<<endl;
        cout<<"Alamat           : ";
        getline(cin,DataUser.alamat);
        cout<<endl;
        cout<<"Nomor Telepon    : ";
        getline(cin,DataUser.telp);
        cout<<endl;
        cout<<"Email            : ";
        getline(cin,DataUser.email);
        cout<<endl;
        alokasiUser(DataUser,PUser);
        insertLastUser(LUser,PUser);
        cout<<"Terima Kasih Saudara "<<info(PUser).nama<<" Telah Berhasil Registrasi"<<endl;
        cout<<"Enter";
        getch();
        system("cls");
    }
    else{
        cout<<"ID Sudah Terdaftar"<<endl;
        cout<<"Enter";
        getch();
        system("cls");
    }
}
