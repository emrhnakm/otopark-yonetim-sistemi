#ifndef OTOPARK_H
#define OTOPARK_H

#include <vector>
#include <string>

#include "ParkKaydi.h"
#include "ParkYeri.h"

using namespace std;

class Otopark {
private:
    vector<ParkKaydi> aktifKayitlar;   // Otoparktaki aktif araçlar
    vector<ParkYeri> parkYerleri;      // Otoparktaki park yerleri

public:
    bool VerileriDosyayaKaydet();
    bool VerileriDosyadanYukle();
    // Park yeri ekleme
    void parkYeriEkle(const ParkYeri& p);

    // Araç giriş
    void aracEkle(const ParkKaydi& kayit);

    // Plakaya göre arama
    ParkKaydi* plakaAra(const string& plaka);

    // Araç çıkışı
    void aracCikar(const string& plaka, int cikisSaati);

    // Toplam gelir
    double toplamGelir() const;

    // Araç silme ve ücret
    void aracCikisiYap(std::string plaka, int cikisSaati);

    // Toplam gelir ve araç sayısı raporu
    void gunlukRaporGoster();

    // Kasayı buraya tanımladık
    double toplamGelir = 0; 
};

#endif
