//
// Created by aidah on 12/9/2022.
//

#ifndef BOLNICA_ODJEL_H
#define BOLNICA_ODJEL_H

#include <iostream>
#include <vector>
#include "Krevet.h"

class Odjel {
private:
    char naziv[50];
    static int maxKreveta;
    std::vector<Krevet> kreveti;
public:
    Odjel();
    void setNaziv();
    static void setMaxKreveta();
    void setKreveti();
    char* getNaziv();
    static int getMaxKrevet();
    std::vector<Krevet>& getKreveti();
    void smjestiPacijenta();
    void rezervisiKrevet();
    void oslobodiKrevet(int n);
    friend std::istream& operator>>(std::istream& stream, Odjel& o);
    friend std::ostream& operator<<(std::ostream& stream, Odjel& o);
    void postaviOdjel();
    void ispisKreveta();
    std::string getStatusString(int n);
    ~Odjel()=default;
};


#endif //BOLNICA_ODJEL_H
