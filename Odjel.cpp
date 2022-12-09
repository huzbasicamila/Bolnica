//
// Created by aidah on 12/9/2022.
//

#include "Odjel.h"
#include <cstring>
#include <memory>

int Odjel::maxKreveta=0;

Odjel::Odjel() {
    strcpy(this->naziv, "Novi odjel");
}

void Odjel::setNaziv() {
    std::cout<<"Unesite naziv odjela:  ";
    std::cin.getline(this->naziv,50);
}

void Odjel::setMaxKreveta() {
    std::cout<<"Unesite broj kreveta na odjelu: ";
    std::cin>>Odjel::maxKreveta;
    std::cin.ignore();
}

void Odjel::setKreveti() {
    auto temp= std::make_shared<Krevet>();
    for(int i=0; i<Odjel::getMaxKrevet();i++){
        temp->setBroj(i);
        temp->setStatus(slobodno);
        this->kreveti.push_back(*temp);
    }

}

char *Odjel::getNaziv() {
    return this->naziv;
}

int Odjel::getMaxKrevet() {
    return  Odjel::maxKreveta;
}

std::vector<Krevet> &Odjel::getKreveti() {
    return this->kreveti;
}

void Odjel::smjestiPacijenta() {
    auto smjesten=std::make_shared<bool>(false);
    try {
        for(auto i: this->kreveti) {
            if(i.getStatus()==slobodno) {
                i.setStatus(zauzeto);
                std::cout << "Pacijent je uspjesno smjesten. \n";
                return;
            }
        }
        throw "Svi kreveti su zauzeti \n";
    }
    catch(const char* Greska) {
        std::cout<<"[G R E S K A]" <<Greska <<std::endl;
    }
    catch (...) {
        std::cout<<"[G R E S K A] Nepoznata greska!" << std::endl;
    }
}

void Odjel::rezervisiKrevet() {
    auto smjesten=std::make_shared<bool>(false);
    try {
        for(auto i: this->kreveti) {
            if(i.getStatus()==slobodno) {
                i.setStatus(rezervisano);
                std::cout << "Krevet je uspjesno rezervisan. \n";
                return;
            }
        }
        throw "Svi kreveti su zauzeti \n";
    }
    catch(const char* Greska) {
        std::cout<<"[G R E S K A]" <<Greska <<std::endl;
    }
    catch (...) {
        std::cout<<"[G R E S K A] Nepoznata greska!" << std::endl;
    }
}

void Odjel::oslobodiKrevet(int n) {
    try {
        if(n>Odjel::getMaxKrevet()||n<0) {
            throw n;
        } else if(this->kreveti[n].getStatus()==slobodno){
            throw "Taj krevet je vec slobodan\n";
        } else if(this->kreveti[n].getStatus()==rezervisano){
            throw "Taj krevet je rezervisan!\n";
        } else {
            this->kreveti[n].setStatus(slobodno);
            std::cout<<"Krevet " << n << " je sada slobodan";
        }
    }
    catch (int n) {
        std::cout<<"[G R E S K A ] Ne postoji krevet sa tim brojem: "
        << n <<"!\n";
    }
    catch (const char* Greska) {
        std::cout<<"[G R E S K A]" << Greska << std::endl;
    }
    catch (...) {
        std::cout<<"[G R E S K A] Nepoznata greska!" << std::endl;
    }
}

std::istream &operator>>(std::istream &stream, Odjel &o) {
    o.setNaziv();
    o.setMaxKreveta();
    o.setKreveti();
    return stream;
}

std::ostream &operator<<(std::ostream &stream, Odjel &o) {
   stream<<"Odjel: " << o.getNaziv() << "\n";
   stream<<"Broj\t\tStatus\n";
   stream<<"kreveta\t\tkreveta\n";
   stream<<"--------------------------------------------\n";
   for (auto i:o.kreveti) {
       stream<< i.getBroj()+1 << "\t\t"<< o.getStatusString(i.getBroj())
       <<std::endl;
   }
}

void Odjel::postaviOdjel() {

}

std::string Odjel::getStatusString(int n) {
    switch (this->kreveti[n].getStatus()) {
        case slobodno:
            return "Slobodan";
        case zauzeto:
            return "Zauzet";
        case rezervisano:
            return "Rezervisan";
        default:
            return "Greska";
    }
}
