/// @file bst.cpp Definicja metod drzewa BST

#include "bst.h"
#include "Wczyt.h"
#include <iostream>


/// @brief Konstruktor drzewa
bst::bst(void) {
    r = 0;
    korzen = NULL;
}

/// @brief Destruktor drzewa
bst::~bst(void) {
    r = 0;
    delete korzen;
}

/// @brief Zwraca element o najniższej wartości z pod podanego elementu
/// @param a - Element drzewa 
wezel *bst::najmin(wezel *a) {
    wezel *b = a;
    while(b->lewy) b = b->lewy;
    return b;
}

/// @brief Zwraca element o najwyższej wartości z pod podanego elementu
/// @param a - Element drzewa 
wezel *bst::najmax(wezel *a) {
    wezel *b = a;
    while(b->prawy) b = b->prawy;
    return b;
}

/// @brief Zwraca element o wartości co najmniej jeden mniejszej od wartości podanego elementu
/// @param a - Element drzewa
wezel *bst::min(wezel *a) {
    if(a->lewy) return najmax(a->lewy);
    wezel *b;
    do {
        b = a;
        a = a->pop;
    } while((a) && (a->prawy != b));
    return a;
}

/// @brief Zwraca element o wartości co najmniej jeden większej od wartości podanego elementu
/// @param a - Element drzewa
wezel *bst::max(wezel *a) {
    if(a->prawy) return najmin(a->prawy);
    wezel *b;
    do {
        b = a;
        a = a->pop;
    } while((a) && (a->lewy != b));
    return a;
}

/// @brief Zwraca element o podanej wartości
/// @param a - Dowolna wartość
wezel *bst::zwroc(int a) {
    wezel *b = korzen;
    while((b) && (b->war != a)) {
        if(a < b->war) b = b->lewy;
        else b = b->prawy;
    }
    if (b) return b;
    std::cout << "Drzewo nie posiada takiego elementu\n";
    return NULL;
}

/// @brief Dodaje element do drzewa
/// @param a - Wartość dodawanego elementu
void bst::dodele(int a) {
    wezel *b = new wezel;
    wezel *c = korzen;
    b->lewy = NULL;
    b->prawy = NULL;
    b->war = a;
    if(!c) korzen = b;
    else {
        while(true) {
            if(b->war < c->war) {
                if(!c->lewy) {
                    c->lewy = b;
                    break;
                }
                else c = c->lewy;
            }
            else {
                if(!c->prawy) {
                    c->prawy = b;
                    break;
                }
                else c = c->prawy;
            }
        }
    }
    b->pop = c;
    r++;
}

/// @brief Usuwa element z drzewa
/// @param a - Wartość usuwanego elementu
wezel *bst::usunele(int d) {
    wezel *a = zwroc(d);
    if (!a) return a;
    wezel *b = a->pop;
    wezel *c = NULL;
    if((a->lewy) && (a->prawy)) {
        if(rand() % 2) c = usunele(min(a)->war);
        else c = usunele(max(a)->war);
        c->lewy = a->lewy;
        if(c->lewy) c->lewy->pop = c;
        c->prawy = a->prawy;
        if(c->prawy) c->prawy->pop = c;
    }
    else {
        if(a->lewy) c = a->lewy;
        else c = a->prawy;
    }
    if(c) c->pop = b;
    if(!b) korzen = c;
    else {
        if(b->lewy == a) b->lewy = c;
        else b->prawy = c;
    }
    r--;
    return a;
}

/// @brief Usuwa całe drzewo
/// @param a - Korzeń drzewa
void bst::usubst(wezel *a) {
    if(a) {
        usubst(a->lewy);
        usubst(a->prawy);
        usunele(a->war);
    }
    r = 0;
}

/// @brief Podaje drogę do elementu o podanej wartości
/// @param a - Dowolna wartość
void bst::szuk(int a) {
    wezel *b = korzen;
    if (!zwroc(a));
    else {
        std::cout << "Do tego elementu trzeba przejsc przez: ";
        while((b) && (b->war != a)) {
            std::cout << b->war << " ";
            if(a < b->war) b = b->lewy;
            else b = b->prawy;
        }
        std::cout << std::endl;
    }
}

/// @brief Wypisuje elementy listy w metodzie preorder
/// @param a - Korzeń drzewa
void bst::wyspre(wezel *a) {
    if (a) {
        std::cout << a->war << " ";
        wyspre(a->lewy);
        wyspre(a->prawy);
    }
    if (r == 0) std::cout << "Drzewo jest puste";
}

/// @brief Wypisuje elementy listy w metodzie inorder
/// @param a - Korzeń drzewa
void bst::wysin(wezel *a) {
    if(a) {
        wysin(a->lewy);
        std::cout << a->war << " ";
        wysin(a->prawy);
    }
    if (r == 0) std::cout << "Drzewo jest puste";
}

/// @brief Wypisuje elementy listy w metodzie postorder
/// @param a - Korzeń drzewa
void bst::wyspost(wezel *a) {
    if(a) {
        wyspost(a->lewy);
        wyspost(a->prawy);
        std::cout << a->war << " ";
    }
    if (r == 0) std::cout << "Drzewo jest puste";
}

/// @brief Zapisuje dzrzewo do pliku
void bst::zapisz() {
    dopliku a(this->korzen);
    a.zapisz();
}

/// @brief Wczytuje drzewo z pliku
void bst::wczytaj() {
    dopliku a(this->korzen);
    a.wczytaj();
    this->korzen = a.drzewo;
}