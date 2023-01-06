#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

struct dll{
    string nama;
    int tarif;
    int durasi;
    dll *next;
    dll *prev;
};

dll *head=NULL;
dll *tail=NULL;

void tambahdepan()
{
    dll *baru;
    baru = new dll;
    cout << "Nama pemancing : ";
    cin >> baru->nama;
    cout << "Durasi Memancing : ";
    cin >> baru->durasi;
    baru->tarif=baru->durasi*5000;
    cout << "Tarif Memancing : " << baru->tarif<<endl;
    baru->next=NULL;
    baru->prev=NULL;
    if(head==NULL)
    {
        head=baru;
        tail=baru;
    }
    else
    {
        baru->next=head;
        head->prev=baru;
        head=baru;
    }
}

void hapusdepan()
{
    dll *hapus;
    if(head==NULL)
    {
        cout << "data masih kosong"<<endl;
    }
    else
    {
        if(head==tail)
        {
            hapus=head=tail;
            head=NULL;
            tail=NULL;
            delete hapus;
        }
        else
        {
            hapus=head;
            head=head->next;
            head->prev=tail;
            tail->next=head;
            delete hapus;
        }

    }

}
void hapusbelakang()
{
    dll *hapus;
    if(head==NULL)
    {
        cout << "data masih kosong"<<endl;
    }
    else
    {
        if(head==tail)
        {
            hapus=head=tail;
            head=NULL;
            tail=NULL;
            delete hapus;
        }
        else
        {
            hapus=tail;
            tail=tail->prev;
            delete hapus;
        }

    }

}
void hapustengah(int cari)
{
    dll *hapus;
    dll *bantu;
    bantu=head;
    if(head==NULL)
    {
        cout << "data masih kosong"<<endl;
    }
    else if(head==tail)
    {
        hapus=head=tail;
        nilai=hapus->nilai;
        head=NULL;
        tail=NULL;
        delete hapus;
    }
    else
    {
        do
        {
            if(bantu->next->nilai==cari)
            {
                if(bantu->next==head)
                {
                    hapusdepan();
                }
                else if(bantu->next==tail)
                {
                    hapusbelakang();
                }
                else
                {
                    hapus=bantu->next;
                    nilai=hapus->nilai;
                    bantu->next->next->prev=bantu;
                    bantu->next=bantu->next->next;
                    delete hapus;
                }
            }
            bantu=bantu->next;
        }while(bantu->next!=NULL);
    }
}

void caridata(int cari)
{
    dll *bantu;
    bantu=head;

    if(head==NULL)
    {
        cout << "Data Kosong"<<endl;
    }
    else
    {
        do
        {
            if(bantu->nilai==cari)
            {
                cout << "Data Ketemu"<<endl;
                break;
            }
            bantu=bantu->next;
        }while(bantu!=head);
    }
}

//void tambahtengah(int cari)
//{
//    dll *baru;
//    dll *bantu;
//    baru = new dll;
//    bantu=head;
//    baru->next=NULL;
//    baru->prev=NULL;
//    if(head==NULL)
//    {
//        head=baru;
//        tail=baru;
//        tail->next=head;
//        head->prev=tail;
//    }
//    else
//    {
//        do
//        {
//            if(bantu->nilai==cari)
//            {
//                if(bantu==head)
//                {
//                    tambahdepan();
//                    break;
//                }
//                else if(bantu==tail)
//                {
//                    tambahbelakang();
//                    break;
//                }
//                else
//                {
//                    cout << "inputkan nilainya : ";
//                    cin >> baru->nilai;
//                    baru->next=bantu->next;
//                    bantu->next=baru;
//                    baru->prev=bantu;
//                    break;
//                }
//
//            }
//            bantu=bantu->next;
//
//        }while(bantu!=head);
//    }
//}
void tampildepan()
{
    dll *bantu;
    bantu=head;
    if(head!=NULL)
    {
        do
        {
            cout << bantu->nilai<<endl;
            bantu=bantu->next;
        }
        while(bantu!=head);
    }
    else
    {
        cout << "Data Masih Kosong"<<endl;
    }

}

void tampilbelakang()
{
    dll *bantu;
    bantu=tail;
    if(head!=NULL)
    {
        do
        {
            cout << bantu->nilai<<endl;
            bantu=bantu->prev;
        }
        while(bantu!=tail);
    }
    else
    {
        cout << "Data Masih Kosong"<<endl;
    }

}

int main()
{
    int pilih;
    string cari;
    do
    {
        system("cls");
        tampildepan();
        cout << "Struktur Data : DOUBLE LINKED LIST CIRCULAR"<<endl;
        cout << "1. Tambah data di depan"<<endl;
        cout << "2. Hapus Data di Depan"<<endl;
        cout << "3. Hapus Data di Tengah"<<endl;
        cout << "4. Tampil Data dari Depan"<<endl;
        cout << "5. Total jam seluruh pemancing"<<endl;
        cout << "6. Total Pendapatan"<<endl;
        cout << "7. Selesai"<<endl;
        cout << endl << "Pilihan Anda [1-7] : ";
        cin >> pilih;

        switch(pilih)
        {
            case 1:
                tambahdepan();
                break;
            case 2:
                hapusdepan();
                break;
            case 3:
                cout << "Hapus data yang mana = ";
                cin >> cari;
                hapustengah(cari);
                break;
            case 4:
                hapusdepan();
                break;
            case 5:
//                totalDurasi();
                break;
            case 6:
                //totalPendapatan();
                break;
            case 7:
                tampildepan();
                cout << "klik untuk lanjut . . .";
                getch();
                break;
        }
    }while(pilih!=10);

    return 0;
}
