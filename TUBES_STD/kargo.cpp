#include "kargo.h"

void init_listArmada(listArmada &L){first(L)=nil;};
void init_listPaket(listPaket &L){first(L)=nil;};
adrArmada createNodeArmada(infotypeArmada x){
    adrArmada p;
    p = new NodeArmada;
    info(p) = x;
    next(p) = nil;
};
adrPaket createNodePaket(infotypePaket x){
    adrPaket p;
    p = new NodePaket;
    info(p) = x;
    next(p) = nil;
    pengiriman(p) = nil;
};
void insertLastArmada(listArmada &L, adrArmada p){
    adrArmada q;
    if(first(L)==nil){
        first(L) = p;
    }else{
        q = first(L);
        while(next(q)!=nil){
            q = next(q);
        }
        next(q) = p;
    }
};
void insertLastPaket(listPaket &L, adrPaket p){
    adrPaket q;
    if(first(L)==nil){
        first(L) = p;
    }else{
        q = first(L);
        while(next(q)!=nil){
            q = next(q);
        }
        next(q) = p;
    }
};
adrArmada searchArmada(listArmada L, string kode){
    adrArmada q = first(L);
    while (q != nil){
        if(info(q).kodeArmada == kode){
            return q;
        }
        q = next(q);
    }
    return nil;
};
adrPaket searchPaket(listPaket L, string kode){
    adrPaket q = first(L);
    while(q != nil){
        if(info(q).kodePaket == kode){
            return q;
        }
        q = next(q);
    }
    return nil;
};
void showArmada(listArmada L){
    adrArmada q;
    cout<<"=================Armada================="<<endl;
    if (first(L) == nil){
        cout<<"Tidak ada armada!"<<endl;
    }else{
        q = first(L);
        int i = 1;
        while(q != nil){
            cout<<"-->Armada "<<i<<endl;
            cout<<"Kode: "<<info(q).kodeArmada<<endl;
            cout<<"Nama: "<<info(q).namaArmada<<endl;
            cout<<"Kapasitas: "<<info(q).kapasitas<<endl;
            cout<<"Muatan: "<<info(q).muatan<<endl;
            q = next(q);
            i = i+1;
        }
    }
    cout<<"========================================"<<endl;
};
void showPaket(listPaket L){
    adrPaket q;
    cout<<"=================Paket================="<<endl;
    if (first(L) == nil){
        cout<<"Tidak ada paket!"<<endl;
    }else{
        q = first(L);
        int i = 1;
        while(q != nil){
            cout<<"-->Paket "<<i<<endl;
            cout<<"Kode: "<<info(q).kodePaket<<endl;
            cout<<"Nama penerima: "<<info(q).namaPenerima<<endl;
            cout<<"Alamat penerima: "<<info(q).alamatPenerima<<endl;
            cout<<"Berat: "<<info(q).berat<<endl;
            cout<<"Kode armada: "<<info(q).kodeArmada<<endl;
            q = next(q);
            i = i+1;
        }
    }
    cout<<"======================================="<<endl;
};
void relationPaketdenganArmadanya(adrPaket p, listArmada La,listPaket &Lp){
    adrArmada q;
    q = searchArmada(La, info(p).kodeArmada);
    char pilihan;
    if(q == nil){
        cout<<"Armada paket anda tidak ditemukan!"<<endl;
        cout<<"urungkan kirim paket ini? (Y/N):";
        cin>>pilihan;
    }else if(info(q).muatan+info(p).berat>info(q).kapasitas){   //Jika kapasitas pada armada sudah penuh untuk menambah paket
        cout<<"Armada '"<<info(q).namaArmada<<"' dengan kode '"<<info(q).kodeArmada<<"' sudah penuh!"<<endl;
        cout<<"Urungkan kirim paket ini? (Y/N):";
        cin>>pilihan;
    }else{
        pengiriman(p) = q;
        info(q).muatan = info(q).muatan + info(p).berat; //menambahkan berat paket pada muatan armada
    }
    if (pilihan=='Y'){
        deletePaket(Lp,p);  //jika dipilih urungkan paket maka node yang akan ditambahkan akan dihapus
    }
};
void deletePaket(listPaket &Lp, adrPaket p){
    adrPaket k;
    if(p==nil){
        cout<<"Kode paket tidak ditemukan"<<endl;
    }else if(next(p)==nil and p==first(Lp)){ //jika terdapat hanya 1 paket
        first(Lp) = nil;
        delete(p);
    }else{
        k = first(Lp);
        while(next(k)!=p){
            k = next(k);
        }
        next(k) = next(p);
        next(p) = nil;
        delete(p);
    }
}
void deleteArmada(listArmada &La, listPaket &Lp, adrArmada p){
    adrArmada qa;
    adrPaket qp;
    if(p==nil){
        cout<<"Kode armada tidak ditemukan!"<<endl;
    }else if(first(La)==p and next(p)==nil){ //jika terdapat hanya 1 armada
        qp = first(Lp);
        while(qp!=nil){
            if(pengiriman(qp)==p){
                deletePaket(Lp,qp);
            }
            qp = next(qp);
        }
        first(La) = nil;
        delete(p);
    }else{
        //menghapus setiap paket yang ada pada armada yang ingin dihapus
        qp = first(Lp);
        while(qp!=nil){
            if(pengiriman(qp)==p){
                deletePaket(Lp,qp);
            }
            qp = next(qp);
        }
        //menghapus armadanya
        qa = first(La);
        while(next(qa)!=p){
            qa = next(qa);
        }
        next(qa) = next(p);
        next(p) = nil;
        delete(p);
    }
}


