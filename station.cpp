#include "station.hpp"
#include <string>
#include <iostream>

using namespace std;
station::station(int mp, int hn, bool es, int propulsiont, int tmaxcrew, int tprice, string n){
    hangarn = hn;
    energyshield = es;
    vrn = n;
	maxp = mp;
	type = 4;
	propulsion = propulsiont;
	maxcrew = tmaxcrew;
	price = tprice;
}
void station::modifymp(int mp) { maxp = mp; }
void station::modifyhn(int hn) { hangarn = hn; }
void station::modifyes(bool es) { energyshield = es; }
void station::show() {
	cout << "Register number: " << vrn << " Station; Number of Hangars: " << hangarn << " Maximum passengers: " << maxp << " Propulsion type: " << showpropulsion() << " Maximum crew: " << maxcrew << " Price: " << price;
	if (energyshield == 0) {
		cout << " Without energy shield" << endl;
	}
	else {
		cout << " With energy shield" << endl;
	}
}
bool station::check(string cvrn){ if (vrn == cvrn) return 1; else return 0; }
int station::hn() { return hangarn; }
string station::reg() {
	string temp, space = " ", t = to_string(type), p = to_string(propulsion), mc = to_string(maxcrew), pr = to_string(price), mp = to_string(maxp), hn = to_string(hangarn), es = to_string(energyshield);
	temp = vrn;
	temp += space;
	temp += t;
	temp += space;
	temp += p;
	temp += space;
	temp += mc;
	temp += space;
	temp += pr;
	temp += space;
	temp += mp;
	temp += space;
	temp += hn;
	temp += space;
	temp += es;
	temp += space;
	return temp;
}