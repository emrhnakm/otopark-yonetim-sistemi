#include <iostream>
#include <string>
#include "Otopark.h"
#include "Arac.h"

using namespace std;

int main() {
    Otopark otopark;

    // Program açılırken eski verileri dosyadan yükler
    otopark.VerileriDosyadanYukle();

    cout << " OTOPARK YONETIM SISTEMI " << endl;
    cout << "1. Yeni Arac Girisi (Otomobil)" << endl;
    cout << "2. Plaka ile Arac Sorgula" << endl;
    cout << "0. Programı Kapat ve Kaydet" << endl;
    cout << "===================================" << endl;

    int secim = -1;
    while (secim != 0) {
        cout << "\nSeciminiz: ";
        cin >> secim;

        if (secim == 1) {
            string plaka;
            cout << "Plaka girin: ";
            cin >> plaka;

            // Yeni bir araç oluşturup otoparka ekliyoruz
            Arac* yeni = new Otomobil(plaka);
            ParkKaydi yeniKayit(yeni, nullptr, 8); // Saat 8'de girmiş gibi varsayalım
            otopark.aracEkle(yeniKayit);
            cout << "Arac sisteme kaydedildi." << endl;

        } else if (secim == 2) {
            string plaka;
            cout << "Aranacak Plaka: ";
            cin >> plaka;

            // try-catch burada test edilir.
            try {
                otopark.plakaAra(plaka);
                cout << "SONUC: Arac otoparkta bulunuyor." << endl;
            } catch (const exception& e) {
                cout << "HATA: " << e.what() << endl;
            }
        }
    }

    // Program kapanırken her şeyi dosyaya kaydeder
    if (otopark.VerileriDosyayaKaydet()) {
        cout << "Kayitlar 'kayitlar.txt' dosyasina yedeklendi." << endl;
    }

    return 0;
}