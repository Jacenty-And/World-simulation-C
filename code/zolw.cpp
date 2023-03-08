#include "Zolw.hpp"
Zolw::Zolw(Polozenie polozenie, Swiat& swiat)
: Zwierze(ZOLW, SILA_ZOLWIA, INICJATYWA_ZOLWIA, polozenie, swiat)
{}
void Zolw::akcja()
{
    if (rand() % 4 == 0)
        Zwierze::akcja();
}
void Zolw::kolizja(Organizm& organizm)
{
    if (typeid(*this).name() == typeid(organizm).name())
    {
        organizm.setPolozenie(0, organizm.getPolozenie(1));
        rozmnazanie(organizm);
    }
    else if (organizm.getSila() < 5)
    {
        organizm.setPolozenie(0, organizm.getPolozenie(1));
        cout << *this << " odpiera atak " << organizm << endl;
    }
    else
        Zwierze::kolizja(organizm);
}
void Zolw::rozmnazanie(Organizm& organizm)
{
    Polozenie newPolozenie = rozmieszczenie();
    if (!(newPolozenie == polozenie[0]) && (swiat.plansza[newPolozenie.x][newPolozenie.y] == '_' || swiat.plansza[newPolozenie.x][newPolozenie.y] == ' '))
    {
        Zolw *zolw = new Zolw(newPolozenie, swiat);
        cout << "Rozmnazanie " << organizm  << " z " << *this << ": nowy " << *zolw << endl;
    }
}
Zolw::~Zolw() {}