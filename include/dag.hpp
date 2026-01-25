#ifndef AISA_PROJEKAT_DAG_HPP
#define AISA_PROJEKAT_DAG_HPP

#include <vector>

class DAG {
private:
    int n;
    std::vector<std::vector<int>> susjedi;
    std::vector<int> indeg;
public:
    explicit DAG(int brojCvorova) : n(brojCvorova), susjedi(brojCvorova), indeg(brojCvorova, 0) {};

    int brojCvorova() const { return n; };

    void dodajGranu(int u, int v) {
        susjedi[u].push_back(v);
        indeg[v]++;
    }

    const std::vector<int>& dohvatiSusjede(int u) const {
        return susjedi[u];
    }

    const std::vector<int>& dohvatiIndeg() const {
        return indeg;
    }
};

#endif //AISA_PROJEKAT_DAG_HPP
