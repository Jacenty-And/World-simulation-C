#include "Antylopa.hpp"
Antylopa::Antylopa(Polozenie polozenie, Swiat& swiat)
: Zwierze(ANTYLOPA, SILA_ANTYLOPY, INICJATYWA_ANTYLOPY, polozenie, swiat)
{}
void Antylopa::akcja()
{
    polozenie[1] = polozenie[0];
    while (polozenie[0] == polozenie[1])
    {
        do
        {
            polozenie[0].x = polozenie[1].x;
            polozenie[0].x += 2 * (rand() % 3 - 1);
        }
        while (polozenie[0].x < 0 || polozenie[0].x >= WYSOKOSC_PLANSZY);
        do
        {
            polozenie[0].y = polozenie[1].y;
            polozenie[0].y += 2 * (rand() % 3 - 1);
        }
        while (polozenie[0].y < 0 || polozenie[0].y >= SZEROKOSC_PLANSZY);
    }
    if (swiat.plansza[polozenie[0].x][polozenie[0].y] == '_' || swiat.plansza[polozenie[0].x][polozenie[0].y] == ' ')
        swiat.plansza[polozenie[1].x][polozenie[1].y] = ' ';
}
void Antylopa::kolizja(Organizm& organizm)
{
    if (typeid(*this).name() == typeid(organizm).name())
    {
        organizm.setPolozenie(0, organizm.getPolozenie(1));
        rozmnazanie(organizm);
    }
    else if (rand() % 2 == 0)
    {
        Polozenie newPolozenie = rozmieszczenie();
        if (!(newPolozenie == getPolozenie()))
        {
            swiat.plansza[organizm.getPolozenie(1).x][organizm.getPolozenie(1).y] = ' ';
            setPolozenie(0, newPolozenie);
            rysowanie();
            cout << *this << " ucieka od " << organizm << endl;
        }
        else
            Zwierze::kolizja(organizm);
    }
    else
        Zwierze::kolizja(organizm);
}
void Antylopa::rozmnazanie(Organizm& organizm)
{
    Polozenie newPolozenie = rozmieszczenie();
    if (!(newPolozenie == polozenie[0]) && (swiat.plansza[newPolozenie.x][newPolozenie.y] == '_' || swiat.plansza[newPolozenie.x][newPolozenie.y] == ' '))
    {
        Antylopa *antylopa = new Antylopa(newPolozenie, swiat);
        cout << "Rozmnazanie " << organizm  << " z " << *this << ": nowy " << *antylopa << endl;
    }
}
Antylopa::~Antylopa() {}