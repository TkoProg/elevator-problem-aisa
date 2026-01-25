#ifndef AISA_PROJEKAT_MODEL_HPP
#define AISA_PROJEKAT_MODEL_HPP

// PUi - preuzimanje putnika na spratu s_i
// DOi - dolazak putnika na spratu di
enum class TipDogadjaja { PU, DO };

struct Zahtjev {
    int id; // indeks zahtjeva
    double t; // vrijeme dolaska zahtjeva
    int s; // sprat poziva
    int d; // sprat dolaska
};

struct Dogadjaj {
    int id; // indeks eventa
    TipDogadjaja tip; // tip eventa, ili ce bit PU ili DO
    int zahId; // indeks zahtjeva kojem pripada
    int sprat; // sprat na kojem se desava
};

inline const char* ispisTipa(TipDogadjaja t) {
    if (t == TipDogadjaja::PU) return "PU";
    else return "DO";
}

#endif // AISA_PROJEKAT_MODEL_HPP
