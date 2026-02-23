#pragma once
#include <vector>
class PL {
private:
    std::vector<int>              m_b{};
    std::vector<std::vector<int>> m_A{};
    std::vector<int>              m_c{};

public:
    PL(std::vector<int> b, std::vector<std::vector<int>> A, std::vector<int> c):
        m_b { b },
        m_A { A },
        m_c { c }
    {}

    const std::vector<int>& get_b() const { return m_b; };
    const std::vector<int>& get_c() const { return m_c; };
    const std::vector<std::vector<int>>& get_A() const { return m_A; };
};

class Simplesso {
private:
    const PL&                        pl;
    std::vector<double>              b_barrato{};
    double                           z_barrato{};
    std::vector<double>              y_trasposta{};
    std::vector<std::vector<double>> carry{};
    std::vector<int>                 base{};
    std::vector<int>                 non_base{};
    bool                             ottimo{false};
    bool                             illimitato{false};

public:
    Simplesso(PL& nuovo_pl);

    void                trova_prima_base();
    void                fuori_base();
    std::vector<int>    trova_identita();
    double              calcolo_costo_ridotto();
    std::vector<double> calcolo_A_barrata_colonna();
    void                pivot();
    void                simplesso();
};
