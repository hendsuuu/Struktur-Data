#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
struct TNode{
    int NilaiX;
    int NilaiY;
    string target;
    TNode *next;
};

TNode *head, *tail;

void init (){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(tail==NULL)return 1;
    else return 0;
}
void kotak(int b1, int k1, int b2, int k2)
{
    for(int x=k1; x<=k2; x++)
    {
        gotoxy(x,b1);printf("%c",196);
        gotoxy(x,b2);printf("%c",196);
    }
    for(int x=b1; x<=b2; x++)
    {
        gotoxy(k1,x);printf("%c",179);
        gotoxy(k2,x);printf("%c",179);
    }

    gotoxy(k2,b1);printf("%c",191); /*+*/
    gotoxy(k1,b2);printf("%c",192); /*+*/
    gotoxy(k1,b1);printf("%c",218); /*+*/
    gotoxy(k2,b2);printf("%c",217); /*+*/
}

void insertDepan(int databaru1,int databaru2,string baru3)
{
    TNode *baru;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->target=baru3;
    baru->next = NULL;
    if(isEmpty()==1)
    {
        head=tail=baru;
        tail->next=NULL;
    }else
    {
        baru->next = head;
        head=baru;
    }
    cout<<"Data "<<databaru1<<" dan "<<databaru2<<" Berhasil Ditambahkan";
}
void Searching(int cari1,int cari2,string cari3)
{
    TNode *bantu;
    if(isEmpty()==0){
        bantu=head;
        while(bantu->NilaiX!= cari1 && bantu->NilaiY!=cari2 && bantu->target!=cari3){
            bantu = bantu->next;
        }
        if(bantu->NilaiX== cari1 && bantu->NilaiY==cari2 && bantu->target==cari3)
        {
            cout << "data ditemukan ";
        }
        else{
            cout << "data tidak ditemukan";
        }

    }
    else{
        cout << "data masih kosong";
    }
}
void insertBelakang(int databaru1,int databaru2,string baru3)
{
    TNode *baru;
    baru = new TNode;
    baru->NilaiX = databaru1;
    baru->NilaiY = databaru2;
    baru->target=baru3;
    baru->next = NULL;
    if(isEmpty()==1)
    {
        head=tail=baru;
        tail->next=NULL;
    }else
    {
        tail->next = baru;
        tail=baru;
    }
    cout<<"Data "<<databaru1<<" dan "<<databaru2<<" Berhasil Ditambahkan";
}
void tampil(){
    TNode *bantu;
    int ke=0;
    bantu=head;
        if(isEmpty()==0)
        {
            while(bantu!=NULL)
            {
                kotak(20,(ke*10),24,(ke*10)+5);
                kotak(20,(ke*10)+5,24,(ke*10)+7);
                gotoxy(1+(ke*10),22);printf("%c%c%c%c",196,196,196,196);
                gotoxy(2+(ke*10),21);cout<<bantu->NilaiX;
                gotoxy(2+(ke*10),23);cout<<bantu->NilaiY;
                gotoxy(2+(ke*10),24);cout<<bantu->target;
                gotoxy(6+(ke*10),22);printf("%c%c>",196,196);
                ke++;
                bantu=bantu->next;
            }
            cout<<"NULL";
        }else cout <<"Masih kosong\n";
}


void tambahDataAfter(int cari1,int cari2,string cari3,int databaru1,int databaru2,string baru3)
{
    TNode *bantu;
    bantu=head;
    if (!isEmpty())
    {
        TNode *baru;
        baru = new  TNode;
        baru->NilaiX = databaru1;
        baru->NilaiY = databaru2;
        baru->target=baru3;
        baru->next = NULL;

        while (bantu != NULL)
        {
            if (bantu->NilaiX == cari1 && bantu->NilaiY == cari2 && bantu->target==cari3)
            {
                if (bantu->next != NULL)
                {
                    baru->next = bantu->next;
                    bantu->next = baru;
                    break;
                }
                else
                {
                    bantu->next = baru;
                    tail = baru;
                }
            }
            else{
                cout << "Data Tidak ada ";
                break;
            }
            bantu = bantu->next;
        }
        cout<<"Data Berhasil Ditambahkan setelah ("<<cari1<<", "<<cari2<<")";
    }
    else
        cout << "Data tidak ditemukan" << endl;
}


void tambahDataBefore(int cari1,int cari2,string cari3,int databaru1,int databaru2,string baru3)
{
    TNode *bantu;
    bantu=head;
    if (!isEmpty())
    {
        TNode *baru;
        baru = new TNode;
        baru->NilaiX = databaru1;
        baru->NilaiY = databaru2;
        baru->target = baru3;
        baru->next = NULL;

        while (bantu != NULL)
        {
            if (bantu->next->NilaiX == cari1 && bantu->next->NilaiY == cari2 && bantu->next->target==cari3)
            {
                if (bantu->next != NULL)
                {
                    baru->next = bantu->next;
                    bantu->next = baru;
                    break;
                }
                else
                {
                    bantu->next = head;
                    head = baru;
                }
            }
            bantu = bantu->next;
        }
        cout<<"Data Berhasil Ditambahkan sebelum ("<<cari1<<", "<<cari2<<")";
    }
    else
        cout << "Data tidak ditemukan" << endl;
}

