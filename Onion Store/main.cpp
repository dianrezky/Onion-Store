#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

//VARIABEL GLOBAL

char password[100],pws[100],FileName[100];
char usr[100],nama[100];
char temp[100];
int n,piladm,i,a,code,z=0,uang,kembalian;
char pil;
int logincntr=0,cntr,gnt;
int kodehapus;
int total;
float totalkeseluruhan,totalpotongan;
float potongan;
float diskon;
int totalawal;

struct datasementara{
    char qhand[100];
    char uhand[100];
    int khandl,jhandl;
}smntr[100];

time_t now=time(0);
char *dt=ctime(&now);

struct datamember{
    char namamember[100];
    char notelp[20];
}member[100];

struct databrg{
    char namabrg[100],category[100];
    int kodebrg,cost;

}item[100];

//CLASS


class inputdata{


public:

    struct data{
        int kode,harga;
        char namabarang[100],kategori[100],tanggal[100];
    }barang[100];

    void akhir(){
        cout<<"TERIMAKASIH ";
    }

}input;

class inputbarang:public inputdata{

public:


    void barang(){

        ofstream data;

        data.open("barang.txt",ios::app);

        do{
            i++;
            tambah:
            cout<<"Masukkan Kode (6 Digit & dilaranng depannya nol) \t: ";
            cin>>input.barang[i].kode;
            if((input.barang[i].kode>=10000)&&(input.barang[i].kode<=999999)){
                cout<<"Masukkan Nama \t\t\t: ";
                cin>>input.barang[i].namabarang;
                cout<<"Masukkan Harga \t\t\t: ";
                cin>>input.barang[i].harga;
                cout<<"Masukkan Kategori \t\t: ";
                cin>>input.barang[i].kategori;
                cout<<"Masukkan Tanggal Expire \t: ";
                cin>>input.barang[i].tanggal;
                data<<input.barang[i].kode<<"\t"<<input.barang[i].namabarang<<"\t"<<input.barang[i].harga<<"\t"<<input.barang[i].kategori<<"\t"<<input.barang[i].tanggal<<endl;
                cout<<"Apakah Anda Ingin Menambahkan Barang Lagi (y/t) : ";
                cin>>pil;
            }
            else{
                cout<<"Kode Harus Terdiri Dari 6 Digit"<<endl;
                goto tambah;
            }
        }while(pil=='y');

        data.close();

    }

    void akhir(){
        cout<<"TELAH MENGGUNAKAN ";
    }

}brg;

class terakhir:public inputdata{

private :

    string copyright;
    string copyright1;
    string copyright2;

public :

    int nim,nim1,nim2;
    char kelas[100];

    void akhir(){
        cout<<"APLIKASI KASIR INI"<<endl;
    }

    void setnama(string inputcopyright){
        copyright = inputcopyright;
    }

    string getnama(){
        return copyright;
    }

    void setnama1(string inputcopyright1){
        copyright1 = inputcopyright1;
    }

    string getnama1(){
        return copyright1;
    }

    void setnama2(string inputcopyright2){
        copyright2 = inputcopyright2;
    }

    string getnama2(){
        return copyright2;
    }

}akhr;

void ending(){

    system("pause");
    system("cls");

    input.akhir();
    brg.akhir();
    akhr.akhir();

    system("pause");
    system("cls");

    akhr.setnama("Dian Rezky Wulandari");
    akhr.setnama1("Mohammad Naufal Nabil Abdillah");
    akhr.setnama2("Jabal Rachmah");

    akhr.nim=1103184022;
    akhr.nim1=1103184062;
    akhr.nim2=1103184016;
    strcpy(akhr.kelas,"TK - 42 - 05");

    cout<<"=========================================================="<<endl;
    cout<<"||\t\t     Copyright By  \t\t\t||"<<endl;
    cout<<"=========================================================="<<endl;
    cout<<"|| "<<akhr.getnama()<<"  "<<"( "<<akhr.nim<<" )"<<" \t\t||"<<endl;
    cout<<"|| "<<akhr.getnama1()<<"  "<<"( "<<akhr.nim1<<" )"<<" \t||"<<endl;
    cout<<"|| "<<akhr.getnama2()<<"  "<<"( "<<akhr.nim2<<" )"<<" \t\t\t||"<<endl;
    cout<<"=========================================================="<<endl;
    cout<<"||\t\t  Class : "<<akhr.kelas<<"     \t\t||"<<endl;
    cout<<"=========================================================="<<endl;

    exit(0);
}

