#include "Wilk.hpp"
Wilk::Wilk(Polozenie polozenie, Swiat& swiat)
: Zwierze(WILK, SILA_WILKA, INICJATYWA_WILKA, polozenie, swiat)
{}
void Wilk::kolizja(Organizm& organizm)
{
    if (typeid(*this).name() == typeid(organizm).name())
    {
        organizm.setPolozenie(0, organizm.getPolozenie(1));
        rozmnazanie(organizm);
    }
    else
        Zwierze::kolizja(organizm);
}
void Wilk::rozmnazanie(Organizm& organizm)
{
    Polozenie newPolozenie = rozmieszczenie();
    if (!(newPolozenie == polozenie[0]) && (swiat.plansza[newPolozenie.x][newPolozenie.y] == '_' || swiat.plansza[newPolozenie.x][newPolozenie.y] == ' '))
    {
        Wilk *wilk = new Wilk(newPolozenie, swiat);
        cout << "Rozmnazanie " << organizm  << " z " << *this << ": nowy " << *wilk << endl;
    }
}
Wilk::~Wilk() {}