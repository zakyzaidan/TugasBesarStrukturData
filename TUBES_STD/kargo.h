#ifndef KARGO_H_INCLUDED
#define KARGO_H_INCLUDED
#include <iostream>
using namespace std;
#define first(l) (l).first
#define info(p) (p)->info
#define next(p) (p)->next
#define pengiriman(p) (p)->pengiriman
#define nil NULL

typedef struct armada infotypeArmada;
typedef struct paket infotypePaket;
typedef struct NodePaket *adrPaket;
typedef struct NodeArmada *adrArmada;
struct armada{
    string kodeArmada;
    string namaArmada;
    int kapasitas;  //kapasitas berisi maksimal berat yang bisa dibawa armada
    int muatan;  //muatan berisi berat paket-paket yang dibawa saat ini
};
struct paket{
    string kodePaket;
    string namaPenerima;
    string kodeArmada;
    string alamatPenerima;
    int berat;  //berat berisi berat paket yang nanti akan menambah muatan pada armada yang dipilih
};
struct NodeArmada{
    adrArmada next;
    infotypeArmada info;
};
struct NodePaket{
    adrArmada pengiriman;
    infotypePaket info;
    adrPaket next;
};
struct listArmada{
    adrArmada first;
};
struct listPaket{
    adrPaket first;
};

void init_listArmada(listArmada &L);
void init_listPaket(listPaket &L);
adrArmada createNodeArmada(infotypeArmada x);
adrPaket createNodePaket(infotypePaket x);
void insertLastArmada(listArmada &L, adrArmada p);
void insertLastPaket(listPaket &L, adrPaket p);
adrArmada searchArmada(listArmada L, string kode);
adrPaket searchPaket(listPaket L, string kode);
void showArmada(listArmada L);
void showPaket(listPaket L);
void relationPaketdenganArmadanya(adrPaket p, listArmada La, listPaket &Lp);
void deletePaket(listPaket &Lp, adrPaket p);
void deleteArmada(listArmada &La, listPaket &Lp, adrArmada p);
int countArmada(listArmada L);
int countPaket(listPaket L);
void showArmadadenganPaketnya(listArmada L, listPaket K);
void inputArmada(listArmada &La);
void inputPaket(listPaket &Lp, listArmada La);
int selectMenu();





#endif // KARGO_H_INCLUDED
