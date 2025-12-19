#ifndef PARKYERI_H
#define PARKYERI_H

#include <string>

class ParkYeri {
private:
    int id;
    std::string konum; // Örn: "Kat 1, A-5"
    bool doluMu;

public:
    ParkYeri(int _id, std::string _konum)
        : id(_id), konum(_konum), doluMu(false) {}

    int getId() const { return id; }
    std::string getKonum() const { return konum; }
    bool isDolu() const { return doluMu; }

    void setDolu(bool durum) { doluMu = durum; }
};

#endif