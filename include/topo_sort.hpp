#ifndef AISA_PROJEKAT_TOPO_SORT_HPP
#define AISA_PROJEKAT_TOPO_SORT_HPP

#include <vector>
#include <queue>
#include <stdexcept>
#include "dag.hpp"

inline std::vector<int> topoSortKahn(const DAG& g) {
    int n = g.brojCvorova();

    std::vector<int> indeg = g.dohvatiIndeg();

    std::queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indeg[i] == 0) q.push(i);
    }

    std::vector<int> redosljed;
    redosljed.reserve(n);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        redosljed.push_back(u);

        for(int v : g.dohvatiSusjede(u)) {
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }

    if(redosljed.size() != n) {
        throw std::runtime_error("Graf nije DAG jer postoji ciklus, topo sort nije moguc.");
    }

    return redosljed;
}

#endif //AISA_PROJEKAT_TOPO_SORT_HPP
