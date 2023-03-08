#pragma once
#include "Zwierze.hpp"
#define OWCA 'O'
#define SILA_OWCY 4
#define INICJATYWA_OWCY 4
class Owca : public Zwierze
{
public:
    Owca(Polozenie polozenie, Swiat& swiat);
    void kolizja(Organizm& organizm) override;
    void rozmnazanie(Organizm &organizm) override;
    virtual ~Owca();
};