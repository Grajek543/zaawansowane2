#include "bst.h"
#include "Wczyt.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    bst e;
    e.dodele(e.korzen, 3);
    e.dodele(e.korzen, 4);
    e.dodele(e.korzen, 2);
    e.dodele(e.korzen, 6);
    e.dodele(e.korzen, 7);
    e.dodele(e.korzen, 98);
    e.dodele(e.korzen, 23);
    e.dodele(e.korzen, 54);
    e.dodele(e.korzen, 2);
    e.dodele(e.korzen, 12);
    e.dodele(e.korzen, 12);
    e.dodele(e.korzen, 453);
    e.wyspre(e.korzen);
    e.zapisz();
    e.wyspre(e.korzen);
}