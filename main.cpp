#include <iostream>
#include <memory>
#include "Odjel.h"


int main() {
    Odjel o;
    std::cin>>o;
    int izbor;
    do {
        system("cls");
        std::cout<<"Odjel: " << o.getNaziv() << "\n";
        std::cout<<"\t1. Ispis odjela \n";
        std::cout<<"\t2. Prijava pacijenta\n";
        std::cout<<"\t3. Rezervacija\n";
        std::cout<<"\t4. Oslobodi krevet\n";
        std::cout<<"\t5. K R A J\n";
        std::cout<<"\t\t Izbor: ";
        std::cin>>izbor;
        std::cin.ignore();
        switch (izbor) {
            case 1:
            system("cls");
            std::cout<<o;
                system("pause");
                break;
            case 2:
                system("cls");
                o.smjestiPacijenta();
                system("pause");
                break;
            case 3:
                system("cls");
                o.rezervisiKrevet();
                system("pause");
                break;
            case 4:
                system("cls");
                std::cout<<o;
                auto n=std::make_shared<int>();
                std::cout<<"Unesite broj kreveta za odjavu: ";
                std::cin>>*n;
                std::cin.ignore();
                system("pause");
                break;

        }
    } while(izbor!=5);
}
