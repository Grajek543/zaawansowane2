struct wezel {
  wezel *pop;
  wezel *lewy;
  wezel *prawy;
  int war;
};

class bst {
public:
    int roz;
    wezel *korzen;
    bst();
    ~bst() {}
    void dodele(bst *&korzen, int a);
    wezel *usuele(bst *&korzen, wezel a);
    wezel *szuk(bst *&korzen, int a);
    void wyspre(bst *&korzen);
    void wysin(bst *&korzen);
    void wyspost(bst *&korzen);
    void zapis(bst *&korzen);
}