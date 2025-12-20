#ifndef ARAC_H
#define ARAC_H

#include <string>

// Temel Araç Sınıfı
class Arac {
protected:
    std::string plaka;
public:
    Arac(const std::string& plaka);
    virtual ~Arac();

    const std::string& getPlaka() const;

    // Polimorfizm kullanılan fonksiyonlar
    virtual double hesaplaUcret(int sure) const = 0;
    virtual std::string getTur() const = 0; // = 0 ile temel sınıftan nesne oluşumu engellenir
};

//Türemiş sınıf(Otomobil)
class Otomobil : public Arac {
    public:
        Otomobil(const std::string& plaka);
        
        double hesaplaUcret(int sure) const override;
        std::string getTur() const override;
};

//Türemiş sınıf (Kamyonet)
class Kamyonet : public Arac {
    public:
        Kamyonet(const std::string& plaka);
        
        double hesaplaUcret(int sure) const override;
        std::string getTur() const override;
};

#endif
