#include "Roslina.hpp"
Roslina::Roslina(char symbol, int sila, Polozenie polozenie, Swiat &swiat)
: Organizm(symbol, sila, 0, polozenie, swiat)
{}   
void Roslina::akcja()
{
    Polozenie newPolozenie = rozmieszczenie();
    if (!(newPolozenie == polozenie[0]) && (swiat.plansza[newPolozenie.x][newPolozenie.y] == '_' || swiat.plansza[newPolozenie.x][newPolozenie.y] == ' '))
        if (rand() % 5 == 0)
            rozprzestrzenianie(newPolozenie);
}
void Roslina::kolizja(Organizm &organizm)
{
    swiat.plansza[organizm.getPolozenie(1).x][organizm.getPolozenie(1).y] = ' ';
    Polozenie bufor = organizm.getPolozenie(0);
    organizm.setPolozenie(0, organizm.getPolozenie(1));
    cout << organizm << " zjada " << *this << endl;
    swiat.usunOrganizm(*this);
    organizm.setPolozenie(0, bufor);
}
Roslina::~Roslina() {}