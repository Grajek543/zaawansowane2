#include <fstream>
class dopliku {
private:
	bst drzewo;
	std::fstream PRE;
	std::fstream IN;
	std::fstream POST;
public:
	dopliku(bst a);
	void zapisz(bst a);
	void zapiszpre(wezel* a);
	void zapiszin(wezel* a);
	void zapiszpost(wezel* a);
	void wczytaj();
	bst rdrzewo();
	void wczytajpre(wezel* a);
	void wczytajin(wezel* a);
	void wczytajpost(wezel* a);
};