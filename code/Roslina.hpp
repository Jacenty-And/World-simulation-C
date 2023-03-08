#pragma once
#include "Organizm.hpp"
class Roslina : public Organizm
{
protected:
    virtual void rozprzestrzenianie(Polozenie polozenie) = 0;
public:
    Roslina(char symbol, int sila, Polozenie polozenie, Swiat &swiat);    
    void akcja() override;
    void kolizja(Organizm &organizm) override;
    virtual ~Roslina();
};