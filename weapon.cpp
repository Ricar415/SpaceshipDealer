#include <iostream>

#include "platform.hpp"

using namespace std;

// -- Constructor --
weapon::weapon() { type = 0; }
weapon::weapon(int ctype) {
	type = ctype;
	if (type == 1) { ocapacity = 10; }
	else if (type == 2) { ocapacity = 20; }
	else if (type == 3) { ocapacity = 5; }
	else if (type == 4) { ocapacity = 15; }
	else { ocapacity = 0; }
}

// -- Modify functions --
void weapon::modify(int ntype) {
	type = ntype;
	if (type == 1) { ocapacity = 10; }
	else if (type == 2) { ocapacity = 20; }
	else if (type == 3) { ocapacity = 5; }
	else if (type == 4) { ocapacity = 15; }
	else { ocapacity = 0; }
}

// -- Auxiliary functions -- 
int weapon::returntype() { return type; }
int weapon::focapacity() { return ocapacity; }

// -- Show functions --
void weapon::show() { cout << type << endl; }