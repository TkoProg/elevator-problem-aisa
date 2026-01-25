#ifndef AISA_PROJEKAT_DOGADJAJI_BUILDER_HPP
#define AISA_PROJEKAT_DOGADJAJI_BUILDER_HPP

#include <vector>
#include "model.hpp"

struct RezultatKreiranjaDogadjaja {
    std::vector<Dogadjaj> dogadjaji; // bit ce 2*N dogadjaja jer za svaki zahtjev dobijamo PU i DO
    std::vector<int> puDogadjajId; // indeksirano po zahId
    std::vector<int> doDogadjajId; // indeksirano po zahId
};

inline RezultatKreiranjaDogadjaja kreirajDogadjaje(const std::vector<Zahtjev>& zahtjevi) {
    RezultatKreiranjaDogadjaja r;

    int n = zahtjevi.size();
    r.dogadjaji.reserve(2 * n); // jer ce ih bit 2 * n
    r.puDogadjajId.assign(n, -1); // nije se desio PU
    r.doDogadjajId.assign(n, -1); // nije se desio DO

    int sljedeciId = 0;

    for(const auto& z : zahtjevi) {
        Dogadjaj PU;
        PU.id = sljedeciId++;
        PU.tip = TipDogadjaja::PU;
        PU.zahId = z.id;
        PU.sprat = z.s;

        r.puDogadjajId[z.id] = PU.id;
        r.dogadjaji.push_back(PU);

        Dogadjaj DO;
        DO.id = sljedeciId++;
        DO.tip = TipDogadjaja::DO;
        DO.zahId = z.id;
        DO.sprat = z.d;

        r.doDogadjajId[z.id] = DO.id;
        r.dogadjaji.push_back(DO);
    }

    return r;
}

#endif // AISA_PROJEKAT_DOGADJAJI_BUILDER_HPP
