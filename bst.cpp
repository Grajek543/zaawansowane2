#include "bst.h"
#include <iostream>

bst::bst(void) {
    roz = 0;
    korzen = NULL;
}

void dodele(wezel *&korzen, int a) {
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

