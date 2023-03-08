#pragma once
#include "Swiat.hpp"
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;
class Swiat;
struct Polozenie
{
    int x, y;
    Polozenie()
    : x(0), y(0)
    {}
    Polozenie(int x, int y)
    : x(y), y(x)
    {}
    bool operator==(const Polozenie& p)
    {
        if (p.x == x && p.y == y)
            return true;
        else
            return false;
    }
    friend std::ostream& operator<<(std::ostream& os, const Polozenie& polozenie)
    {
        os << "(" << polozenie.y << "," << polozenie.x << ")";
        return os;
    }
};
class Organizm
{
protected:
    char symbol;
    int sila;
    int inicjatywa;
    Polozenie polozenie[2];
    Swiat &swiat;
    friend std::ostream& operator<<(std::ostream& os, const Organizm& organizm);
    Polozenie rozmieszczenie();
public:
    Organizm(char symbol, int sila, int inicjatywa, Polozenie polozenie, Swiat &swiat);
    void rysowanie();

    int getSila() const;
    int getInicjatywa() const;
    Polozenie getPolozenie() const;
    Polozenie getPolozenie(int i) const;
    void setSymbol(char symbol);
    void setSila(int sila);
    void setPolozenie(int i, Polozenie polozenie);

    virtual void akcja() = 0;
    virtual void kolizja(Organizm &organizm) = 0;
    virtual ~Organizm();
};