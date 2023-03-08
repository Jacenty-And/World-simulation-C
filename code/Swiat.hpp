#pragma once
#include "Organizm.hpp"
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <vector>
using namespace std;
#define SZEROKOSC_PLANSZY 10
#define WYSOKOSC_PLANSZY 10
struct Polozenie;
class Organizm;
class Swiat
{
    int tura;
    bool koniec;
    std::vector<Organizm*> organizmy;
    void sortujOrganizmy();
public:
    Swiat();
    char plansza[WYSOKOSC_PLANSZY][SZEROKOSC_PLANSZY];
    bool getKoniec() const;
    int getTura() const;
    Organizm& getOrganizm(Polozenie polozenie) const;
    void setKoniec(bool koniec);
    void dodajOrganizm(Organizm& organizm);
    void usunOrganizm(Organizm& organizm);
    void wykonajTure();
    void rysujSwiat();
};