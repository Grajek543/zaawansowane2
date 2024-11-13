/// @file main.cpp Plik główny

#include "bst.h"
#include "Wczyt.h"
#include <iostream>

/// @brief Menu z opcjami drzewa
int main(int argc, char const *argv[]) {
    int a = 0;
    int b = 0;
    bst e;
    int r;
    while (b == 0) {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Co chcesz zrobic? \n";
        std::cout << "1 - Dodaj element do drzewa\n2 - Usun element z drzewa\n3 - Usun cale drzewo\n4 - Szukaj drogi do elementu\n5 - Wyswietl drzewo\n6 - Zapisz do pliku\n7 - Wczytaj z pliku\n8 - Zakoncz program \nPodaj operacje: ";
        std::cin >> a;
        switch (a) {
        case 1:
            std::cout << "Podaj element: ";
            std::cin >> r;
            e.dodele(r);
            std::cout << "Udalo sie! \n";
            system("pause");
            break;
        case 2:
            std::cout << "Podaj element: ";
            std::cin >> r;
            e.usunele(r);
            std::cout << "Udalo sie! \n";
            system("pause");
            break;
        case 3:
            e.usubst(e.korzen);
            std::cout << "Udalo sie! \n";
            system("pause");
            break;
        case 4:
            std::cout << "Podaj element: ";
            std::cin >> r;
            e.szuk(r);
            std::cout << "Udalo sie! \n";
            system("pause");
            break;
        case 5:
            int y;
            std::cout << "\nPRE-1, IN-2, POST-3 \nWybierz z ktorej metody ma byc wypisane: ";
            std::cin >> y;
            switch (y) {
            case 1:
                e.wyspre(e.korzen);
                break;
            case 2:
                e.wysin(e.korzen);
                break;
            case 3:
                e.wyspost(e.korzen);
                break;
            default:
                std::cout << "Sprobuj jeszcze raz!";
                break;
            }
            std::cout << "\nUdalo sie! \n";
            system("pause");
            break;
        case 6:
            e.zapisz();
            std::cout << "Udalo sie! \n";
            system("pause");
            break;
        case 7:
            e.wczytaj();
            std::cout << "Udalo sie! \n";
            system("pause");
            break;
        case 8:
            b = 1;
            break;
        default:
            std::cout << "Zla komenda, powtorz\n";
            system("pause");
            break;
        }   
    }
}