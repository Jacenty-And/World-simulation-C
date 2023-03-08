#include "Swiat.hpp"
Swiat::Swiat()
: tura(1), koniec(false)
{
    srand(time(NULL));
    for (int i = 0; i < WYSOKOSC_PLANSZY; i++)
        for (int j = 0; j < SZEROKOSC_PLANSZY; j++)
            plansza[i][j] = '_';
}
bool Swiat::getKoniec() const
{
    return koniec;
}
int Swiat::getTura() const
{
    return tura;
}
Organizm& Swiat::getOrganizm(Polozenie polozenie) const
{
    for (int i = 0; i < organizmy.size(); i++)
        if (organizmy[i]->getPolozenie() == polozenie)
            return *organizmy[i];
    return *organizmy[0];
}
void Swiat::setKoniec(bool koniec)
{
    this->koniec = koniec;
}
void Swiat::dodajOrganizm(Organizm& organizm)
{
    organizmy.push_back(&organizm);
}
void Swiat::usunOrganizm(Organizm& organizm)
{
    for (int i = 0; i < organizmy.size(); i++)
        if (organizmy[i] == &organizm)
        {
            organizmy.erase(organizmy.begin() + i);
            break;
        }
}
void Swiat::sortujOrganizmy()
{
    for (int i = 0; i < organizmy.size(); i++)
        for (int j = 0; j < organizmy.size() - i - 1; j++)
            if (organizmy[j]->getInicjatywa() < organizmy[j + 1]->getInicjatywa())
                swap(organizmy[j],organizmy[j+1]);
}
void Swiat::wykonajTure()
{
    system("CLS");
    cout << "Jacenty Andruszkiewicz 184788" << endl;
    cout << "Sterowanie - Strzalki" << endl;
    cout << "Specjalna umiejetnosc - S" << endl;
    cout << "Nastepna tura - Enter" << endl;
    cout << "Wyjscie - Q" << endl;
    cout << endl;
    rysujSwiat();
    cout << "Tura " << tura++ << endl;
    sortujOrganizmy();
    for (int i = 0; i < organizmy.size(); i++)
    {
        organizmy[i]->akcja();
        bool flag = false;
        int j;
        for (j = 0; j < organizmy.size(); j++)
        {
            if (i != j && organizmy[i]->getPolozenie() == organizmy[j]->getPolozenie())
            {
                organizmy[j]->kolizja(*organizmy[i]);
                bool flag = true;
                break;
            }
        }
        organizmy[i]->rysowanie();
        if (flag)
        {
            flag = false;
            organizmy[j]->rysowanie();
        }
    }
    cout << endl;
    rysujSwiat();
}
void Swiat::rysujSwiat()
{
    cout << "Organizmy: " << organizmy.size() << endl;
    for (int i = 0; i < WYSOKOSC_PLANSZY; i++)
    {
        for (int j = 0; j < SZEROKOSC_PLANSZY; j++)
            cout << plansza[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}