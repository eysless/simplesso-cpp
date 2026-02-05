/*  COSA VOGLIO FARE:
    Classe PL, che contiene:
        Oggetto Matrice A
        Oggetto Vettore c^T
        Oggetto Vettore b

    Classe simplesso, che contiene:

        Oggetto Vettore b barrato
        Oggetto double -Z barrato
        Oggetto Vettore -Y trasposta
        Oggetto Matrice Carry completa
        Oggetto Vettore variabili in base
        Oggetto Vettore variabili non in base
        Oggetto bool ottimo
        Oggetto bool illimitato

        Funzione simplesso
        Funzione trovare identità in A, ritorna quante variabili e quali rappresentano l'identità

        Momento di cambio di base:
            Funzione calcola c barrato di una variabile candidata
            Funzione calcola A barrato per vedere se è illimitato inferiormente
            Funzione pivot, da fare solo se il problema non è illimitato e esiste un c barrato < 0
*/

#include <vector>
class PL {
private:
    std::vector<double>              b{};
    std::vector<std::vector<double>> A{};
    std::vector<double>              c{};

public:
    void inserisci_matrice_A();
    void inserisci_vettore_b();
    void inserisci_vettore_c();
};

class Simplesso {
private:
    const PL& pl;
    std::vector<double>              b_barrato{};
    double                           z_barrato{};
    std::vector<double>              y{};
    std::vector<std::vector<double>> carry{};
    std::vector<int>                 base{};
    std::vector<int>                 non_base{};
    bool                             ottimo{false};
    bool                             illimitato{false};

public:
    std::vector<int> trova_identità ();
    double calcolo_costo_ridotto ();
    std::vector<double> calcolo_A_barrata_colonna ();
    void pivot ();
    void simplesso();
    Simplesso ();
};
