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
};