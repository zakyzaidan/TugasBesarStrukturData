#include "kargo.h"

int main()
{
    //inisialisasi list armada dan list paket
    listArmada La;
    init_listArmada(La);
    listPaket Lp;
    init_listPaket(Lp);

    int pilihan;
    char kembali = 'Y';
    pilihan = selectMenu();
    string kode;
    while (pilihan != 0){
        switch (pilihan){
        case 1:{
            //penginputan armada kedalam list armada
            inputArmada(La);
            break;
        }
        case 2:
            //penginputan paket kedalam list paket dan langsung terhubung ke kode armadanya
            inputPaket(Lp,La);
            break;
        case 3:
            //penghapusan node armada disertai dengan paket yang ada didalamnya
            if(first(La)==nil){
                cout<<"Tidak ada armada pengiriman!!!"<<endl;
                break;
            }
            cout<<"Masukkan kode armada yang ingin dihapus : ";
            cin>>kode;
            if(searchArmada(La,kode)==nil){
                cout<<"Armada dengan kode '"<<kode<<"' tidak ditemukan"<<endl;
            }else{
                deleteArmada(La,Lp,searchArmada(La,kode));
                cout<<"Armada dengan kode '"<<kode<<"' berhasil dihapus..."<<endl;
            }
            break;
        case 4:
            //penghapusan satu paket yang dipilih
            if(first(Lp)==nil){
                cout<<"Tidak ada paket!!!"<<endl;
                break;
            }
            cout<<"Masukkan kode paket yang ingin dihapus : ";
            cin>>kode;
            if(searchPaket(Lp,kode)==nil){
                cout<<"Paket dengan kode '"<<kode<<"' tidak ditemukan"<<endl;
            }else{
                deletePaket(Lp,searchPaket(Lp, kode));
                cout<<"Paket dengan kode '"<<kode<<"' berhasil dihapus..."<<endl;
            }
            break;
        case 5:
            showArmada(La);
            break;
        case 6:
            showPaket(Lp);
            break;
        case 7:
            showArmadadenganPaketnya(La, Lp);
            break;
        }
        cout<<"\n";
        char kembali;
        cout<<"Kembali ke menu utama? (Y/N): ";
        cin>>kembali;
        if (kembali=='N'){
            break;
        }

        pilihan = selectMenu();

    }

    return 0;
}
