#pragma once
#include "Roslina.hpp"
#define MLECZ 'm'
#define SILA_MLECZA 0
class Mlecz : public Roslina
{
protected:
    void rozprzestrzenianie(Polozenie polozenie) override;
public:
    Mlecz(Polozenie polozenie, Swiat& swiat);
    void akcja() override;
    virtual ~Mlecz();
};