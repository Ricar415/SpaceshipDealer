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