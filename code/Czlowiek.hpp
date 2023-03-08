#pragma once
#include "Zwierze.hpp"
#define CZLOWIEK 'C'
#define SILA_CZLOWIEKA 5
#define INICJATYWA_CZLOWIEKA 4
#define CZAS_TRWANIA_TARCZY 5
#define CZAS_REGENERACJI_TARCZY 5
class Czlowiek : public Zwierze
{
    int ruchCzlowieka;
    bool tarczaAktywna;
    int czasDzialaniaTarczy;
    int czasRegeneracjiTarczy;
protected:
    void rozmnazanie(Organizm &organizm) override;
public:
    Czlowiek(Polozenie polozenie, Swiat& swiat);
    void ruch();
    void akcja() override;
    void kolizja(Organizm& organizm) override;
    void tarczaAlzura();
    virtual ~Czlowiek();
};