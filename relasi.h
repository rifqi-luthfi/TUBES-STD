#ifndef RELASI_H_INCLUED
#define RELASI_H_INCLUED

#include "header.h"
#include "user.h"
#include "barang.h"

using namespace std;

typedef struct elmListRel *addressRel;

struct elmListRel{
    addressUser nextUser ;
    addressBarang nextBarang;
    addressRel next;
    addressRel prev;
};

struct ListRel{
    addressRel first;
    addressRel last ;
};

void alokasiRel(addressRel &P,addressUser User, addressBarang Barang);
void dealokasiRel(addressRel &P);
void createListRel(ListRel &L);
void insertLastRel(ListRel &L,addressRel P);
void deleteFirstRel(ListRel &L, addressRel &P);
void deleteLastRel(ListRel &L, addressRel &P);
void deleteRel(ListRel &L, addressRel &P);
void printInfoRelasi(ListUser LUser,ListRel LRel);
void membeliBarang(ListRel &L, addressUser PUser, addressBarang PBarang);
void membuatRelasi(ListRel &L, addressBarang PBarang, addressUser PUser);
void Pembelian(ListBarang &LBarang, ListRel &LRelasi, ListUser LUser, addressUser PUser);
void printInfoPembeli(ListUser LUser, ListRel LRel,addressUser PUser);
void pembayaran(ListUser LUser, ListRel &LRelasi ,ListBarang LBarang, addressUser PUser);
#endif
