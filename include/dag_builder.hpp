#ifndef AISA_PROJEKAT_DAG_BUILDER_HPP
#define AISA_PROJEKAT_DAG_BUILDER_HPP

#include "dag.hpp"
#include "dogadjaji_builder.hpp"

inline DAG napraviDAG(const RezultatKreiranjaDogadjaja& r) {
    DAG g(r.dogadjaji.size());

    int n = r.puDogadjajId.size(); // broj dogadjaja

    for(int i = 0; i < n; i++) {
        int PU = r.puDogadjajId[i];
        int DO = r.doDogadjajId[i];
        g.dodajGranu(PU, DO);
    }

    return g;
}

#endif //AISA_PROJEKAT_DAG_BUILDER_HPP
