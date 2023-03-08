#include "Swiat.hpp"
#include "Organizm.hpp"
#include "Zwierze.hpp"
#include "Wilk.hpp"
#include "Owca.hpp"
#include "Lis.hpp"
#include "Zolw.hpp"
#include "Antylopa.hpp"
#include "Roslina.hpp"
#include "Trawa.hpp"
#include "Mlecz.hpp"
#include "Guarana.hpp"
#include "WilczeJagody.hpp"
#include "BarszczSosnowskiego.hpp"
#include "Czlowiek.hpp"
#define ILE_ORGANIZMOW 20
int main()
{
    Swiat swiat;

    Polozenie polozenia[ILE_ORGANIZMOW];
    for (int i = 0; i < ILE_ORGANIZMOW; i++)
    {
        polozenia[i] = Polozenie(rand() % SZEROKOSC_PLANSZY, rand() % WYSOKOSC_PLANSZY);
        for (int j = 0; j < i; j++)
            if (polozenia[j] == polozenia[i])
            {
                i--;
                break;
            }
    }

    Czlowiek czlowiek(polozenia[0], swiat);
    Trawa t1(polozenia[1], swiat);
    Trawa t2(polozenia[2], swiat);
    Mlecz m1(polozenia[3], swiat);
    Guarana g1(polozenia[4], swiat);
    Guarana g2(polozenia[5], swiat);
    WilczeJagody wj1(polozenia[6], swiat);
    WilczeJagody wj2(polozenia[7], swiat);
    BarszczSosnowskiego b1(polozenia[8], swiat);
    BarszczSosnowskiego b2(polozenia[9], swiat);
    Wilk w1(polozenia[10], swiat);
    Wilk w2(polozenia[11], swiat);
    Owca o1(polozenia[12], swiat);
    Owca o2(polozenia[13], swiat);
    Lis l1(polozenia[14], swiat);
    Lis l2(polozenia[15], swiat);
    Zolw z1(polozenia[16], swiat);
    Zolw z2(polozenia[17], swiat);
    Antylopa a1(polozenia[18], swiat);
    Antylopa a2(polozenia[19], swiat);

    while (true)
    {
        swiat.wykonajTure();
        if (swiat.getKoniec())
            break;
        else
            czlowiek.ruch();
    }
    return 0;
}