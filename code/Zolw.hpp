#pragma once
#include "Zwierze.hpp"
#define ZOLW 'Z'
#define SILA_ZOLWIA 2
#define INICJATYWA_ZOLWIA 1
class Zolw : public Zwierze
{
protected:
    void rozmnazanie(Organizm &organizm) override;
public:
    Zolw(Polozenie polozenie, Swiat& swiat);
    void akcja() override;
    void kolizja(Organizm& organizm) override;
    virtual ~Zolw();
};