#ifndef ARAC_H
#define ARAC_H

#include <string>

class Arac {
protected:
    std::string plaka;
public:
    Arac(const std::string& plaka); 
    virtual ~Arac();

    const std::string& getPlaka() const;

    virtual double hesaplaUcret(int sure) const = 0;
    virtual std::string getTur() const = 0;
};

class Otomobil : public Arac {
public:
    Otomobil(const std::string& plaka);
    double hesaplaUcret(int sure) const override;
    std::string getTur() const override;
};

class Kamyonet : public Arac {
public:
    Kamyonet(const std::string& plaka);
    double hesaplaUcret(int sure) const override;
    std::string getTur() const override;
};

#endif
