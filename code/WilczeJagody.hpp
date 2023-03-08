#pragma once
#include "Roslina.hpp"
#define WILCZE_JAGODY 'w'
#define SILA_WILCZYCH_JAGOD 99
class WilczeJagody : public Roslina
{
protected:
    void rozprzestrzenianie(Polozenie polozenie) override;
public:
    WilczeJagody(Polozenie polozenie, Swiat& swiat);
    void kolizja(Organizm &organizm) override;
    virtual ~WilczeJagody();
};