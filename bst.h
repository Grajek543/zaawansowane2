struct wezel {
    wezel *pop;
    wezel *lewy;
    wezel *prawy;
    int war;
};

class bst {
public:
    wezel *korzen;
    bst();
    ~bst();
    wezel *najmin(wezel *a);
    wezel *najmax(wezel *a);
    wezel *min(wezel *a);
    wezel *max(wezel *a);
    wezel *zwroc(int a);
    void dodele(int a);
    wezel *usunele(int d);
    void usubst(wezel *korzen);
    void szuk(int a);
    void wyspre(wezel *korzen);
    void wysin(wezel *korzen);
    void wyspost(wezel *korzen);
    void wczytaj();
    void zapisz();
};