#include "bst.h"
#include <iostream>

bst::bst(void) {
    roz = 0;
    korzen = NULL;
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
    } while(a && (a->prawy != b));
    return a;
}

wezel *bst::max(wezel *a) {
    if(a->prawy) return najmin(a->prawy);
    wezel *b;
    do {
        b = a;
        a = a->pop;
    } while(a && (a->lewy != b));
    return a;
}

void bst::dodele(wezel *&korzen, int a) {
    wezel *b = new wezel;
    wezel *c = korzen;
    b->lewy = NULL;
    b->prawy = NULL;
    b->war = a;
    if(!c) korzen = b;
    else
        while(true)
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
    b->pop = c;
}

wezel *bst::usunele(wezel *&korzen, wezel *a) {
    wezel *b = a->pop;
    wezel *c;
    if((a->lewy) && (a->prawy)) {
        if(rand() % 2) c = usunele(korzen, min(a));
        else usunele(korzen, max(a));
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
        delete a;
    }
}

void bst::wyspre(wezel *&korzen) {
    if(korzen) {
        std::cout << korzen->war<<" ";
        wyspre(korzen->lewy);
        wyspre(korzen->prawy);
    }
}

void bst::wysin(wezel *&korzen) {
    if(korzen) {
        wysin(korzen->lewy);
        std::cout << korzen->war<<" ";
        wysin(korzen->prawy);
    }
}

void bst::wyspost(wezel *&korzen) {
    if(korzen) {
        wyspost(korzen->lewy);
        wyspost(korzen->prawy);
        std::cout << korzen->war<<" ";
    }
}