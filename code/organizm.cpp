#include "Organizm.hpp"
std::ostream& operator<<(std::ostream& os, const Organizm& organizm)
{
    string s = typeid(organizm).name();
    if (s.size() < 10)
        s.erase(s.begin());
    else
        s.erase(s.begin(), s.begin() + 2);
    os << s << organizm.getPolozenie();
    return os;
}
Organizm::Organizm(char symbol, int sila, int inicjatywa, Polozenie polozenie, Swiat &swiat)
: symbol(symbol), sila(sila), inicjatywa(inicjatywa), swiat(swiat)
{
    this->polozenie[0] = this->polozenie[1] = polozenie;
    swiat.dodajOrganizm(*this);
    rysowanie();
}
void Organizm::rysowanie()
{
    swiat.plansza[polozenie[0].x][polozenie[0].y] = symbol;
}
Polozenie Organizm::rozmieszczenie()
{
    Polozenie newPolozenie = polozenie[0];
    int i = 9;
    while (--i)
    {
        do
        {
            newPolozenie.x = polozenie[0].x + rand() % 3 - 1;
        }
        while (newPolozenie.x < 0 || newPolozenie.x >= WYSOKOSC_PLANSZY);
        do 
        {
            newPolozenie.y = polozenie[0].y + rand() % 3 - 1;
        }
        while (newPolozenie.y < 0 || newPolozenie.y >= SZEROKOSC_PLANSZY);
        if ((swiat.plansza[newPolozenie.x][newPolozenie.y] == '_' || swiat.plansza[newPolozenie.x][newPolozenie.y] == ' ') && !(newPolozenie == polozenie[0]))
            break;
    }
    return newPolozenie;
}
int Organizm::getSila() const
{
    return sila;
}
int Organizm::getInicjatywa() const
{
    return inicjatywa;
}
Polozenie Organizm::getPolozenie() const
{
    return polozenie[0];
}
Polozenie Organizm::getPolozenie(int i) const
{
    return polozenie[i];
}
void Organizm::setSymbol(char symbol)
{
    this->symbol = symbol;
}
void Organizm::setSila(int sila)
{
    this->sila = sila;
}
void Organizm::setPolozenie(int i, Polozenie polozenie)
{
    this->polozenie[i] = polozenie;
}
Organizm::~Organizm() {}