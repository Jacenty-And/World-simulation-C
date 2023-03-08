#include "WilczeJagody.hpp"
WilczeJagody::WilczeJagody(Polozenie polozenie, Swiat& swiat)
: Roslina(WILCZE_JAGODY, SILA_WILCZYCH_JAGOD, polozenie, swiat)
{}
void WilczeJagody::kolizja(Organizm &organizm)
{
    swiat.plansza[this->getPolozenie().x][this->getPolozenie().y] = ' ';
    swiat.plansza[organizm.getPolozenie(1).x][organizm.getPolozenie(1).y] = ' ';
    Polozenie bufor = organizm.getPolozenie(0);
    organizm.setPolozenie(0, organizm.getPolozenie(1));
    cout << organizm << " zjada " << *this << endl;
    swiat.usunOrganizm(*this);
    organizm.setPolozenie(0, bufor);
    cout << organizm << " umiera" << endl;
    swiat.usunOrganizm(organizm);
}
void WilczeJagody::rozprzestrzenianie(Polozenie polozenie)
{
    WilczeJagody *wilczeJagody = new WilczeJagody(polozenie, swiat);
    cout << "Rosna " << *wilczeJagody << endl;
}
WilczeJagody::~WilczeJagody() {}