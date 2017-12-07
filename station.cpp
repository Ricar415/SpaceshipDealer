#include <string>
#include <iostream>

#include "station.hpp"

using namespace std;

// -- Constructor --
station::station(int mp, int hn, bool es, int propulsiont, int tmaxcrew, int tprice, string n) : vehicle(n, propulsiont, tmaxcrew, tprice, 4){
    hangarn = hn;
    energyshield = es;
	maxp = mp;
}

// -- Modify functions --
void station::modifymp(int mp) { maxp = mp; }
void station::modifyhn(int hn) { hangarn = hn; }
void station::modifyes(bool es) { energyshield = es; }

// -- Auxiliary functions --
int station::hn() { return hangarn; }

// -- Show functions --
void station::show() {
	cout << "Register number: " << vrn << " Station; Number of Hangars: " << hangarn << " Maximum passengers: " << maxp << " Propulsion type: " << showpropulsion() << " Maximum crew: " << maxcrew << " Price: " << price;
	if (energyshield == 0) { cout << " Without energy shield" << endl; }
	else { cout << " With energy shield" << endl; }
}

// -- Formatting functions --
string station::reg() {
	string space = " ", t = to_string(type), p = to_string(propulsion), mc = to_string(maxcrew), pr = to_string(price), mp = to_string(maxp), hn = to_string(hangarn), es = to_string(energyshield);
	return vrn + space + t + space + p + space + mc + space + pr + space + mp + space + hn + space + es + space;
}