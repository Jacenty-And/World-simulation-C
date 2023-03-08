#pragma once
#include "Roslina.hpp"
#define GUARANA 'g'
#define SILA_GUARANY 0
class Guarana : public Roslina
{
protected:
    void rozprzestrzenianie(Polozenie polozenie) override;
public:
    Guarana(Polozenie polozenie, Swiat& swiat);
    void kolizja(Organizm &organizm) override;
    virtual ~Guarana();
};