//UNTUK LOADING

void loading(){

    system("color 8f");

    cout<<"\t\t\t\t\t                 "<<endl;
    cout<<"\t\t\t\t\t         88888888"<<endl;
    cout<<"\t\t\t\t\t         88888 88"<<endl;
    cout<<"\t\t\t\t\t 8       88888888"<<endl;
    cout<<"\t\t\t\t\t 88      88888888 "<<endl;
    cout<<"\t\t\t\t\t 888  8888888888 "<<endl;
    cout<<"\t\t\t\t\t 888888888888  8 "<<endl;
    cout<<"\t\t\t\t\t   888888888   8  "<<endl;
    cout<<"\t\t\t\t\t    88   88      8 "<<endl;
    cout<<"\t\t\t\t\t    88   88      "<<endl;
    cout<<"\t\t\t\t\t    88   88      "<<endl;
    cout<<"\t\t\t\t\t    ==>  ==>    "<<endl<<endl;
    cout<<"\t\t\t\t\t   oo      nn  nn   iiii            nn  nn"<<endl;
    cout<<"\t\t\t\t\t  o  o     nn  nn   iiii     o      nn  nn"<<endl;
    cout<<"\t\t\t\t\t o    o    nnn nn   iiii    o o     nnn nn"<<endl;
    cout<<"\t\t\t\t\to      o   nnnnnn   iiii  o     o   nnnnnn"<<endl;
    cout<<"\t\t\t\t\t o    o    nnnnnn   iiii   o   o    nnnnnn"<<endl;
    cout<<"\t\t\t\t\t  o  o     nn nnn   iiii    o o     nn nnn"<<endl;
    cout<<"\t\t\t\t\t   oo      nn  nn   iiii     o      nn  nn"<<endl;

    cout<<endl;
    cout<<"\t\t\t\t\t Application Created By Jabal, Dian, Nabil"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\tPlease Wait While Loading......\n\n";

    char a=177, b=219;

    cout<<"\t\t\t\t\t\t";

    for (int i=0;i<=30;i++)
    cout<<a;
    cout<<"\r";
    cout<<"\t\t\t\t\t\t";
    for (int i=0;i<=30;i++){
        cout<<b;
        for (int j=0;j<=1e8;j++);
    }

    cout<<endl<<endl<<"\t\t\t\t\t\t     WELCOME TO ONION STORE"<<endl;

    cout<<"\t\t\t\t\t\t";
    system("pause");
    system("CLS");


}
//MENU UNTUK TAMPILAN

void tampilbarang(){


    ifstream data;
    z=0;
    i=0;
    data.open("barang.txt");

    cout<<"\n\t\t\t\t\t\t ~~~~~~~~~~ LIST OF ITEM ~~~~~~~~~~\n\n";
    cout<<"_________________________________________________________________________________________________________________________________________\n";
    cout<<"NO |      KODE        |        NAMA BARANG      |        HARGA    \t\t\t|       KATEGORI     \t|    TANGGAL EXPIRE \t|\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------\n";

    while(!data.eof()){
        z++;
        i++;
        data>>input.barang[i].kode>>input.barang[i].namabarang>>input.barang[i].harga>>input.barang[i].kategori>>input.barang[i].tanggal;
    }

    for(i=1;i<=z;i++){
        while(i>=10){
            cout<<i<<" | "<<"      "<<input.barang[i].kode<<"     |"<<"\t       "<<input.barang[i].namabarang<<"\t\t|"<<"        "<<input.barang[i].harga<<"     \t\t\t|"<<"       "<<input.barang[i].kategori<<"     \t|"<<"        "<<input.barang[i].tanggal<<"   \t|"<<endl;
        }
        while(i<10){
            cout<<i<<"  | "<<"      "<<input.barang[i].kode<<"     |"<<"\t       "<<input.barang[i].namabarang<<"\t\t|"<<"        "<<input.barang[i].harga<<"     \t\t\t|"<<"       "<<input.barang[i].kategori<<"     \t|"<<"        "<<input.barang[i].tanggal<<"   \t|"<<endl;
        }
    }


    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------\n";
    data.close();

    exit(0);

}

