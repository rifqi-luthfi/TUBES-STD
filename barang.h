#ifndef BARANG_H_INCLUDED
#define BARANG_H_INCLUDED

#include "header.h"

using namespace std ;

struct Barang{
    string nama;
    string size;
    long harga;
};

typedef struct elmListBarang *addressBarang;

struct elmListBarang{
    Barang Data;
    addressBarang prev;
    addressBarang next;
};

struct ListBarang{
    addressBarang first;
    addressBarang last;
};

void alokasiBarang(Barang Data, addressBarang &P);
bool isEmptyBarang(ListBarang L);
void createListBarang(ListBarang &L);
void dealokasiBarang(addressBarang &P);
addressBarang searchDataBarang(ListBarang L, Barang DataNama, Barang DataSize);
void insertFirstBarang(ListBarang &L, addressBarang P);
void insertLastBarang(ListBarang &L, addressBarang P);
void deleteLastBarang(ListBarang &L, addressBarang &P);
void deleteFirstBarang(ListBarang &L, addressBarang &P);
void inputBarang(ListBarang &L);
void deleteBarang(ListBarang &L, addressBarang &Prec, addressBarang &P);
void printInfoBarang(ListBarang L);
void urutkanbarang(ListBarang & L);

#endif // BARANG_H_INCLUDED
