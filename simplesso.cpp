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

#include <algorithm>
#include <vector>
#include "simplesso.hpp"


Simplesso::Simplesso(PL& nuovo_pl)
    : pl{ nuovo_pl }
{
    trova_prima_base();
    fuori_base();
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

void Simplesso::trova_prima_base(){
    base.clear();
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
}

void swap_int(int* x1, int* x2){
    int hold = *x1;
    *x1 = *x2;
    *x2 = hold;
}

void Simplesso::fuori_base() {
    non_base.clear();
    const auto& A = pl.get_A();
    int rows = A.size();
    int columns = A[0].size();
    std::vector<int> base_ordinata = base;
    int sorted = 0;

    while(!sorted){
        sorted = 1;
        for (int i = 0; i < base_ordinata.size() - 1; i++) {
            if (base_ordinata[i] > base_ordinata[i+1]) {
                swap_int(&base_ordinata[i], &base_ordinata[i+1]);
                sorted = 0;
            }
        }
    }

    int iteratore_base = 0;
    for (int i = 0; i < columns; i++) {
        if (base_ordinata.at(iteratore_base) == i) ++iteratore_base;
        else non_base.push_back(i);
    }
}

double Simplesso::calcolo_costo_ridotto(){
    double costo_ridotto;
    return costo_ridotto;
}
