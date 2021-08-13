#include <iostream>
#include<string>

#include "bank.h"
#include "cont.h"




void interfataUtilizator() {
    bank* ItSchoolBank = new bank(); // instantam o banca
    bool isRunning = true;

    do
    {
        system("CLS");
        std::cout << "Welcome to ItSchool Bank\n";
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Meniu principal\n";
        std::cout << std::endl;

        std::cout << "1 -> Adaugare Cont\n";
        std::cout << "2 -> Vizualizare Conturi\n";
        std::cout << "3 -> Modificare Conturi\n";
        std::cout << "9 -> Exit\n";
        std::cout << std::endl;
        std::cout << "Introduceti optiunea: ";
        char optiune;
        std::cin >> optiune;
        switch (optiune)
        {
        case '1':
            system("CLS");
            ItSchoolBank->adaugareCont();
            break;
        case'2':
            system("CLS");
            ItSchoolBank->vizualizareConturi();
            break;
        case '3':
            system("CLS");
            ItSchoolBank->modificareCont();
            break;
        case'9':
            std::cout << "Va multumim!\n";
            isRunning = false;
            system("CLS");
            
            break;
        default:
            std::cout << "Optiunea nu este valida.\n";
            break;
        }

    } while (isRunning);



    delete ItSchoolBank;
}
/*
void parolaId()
{
    bool merge = true;
    do
    {
        system("CLS");

        std::string parola = "banca1";
        std::string user = "Marcel";
        int numarIncercari = { 3 };
        for (int i = numarIncercari; i >= 0; i--)
        {

            std::cout << "Introduceti datele de acces: \n";

            std::cout << "User id ";
            std::string userId;
            std::getline(std::cin, userId);
            std::cout << "Parola ";
            std::string par;
            std::getline(std::cin, par);
            if (userId == user && par == parola) {
                system("CLS");

                interfataUtilizator();

            }

            else {
                system("CLS");
                std::cout << "Date de acces incorecte!\n";
                std::cout << std::endl;
                std::cout << "Incercari ramase: " << i << std::endl;
                if (i == 0) {
                    std::cout << "User Id sau parola gresita! Va rugam contactati administratorul.\n";
                    std::exit(0);
                }
            }
        }
    } while (merge);

}

*/