void hapusDepan()
{

    TNode *hapus;
    int d,d2;
    string d3;
    if (isEmpty()==0)
    {
        if(head!=tail)
        {
            hapus=head;
            d=hapus->NilaiX;
            d2=hapus->NilaiY;
            d3=hapus->target;
            head=head->next;
            delete hapus;
        }else
        {
            hapus=head;
            d=hapus->NilaiX;
            d2=hapus->NilaiY;
            d3=hapus->target;
            head=tail=NULL;
            delete hapus;
        }
        cout<<"Nilai X = "<<d<< " " <<"Niai Y = "<<d2<<"terhapus";
    }else cout<<"Masih kosong\n";
}
void hapusSpecial(int cari1,int cari2,string cari3)
{
    TNode *bantu;
    TNode *hapus;
    bantu=head;
    int d,d2;
    string d3;
    if (!isEmpty())
    {
        while (bantu != NULL)
        {
            if(head!=tail){
                 if (bantu->next->NilaiX == cari1 && bantu->next->NilaiY == cari2 && bantu->next->target == cari3)
                {
                    hapus=bantu->next;
                    bantu->next = hapus->next;
                    d=hapus->NilaiX;
                    d2=hapus->NilaiY;
                    d3=hapus->target;
                    delete hapus;
                    break;
                }
            }else{
                hapus=head=tail;
                d=hapus->NilaiX;
                d2=hapus->NilaiY;
                d3=hapus->target;
                head=tail=NULL;
                delete hapus;
            }

            bantu = bantu->next;
        }
        cout<<"Nilai X = "<<d<< " " <<"Niai Y = "<<d2<<" Berhasil terhapus";
    }
    else
        cout << "Data tidak ditemukan" << endl;
}
void hapusBelakang()
{

    TNode *hapus;
    TNode *bantu;

    if (!isEmpty())
    {
        if(head->next!=NULL)
        {
            bantu = head;
            while(bantu->next != tail){
                bantu = bantu->next;
            }
            hapus=tail;
            tail=bantu;
            tail->next=NULL;
            delete hapus;
        }
        else{
            head = NULL;
            tail=NULL;
        }
        cout<<"data berhasil terhapus";

    }else cout<<"Masih kosong\n";
}

void clear()
{
    TNode *bantu, *hapus;
    bantu =head;
    while(bantu!=NULL)
    {
        hapus=bantu;
        bantu=bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    printf("clear");
}

main()
{
    int pil, databaru1, databaru2,cari1,cari2;
    string baru,cari3;

    do
    {
        system("cls");
        tampil();
        gotoxy(1,1);
        cout<<endl;
        cout<<" ============================"<<endl;
        cout<<" =   PROGRAM LINKED LIST    ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" = 1. Insert Depan          ="<<endl;
        cout<<" = 2. Insert belakang       ="<<endl;
        cout<<" = 3. Tambah data after     ="<<endl;
        cout<<" = 4. Tambah Data before    ="<<endl;
        cout<<" = 5. Delete depan          ="<<endl;
        cout<<" = 6. Delete belakang       ="<<endl;
        cout<<" = 7. Special Delete        ="<<endl;
        cout<<" = 8. Searching Data        ="<<endl;
        cout<<" = 9. Tampil Data           ="<<endl;
        cout<<" = 10. Clear                ="<<endl;
        cout<<" = 11. Exit                 ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" Masukan Pilihan : ";cin>>pil;
        switch (pil)
        {
            case 1: system("cls");{
                cout<<"Masukan Data X = ";cin>>databaru1;
                cout<<"Masukan Data Y = ";cin>>databaru2;
                cout << "masukkan string target = ";cin>> baru;
                insertDepan(databaru1,databaru2,baru);
                break;
            }
            case 2: system("cls");{
                cout<<"Masukan Data X = ";cin>>databaru1;
                cout<<"Masukan Data Y = ";cin>>databaru2;
                cout << "masukkan string target = ";cin>> baru;
                insertBelakang(databaru1,databaru2,baru);
                break;
            }
            case 3: system("cls");{
                cout << "Maukkan setelah data"<<endl;
                cout << "Data X = ";
                cin >> cari1;
                cout << "Data Y = ";
                cin >> cari2;
                cout << "Cari data target = ";cin >> cari3;
                cout<< "Maukkan databaru"<<endl;
                cout<<"Masukkan Data X= ";cin>>databaru1;
                cout<<"Masukkan Data Y= ";cin>>databaru2;
                cout<<"Masukkan data target = ";cin>>baru;
                tambahDataAfter(cari1,cari2,cari3,databaru1,databaru2,baru);
                break;
            }
            case 4: system("cls");{
                cout << "Maukkan setelah data"<<endl;
                cout << "Data X = ";
                cin >> cari1;
                cout << "Data Y = ";
                cin >> cari2;
                cout << "Cari data target = ";cin >> cari3;
                cout<< "Maukkan databaru"<<endl;
                cout<<"Masukan Data X= ";cin>>databaru1;
                cout<<"Masukan Data Y= ";cin>>databaru2;
                cout<<"Masukkan data target = ";cin>>baru;
                tambahDataBefore(cari1,cari2,cari3,databaru1,databaru2,baru);
                break;
            }
            case 5: system("cls");{
                hapusDepan();
                break;
            }
            case 6: system("cls");{
                hapusBelakang();
                break;
            }
            case 7: system("cls");{
                cout<< "Data yang ingin di hapus "<<endl;
                cout << "Data X = ";
                cin >> cari1;
                cout << "Data Y = ";
                cin >> cari2;
                cout << "Data target = ";cin>>cari3;
                hapusSpecial(cari1,cari2,cari3);
                break;
            }
            case 8: system("cls");{
                cout << "Cari Data X = ";
                cin >> cari1;
                cout << "Cari Data Y = ";
                cin >> cari2;
                cout << "Data target = ";cin>>cari3;
                Searching(cari1,cari2,cari3);
                break;
            }
            case 9: system("cls");{
                tampil();
                break;
            }
            case 10: system("cls");{
                clear();
                break;
            }
            case 11: system("cls");{
                return 0;
                break;
            }
            default : system("cls");
            {
                cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
            }
        }
        getch();
    }
    while (pil!=11);
}
