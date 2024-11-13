#include "bst.h"
#include "Wczyt.h"
#include <iostream>

bst::bst(void) {
    korzen = NULL;
}

bst::~bst(void) {
    delete korzen;
}

wezel *bst::najmin(wezel *a) {
    wezel *b = a;
    while(b->lewy) b = b->lewy;
    return b;
}

wezel *bst::najmax(wezel *a) {
    wezel *b = a;
    while(b->prawy) b = b->prawy;
    return b;
}

wezel *bst::min(wezel *a) {
    if(a->lewy) return najmax(a->lewy);
    wezel *b;
    do {
        b = a;
        a = a->pop;
    } while((a) && (a->prawy != b));
    return a;
}

wezel *bst::max(wezel *a) {
    if(a->prawy) return najmin(a->prawy);
    wezel *b;
    do {
        b = a;
        a = a->pop;
    } while((a) && (a->lewy != b));
    return a;
}

wezel *bst::zwroc(int a) {
    wezel *b = korzen;
    while((b) && (b->war != a)) {
        if(a < b->war) b = b->lewy;
        else b = b->prawy;
    }
    return b;
}

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
}

wezel *bst::usunele(int d) {
    wezel *a = zwroc(d);
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
    return a;
}

void bst::usubst(wezel *a) {
    if(a) {
        usubst(a->lewy);
        usubst(a->prawy);
        usunele(a->war);
    }
}

void bst::szuk(int a) {
    wezel *b = korzen;
    while((b) && (b->war != a)) {
        std::cout << b->war << " ";
        if(a < b->war) b = b->lewy;
        else b = b->prawy;
    }
    std::cout << std::endl;
}

void bst::wyspre(wezel *a) {
    if (a) {
        std::cout << a->war << " ";
        wyspre(a->lewy);
        wyspre(a->prawy);
    }
}

void bst::wysin(wezel *a) {
    if(a) {
        wysin(a->lewy);
        std::cout << a->war << " ";
        wysin(a->prawy);
    }
}

void bst::wyspost(wezel *a) {
    if(a) {
        wyspost(a->lewy);
        wyspost(a->prawy);
        std::cout << a->war << " ";
    }
}

void bst::zapisz() {
    dopliku a(this->korzen);
    a.zapisz();
}

void bst::wczytaj() {
    dopliku a(this->korzen);
    a.wczytaj();
    this->korzen = a.drzewo;
}