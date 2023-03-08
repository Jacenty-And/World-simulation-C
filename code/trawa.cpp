#include "Trawa.hpp"
Trawa::Trawa(Polozenie polozenie, Swiat& swiat)
: Roslina(TRAWA, SILA_TRAWY, polozenie, swiat)
{}
void Trawa::rozprzestrzenianie(Polozenie polozenie)
{
    Trawa *trawa = new Trawa(polozenie, swiat);
    cout << "Rosnie " << *trawa << endl;
}
Trawa::~Trawa() {}