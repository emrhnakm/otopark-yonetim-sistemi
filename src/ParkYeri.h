#ifndef PARKYERI_H
#define PARKYERI_H

#include <string>

class ParkYeri {
private:
    int id;
    std::string konum;
    bool doluMu;

public:
    ParkYeri(int _id, std::string _konum);

    int getId() const;
    std::string getKonum() const;
    bool isDolu() const;
    void setDolu(bool durum);
};

#endif
