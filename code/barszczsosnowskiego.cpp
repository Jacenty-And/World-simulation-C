#include "BarszczSosnowskiego.hpp"
BarszczSosnowskiego::BarszczSosnowskiego(Polozenie polozenie, Swiat& swiat)
: WilczeJagody(polozenie, swiat)
{
    setSila(SILA_BARSZCZU_SOSNOWSKIEGO);
    setSymbol(BARSZCZ_SOSNOWSKIEGO);
    rysowanie();
}
void BarszczSosnowskiego::akcja()
{
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (!(i == 0 && j == 0))
            {
                Polozenie temp;
                temp.x = polozenie[0].x + i;
                temp.y = polozenie[0].y + j;
                if (temp.x >= 0 && temp.x < WYSOKOSC_PLANSZY && temp.y >= 0 && temp.y < SZEROKOSC_PLANSZY)
                {
                    Organizm* organizm = &swiat.getOrganizm(temp);
                    if (organizm->getPolozenie() == temp && dynamic_cast<Zwierze*>(organizm))
                    {
                        swiat.plansza[organizm->getPolozenie().x][organizm->getPolozenie().y] = ' ';
                        cout << *this << " zabija " << *organizm << endl;
                        swiat.usunOrganizm(*organizm);
                    }
                }
            }
    Roslina::akcja();
}
void BarszczSosnowskiego::rozprzestrzenianie(Polozenie polozenie)
{
    BarszczSosnowskiego *barszczSosnowskiego = new BarszczSosnowskiego(polozenie, swiat);
    cout << "Rosnie " << *barszczSosnowskiego << endl;
}
BarszczSosnowskiego::~BarszczSosnowskiego() {}