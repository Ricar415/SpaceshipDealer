#include <cstring>
#include <iostream>

#include "alien.hpp"

using namespace std;

alien::alien(string n) : owner(n) {}
void alien::show() { cout << "Alien with register number: " << rn << endl; }