void hapusbarang2(){

    ofstream data;

    data.open("barang.txt",ios::trunc);

    for(i=1;i<=z;i++){
        if(input.barang[i].kode!=kodehapus){
            data<<input.barang[i].kode<<"\t"<<input.barang[i].namabarang<<"\t"<<input.barang[i].harga<<"\t"<<input.barang[i].kategori<<"\t"<<input.barang[i].tanggal<<endl;
        }
    }

    data.close();
}

//MENU HAPUS HAFI
void hapusbarang(){

    i=0;
    z=0;
    ifstream data;
    data.open("barang.txt");

    cout<<"\n\t\t\t\t ~~~~~~~~~~ LIST OF ITEM ~~~~~~~~~~\n\n";
    cout<<"_________________________________________________________________________________________________________________________________________\n";
    cout<<"NO|      KODE       |        NAMA BARANG        |        HARGA    \t\t\t|       KATEGORI     \t|    TANGGAL EXPIRE \t|\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------\n";

    while(!data.eof()){
        z++;
        i++;
        data>>input.barang[i].kode>>input.barang[i].namabarang>>input.barang[i].harga>>input.barang[i].kategori>>input.barang[i].tanggal;
    }

    for(i=1;i<=z;i++){
        cout<<i<<" |"<<"      "<<input.barang[i].kode<<"     |"<<"\t       "<<input.barang[i].namabarang<<"\t\t|"<<"        "<<input.barang[i].harga<<"     \t\t\t|"<<"       "<<input.barang[i].kategori<<"     \t|"<<"        "<<input.barang[i].tanggal<<"   \t|"<<endl;
    }

    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------\n";

    data.close();

    cout << "Masukkan Kode yg ingin di hapus: ";
    cin >> kodehapus;

    hapusbarang2();

}

//MENU PETUGAS

void strukmember(){

    i=0;
    z=0;
    ifstream last;

    struct cobatukeran{
        char tukernama[100];
        int tukerkode;
        int tukerharga,tukerawal;
    }tuker[100];

    int tukerkembalian,tukeruang;

    last.open("struk.txt");

    while(!last.eof()){
        z++;
        i++;
        last>>input.barang[i].kode>>input.barang[i].namabarang>>input.barang[i].harga>>totalpotongan>>totalawal>>total;
        strcpy(tuker[i].tukernama,input.barang[i].namabarang);
        tuker[i].tukerkode=input.barang[i].kode;
        tuker[i].tukerharga=input.barang[i].harga;
        tuker[i].tukerawal=totalawal;
    }

    cout<<"=========================================================="<<endl;
    cout<<"|| PT ONION STORE \t\t\t\t\t||"<<endl;
    cout<<"|| Jalan Telekomunikasi No 1, Bandung \t\t\t||"<<endl;
    cout<<"|| (022)  1213983923 \t\t\t\t\t||"<<endl;
    cout<<"|| \t\t\t\t\t\t\t||"<<endl;
    cout<<"  \t\t"<<dt;
    cout<<"=========================================================="<<endl;

    for(i=1;i<z;i++){
        cout<<"|| "<<tuker[i].tukerkode<<"\t\t"<<tuker[i].tukernama<<"\t\t"<<tuker[i].tukerharga<<"\t\t||"<<endl;
    }
    last.close();

    ifstream baayaruang;

    baayaruang.open("duit.txt");

    baayaruang>>uang>>kembalian;

    tukerkembalian=kembalian;
    tukeruang=uang;
    cout<<"|| "<<"\t\t\t\t\t\t\t||";
    cout<<endl;
    cout<<"||\t\t----------------------------------------||"<<endl;
    cout<<"||\t\tHarga Jual\t: Rp. "<<totalawal<<"\t\t||"<<endl;
    cout<<"||\t\t----------------------------------------||"<<endl;
    cout<<"||\t\tAnda Hemat\t: Rp. "<<totalpotongan<<"\t\t||"<<endl;
    cout<<"||\t\tTotal \t\t: Rp. "<<total<<"\t\t||"<<endl;
    cout<<"||\t\tTunai \t\t: Rp. "<<tukeruang<<"\t\t||"<<endl;
    cout<<"||\t\tKembalian \t: Rp. "<<tukerkembalian<<"\t\t||"<<endl;
    cout<<"|| "<<"\t\t\t\t\t\t\t||"<<endl;
    cout<<"|| "<<"\t\t\t\t\t\t\t||"<<endl;
    cout<<"|| "<<"\t\t\t\t\t\t\t||"<<endl;
    cout<<"|| "<<"    TERIMAKASIH SUDAH BERBELANJA DI ONION STORE \t||"<<endl;
    cout<<"|| "<<"\t   TERIMAKASIH SUDAH MENDAFTAR MEMBER \t\t||"<<endl;
    cout<<"=========================================================="<<endl;


    ending();

}

