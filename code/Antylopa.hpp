#pragma once
#include "Zwierze.hpp"
#define ANTYLOPA 'A'
#define SILA_ANTYLOPY 4
#define INICJATYWA_ANTYLOPY 4
class Antylopa : public Zwierze
{
protected:
    void rozmnazanie(Organizm &organizm) override;
public:
    Antylopa(Polozenie polozenie, Swiat& swiat);
    void akcja() override;
    void kolizja(Organizm& organizm) override;
    virtual ~Antylopa();
};