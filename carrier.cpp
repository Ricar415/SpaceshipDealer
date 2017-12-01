#include "carrier.hpp"
#include <string>
#include <iostream>

using namespace std;
carrier::carrier(int ml, int cs , bool es, string vn){
    cruisingspeed = cs;
    maxload = ml;
    energyshield = es;
    vrn = vn;
	type = 1;
}
void carrier::modifyml(int ml){
    maxload = ml;
}
void carrier::modifycs(int cs){
    cruisingspeed = cs;
}
void carrier::modifyes(bool es){
    energyshield = es;
}
void carrier::show() {
	cout << "Register number: " << vrn << " Carrier Cruising Speed: " << cruisingspeed << " Maximum load (tons): " << maxload;
	if (energyshield == 0) {
		cout << " Without energy shield" << endl;
	}
	else {
		cout << " With energy shield" << endl;
	}
}