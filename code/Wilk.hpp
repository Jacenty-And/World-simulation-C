#pragma once
#include "Zwierze.hpp"
#define WILK 'W'
#define SILA_WILKA 9
#define INICJATYWA_WILKA 5
class Wilk : public Zwierze
{
protected:
    void rozmnazanie(Organizm &organizm) override;
public:
    Wilk(Polozenie polozenie, Swiat& swiat);
    void kolizja(Organizm& organizm) override;
    virtual ~Wilk();
};