#include "platform.hpp"
#include <iostream>

weapon::weapon(int ctype) {
	type = ctype;
	if (type == 1) {
		ocapacity = 10;
	}
	else if (type == 2) {
		ocapacity = 20;
	}
	else if (type == 3) {
		ocapacity = 5;
	}
	else if (type == 4) {
		ocapacity = 15;
	}
	else {
		ocapacity = 0;
	}
}
int weapon::focapacity() {
	return ocapacity;
}
weapon::weapon() {
	type = 0;
}
void weapon::modify(int ntype) {
	type = ntype;
	if (type == 1) {
		ocapacity = 10;
	}
	else if (type == 2) {
		ocapacity = 20;
	}
	else if (type == 3) {
		ocapacity = 5;
	}
	else if (type == 4) {
		ocapacity = 15;
	}
	else {
		ocapacity = 0;
	}
}
void weapon::show() {
	cout << type << endl;
}
int weapon::returntype() {
	return type;
}