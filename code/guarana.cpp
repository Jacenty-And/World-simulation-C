#include "Guarana.hpp"
Guarana::Guarana(Polozenie polozenie, Swiat& swiat)
: Roslina(GUARANA, SILA_GUARANY, polozenie, swiat)
{}
void Guarana::kolizja(Organizm &organizm)
{
    organizm.setSila(organizm.getSila() + 3);
    Roslina::kolizja(organizm);
    cout << "Sila " << organizm << " zwieksza sie do " << organizm.getSila() << endl;
}
void Guarana::rozprzestrzenianie(Polozenie polozenie)
{
    Guarana *guarana = new Guarana(polozenie, swiat);
    cout << "Rosnie " << *guarana << endl;
}
Guarana::~Guarana() {}