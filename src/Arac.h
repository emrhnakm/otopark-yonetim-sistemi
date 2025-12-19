#ifndef ARAC_H
#define ARAC_H

#include <string>

// Temel Araç Sınıfı
class Arac {
protected:
    std::string plaka;
    std::string tur;
public:
    Arac(std::string p, std::string t) : plaka(p), tur(t) {}
    virtual ~Arac() {}

    std::string getPlaka() const { return plaka; }
    std::string getTur() const { return tur; }

    // Polimorfizm için ücret hesaplama fonksiyonu
    virtual double hesaplaUcret(int sure) = 0;
};

// Otomobil Sınıfı
class Otomobil : public Arac {
public:
    Otomobil(std::string p) : Arac(p, "Otomobil") {}
    double hesaplaUcret(int sure) override {
        return sure * 10.0; // Otomobil saatlik 10 TL
    }
};

// Kamyonet Sınıfı
class Kamyonet : public Arac {
public:
    Kamyonet(std::string p) : Arac(p, "Kamyonet") {}
    double hesaplaUcret(int sure) override {
        return sure * 15.0; // Kamyonet saatlik 15 TL
    }
};

#endif