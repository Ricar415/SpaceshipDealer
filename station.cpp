#include "station.hpp"
#include <string>
#include <iostream>

using namespace std;
station::station(int mp, int hn, bool es, string n){
    hangarn = hn;
    energyshield = es;
    vrn = n;
	maxp = mp;
	type = 4;
}
void station::modifymp(int mp){
	maxp = mp;
}
void station::modifyhn(int hn){
	hangarn = hn;
}
void station::modifyes(bool es){
	energyshield = es;
}
void station::show() {
	cout << "Register number: " << vrn << " Station; Number of Hangars: " << hangarn << " Maximum passengers: " << maxp;
	if (energyshield == 0) {
		cout << " Without energy shield" << endl;
	}
	else {
		cout << " With energy shield" << endl;
	}
}
bool station::check(string cvrn){ if (vrn == cvrn) return 1; else return 0; }