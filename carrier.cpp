#include "carrier.hpp"
#include <string>
#include <iostream>

using namespace std;
carrier::carrier(int ml, int cs , bool es, int propulsiont, int maxcrewt, int pricet, string vn){ /*! Parametrized constructor */
    cruisingspeed = cs;
    maxload = ml;
    energyshield = es;
    vrn = vn;
	type = 1;
	maxcrew = maxcrewt;
	propulsion = propulsiont;
	price = pricet;
}

void carrier::modifyml(int ml){ // Maximum load modify function
    maxload = ml;
}
void carrier::modifycs(int cs){ // Cruising speed modify function
    cruisingspeed = cs;
}
void carrier::modifyes(bool es){ // Energy shield modify function
    energyshield = es;
}

void carrier::show() { // Parameter display function
	cout << "Register number: " << vrn << " Carrier Cruising Speed: " << cruisingspeed << " Maximum load (tons): " << maxload << " Propulsion type: " << showpropulsion() << " Maximum crew: " << maxcrew << " Price: " << price ;
	if (energyshield == 0) {
		cout << " Without energy shield" << endl;
	}
	else {
		cout << " With energy shield" << endl;
	}
}

bool carrier::check(string cvrn) {
	if (vrn == cvrn) return 1; else return 0;
}
string carrier::reg() {
	string temp, space = " ", pt = to_string(propulsion), mcrew = to_string(maxcrew), pr = to_string(price), ml = to_string(maxload), es = to_string(energyshield), cs = to_string(cruisingspeed), t = to_string(type);
	temp = vrn;
	temp += space;
	temp += t;
	temp += space;
	temp += pt;
	temp += space;
	temp += mcrew;
	temp += space;
	temp += pr;
	temp += space;
	temp += ml;
	temp += space;
	temp += es;
	temp += space;
	temp += cs;
	temp += space;
	return temp;
}