#include "Owca.hpp"
Owca::Owca(Polozenie polozenie, Swiat& swiat)
: Zwierze(OWCA, SILA_OWCY, INICJATYWA_OWCY, polozenie, swiat)
{}
void Owca::kolizja(Organizm& organizm)
{
    if (typeid(*this).name() == typeid(organizm).name())
    {
        organizm.setPolozenie(0, organizm.getPolozenie(1));
        rozmnazanie(organizm);
    }
    else
        Zwierze::kolizja(organizm);
}
void Owca::rozmnazanie(Organizm &organizm)
{
    Polozenie newPolozenie = rozmieszczenie();
    if (!(newPolozenie == polozenie[0]) && (swiat.plansza[newPolozenie.x][newPolozenie.y] == '_' || swiat.plansza[newPolozenie.x][newPolozenie.y] == ' '))
    {
        Owca *owca = new Owca(newPolozenie, swiat);
        cout << "Rozmnazanie " << organizm  << " z " << *this << ": nowa " << *owca << endl;
    }
}
Owca::~Owca() {}