#pragma once
#include "Zwierze.hpp"
#define LIS 'L'
#define SILA_LISA 3
#define INICJATYWA_LISA 7
class Lis : public Zwierze
{
protected:
    void rozmnazanie(Organizm &organizm) override;
public:
    Lis(Polozenie polozenie, Swiat& swiat);
    void akcja() override;
    void kolizja(Organizm& organizm) override;
    virtual ~Lis();
};