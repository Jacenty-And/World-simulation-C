#include "Czlowiek.hpp"
#define ARROWS 224
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
Czlowiek::Czlowiek(Polozenie polozenie, Swiat& swiat)
: Zwierze(CZLOWIEK, SILA_CZLOWIEKA, INICJATYWA_CZLOWIEKA, polozenie, swiat)
{
    tarczaAktywna = false;
    czasDzialaniaTarczy = czasRegeneracjiTarczy = 0;
}
void Czlowiek::ruch()
{
    cout << "Ruch czlowieka:" << endl;
    ruchCzlowieka = getch();
    if (ruchCzlowieka == ARROWS)
        ruchCzlowieka = getch();
    if (ruchCzlowieka == 'q' || ruchCzlowieka == 'Q')
        swiat.setKoniec(true);
}
void Czlowiek::akcja()
{
    cout << "Akcja czlowieka: ";
    if (ruchCzlowieka == KEY_UP || ruchCzlowieka == KEY_DOWN || ruchCzlowieka == KEY_LEFT || ruchCzlowieka == KEY_RIGHT)
    {
        polozenie[1] = polozenie[0];
        swiat.plansza[getPolozenie().x][getPolozenie().y] = ' ';
        cout << "ruch w ";
        Polozenie newPolozenie = polozenie[0];
        switch(ruchCzlowieka)
        {
        case KEY_UP:
            cout << "gore" << endl;
            newPolozenie.x -= 1;
            break;
        case KEY_DOWN:
            cout << "dol" << endl;
            newPolozenie.x += 1;
            break;
        case KEY_LEFT:
            cout << "lewo" << endl;
            newPolozenie.y -= 1;
            break;
        case KEY_RIGHT:
            cout << "prawo" << endl;
            newPolozenie.y += 1;
            break;
        }
        if (swiat.getOrganizm(newPolozenie).getPolozenie() == newPolozenie && swiat.getOrganizm(newPolozenie).getSila() > sila)
        {
            cout << *this << " probuje pokonac silniejszego przeciwnika " << swiat.getOrganizm(newPolozenie) << endl;
            cout << "Czlowiek umiera" << endl;
            swiat.setKoniec(true);
        }
        else
        {
            polozenie[0] = newPolozenie;
            rysowanie();
        }
    }
    else
    {
        switch(ruchCzlowieka)
        {
        case ENTER:
            cout << "nastepna tura" << endl;
            break;
        case 'S':
        case 's':
            cout << "specjalna umiejetnosc aktywowana" << endl;
            tarczaAlzura();
            break;
        case 'Q':
        case 'q':
            cout << "koniec symulacji" << endl;
            break;
        default:
            cout << "nastepna tura" << endl;
            break;
        }
    }
    if (czasDzialaniaTarczy > 0)
        cout << "Tarcza Alzura: pozostalo " << czasDzialaniaTarczy-- << " tur" << endl;
    else if (czasDzialaniaTarczy == 0 && tarczaAktywna)
    {
        tarczaAktywna = false;
        czasRegeneracjiTarczy = CZAS_REGENERACJI_TARCZY;
    }
    if (tarczaAktywna == false && czasRegeneracjiTarczy > 0)
        cout << "Tarcza Alzura: do ponownej aktywacji pozostalo " << czasRegeneracjiTarczy-- << " tur" << endl;
}
void Czlowiek::kolizja(Organizm& organizm)
{
    if (tarczaAktywna)
    {
        Polozenie newPolozenie = rozmieszczenie();
        if (!(newPolozenie == getPolozenie()))
        {
            swiat.plansza[organizm.getPolozenie(1).x][organizm.getPolozenie(1).y] = ' ';
            organizm.setPolozenie(0, newPolozenie);
        }
        else
            organizm.setPolozenie(0, organizm.getPolozenie(1));
        organizm.rysowanie();
        Polozenie bufor = organizm.getPolozenie(0);
        organizm.setPolozenie(0, organizm.getPolozenie(1));
        cout << "Tarcza Alzura: chroni " << *this << " przed atakiem " << organizm << endl;
        organizm.setPolozenie(0, bufor);
    }
    else
    {
        Zwierze::kolizja(organizm);
        if (sila < organizm.getSila())
        {
            cout << "Czlowiek umiera" << endl;
            swiat.setKoniec(true);
        }
    }
}
void Czlowiek::tarczaAlzura()
{
    if (czasRegeneracjiTarczy > 0)
        cout << "Tarcza Alzura: tarcza musi sie zregenerowac" << endl;
    else if (tarczaAktywna)
        cout << "Tarcza Alzura: tarcza jest juz aktywna" << endl;
    else
    {
        tarczaAktywna = true;
        czasDzialaniaTarczy = CZAS_TRWANIA_TARCZY;
    }
}
void Czlowiek::rozmnazanie(Organizm& organizm) {}
Czlowiek::~Czlowiek() {}