#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include <time.h>
#include <dos.h>


int datake=1;
int cap  = 10;

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


using namespace std;
struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[100];

/*******************************************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void isFull()
{
    if(datake > cap){
        gotoxy(20,12);cout << "Stack Sudah Penuh !";
    }
    else{
        gotoxy(20,12);cout << "Stack Belum Penuh Masih bisa diisi";
    }

    gotoxy(20,15);
    cout<<"Press Any Key...";
    getch();
}

void isempty()
{
    if(datake == 1){
        gotoxy(20,12);cout << "Stack Masih Kosong ";
    }
    else
        gotoxy(20,12);cout << "Stack sudah Terisi ";


    gotoxy(20,15);
    cout<<"Press Any Key...";
    getch();
}

void Top()
{
    gotoxy(20,12);
    cout << "Data Tumpukan Paling atas Adalah : ";
    gotoxy(20,14);
    cout<<kirim[datake-1].jenis_brg<<" ";
    cout<<kirim[datake-1].berat<<" ";
    cout<<kirim[datake-1].kota<<endl;

    gotoxy(20,15);
    cout<<"Press Any Key...";
    getch();
}

void tambahdata()
{

    char pilih;
    do{
        system("cls");
         if(datake > cap){
            gotoxy(20,12);cout << "Stack Sudah Penuh !";
            gotoxy(20,24);
            cout<<"Press Any Key...";
            getch();
            break;
        }

        gotoxy(20,1);
        cout<<"Inputkan Jenis Barang    :";
        cin>>kirim[datake].jenis_brg;
        gotoxy(20,2);cout<<"Inputkan Berat           :";
        cin>>kirim[datake].berat;
        gotoxy(20,3);cout<<"Inputkan Kota Tujuan     :";
        cin>>kirim[datake].kota;

        gotoxy(20,6);cout << "Ada Lagi ? (Y / T) = ";
        cin >> pilih;
        datake++;
    }while(pilih == 'Y' || pilih == 'y');

}

void tampildata()
{
    system("cls");
    gotoxy(20,1);cout<<"Daftar Kiriman Paket"<<endl;

    for(int i=1;i<datake;i++){
        gotoxy(20,20-i);

        cout<<i<<". "<< kirim[i].jenis_brg<<" "<< kirim[i].berat<<" "<< kirim[i].kota;
    }


    gotoxy(20,24);
    cout<<"Press Any Key...";
    getch();
    /*harus Ijin --> #include<conio.h>*/
}
void specialpop()
{
    int angka;
    if(angka>datake){
        gotoxy(20,12);cout << "Maaf Angka yang anda masukan Melebihi stack ";
    }
    else if(angka<=1)
    {
      gotoxy(20,12);cout << "Maaf stack kosong ";
    }
    else{
        gotoxy(20,12);cout << "Masukkan data ke berapa yang ingin dikeluarkan : ";
        cin >> angka;
        gotoxy(20,14);cout<<"Data Terakhir yang anda Keluarkan Adalah :"<<endl;
        for(datake-1;datake-1>=angka;datake--)
        {

            gotoxy(20,20-datake);cout<<kirim[datake-1].jenis_brg<<" ";
            cout<<kirim[datake-1].berat<<" Kg ";
            cout<<kirim[datake-1].kota<<endl;
        }
    }

    gotoxy(20,24);
    cout<<"Press Any Key...";
    getch();

}
void hapusdata(int x)
{
    system("cls");
    gotoxy(50,17);cout<<"Data Terakhir yang anda Keluarkan Adalah :"<<endl;
    gotoxy(50,20);cout<<kirim[x].jenis_brg<<" ";
    cout<<kirim[x].berat<<" Kg ";
    cout<<kirim[x].kota<<endl;
    datake--;
    gotoxy(20,24);
    cout<<"Press Any Key...";
    getch();
}

int main()
{
    int pilih;
    do
    {
            system("cls");
            gotoxy(20,1);cout<<"MENU UTAMA";
            gotoxy(20,2);cout<<"1. PUSH";
            gotoxy(20,3);cout<<"2. POP";
            gotoxy(20,4);cout<<"3. DISPLAY";
            gotoxy(20,5);cout<<"4. TOP";
            gotoxy(20,6);cout<<"5. ISEMPTY";
            gotoxy(20,7);cout<<"6. ISFULL";
            gotoxy(20,8);cout<<"7. SpecialPOP";
            gotoxy(20,9);cout<<"9. Keluar";

            gotoxy(20,10);cout<<"Pilihan Anda [1-9] : ";

        cin>>pilih;
        switch(pilih)
        {
        case 1:
            tambahdata();
            break;
        case 2:
            hapusdata(datake-1);

            break;
        case 3:
            tampildata();
            break;
        case 4:
            Top();
            break;
        case 5:
            isempty();
            break;
        case 6:
            isFull();
            break;
        case 7:
            specialpop();
            break;
        default:
            break;
        }

    }
    while(pilih!=9);
    return 0;
}