void struknonmember(){

    i=0;
    z=0;

    ifstream struknon;

    struct cobatukeran{
        char nonnama[100];
        int nonkode;
        int nonharga;
    }tukernon[100];

    int nonkembalian,nonuang;

    struknon.open("struknnonmember.txt");

    while(!struknon.eof()){
        z++;
        i++;
        struknon>>input.barang[i].kode>>input.barang[i].namabarang>>input.barang[i].harga>>total;
        strcpy(tukernon[i].nonnama,input.barang[i].namabarang);
        tukernon[i].nonkode=input.barang[i].kode;
        tukernon[i].nonharga=input.barang[i].harga;
    }

    cout<<"=========================================================="<<endl;
    cout<<"|| PT ONION STORE \t\t\t\t\t||"<<endl;
    cout<<"|| Jalan Telekomunikasi No 1, Bandung \t\t\t||"<<endl;
    cout<<"|| (022)  1213983923 \t\t\t\t\t||"<<endl;
    cout<<"|| \t\t\t\t\t\t\t||"<<endl;
    cout<<"  \t\t"<<dt;
    cout<<"=========================================================="<<endl;

    for(i=1;i<z;i++){
        cout<<"|| "<<tukernon[i].nonkode<<"\t\t"<<tukernon[i].nonnama<<"\t\t"<<tukernon[i].nonharga<<"\t\t||"<<endl;
    }

    struknon.close();

    ifstream baayaruangnonmem;

    baayaruangnonmem.open("duitnonmem.txt");

    baayaruangnonmem>>uang>>kembalian;

    nonkembalian=kembalian;
    nonuang=uang;

    cout<<"|| "<<"\t\t\t\t\t\t\t||";
    cout<<endl;
    cout<<"||\t\t----------------------------------------||"<<endl;
    cout<<"||\t\tHarga Jual\t: Rp. "<<total<<"\t\t||"<<endl;
    cout<<"||\t\t----------------------------------------||"<<endl;
    cout<<"||\t\tTotal \t\t: Rp. "<<total<<"\t\t||"<<endl;
    cout<<"||\t\tTunai \t\t: Rp. "<<nonuang<<"\t\t||"<<endl;
    cout<<"||\t\tKembalian \t: Rp. "<<nonkembalian<<"\t\t||"<<endl;
    cout<<"|| "<<"\t\t\t\t\t\t\t||"<<endl;
    cout<<"|| "<<"\t\t\t\t\t\t\t||"<<endl;
    cout<<"|| "<<"\t\t\t\t\t\t\t||"<<endl;
    cout<<"|| "<<"    TERIMAKASIH SUDAH BERBELANJA DI ONION STORE \t||"<<endl;
    cout<<"|| "<<"\t   BELANJA LEBIH HEMAT DENGAN MEMBER! \t\t||"<<endl;
    cout<<"|| "<<"    DAFTAR MEMBER UNTUK MENDAPATKAN POTONGAN 5% \t||"<<endl;
    cout<<"=========================================================="<<endl<<endl;

    ending();
}

void daftarmember(){


    ofstream fn;
    fn.open("member.txt",ios::app);

    do{
        i++;
        cout<<"Masukkan Nama Member \t: ";
        cin>>member[i].namamember;
        cout<<"No Handphone \t\t: ";
        cin>>member[i].notelp;
        fn<<member[i].namamember<<"\t"<<member[i].notelp<<endl;
        cout<<endl;
        cout<<"Apakah Ingin Tambah Member Lagi ( y/t ) : ";
        cin>>pil;
    }while(pil=='y');

    cout<<endl;
    cout<<"MEMBER BERHASIL TERDAFTAR ! "<<endl;
}


