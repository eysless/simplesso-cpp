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
#include "simplesso.hpp"


Simplesso::Simplesso(PL& nuovo_pl)
    : pl{ nuovo_pl }
{
    base = trova_base();

}

std::vector<int>    Simplesso::trova_identita() {
    const auto& A = pl.get_A();
    int rows = A.size();
    int columns = A[0].size();

    std::vector<int> unitari(columns, -1);


    for (int i = 0; i < columns; i++){
        int singular = 1;
        int trovato_singolo = 0;
        int j = 0;
        while (j < rows && singular) {
            if (A[j][i] != 0){
                if (A[j][i] == 1 && !trovato_singolo) {
                    trovato_singolo = 1;
                    unitari[i] = j;
                }
                else singular = 0;
            }
            j++;
        }
        if (!singular) unitari[i] = -1;
    }
    
    return unitari;
}

std::vector<int> Simplesso::trova_base(){
    const std::vector<int> identity = trova_identita();
    const auto& A = pl.get_A();
    int rows = A.size();
    int columns = A[0].size();

    std::vector<int> base(rows, -1);
    for (int i = 0; i < identity.size(); i++){
        if (identity[i] != -1){
            base[identity[i]] = i;
        }
    }
    return base;
}

double Simplesso::calcolo_costo_ridotto(){
    double costo_ridotto;
    return costo_ridotto;
}
