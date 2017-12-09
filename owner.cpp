#include "owner.hpp"

using namespace std;

owner::owner(string n) { rn = n; }

void owner::modify(string nrn) { rn = nrn; }

string owner::rrn() { return rn; }
string owner::reg() {
	string temp = rn + " ";
	return temp;
}