void bayarmember(){

    tampilbarang();
    char choose;
    diskon=5;
    total=0;
    totalpotongan=0;
    totalawal=0;

    ofstream last;

    last.open("struk.txt",ios::trunc);

     do{
        cout<<"Masukkan Kode Barang Yang Dibeli : ";
        cin>>code;

        for(i=1;i<=z;i++){
            if(code==input.barang[i].kode){
                cout<<"Anda Membeli "<<input.barang[i].namabarang<<endl;
                potongan=(float)(diskon/100)*input.barang[i].harga;
                totalawal=totalawal+input.barang[i].harga;
                totalpotongan=totalpotongan+potongan;
                totalkeseluruhan=(float)input.barang[i].harga-potongan;
                total=total+totalkeseluruhan;
                last<<input.barang[i].kode<<"\t"<<input.barang[i].namabarang<<"\t"<<input.barang[i].harga<<"\t"<<totalpotongan<<"\t"<<totalawal<<"\t"<<total<<endl;
            }
        }
        //cout<<"Data dengan Kode "<<code<<" Tidak Tersedia"<<endl;
        cout<<"Apakah Ada Tambahan Lagi (y/t) : ";
        cin>>pil;

    }while(pil=='y');

    last.close();

    ofstream baayaruang;

    baayaruang.open("duit.txt",ios::trunc);

    cout<<"Anda Mendapatkan Potongan Sebesar \t: "<<totalpotongan<<endl;
    cout<<"Total Harga Belanja Anda \t\t: "<<total<<endl;

    cout<<"Masukkan Jumlah Uang Yang Dibayarkan : Rp. ";
    cin>>uang;

    kembalian=uang-total;

    cout<<endl;

    baayaruang<<uang<<"\t"<<kembalian<<endl;

    baayaruang.close();

    system("pause");

    cout<<"Apakah Anda Ingin Mencetak Struk ( y/t ) : ";
    cin>>choose;

    switch(choose){
        case 'y':system("pause");system("cls");strukmember();break;
        case 't': ending();break;

    }
}

void bayarnonmember(){

    char choosed;

    tampilbarang();

    ofstream struknon;
    struknon.open("struknnonmember.txt",ios::trunc);

    do{
        cout<<"Masukkan Kode Barang Yang Dibeli : ";
        cin>>code;
        for(i=1;i<=z;i++){
            if(code==input.barang[i].kode){
                cout<<"Anda Membeli "<<input.barang[i].namabarang<<endl;
                total=total+input.barang[i].harga;
                struknon<<input.barang[i].kode<<"\t"<<input.barang[i].namabarang<<"\t"<<input.barang[i].harga<<"\t"<<total<<endl;
            }
        }

        cout<<"Apakah Ada Tambahan Lagi (y/t) : ";
        cin>>pil;

    }while(pil=='y');

    struknon.close();

    ofstream baayaruangnonmem;

    baayaruangnonmem.open("duitnonmem.txt",ios::trunc);

    cout<<"Total Harga : "<<total<<endl;
    cout<<"Masukkan Jumlah Uang Yang Dibayarkan : Rp. ";
    cin>>uang;

    kembalian=uang-total;

    cout<<endl;
    cout<<"Kembali : Rp. "<<kembalian;

    baayaruangnonmem<<uang<<"\t"<<kembalian<<endl;

    baayaruangnonmem.close();

    system("pause");

    cout<<"Apakah Anda Ingin Mencetak Struk ( y/t ) : ";
    cin>>choosed;

    switch(choosed){
        case 'y':system("pause");system("cls");struknonmember();break;
        case 't': ending();break;
    }

}



void pembayaran(){

    int j;
    char temp[20];

    sini:
    cout<<"Do You Have Member (y/t) : ";
    cin>>pil;

    if(pil=='y'){

        cout<<"Masukkan No Handphone Member \t: ";
        cin>>temp;
        i=0;
        int o=0;

        system("pause");
        system("cls");

        ifstream fn;
        fn.open("member.txt");

        while(!fn.eof()){
            i++;
            o++;
            fn>>member[i].namamember>>member[i].notelp;
        }

        for(j=1;j<=o;j++){
            if(strcmp(member[j].notelp,temp)==0){
                cout<<"Nama Member \t\t: "<<member[j].namamember<<endl;
                cout<<"Nomer Handphone Member \t: "<<member[j].notelp<<endl<<endl;
                cout<<"SELAMAT ANDA MENDAPATKAN DISKON 5%"<<endl<<endl;
                system("pause");
                system("cls");
                bayarmember();
            }
        }
        cout<<"No Members Found With "<<temp<<endl;
        goto sini;

        fn.close();

    }

    else{
        system("cls");
        bayarnonmember();

    }
}

