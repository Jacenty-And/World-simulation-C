#pragma once
#include "Zwierze.hpp"
#include "Roslina.hpp"
#include "WilczeJagody.hpp"
#define BARSZCZ_SOSNOWSKIEGO 'b'
#define SILA_BARSZCZU_SOSNOWSKIEGO 10
class BarszczSosnowskiego : public WilczeJagody
{
protected:
    void rozprzestrzenianie(Polozenie polozenie) override;
public:
    BarszczSosnowskiego(Polozenie polozenie, Swiat& swiat);
    void akcja() override;
    virtual ~BarszczSosnowskiego();
};