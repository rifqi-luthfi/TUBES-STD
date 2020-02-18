#ifndef USER_H_INCLUED
#define USER_H_INCLUED

#include "header.h"

using namespace std ;

struct User{
    string nama;
    string password;
    string alamat;
    string telp;
    string email;
};

typedef struct elmListUser *addressUser;

struct elmListUser{
    User Data ;
    addressUser prev;
    addressUser next;
};

struct ListUser{
    addressUser first;
    addressUser last;
};

bool isEmptyUser(ListUser L);
void createListUser(ListUser &L);
void alokasiUser(User Data, addressUser &P);
void dealokasiUser(addressUser &P);
void printInfoUser(ListUser L);
void insertFirstUser(ListUser &L, addressUser P);
void insertLastUser(ListUser &L, addressUser P);
void deleteFirstUser(ListUser &L, addressUser &P);
void deleteLastUser(ListUser &L, addressUser &P);
void deleteUser(ListUser &L, addressUser &P);
addressUser searchDataUser(ListUser L, User Data);
addressUser searchDataUserPassword (ListUser L, User DataNama, User DataPassword);
void mencariUser(ListUser L, User Data);
void menghapusUser(ListUser &L, User Data);
void registrasi(ListUser &L);

#endif