void petugas(){

    awal:

    cout<<"\t\t\t\t MENU PETUGAS"<<endl;
    cout<<"=================================="<<endl;
    cout<<"||======== Pilihan Menu ========||"<<endl;
    cout<<"=================================="<<endl;
    cout<<"|| 1. Tambah Member \t\t||"<<endl;
    cout<<"|| 2. Menu Pembayaran \t\t||"<<endl;
    cout<<"=================================="<<endl<<endl;

    cout<<"Masukkan Pilihan : ";
    cin>>n;

    switch(n){
        case 1:system("pause");system("cls");daftarmember();break;
        case 2:system("pause");system("cls");pembayaran();break;

    }

}

void lihatmember(){

    ifstream fn;
    fn.open("member.txt",ios::app);


    while(!fn.eof()){
        z++;
        i++;
        fn>>member[i].namamember>>member[i].notelp;

    }

    cout<<"\n\t\t ~~~~~~~~~~ LIST OF MEMBER ~~~~~~~~~~\n\n";
    cout<<"_________________________________________________________________\n";
    cout<<"NO|    NAMA MEMBER \t|        NOMER HANDPHONE MEMBER   \t|\n";
    cout<<"-----------------------------------------------------------------\n";

    for(i=1;i<=z;i++){
        if(i>=10){
                cout<<i<<" |"<<"      "<<member[i].namamember<<"     \t|"<<"\t       "<<member[i].notelp<<"\t\t|"<<endl;
        }
        else{
               cout<<i<<"  |"<<"      "<<member[i].namamember<<"     \t|"<<"\t       "<<member[i].notelp<<"\t\t|"<<endl;
        }
    }

    cout<<"-----------------------------------------------------------------\n";

    fn.close();


}

//MENU ADMIN

void menuadmin(){

    system("cls");

    cout<<"=================================="<<endl;
    cout<<"||======== Pilihan Menu ========||"<<endl;
    cout<<"=================================="<<endl;
    cout<<"|| 1. Tambah Barang          \t||"<<endl;
    cout<<"|| 2. Remove Barang          \t||"<<endl;
    cout<<"|| 3. Lihat Daftar Barang    \t||"<<endl;
    cout<<"|| 4. Lihat Daftar Member    \t||"<<endl;
    cout<<"=================================="<<endl<<endl;

    cout<<"Masukkan Pilihan : ";
    cin>>a;

    switch(a){
        case 1 : system("pause");system("cls");brg.barang();break;
        case 2 : system("pause");system("cls");hapusbarang();break;
        case 3 : system("pause");system("cls");tampilbarang();break;
        case 4 : system("pause");system("cls");lihatmember();break;

    }

}

//UNTUK LOGIN

//Menyamarkan Password
void readPass(char *temp){
    int key=0,index=0;
    do{
        key=getch();
        switch (key){
            case 0:
            case 224:
                getch();
                break;
            case '\b':
                if(index>0){
                    index=index-1;
                    temp[index] = 0;
                    printf("\b \b");
                }
                break;
            default:
                if(key>31&&key<127){
                    temp[index]=key;
                    index = index + 1;
                    printf("*");
                }
        }
    } while(key!=13);

    temp[index]='\0';
}



void create(){

    system("CLS");
    system("color 3f");

    cout<<"\t-----------------------------------------"<<endl;
    cout<<"\t|\t\tRegister Menu\t\t|"<<endl;
    cout<<"\t-----------------------------------------"<<endl;


    ofstream data;

    data.open("user.txt",ios::app);

    cout<<"\tCreate Username : ";
    cin>>nama;
    cout<<"\tCreate Password : ";
    readPass(password);

    cout<<endl<<endl;
    cout<<"\t\t\t\tCreate Success !"<<endl<<endl;

    if(!data.fail()){
        data<<nama<<"\t"<<password<<endl;
        data.close();
    }

}

