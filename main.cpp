#include "header.h"
#include "user.h"
#include "barang.h"
#include "relasi.h"

void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    cout.flush();
    dwCursorPosition.X = x;
    dwCursorPosition.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

int main(){
    addressUser PUser;
    addressBarang PBarang,PRec;
    addressRel PRelasi;
    //=====================================
    ListUser LUser;
    ListBarang LBarang;
    ListRel LRelasi ;
    //=====================================
    User DataUserNama, DataUserPassword;
    Barang DataBarangNama, DataBarangSize, B;
    //=====================================
    char pilih,input,masuk;
    bool BFound = false;
    bool stop = false;
    bool Login = false;
    bool Admin = false;
    //===============================
    createListUser(LUser);
    createListBarang(LBarang);
    createListRel(LRelasi);
    //=================================
    B.nama= "topi";
    B.size= "M";
    B.harga=130000;
    alokasiBarang(B,PBarang);
    insertLastBarang(LBarang,PBarang);

    B.nama= "jam";
    B.size= "-";
    B.harga=1300000;
    alokasiBarang(B,PBarang);
    insertLastBarang(LBarang,PBarang);

    B.nama= "kacamata";
    B.size= "-";
    B.harga=150000;
    alokasiBarang(B,PBarang);
    insertLastBarang(LBarang,PBarang);

    B.nama= "hoodie";
    B.size= "M";
    B.harga=250000;
    alokasiBarang(B,PBarang);
    insertLastBarang(LBarang,PBarang);

    B.nama= "celana";
    B.size= "29";
    B.harga=400000;
    alokasiBarang(B,PBarang);
    insertLastBarang(LBarang,PBarang);

    B.nama= "sandal";
    B.size= "43";
    B.harga=100000;
    alokasiBarang(B,PBarang);
    insertLastBarang(LBarang,PBarang);

    B.nama= "tas";
    B.size= "-";
    B.harga=300000;
    alokasiBarang(B,PBarang);
    insertLastBarang(LBarang,PBarang);

    B.nama= "baju";
    B.size= "s";
    B.harga=150000;
    alokasiBarang(B,PBarang);
    insertLastBarang(LBarang,PBarang);

    B.nama= "sepatu";
    B.size= "41";
    B.harga=2400000;
    alokasiBarang(B,PBarang);
    insertLastBarang(LBarang,PBarang);

    B.nama= "kemeja";
    B.size= "xl";
    B.harga=350000;
    alokasiBarang(B,PBarang);
    insertLastBarang(LBarang,PBarang);
    //=================================================================================================
    do{
        system("cls");
        gotoxy(24,3);cout<<"------------------------------------------------------------------"<<endl;
        gotoxy(24,4);cout<<"|                     Selamat Datang Di Torque                   | "<<endl;
        gotoxy(24,5);cout<<"------------------------------------------------------------------"<<endl;
        gotoxy(24,7);cout<<" ================================================================"<<endl;
        gotoxy(24,8);cout<<"|                        1. Registrasi                           |"<<endl;
        gotoxy(24,9);cout<<"|                        2. Log In                               |"<<endl;
        gotoxy(24,10);cout<<"|                        0. Exit                                 |"<<endl;
        gotoxy(24,11);cout<<" ================================================================"<<endl;
        gotoxy(24,13);cout<<"Pilih Angka : ";
        pilih = getch();
        system("cls");
        switch(pilih){
            case '1' :
                registrasi(LUser);
                break;
            case '2' :
                cout<<"Masukan UserName / ID : ";
                getline(cin,DataUserNama.nama);
                cout<<endl;
                cout<<"Masukan Password      : ";
                getline(cin,DataUserPassword.password);
                cout<<endl;
                PUser = searchDataUserPassword(LUser,DataUserNama,DataUserPassword);
                if(DataUserNama.nama == "admin" && DataUserPassword.password == "admin"){
                    do{
                        system("cls");
                        cout<<"------------------------------"<<endl;
                        cout<<"| 1. Supply Barang           |"<<endl;
                        cout<<"| 2. Hapus Barang            |"<<endl;
                        cout<<"| 3. Print Riwayat Pembelian |"<<endl;
                        cout<<"| 4. Hapus User              |"<<endl;
                        cout<<"| 5. Stock Barang            |"<<endl;
                        cout<<"| 0. Log Out                 |"<<endl;
                        cout<<"------------------------------"<<endl;
                        cout<<"Pilih Angka : ";
                        masuk = getch();
                        switch(masuk){
                        case '1' :
                            system("cls");
                            inputBarang(LBarang);
                            cout<<"------------------------------"<<endl;
                            cout<<"| Barang Berhasil Di Masukan |"<<endl;
                            cout<<"------------------------------"<<endl;
                            cout<<"Enter";
                            getch();
                            system("cls");
                            break;
                        case '2' :
                            system("cls");
                            printInfoBarang(LBarang);
                            PRec = first(LBarang);
                            if(PRec != NULL){
                                cout<<"Masukan Nama Barang : ";
                                getline(cin,DataBarangNama.nama);
                                // cin.ignore();
                                cout<<"Masukan Size Barang : ";
                                getline(cin,DataBarangSize.size);
                                // cin.ignore();
                                PBarang = searchDataBarang(LBarang,DataBarangNama,DataBarangSize);
                                if(PBarang == NULL){
                                    cout<<"Data Barang Tidak Di Temukan"<<endl;
                                }
                                else{
                                    cout<<"Data Barang Dengan Nama Tersebut Berhasil Di Hapus"<<endl;
                                    PRec = PBarang;
                                    deleteBarang(LBarang,PRec,PBarang);
                                }
                            }
                            else{
                                cout<<"Tidak Ada Barang Yang Dapat Di Hapus"<<endl;
                            }
                            cout<<"Enter";
                            getch();
                            system("cls");
                            break;
                        
                        case '3' :
                            cout<<endl;
                            printInfoRelasi(LUser,LRelasi);
                            cout<<"Enter";
                            getch();
                            system("cls");
                            break;
                        case '4' :
                            cout<<endl;
                            printInfoUser(LUser);
                            PUser = first(LUser);
                            if(PUser != NULL){
                                cout<<"Masukan UserName / ID : ";
                                getline(cin,DataUserNama.nama);
                                cout<<endl;
                                PUser = searchDataUser(LUser,DataUserNama);
                                if(PUser == NULL){
                                    cout<<"Data User Tidak Di Temukan"<<endl;
                                }
                                else{
                                    cout<<"Data User Dengan Nama Tersebut Berhasil Di Hapus"<<endl;
                                    deleteUser(LUser,PUser);
                                }
                            }
                            else{
                                cout<<"Tidak Ada User Yang Dapat Di Hapus"<<endl;
                            }
                            printInfoUser(LUser);
                            cout<<"Enter";
                            getch();
                            system("cls");
                            break;
                        case '5' :
                            urutkanbarang(LBarang);
                            printInfoBarang(LBarang);
                            cout<<"Enter";
                            getch();
                            system("cls");
                            break;
                        case '0' :
                            cout<<endl;
                            cout<<"--------------------"<<endl;
                            cout<<"| Berhasil Log Out |"<<endl;
                            cout<<"--------------------"<<endl;
                            cout<<"Enter";
                            Admin = true;
                            getch();
                            system("cls");
                            break;
                        }
                    }while(Admin != true);
                }
                else if(PUser != NULL){
                    do{
                        system("cls");
                        cout<<"--------------------------------"<<endl;
                        cout<<"| 1. Ingin Melakukan Pembelian |"<<endl;
                        cout<<"| 2. Riwayat Pembelian         |"<<endl;
                        cout<<"| 3. Log Out                   |"<<endl;
                        cout<<"--------------------------------"<<endl;
                        cout<<"Pilih Angka : ";
                        input = getch();
                        switch(input){
                        case '1' :
                            Pembelian(LBarang,LRelasi,LUser,PUser);
                            Login = false;
                            break;
                        case '2' :
                            printInfoPembeli(LUser,LRelasi,PUser);
                            getch();
                            cout<<"Enter";
                            system("cls");
                            break;
                        case '3' :
                            cout<<endl;
                            cout<<"--------------------"<<endl;
                            cout<<"| Berhasil Log Out |"<<endl;
                            cout<<"--------------------"<<endl;
                            Login = true;
                            break;
                        }
                    }while(Login != true);
                }
                else{
                    cout<<"-----------------------------"<<endl;
                    cout<<"| UserName / Password Salah |"<<endl;
                    cout<<"-----------------------------"<<endl;
                    cout<<"Enter";
                    getch();
                    system("cls");
                }
                break;
            case '0' :
                stop = true ;
                break;
        }
    }while(stop != true) ;
    return 0 ;
}
