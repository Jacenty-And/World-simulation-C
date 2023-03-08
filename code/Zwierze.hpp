#pragma once
#include "Organizm.hpp"
class Zwierze : public Organizm
{
protected:
    virtual void rozmnazanie(Organizm &organizm) = 0;
public:
    Zwierze(char symbol, int sila, int inicjatywa, Polozenie polozenie, Swiat &swiat);    
    void akcja() override;
    void kolizja(Organizm &organizm) override;
    virtual ~Zwierze();
};