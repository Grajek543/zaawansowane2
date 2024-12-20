/// @file bst.h Deklaracja metod drzewa BST

/// @brief Deklaracja pojedynczego elementu drzewa
struct wezel {
    wezel *pop; ///< Poprzednik elementu
    wezel *lewy; ///< Lewy dziedzic elementu
    wezel *prawy; ///< Prawy dziedzic elementu
    int war; ///< Wartość elementu
};

///@brief Deklaracja drzewa, jego zmiennych i jego metod
class bst {
public:
    wezel *korzen; ///< Pierwszy element drzewa
    int r; ///< Liczba elementów drzewa
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