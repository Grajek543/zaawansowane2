/// @file wczyt.h Deklaracja metod wczytu i zapisu

#include <fstream>

/// @brief Deklaracja klasy zawierającej metody wczytu i zapisu
class dopliku {
public:
	wezel *drzewo; ///< Element zawierający korzeń drzewa
	std::fstream PRE; ///< Zmienna obsługująca plik metody preorder
	std::fstream IN; ///< Zmienna obsługująca plik metody inorder
	std::fstream POST; ///< Zmienna obsługująca plik metody postorder
	dopliku(wezel *a);
	void zapisz();
	void zapiszpre(wezel* a);
	void zapiszin(wezel* a);
	void zapiszpost(wezel* a);
	void wczytaj();
	void wczytajpre(wezel* a);
	void wczytajin(wezel* a);
	void wczytajpost(wezel* a);
	int bintoint(int a);
	int inttobin(int a);
};