#include "Mlecz.hpp"
Mlecz::Mlecz(Polozenie polozenie, Swiat& swiat)
: Roslina(MLECZ, SILA_MLECZA, polozenie, swiat)
{}
void Mlecz::akcja()
{
    int i = 3;
    while (i--)
        Roslina::akcja();
}
void Mlecz::rozprzestrzenianie(Polozenie polozenie)
{
    Mlecz *mlecz = new Mlecz(polozenie, swiat);
    cout << "Rosnie " << *mlecz << endl;
}
Mlecz::~Mlecz() {}