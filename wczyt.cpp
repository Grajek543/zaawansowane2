/// @file wczyt.cpp Definicja metod wczytu i zapisu

#include "bst.h"
#include "Wczyt.h"
#include <fstream>
#include <iostream>
#include <string>

/// @brief Konstruktor klasy
/// @param a - Korzeń drzewa
dopliku::dopliku(wezel *a) : drzewo(a) {}

/// @brief Zapisuje drzewo do pliku, używając trzech metod
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

/// @brief Zapisuje drzewo do pliku w metodzie preorder
/// @param a - Korzeń drzewa
void dopliku::zapiszpre(wezel* a) { 
    if (a) {
        PRE << " " << inttobin(a->war);        
        zapiszpre(a->lewy);          
        zapiszpre(a->prawy);         
    }
}

/// @brief Zapisuje drzewo do pliku w metodzie inorder
/// @param a - Korzeń drzewa
void dopliku::zapiszin(wezel* a) {
    if (a) {
        zapiszin(a->lewy);
        IN << " " << inttobin(a->war);
        zapiszin(a->prawy);
    }
}

/// @brief Zapisuje drzewo do pliku w metodzie postorder
/// @param a - Korzeń drzewa
void dopliku::zapiszpost(wezel* a) {
    if (a) {
        zapiszpost(a->lewy);
        zapiszpost(a->prawy);
        POST << " " << inttobin(a->war);
    }
}

/// @brief Wczytuje drzewo z pliku, używając trzech metod
void dopliku::wczytaj() {
    std::cout << "\nPRE-1, IN-2, POST-3 \nWybierz z ktorej metody ma byc wczytane: ";
    int x;
    std::cin >> x;
    if (x == 1) {
        PRE.open("PRE.txt", std::ios::in);
        if (!PRE.is_open()) {
            std::cout << "Nie ma dostepu do pliku PRE.txt" << std::endl;
            return;
        }
        wczytajpre(drzewo);
        PRE.close();
    }
    else if (x == 2) {
        IN.open("IN.txt", std::ios::in);
        if (!IN.is_open()) {
            std::cout << "Nie ma dostepu do pliku IN.txt" << std::endl;
            return;
        }
        wczytajin(drzewo);
        IN.close();
    }
    else if (x == 3) {
        POST.open("POST.txt", std::ios::in);
        if (!POST.is_open()) {
            std::cout << "Nie ma dostepu do pliku POST.txt" << std::endl;
            return;
        }
        wczytajpost(drzewo);
        POST.close();
    }
    else {
        std::cout << "Wprowadzony zly znak, wprowadz jeszcze raz";
        wczytaj();
    }
}

/// @brief Wczytuje drzewo z pliku w metodzie preorder
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

/// @brief Wczytuje drzewo z pliku w metodzie inorder
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

/// @brief Wczytuje drzewo z pliku w metodzie postorder
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

/// @brief Konwertuje liczbę dziesiętną na binarną
/// @param a - Liczba do konwersji
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

/// @brief Konwertuje liczbę binarną na dziesiętną
/// @param a - Liczba do konwersji
int dopliku::bintoint(int a) {
    int b = 0;
    int c = 1;
    std::string d = std::to_string(a);
    for (int i = d.length() - 1; i >= 0; --i, c <<= 1) {
        b += (d[i] - '0') * c;
    }
    return b;
}