#include "alien.hpp"

using namespace std;

alien::alien(string n, string p) : owner(n, p) {}
void alien::show() { cout << "Alien with NIE: " << rn << " and planet of origin: " << planet << endl; }
