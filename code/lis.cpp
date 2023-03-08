#include "Lis.hpp"
Lis::Lis(Polozenie polozenie, Swiat& swiat)
: Zwierze(LIS, SILA_LISA, INICJATYWA_LISA, polozenie, swiat)
{}
void Lis::akcja()
{
    polozenie[1] = polozenie[0];
    int i = 9;
    while (--i)
    {
        Polozenie newPolozenie = polozenie[0];
        while (newPolozenie == polozenie[1])
        {
            do
            {
                newPolozenie.x = polozenie[1].x;
                newPolozenie.x += rand() % 3 - 1;
            }
            while (newPolozenie.x < 0 || newPolozenie.x >= WYSOKOSC_PLANSZY);
            do
            {
                newPolozenie.y = polozenie[1].y;
                newPolozenie.y += rand() % 3 - 1;
            }
            while (newPolozenie.y < 0 || newPolozenie.y >= SZEROKOSC_PLANSZY);
        }
        if (swiat.plansza[newPolozenie.x][newPolozenie.y] == '_' || 
            swiat.plansza[newPolozenie.x][newPolozenie.y] == ' ' ||
            (swiat.getOrganizm(newPolozenie).getPolozenie() == newPolozenie && swiat.getOrganizm(newPolozenie).getSila() <= sila))
        {
            polozenie[0] = newPolozenie;
            swiat.plansza[polozenie[1].x][polozenie[1].y] = ' ';
            break;
        }
    }
}
void Lis::kolizja(Organizm& organizm)
{
    if (typeid(*this).name() == typeid(organizm).name())
    {
        organizm.setPolozenie(0, organizm.getPolozenie(1));
        rozmnazanie(organizm);
    }
    else
        Zwierze::kolizja(organizm);
}
void Lis::rozmnazanie(Organizm& organizm)
{
    Polozenie newPolozenie = rozmieszczenie();
    if (!(newPolozenie == polozenie[0]) && (swiat.plansza[newPolozenie.x][newPolozenie.y] == '_' || swiat.plansza[newPolozenie.x][newPolozenie.y] == ' '))
    {
        Lis *lis = new Lis(newPolozenie, swiat);
        cout << "Rozmnazanie " << organizm  << " z " << *this << ": nowy " << *lis << endl;
    }
}
Lis::~Lis() {}