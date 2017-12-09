#include "human.hpp"

using namespace std;


human::human(string n) : owner(n){}
void human::show() { cout << "Human with register number: " << rn << endl; }
