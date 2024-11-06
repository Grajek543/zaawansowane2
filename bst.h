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
    wezel *najmin(wezel *a);
    wezel *najmax(wezel *a);
    wezel *min(wezel *a);
    wezel *max(wezel *a);
    void dodele(wezel *&korzen, int a);
    wezel *usunele(wezel *&korzen, wezel *a);
    void usubst(wezel *a);
    wezel *szuk(wezel *&korzen, int a) {}
    void wyspre(wezel *&korzen);
    void wysin(wezel *&korzen);
    void wyspost(wezel *&korzen);
    void zapis(wezel *&korzen) {}
};