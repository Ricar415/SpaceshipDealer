#include <string>
#include <iostream>

#include "carrier.hpp"

using namespace std;

// -- Constructor --
carrier::carrier(int ml, int cs , bool es, int propulsiont, int maxcrewt, int pricet, string vn) : vehicle (vn, propulsiont, maxcrewt, pricet, 1){
    cruisingspeed = cs;
    maxload = ml;
    energyshield = es;
}

// -- Modify funtions --
void carrier::modifyml(int ml) { maxload = ml; }
void carrier::modifycs(int cs) { cruisingspeed = cs; }
void carrier::modifyes(bool es) { energyshield = es; }

// -- Show functions --
void carrier::show() {
	cout << "Register number: " << vrn << " Carrier Cruising Speed: " << cruisingspeed << " Maximum load (tons): " << maxload << " Propulsion type: " << showpropulsion() << " Maximum crew: " << maxcrew << " Price: " << price ;
	if (energyshield == 0) { cout << " Without energy shield" << endl; }
	else { cout << " With energy shield" << endl; }
}

// -- Formatting functions --
string carrier::reg() {
	string space = " ", pt = to_string(propulsion), mcrew = to_string(maxcrew), pr = to_string(price), ml = to_string(maxload), es = to_string(energyshield), cs = to_string(cruisingspeed), t = to_string(type);
	return vrn + space + t + space + pt + space + mcrew + space + pr + space + ml + space + es + space + cs + space;
}