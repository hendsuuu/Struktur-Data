#include <iostream>

using namespace std;

struct antrian
{
    char nama[30];
    char sex;
    int umur;

};
struct antrian pasien[100];
int datake = 1;
int maxx = 10;

void inqueue()
{
    cout <<endl;
    cout << "Inputkan nama Pasien : ";
    cin >> pasien[datake].nama;
    cout << "Inputkan Jenis Kelamin : ";
    cin >> pasien[datake].sex;
    cout << "Inputkan Umur Pasien : ";
    cin >> pasien[datake].umur;
    datake++;
}
void tampildata()
{
    cout<<endl;
    for(int x=1;x<datake;x++)
    {
        cout<<x<<" "<<pasien[x].nama;
        cout << " "<<pasien[x].sex;
        cout << " "<<pasien[x].umur<<endl<<endl;
    }
}
void maju(int x)
{
    for(x;x<datake;x++){
        pasien[x-1]=pasien[x];
    }

}
void isFull()
{
    if(datake>maxx)
        cout << " Maaf Antrian Penuh "<<endl;

}
void isEmpty()
{
    if(datake==1)
        cout << " Antrian Masih Kosong"<<endl;

}

void dequeue()
{
    int ke;
    cout << "yang akan di dequeue : ";
    cin >> ke;
    cout << "Data Hasil Dequeue adalah : ";
    cout << pasien[ke].nama << " "<<pasien[ke].sex<<" "<<pasien[ke].umur<<endl;
    maju(ke+1);
    datake--;

}



int main()
{
    int pilih;
    do
    {
        tampildata();
        cout << " QUEUE - ANTRIAN " << endl;
        cout << "1. INQUEUE "<<endl;
        cout << "2. DEQUEUE "<<endl;
        cout << "9. EXIT "<<endl;
        cout<< "Pilihan Anda (1-9) : ";
        cin >> pilih;
         if(pilih==1){
            isFull();
            inqueue();
         }

        if(pilih==2){
            isEmpty();
            dequeue();
        }




    }while(pilih!=9);


    return 0;
}
