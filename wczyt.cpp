#include "bst.h"
#include "Wczyt.h"
#include <fstream>
#include <iostream>
#include <string>


dopliku::dopliku(wezel *a) : drzewo(a) {}

void dopliku::zapisz(){
    PRE.open("PRE.txt", std::ios::out | std::ios::trunc);
    if (!PRE.is_open()) {
        std::cout << "Nie ma dostepu do pliku PRE.txt" << std::endl;
        return;
    }
    zapiszpre(drzewo);
    PRE.close();

    IN.open("IN.txt", std::ios::out | std::ios::trunc);
    if (!IN.is_open()) {
        std::cout << "Nie ma dostepu do pliku IN.txt" << std::endl;
        return;
    }
    zapiszin(drzewo);
    IN.close();

    POST.open("POST.txt", std::ios::out | std::ios::trunc);
    if (!POST.is_open()) {
        std::cout << "Nie ma dostepu do pliku POST.txt" << std::endl;
        return;
    }
    zapiszpost(drzewo);
    POST.close();
}

void dopliku::wczytajpre(wezel* a) {
    wezel* b = new wezel;
    wezel* c = drzewo;
    b->lewy = NULL;
    b->prawy = NULL;
    int t;
    PRE >> t;
    b->war = bintoint(t);
    if (!c) drzewo = b;
    else {
        while (true) {
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
        }
    }
    b->pop = c;
    if (!PRE.eof()) {
        wczytajpre(a);
    }
}

void dopliku::wczytajin(wezel* a) {
    wezel* b = new wezel;
    wezel* c = drzewo;
    b->lewy = NULL;
    b->prawy = NULL;
    int t;
    IN >> t;
    b->war = bintoint(t);
    if (!c) drzewo = b;
    else {
        while (true) {
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
        }
    }
    b->pop = c;
    if (!IN.eof()) {
        wczytajin(a);
    }
}

void dopliku::wczytajpost(wezel* a) {
    wezel* b = new wezel;
    wezel* c = drzewo;
    b->lewy = NULL;
    b->prawy = NULL;
    int t;
    POST >> t;
    b->war = bintoint(t);
    if (!c) drzewo = b;
    else {
        while (true) {
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
        }
    }
    b->pop = c;
    if (!POST.eof()) {
        wczytajpost(a);
    }
}

void dopliku::zapiszpre(wezel* a) { 
    if (a) {
        PRE << " " << inttobin(a->war);        
        zapiszpre(a->lewy);          
        zapiszpre(a->prawy);         
    }
}

void dopliku::zapiszin(wezel* a) {
    if (a) {
        zapiszin(a->lewy);
        IN << " " << inttobin(a->war);
        zapiszin(a->prawy);
    }
}

void dopliku::zapiszpost(wezel* a) {
    if (a) {
        zapiszpost(a->lewy);
        zapiszpost(a->prawy);
        POST << " " << inttobin(a->war);
    }
}

void dopliku::wczytaj() {
    std::cout << "\n PRE-1, IN-2, POST-3 \n wybierz z ktorej metody ma byc wczytane:";
    int x;
    std::cin >> x;
    if (x == 1) {
        PRE.open("PRE.txt", std::ios::in); // Open file once here
        if (!PRE.is_open()) {
            std::cout << "Nie ma dostepu do pliku PRE.txt" << std::endl;
            return;
        }
        wczytajpre(drzewo);
        PRE.close(); // Close file after traversal is complete
    }
    else if (x == 2) {
        IN.open("IN.txt", std::ios::in); // Open file once here
        if (!IN.is_open()) {
            std::cout << "Nie ma dostepu do pliku IN.txt" << std::endl;
            return;
        }
        wczytajin(drzewo);
        IN.close(); // Close file after traversal is complete
    }
    else if (x == 3) {
        POST.open("POST.txt", std::ios::in); // Open file once here
        if (!POST.is_open()) {
            std::cout << "Nie ma dostepu do pliku POST.txt" << std::endl;
            return;
        }
        wczytajpost(drzewo);
        POST.close(); // Close file after traversal is complete
    }
    else {
        std::cout << "Wprowadzony zly znak, wprowadz jeszcze raz";
        wczytaj();
    }
}

wezel *dopliku::rdrzewo() {
    return drzewo;
}

int dopliku::inttobin(int a) {
    int b;
    std::string c;
    while (a) {
        c = (a % 2 ? "1" : "0") + c;
        a /= 2;
    }
    b = std::stoi(c);
    return b;
}

int dopliku::bintoint(int a) {
    int b = 0;
    int c = 1;
    std::string d = std::to_string(a);
    for (int i = d.length() - 1; i >= 0; --i, c <<= 1) {
        b += (d[i] - '0') * c;
    }
    return b;
}