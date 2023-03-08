#include "Zwierze.hpp"
Zwierze::Zwierze(char symbol, int sila, int inicjatywa, Polozenie polozenie, Swiat &swiat)
: Organizm(symbol, sila, inicjatywa, polozenie, swiat)
{}
void Zwierze::akcja()
{
    polozenie[1] = polozenie[0];
    while (polozenie[0] == polozenie[1])
    {
        do
        {
            polozenie[0].x = polozenie[1].x;
            polozenie[0].x += rand() % 3 - 1;
        }
        while (polozenie[0].x < 0 || polozenie[0].x >= WYSOKOSC_PLANSZY);
        do
        {
            polozenie[0].y = polozenie[1].y;
            polozenie[0].y += rand() % 3 - 1;
        }
        while (polozenie[0].y < 0 || polozenie[0].y >= SZEROKOSC_PLANSZY);
    }
    if (swiat.plansza[polozenie[0].x][polozenie[0].y] == '_' || swiat.plansza[polozenie[0].x][polozenie[0].y] == ' ')
        swiat.plansza[polozenie[1].x][polozenie[1].y] = ' ';
}
void Zwierze::kolizja(Organizm &organizm)
{
    printf("O Bogowie walka!\n");
    swiat.plansza[organizm.getPolozenie(1).x][organizm.getPolozenie(1).y] = ' ';
    Polozenie bufor = organizm.getPolozenie(0);
    organizm.setPolozenie(0, organizm.getPolozenie(1));
    cout << organizm << " atakuje " << *this << endl;
    organizm.setPolozenie(0, bufor);
    cout << "Walke wygrywa ";
    if (this->getSila() <= organizm.getSila())
    {
        cout << organizm << endl;
        swiat.usunOrganizm(*this);
        organizm.rysowanie();
    }
    else
    {
        cout << *this << endl;
        swiat.usunOrganizm(organizm);
        this->rysowanie();
    }
}
Zwierze::~Zwierze() {}