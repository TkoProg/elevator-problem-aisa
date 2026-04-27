# Elevator Problem - AiSA

Projekat iz predmeta **Analiza i sinteza algoritama** na PMF-u.

## Opis projekta

Ovaj projekat modelira problem planiranja rada lifta pomocu grafa zavisnosti dogadjaja.  
Svaki zahtjev putnika se pretvara u dva dogadjaja:

- `PU` - preuzimanje putnika na pocetnom spratu
- `DO` - ostavljanje putnika na odredisnom spratu

Za svaki zahtjev mora vaziti da se `PU` dogadjaj izvrsi prije odgovarajuceg `DO` dogadjaja. Zbog toga se problem predstavlja kao **DAG** graf, nad kojim se zatim primjenjuje **topolosko sortiranje**.

## Trenutno implementirano

- model zahtjeva i dogadjaja
- kreiranje `PU` i `DO` dogadjaja za svaki zahtjev
- konstrukcija DAG grafa
- dodavanje grana zavisnosti `PU -> DO`
- topolosko sortiranje pomocu Kahn algoritma
- osnovni primjer izvrsavanja u `main.cpp`

## Struktura projekta

```text
elevator-problem-aisa/
├── include/
│   ├── dag.hpp
│   ├── dag_builder.hpp
│   ├── dogadjaji_builder.hpp
│   ├── model.hpp
│   └── topo_sort.hpp
├── src/
│   └── main.cpp
└── CMakeLists.txt
