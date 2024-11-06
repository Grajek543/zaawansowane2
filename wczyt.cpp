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
}

void dopliku::zapiszpre(wezel* b) { // Recursive function for pre-order traversal
    if (b) {
        PRE << " " << b->war;        // Write node value to file
        zapiszpre(b->lewy);          // Traverse left subtree
        zapiszpre(b->prawy);         // Traverse right subtree
    }
}

void dopliku::zapiszin(wezel* a) {
    if (a) {
        zapiszin(a->lewy);
        IN << " " << a->war;
        zapiszin(a->prawy);
    }
}