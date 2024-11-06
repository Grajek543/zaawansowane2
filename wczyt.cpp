#include "bst.h"
#include "Wczyt.h"
#include <fstream>
#include <iostream>
#include <string>


dopliku::dopliku(bst a) : drzewo(a) {
    
    
}
void dopliku::zapisz(bst a) {
    PRE.open("PRE.txt", std::ios::out | std::ios::trunc); // Open file once here
    if (!PRE.is_open()) {
        std::cout << "Nie ma dost�pu do pliku PRE.txt" << std::endl;
        return;
    }
    zapiszpre(drzewo.korzen);
    PRE.close(); // Close file after traversal is complete

    IN.open("IN.txt", std::ios::out | std::ios::trunc); // Open file once here
    if (!IN.is_open()) {
        std::cout << "Nie ma dost�pu do pliku IN.txt" << std::endl;
        return;
    }
    zapiszin(drzewo.korzen);
    IN.close(); // Close file after traversal is complete
    POST.open("POST.txt", std::ios::out | std::ios::trunc); // Open file once here
    if (!POST.is_open()) {
        std::cout << "Nie ma dost�pu do pliku POST.txt" << std::endl;
        return;
    }
    zapiszpost(drzewo.korzen);
    POST.close(); // 
}


void dopliku::zapiszpre(wezel* b) { 
    if (b) {
        PRE << " " << b->war;       
        zapiszpre(b->lewy);         
        zapiszpre(b->prawy);        
    }
}

void dopliku::zapiszin(wezel* a) {
    if (a) {
        zapiszin(a->lewy);
        IN << " " << a->war;
        zapiszin(a->prawy);
    }
}

void dopliku::zapiszpost(wezel* a) {
    if (a) {
        zapiszpost(a->lewy);
        zapiszpost(a->prawy);
        POST << " " << a->war;
    }
}

void dopliku::wczytaj() {
    std::cout << "\n PRE-1, IN-2, POST-3 \n wybierz z ktorej metody ma byc wczytane:";
    int x;
    std::cin >> x;
    if (x == 1) {
        PRE.open("PRE.txt", std::ios::in); // Open file once here
        if (!PRE.is_open()) {
            std::cout << "Nie ma dostępu do pliku PRE.txt" << std::endl;
            return;
        }
        wczytajpre(drzewo.korzen);
        PRE.close(); // Close file after traversal is complete
    }
    else if (x == 2) {
        IN.open("IN.txt", std::ios::in); // Open file once here
        if (!IN.is_open()) {
            std::cout << "Nie ma dostępu do pliku IN.txt" << std::endl;
            return;
        }
        wczytajin(drzewo.korzen);
        IN.close(); // Close file after traversal is complete
    }
    else if (x == 3) {
        POST.open("POST.txt", std::ios::in); // Open file once here
        if (!POST.is_open()) {
            std::cout << "Nie ma dostępu do pliku POST.txt" << std::endl;
            return;
        }
        wczytajpost(drzewo.korzen);
        POST.close(); // Close file after traversal is complete
    }
    else {
        std::cout << "Wprowadzony zly znak, wprowadz jeszcze raz";
        wczytaj();
    }
}

bst dopliku::rdrzewo() {
    return drzewo;
}

void dopliku::wczytajpre(wezel* a) {
    wezel* b = new wezel;
    wezel* c = a;
    b->lewy = NULL;
    b->prawy = NULL;
    int d;
    PRE >> d;
    b->war = d;
    if (!c) a = b;
    else
        while (true)
            if (b->war < c->war) {
                if (!c->lewy) {
                    c->lewy = b;
                    break;
                }
                else c = c->lewy;
            }
            else {
                if (!c->prawy) {
                    c->prawy = b;
                    break;
                }
                else c = c->prawy;
            }
    b->pop = c;
    if (!PRE.eof()) {
        wczytajpre(a);
    }
}

void dopliku::wczytajin(wezel* a) {
    wezel* b = new wezel;
    wezel* c = a;
    b->lewy = NULL;
    b->prawy = NULL;
    int d;
    IN >> d;
    b->war = d;
    if (!c) a = b;
    else
        while (true)
            if (b->war < c->war) {
                if (!c->lewy) {
                    c->lewy = b;
                    break;
                }
                else c = c->lewy;
            }
            else {
                if (!c->prawy) {
                    c->prawy = b;
                    break;
                }
                else c = c->prawy;
            }
    b->pop = c;
    if (!IN.eof()) {
        wczytajin(a);
    }
}

void dopliku::wczytajpost(wezel* a) {
    wezel* b = new wezel;
    wezel* c = a;
    b->lewy = NULL;
    b->prawy = NULL;
    int d;
    POST >> d;
    b->war = d;
    if (!c) a = b;
    else
        while (true)
            if (b->war < c->war) {
                if (!c->lewy) {
                    c->lewy = b;
                    break;
                }
                else c = c->lewy;
            }
            else {
                if (!c->prawy) {
                    c->prawy = b;
                    break;
                }
                else c = c->prawy;
            }
    b->pop = c;
    if (!POST.eof()) {
        wczytajpost(a);
    }
}
