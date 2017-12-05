#include "owner.hpp"
#include <string>
#include <iostream>

using namespace std;

void owner::modify(string nrn) {
	rn = nrn;
}
bool owner::check(string crn) {
	if (rn == crn) return 1; else return 0;
}
void owner::show() {
	cout << "Owner with register number: " << rn << endl;
}
string owner::reg() { // Returns string of formatted parameters
	string temp;
	temp = rn;
	temp += " ";
	return temp;
}