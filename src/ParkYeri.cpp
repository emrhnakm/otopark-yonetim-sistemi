#include "ParkYeri.h"

ParkYeri::ParkYeri(int _id, std::string _konum)
    : id(_id), konum(_konum), doluMu(false) {}

int ParkYeri::getId() const {
    return id;
}

std::string ParkYeri::getKonum() const {
    return konum;
}

bool ParkYeri::isDolu() const {
    return doluMu;
}

void ParkYeri::setDolu(bool durum) {
    doluMu = durum;
}

