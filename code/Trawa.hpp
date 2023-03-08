#pragma once
#include "Roslina.hpp"
#define TRAWA 't'
#define SILA_TRAWY 0
class Trawa : public Roslina
{
protected:
    void rozprzestrzenianie(Polozenie polozenie) override;
public:
    Trawa(Polozenie polozenie, Swiat& swiat);
    virtual ~Trawa();
};