int countArmada(listArmada L){
    int i = 0;
    adrArmada p = first(L);
    while(p!=nil){
        i = i+1;
        p = next(p);
    }
    return i;
};
int countPaket(listPaket L){
    int i = 0;
    adrPaket p = first(L);
    while(p!=nil){
        i = i+1;
        p = next(p);
    }
    return i;
};
void showArmadadenganPaketnya(listArmada La, listPaket Lp){
    cout<<"=================Armada dengan paketnya================="<<endl;
    adrArmada A = first(La);
    adrPaket p;
    int i = 1;
    while (A!=nil){
        cout<<"-->Paket yang dibawa armada '"<<info(A).namaArmada<<"':"<<endl;
        p = first(Lp);
        while(p!=nil){
            if(pengiriman(p)==A){
                cout<<"-Paket "<<i<<endl;
                cout<<"Kode paket : "<<info(p).kodePaket<<endl;
                cout<<"Penerima : "<<info(p).namaPenerima<<endl;
                cout<<"Alamat : "<<info(p).alamatPenerima<<endl;
                i=i+1;
            }
            p = next(p);
        }
        i = 1;
        A = next(A);
    }
    cout<<"========================================================"<<endl;
};
void inputArmada(listArmada &La){
    infotypeArmada x;
    int n;
    cout<<"Masukkan jumlah armada yang ingin ditambah :";
    cin>>n;
    cout<<"==========INPUT ARMADA=========="<<endl;
    for(int i=0;i<n;i++){
        cout<<"-->Armada "<<i+1<<endl;
        cout<<"Kode armada : ";
        cin>>x.kodeArmada;
        cout<<"Nama armada : ";
        cin>>x.namaArmada;
        cout<<"Kapasitas(Kg) : ";
        cin>>x.kapasitas;
        cout<<"Muatan awal(Kg) : ";
        cin>>x.muatan;
        insertLastArmada(La, createNodeArmada(x));
    }
};
void inputPaket(listPaket &Lp, listArmada La){
    infotypePaket y;
    char m='Y';
    int i = 1;
    while(m=='Y'){
        cout<<"-->Paket "<<i<<endl;
        cout<<"Kode paket : ";
        cin>>y.kodePaket;
        cout<<"Kode armada : ";
        cin>>y.kodeArmada;
        cout<<"Nama penerima : ";
        cin>>y.namaPenerima;
        cout<<"Alamat penerima : ";
        cin>>y.alamatPenerima;
        cout<<"Berat(Kg) : ";
        cin>>y.berat;
        insertLastPaket(Lp,createNodePaket(y));
        relationPaketdenganArmadanya(searchPaket(Lp,y.kodePaket),La,Lp);  //setiap input paket langsung terhubung dengan armadanya
        cout<<"Apakah anda mau mengirim paket lagi? (Y/N) ";
        cin>>m;
        i = i+1;
    }
}
int selectMenu(){
    cout<<endl;
    cout<<"==========MENU=========="<<endl;
    cout<<"1.Menambah armada"<<endl;
    cout<<"2.Menambah paket"<<endl;
    cout<<"3.Menghapus armada"<<endl;
    cout<<"4.Menghapus paket"<<endl;
    cout<<"5.Menampilkan semua armada"<<endl;
    cout<<"6.Menampilkan semua paket"<<endl;
    cout<<"7.Menampilkan setiap armada dengan paketnya"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"Pilihan menu: ";

    int input = 0;
    cin >> input;
    return input;
}

