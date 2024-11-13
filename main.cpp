#include "bst.h"
#include "Wczyt.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    bst e;
    e.dodele(3);
    e.dodele(4);
    e.dodele(2);
    e.dodele(6);
    e.dodele(7);
    e.dodele(98);
    e.dodele(23);
    e.dodele(54);
    e.dodele(2);
    e.dodele(12);
    e.dodele(12);
    e.dodele(453);
    e.wyspre(e.korzen);
    e.zapisz();
    e.usubst(e.korzen);
    e.wczytaj();
    e.wyspre(e.korzen);
    e.usunele(23);
    std::cout << std::endl;
    e.wyspre(e.korzen);
    e.usubst(e.korzen);
    e.wczytaj();
    e.wyspre(e.korzen);
    e.usubst(e.korzen);
    e.wczytaj();
    e.wyspre(e.korzen);
    std::cout << std::endl;
    e.szuk(54);
    std::cout << std::endl;
    e.wysin(e.korzen);
    std::cout << std::endl;
    e.wyspost(e.korzen);
}