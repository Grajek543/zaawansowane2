#include <fstream>

class dopliku {
public:
	wezel *drzewo;
	std::fstream PRE;
	std::fstream IN;
	std::fstream POST;
	dopliku(wezel *a);
	void wczytajpre(wezel* a);
	void wczytajin(wezel* a);
	void wczytajpost(wezel* a);
	void zapisz();
	void zapiszpre(wezel* a);
	void zapiszin(wezel* a);
	void zapiszpost(wezel* a);
	void wczytaj();
	wezel *rdrzewo();
	int bintoint(int a);
	int inttobin(int a);
};