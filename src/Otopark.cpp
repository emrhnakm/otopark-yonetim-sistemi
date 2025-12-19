#include "Otopark.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

// Yeni park yeri ekler
void Otopark::parkYeriEkle(const ParkYeri& p) {
    parkYerleri.push_back(p);
}

// Yeni araç kaydı ekler
void Otopark::aracEkle(const ParkKaydi& kayit) {
    aktifKayitlar.push_back(kayit);
}

// Plakaya göre araç arar
ParkKaydi* Otopark::plakaAra(const std::string& plaka) {
    for (int i = 0; i < aktifKayitlar.size(); i++) {
        if (aktifKayitlar[i].getArac()->getPlaka() == plaka) {
            return &aktifKayitlar[i];
        }
    }
    throw std::runtime_error("Plaka bulunamadi!");
}

// Araç çıkışı yapar
void Otopark::aracCikar(const std::string& plaka, int cikisSaati) {
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
bool Otopark::VerileriDosyayaKaydet() {
    std::ofstream dosya("kayitlar.txt");

    if (!dosya.is_open()) {
        std::cerr << "Hata: Kayit dosyasi acilamadi!" << std::endl;
        return false;
    }

    // Aktif kayıtları tek tek dosyaya yazıyoruz
    for (const auto& kayit : aktifKayitlar) {
        dosya << kayit.getPlaka() << ","
              << kayit.getAracTuru() << ","
              << kayit.getGirisSaati() << ","
              << kayit.getUcret() << "\n";
    }

    dosya.close();
    return true;
}

bool Otopark::VerileriDosyadanYukle() {
    std::ifstream dosya("kayitlar.txt");

    if (!dosya.is_open()) {
        return false;
    }

    std::string satir;
    while (std::getline(dosya, satir)) {
        if (satir.empty()) continue;

        std::stringstream ss(satir);
        std::string plaka, tur, zamanStr, ucretStr;

        std::getline(ss, plaka, ',');
        std::getline(ss, tur, ',');
        std::getline(ss, zamanStr, ',');
        std::getline(ss, ucretStr, ',');

        // String olan zamanı tam sayıya (int) çevir
        int gSaati = std::stoi(zamanStr);

        Arac* yeniArac = nullptr;

        // Polimorfizm: Araç türüne göre nesne oluştur
        if (tur == "Otomobil") {
            yeniArac = new Otomobil(plaka);
        } else if (tur == "Kamyonet") {
            yeniArac = new Kamyonet(plaka);
        }

        if (yeniArac) {
            ParkKaydi yuklenenKayit(yeniArac, nullptr, gSaati);
            aktifKayitlar.push_back(yuklenenKayit);
        }
    }

    dosya.close();
    return true;
}
