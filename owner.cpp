#include "owner.hpp"

using namespace std;

owner::owner(string n, string p) { rn = n; planet = p; }

void owner::modify(string nrn) { rn = nrn; }
void owner::modifyplanet(string nplanet) { planet = nplanet; }

string owner::rrn() { return rn; }
string owner::reg() {
	string temp = rn + " " + planet + " ";
	return temp;
}