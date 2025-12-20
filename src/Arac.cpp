#include "Arac.h"

//Temel sınıf
Arac::Arac(const std::string& plaka) : plaka(plaka){}
Arac::~Arac() {}

const std::string& Arac::getPlaka() const {
    return plaka;
}

//Türemiş sınıf (Otomobil)

Otomobil::Otomobil(const std::string& plaka) : Arac(plaka){}

double Otomobil::hesaplaUcret(int sure) const {
    if (sure < 1) sure = 1;// sure 1 saatten daha az ise 1 saatlik ücret al
    return sure * 50; // Saatlik 50 TL
}

std::string Otomobil::getTur() const {
    return "Otomobil";
}

//Türemiş sınıf (Kamyonet) 

Kamyonet::Kamyonet(const std::string& plaka) : Arac(plaka){}

        
double Kamyonet::hesaplaUcret(int sure) const {
    if (sure < 1) sure = 1;
    return sure * 70; //Saatlik 70 TL
}
std::string Kamyonet::getTur() const {
    return "Kamyonet";
}  
