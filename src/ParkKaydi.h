#ifndef PARKKAYDI_H
#define PARKKAYDI_H

#include "Arac.h"
#include "ParkYeri.h"
#include <string>
#include <ctime>

class ParkKaydi {
private:
    Arac* arac;        // Arac nesnesi
    ParkYeri* parkYeri;
    int girisSaati;
    int cikisSaati;
    double ucret;

public:
    // Kayıt: Girişte oluşur
    ParkKaydi(Arac* a, ParkYeri* p, int giris);

    ~ParkKaydi();

    // İşlemler
    void cikisYap(int cikis); // Çıkış saatini alır, ücreti hesaplar

    // Bilgi Getirme
    Arac* getArac() const;
    ParkYeri* getParkYeri() const;
    double getUcret() const;
    int getGirisSaati() const;
    int getCikisSaati() const;

    std::string getPlaka() const { return arac->getPlaka(); }
    std::string getAracTuru() const { return arac->getTur(); }
};

#endif