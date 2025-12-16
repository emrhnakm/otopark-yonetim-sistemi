#include "ParkKaydi.h"
#include <iostream>

// Girişte kayıt oluşturur.
ParkKaydi::ParkKaydi(Arac* a, ParkYeri* p, int giris)
    : arac(a), parkYeri(p), girisSaati(giris), cikisSaati(-1), ucret(0.0)
{
}

ParkKaydi::~ParkKaydi() {
}

// Araç çıkışı
void ParkKaydi::cikisYap(int cikis) {
    cikisSaati = cikis;
    int sure = cikisSaati - girisSaati;

    if (sure < 0)
        sure = 0;

    // Ücret hesaplama
    ucret = arac->hesaplaUcret(sure);
}

Arac* ParkKaydi::getArac() const {
    return arac;
}

ParkYeri* ParkKaydi::getParkYeri() const {
    return parkYeri;
}

double ParkKaydi::getUcret() const {
    return ucret;
}

int ParkKaydi::getGirisSaati() const {
    return girisSaati;
}

int ParkKaydi::getCikisSaati() const {
    return cikisSaati;
}
