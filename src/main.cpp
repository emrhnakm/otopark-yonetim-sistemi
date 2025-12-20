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
    cout << "3. Arac Cikisi ve Ucret Hesabi" << endl;
    cout << "4. Gunluk Rapor" << endl;
    cout << "0. Programı Kapat ve Kaydet" << endl;
    cout << "===================================" << endl;
    
    string plaka;
    int secim = -1;
    while (secim != 0) {
        cout << "\nSeciminiz: ";
        cin >> secim;

        if (secim == 1) {
            cout << "Plaka giriniz: " << endl;
            cin >> plaka;
            
            int turSecim;
            cout <<"Aracın türünü giriniz: \n 1-Otomobil \n 2-Kamyonet \n 0- Menüye Dön " << endl; //Aracın türünü alıyoruz
            cin >> turSecim;
            
            Arac* yeni = nullptr; // Araç türü için polimorfizm 
            
            // Türe göre yeni bir araç oluşturup otoparka ekliyoruz
            while(true) {
            if(turSecim == 1) {
                yeni = new Otomobil(plaka);
                ParkKaydi yeniKayit(yeni, nullptr, 8); // Saat 8'de girmiş gibi varsayalım
                otopark.aracEkle(yeniKayit);
                cout << "Arac sisteme kaydedildi." << endl;
                break;
            } else if (turSecim == 2) {
                yeni = new Kamyonet(plaka);
                ParkKaydi yeniKayit(yeni, nullptr, 8);
                otopark.aracEkle(yeniKayit);
                cout << "Arac sisteme kaydedildi." << endl;
                break;
            } else {
                cout << "Geçerli bir numara giriniz." << endl;
                break;
            }
            }

        } else if (secim == 2) {
            cout << "Aranacak Plaka: ";
            cin >> plaka;

            // try-catch burada test edilir.
            try {
                otopark.plakaAra(plaka);
                cout << "SONUC: Arac otoparkta bulunuyor." << endl;
            } catch (const exception& e) {
                cout << "HATA: " << e.what() << endl;
            }
        } else if (secim == 3) {
        int cSaati;
        cout << "Cikis yapacak plaka: ";
        cin >> plaka;
        cout << "Cikis saati: ";
        cin >> cSaati;
        otopark.aracCikar(plaka, cSaati);

    } else if (secim == 4) {
        otopark.gunlukRaporGoster();
    }
    }        

    // Program kapanırken her şeyi dosyaya kaydeder
    if (otopark.VerileriDosyayaKaydet()) {
        cout << "Kayitlar 'kayitlar.txt' dosyasina yedeklendi." << endl;
    }

    return 0;
}
