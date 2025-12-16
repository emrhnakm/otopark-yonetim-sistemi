#include "Otopark.h"

// Yeni park yeri ekler
void Otopark::parkYeriEkle(const ParkYeri& p) {
    parkYerleri.push_back(p);
}

// Yeni araç kaydı ekler
void Otopark::aracEkle(const ParkKaydi& kayit) {
    aktifKayitlar.push_back(kayit);
}

// Plakaya göre araç arar
ParkKaydi* Otopark::plakaAra(const string& plaka) {
    for (int i = 0; i < aktifKayitlar.size(); i++) {
        if (aktifKayitlar[i].getArac()->getPlaka() == plaka) {
            return &aktifKayitlar[i];
        }
    }
    return nullptr;
}

// Araç çıkışı yapar
void Otopark::aracCikar(const string& plaka, int cikisSaati) {
    for (int i = 0; i < aktifKayitlar.size(); i++) {
        if (aktifKayitlar[i].getArac()->getPlaka() == plaka) {
            aktifKayitlar[i].cikisYap(cikisSaati);
            aktifKayitlar.erase(aktifKayitlar.begin() + i);
            break;
        }
    }
}

// Toplam geliri hesaplar
double Otopark::toplamGelir() const {
    double toplam = 0.0;
    for (int i = 0; i < aktifKayitlar.size(); i++) {
        toplam += aktifKayitlar[i].getUcret();
    }
    return toplam;
}
