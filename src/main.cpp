#include <iostream>
#include <vector>

#include "model.hpp"
#include "dogadjaji_builder.hpp"
#include "dag_builder.hpp"
#include "topo_sort.hpp"

using namespace std;

int main() {

    vector<Zahtjev> zahtjevi = {{0, 0.0, 0, 5}, {1, 2.0, 3, 1}, {2, 4.0, 1, 3}};

    auto r = kreirajDogadjaje(zahtjevi);
    auto g = napraviDAG(r);
    auto red = topoSortKahn(g);
    cout<<"Topo redosljed: ";
    for(int x : red) cout<<x<<" ";
    cout<<endl;

    cout<<"Broj cvorova: "<<g.brojCvorova()<<endl;

    for(int u = 0; u < g.brojCvorova(); u++) {
        cout<<"Iz "<<u<<" ide u: ";
        for(int v : g.dohvatiSusjede(u)) cout<<v<<" ";
        cout<<endl;
    }

    return 0;
}