//Save file
void save(int a,int b,char u[100][100],char p[100][100]){

    ofstream rk;

    rk.open("user.txt");

    for(i=0;i<a;i++){
        if(i==b){
            rk<<"";
            continue;
        }
        else
            rk<<u[i]<<"\t"<<p[i]<<endl;

    }

    rk.close();

}

void hapususer(){


    char phandler[100][100];
    char uhandler[100][100];

    ifstream rk;

    rk.open("user.txt");

    int cntr=0;

    while(!rk.eof()){
        rk>>nama>>password;
        strcpy(uhandler[cntr],nama);
        strcpy(phandler[cntr],password);
        cntr++;
    }

    rk.close();

    cout<<"=========================="<<endl;
    cout<<"||    ~LIST OF USER~ \t||"<<endl;
    cout<<"=========================="<<endl;
    for(i=1;i<cntr-1;i++)
        cout<<"|| "<<i<<". username  : "<< uhandler[i]<<"\t||"<<endl;
    cout<<"=========================="<<endl;

    cout<<endl;
    cout<<"Masukkan Username yang ingin di hapus: ";
    cin>>nama;

    system("cls");

    cout<<"You Must Input Password To Remove Username: ";
    readPass(password);

    if(strcmp(password,"admin")==0){
        for(i=0;i<cntr-1;i++){
            if(strcmp(uhandler[i],nama)==0){
                int cntr2=i;
                save(cntr-1,cntr2,uhandler,phandler);break;
            }
        }
    }

    rk.close();

}

void login(){


    cout<<"\t\t\t\t\t-----------------------------------------"<<endl;
    cout<<"\t\t\t\t\t*****************************************"<<endl;
    cout<<"\t\t\t\t\t|\t\tMENU LOGIN    \t\t|"<<endl;
    cout<<"\t\t\t\t\t*****************************************"<<endl;
    cout<<"\t\t\t\t\t-----------------------------------------"<<endl;

    if(logincntr>0){
        system("cls");
        cout<<"\t\t\t\t\t   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        cout<<"\t\t\t\t\t   ! USERNAME OR PASSWORD WAS INCORRECT !"<<endl;
        cout<<"\t\t\t\t\t   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl<<endl;
        cout<<"\t\t\t\t       Please Try Again To Input Username Or Password"<<endl;
    }

    ifstream rk;

    rk.open("user.txt");


    bool loginz;
    loginz=false;
    cout<<"\n\n\t\t\t\t      PLEASE INSERT YOUR USERNAMSE AND PASSWORD AGAIN\n\n";
    cout<<"\n\t\t\t\t\t\t   Username: ";
    cin>>usr;
    cout<<"\t\t\t\t\t\t   Password: ";
    readPass(pws);


    while(!rk.eof()){
        rk>>nama>>password;
        if((strcmp(nama,usr)==0)&&(strcmp(pws,password)==0)){
            loginz=true;
            cout<<"\n\n\t\t\t\t\t     Login Successful Welcome "<<usr; break;
        }
    }

    if(!loginz){
        logincntr=1;
        login();
    }

    if(loginz){
        cout<<endl<<endl;
        cout<<"\t\t\t\t\t\t";system("pause");
        system("cls");

        if((strcmp("admin",usr)==0)&&(strcmp(pws,"admin")==0)){
            system("color 3f");
            cout<<"==================================="<<endl;
            cout<<"||======== Pilihan Admin ========||"<<endl;
            cout<<"==================================="<<endl;
            cout<<"|| 1. Tambah User    \t\t ||"<<endl;
            cout<<"|| 2. Remove User    \t\t ||"<<endl;
            cout<<"|| 3. Menu Admin   \t\t ||"<<endl;
            cout<<"==================================="<<endl<<endl;
            cout<<"Masukkan Pilihan : ";
            cin>>piladm;

            switch(piladm){
                case 1:system("pause");system("cls");create();break;
                case 2:system("pause");system("cls");hapususer();break;
                case 3:system("pause");system("cls");menuadmin();break;
            }
        }
        else{
            petugas();
        }
    }
}



int main()
{
    loading();
    login();

    //ending();
    //lihatmember();
    //struknonmember();
    //strukmember();
    //daftarmember();
    //tampilbarang();

    return 0;
}
