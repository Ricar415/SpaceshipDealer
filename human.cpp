#include "human.hpp"

using namespace std;


human::human(string n, string p) : owner(n, p){}
void human::show() { cout << "Human with NIF: " << rn << " and planet of origin: " << planet << endl; }
