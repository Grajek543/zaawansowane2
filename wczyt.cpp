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
        std::cout << "Nie ma dostêpu do pliku PRE.txt" << std::endl;
        return;
    }
    zapiszpre(drzewo.korzen);
    PRE.close(); // Close file after traversal is complete

    IN.open("IN.txt", std::ios::out | std::ios::trunc); // Open file once here
    if (!IN.is_open()) {
        std::cout << "Nie ma dostêpu do pliku IN.txt" << std::endl;
        return;
    }
    zapiszin(drzewo.korzen);
    IN.close(); // Close file after traversal is complete
    POST.open("POST.txt", std::ios::out | std::ios::trunc); // Open file once here
    if (!POST.is_open()) {
        std::cout << "Nie ma dostêpu do pliku POST.txt" << std::endl;
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