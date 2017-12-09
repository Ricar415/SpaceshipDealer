#include "platform.hpp"
#include "carrier.hpp"
#include "destroyer.hpp"
#include "fighter.hpp"
#include "station.hpp"

#include "human.hpp"
#include "alien.hpp"

#include "sale.hpp"
using namespace std;

// -- Destructor --
platform::~platform() {
	for (unsigned int i = 0; i < vehicles.size(); i++) {
		delete vehicles[i];
	}
	for (unsigned int i = 0; i < owners.size(); i++) {
		delete owners[i];
	}
}

// -- List functions --
void platform::lavailable() {
	vector<vehicle*> tempvector;
	vehicle *temp;
	for (unsigned int i = 0; i < vehicles.size(); i++) {
		if (checksales(vehicles[i]->rvrn()) == 0) { tempvector.push_back(vehicles[i]); }
	}
    int a;
	for (unsigned int i = 1; i < tempvector.size(); i++) { // Using insertion sorting as we are expecting low amounts of vehicles for testing
		temp = tempvector[i];
		for (a = i - 1; (a >= 0) && (vehicles[a]->rvrn() < vehicles[i]->rvrn()); a--) /* Overloaded operators at string.h lets us do _StringA < _StringB directly */{
			tempvector[a + 1] = tempvector[a];
		}
		tempvector[a + 1] = temp;
	}
	for (unsigned int i = 0; i < tempvector.size(); i++) { tempvector[i]->show(); }
}
void platform::lall() {
	vector<vehicle*> tempvector = vehicles;
	vehicle *temp;
    int a;
	for (unsigned int i = 1; i < tempvector.size(); i++) { // Using insertion sorting as we are expecting low amounts of vehicles for testing
		temp = tempvector[i];
		for (a = i - 1; (a >= 0) && (vehicles[a]->rvrn() < vehicles[i]->rvrn()); a--){
			tempvector[a + 1] = tempvector[a];
		}
		tempvector[a + 1] = temp;
	}
	for (unsigned int i = 0; i < tempvector.size(); i++) {
		tempvector[i]->show();
	}
}
void platform::lbyocapacity() {
	vector<vehicle*> tempvector = vehicles;
	vehicle *temp;
    int a;
	for (unsigned int i = 1; i < tempvector.size(); i++) { // Using insertion sorting as we are expecting low amounts of vehicles for testing
		temp = tempvector[i];
		for (a = i - 1; (a >= 0) && (tempvector[a]->ocapacity() < tempvector[i]->ocapacity()); a--){
			tempvector[a + 1] = tempvector[a];
		}
		tempvector[a + 1] = temp;
	}
	for (unsigned int i = 0; i < tempvector.size(); i++) {
		tempvector[i]->show();
	}
}
void platform::lbyowner(string rn) {
	for (unsigned int i = 0; i < sales.size(); i++) {
		if (sales[i].rorn() == rn) { sales[i].showsale(); }
	}
}

void platform::listowners() {
	vector<owner*> tempvector = owners;
	owner *temp;
	int type = 0, a;
	for (unsigned int i = 1; i < tempvector.size(); i++) { // Using insertion sorting as we are expecting low amounts of owners for testing
		temp = tempvector[i];
		for (a = i - 1; (a >= 0) && (owners[a]->rrn() < owners[i]->rrn()); a--) {
			tempvector[a + 1] = tempvector[a];
		}
		tempvector[a + 1] = temp;
	}
	for (unsigned int i = 0; i < tempvector.size(); i++) {
		tempvector[i]->show();
	}
}

void platform::showweapons(int position) {
    int nweapons;
	if (vehicles[position]->checktype() == 3) {
		nweapons = 2;
		cout << "Weapon 1 type:: ";
		vehicles[position]->showweapon(1);
		cout << "Weapon 2 type: ";
		vehicles[position]->showweapon(2);
	}
	else {
		nweapons = vehicles[position]->nweapons(); // function of destroyer
		for (int i = 0; i < nweapons; i++) {
			cout << "Position " << i << " weapon type:";
			vehicles[position]->showweapon(i); // function of weapon in vector of destroyer
		}
	}
}

void platform::lsales() {
	for (unsigned int i = 0; i < sales.size(); i++) {
		sales[i].showsale();
	}
}
void platform::lsales(date start, date end) {
	for (unsigned int i = 0; i < sales.size(); i++){
		if ((sales[i].greaterequalthan(start) == 1) && (sales[i].greaterequalthan(end) == 0)) { sales[i].showsale(); }
	}
}


// -- Create functions --
void platform::createhuman(string rn) {
	human *a = new human(rn);
	owners.push_back(a);
}
void platform::createalien(string rn){
	alien *a = new alien(rn);
    owners.push_back(a);
}

void platform::createfighter(int ms, int propulsiont, int pricet, weapon weapon1, weapon weapon2, string rn){
	fighter *a = new fighter(ms, propulsiont, pricet, weapon1, weapon2, rn);
	vehicles.push_back(a);
}
void platform::createcarrier(int ml, int cs, bool es, int propulsion, int maxcrew, int price, string rn) { // creates a carrier with given parameters and includes it in vehicles vector
	carrier *a = new carrier(ml, cs, es, propulsion, maxcrew, price, rn);
	vehicles.push_back(a);

}
void platform::createdestroyer(vector<weapon> weapons, int propulsion, int maxcrew, int price, string rn) { // creates a destroyer with given parameters and includes it in vehicles vector
	destroyer *a = new destroyer(weapons, propulsion, maxcrew, price, rn);
	vehicles.push_back(a);
}
void platform::createstation(int maxp, int hn, bool eshield, int propulsion, int maxcrew, int price, string rn) { // creates a station with given parameters and includes it in vehicles vector
	station *a = new  station(maxp, hn, eshield, propulsion, maxcrew, price, rn);
	vehicles.push_back(a);
}


// -- Modify functions --
void platform::modifyowner(int position, string nrn) { owners[position]->modify(nrn); }

void platform::modifyvehicle(int position, string nrn) { vehicles[position]->modifyvrn(nrn); }
void platform::modifyvehicle(int position, int code, int value) { // code-based to avoid creating too many functions
	if (code == 1) { vehicles[position]->modifycs(value); }
	else if (code == 2) { vehicles[position]->modifyml(value); }
	else if (code == 3) { vehicles[position]->addweapon(value); }
	else if (code == 4) { vehicles[position]->removeweapon(value); }
	else if (code == 5) { vehicles[position]->modifyms(value); }
	else if (code == 6) { vehicles[position]->modifymp(value); }
	else if (code == 7) { vehicles[position]->modifyhn(value); }
}
void platform::modifyvehicle(int position, int wposition, weapon weapon) { vehicles[position]->modifyweapon(wposition, weapon); }
void platform::modifyvehicle(int position, bool es) { vehicles[position]->modifyes(es); }
void platform::modifypropulsion(int position, int propulsion) { vehicles[position]->modifypropulsion(propulsion); }
void platform::modifymcrew(int position, int maxcrew) { vehicles[position]->modifymaxcrew(maxcrew); }
void platform::modifyprice(int position, int price) { vehicles[position]->modifyprice(price); }


// -- Remove functions --
void platform::removeowner(int position) { delete owners[position]; owners.erase(owners.begin() + position); }
void platform::removevehicle(int position) { delete vehicles[position];  vehicles.erase(vehicles.begin() + position); }


// -- Sell functions --
void platform::sell(string vrn, string rn, date saledate) {
	sale newsale(vrn, rn, saledate);
	sales.push_back(newsale);
}


// -- Check functions --
bool platform::checkowner(string rn) {
	for (unsigned int i = 0; i < owners.size(); i++) {
		if (owners[i]->rrn() == rn) { return 1; } // checks if the given rn is equal to the owner rn
	}
	return 0;
}
bool platform::checkvehicle(string rn) {
	for (unsigned int i = 0; i < vehicles.size(); i++) {
		if (vehicles[i]->rvrn() == rn) { return 1; } // checks if the given rn is equal to the vehicle rn
	}
	return 0;
}
bool platform::checksales(string vrn) {
	for (unsigned int i = 0; i < sales.size(); i++) {
		if (sales[i].rvrn() == vrn) { return 1; } // checks if the given rn is equal to the sold vehicle rn
	}
	return 0;
}

bool platform::checkdate(date d) {
	if (d.month <= 0 || d.month > 12 || d.day <= 0 || d.year <= 0) { return 0; }
	else if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 || d.month == 9 || d.month == 1) {
		if (d.day > 31) { return 0; }
	}
	else if (d.month == 2){
		if (d.year % 4 == 0 && d.year % 100 != 0) { // leap years
			if (d.day > 29) { return 0; }
		}
		else {
			if (d.day > 28) { return 0; }
		}
	}
	else {
		if (d.day > 30) { return 0; }
	}
	return 1;
} 
int platform::checktype(string rn){
    int length = rn.length();
    if (length!=10 && length!=9 && length!=8) return 0; // will only check valid lengths
    int position = 0, check = checkchar(rn.at(position));
    if (check == 1){
        for(int i=1;i<8;i++){ // 9 letters
            check = checkchar(rn.at(i));
            if(check != 1) return 0;
        }
        check = checkchar(rn.at(8));
        if (check == 1 && length == 10){ // + 1 letter = alien
			if (checkchar(rn.at(9)) == 1 && length == 10) return 2;
			else { return 0; }
		}
		else if (check == 2 && length == 9) return 1; // or + 1 number = human
		else return 0;
    } else if (check == 2){ // 1 letter
        for(int i=1;i<5;i++){ // + 4 numbers
            check = checkchar(rn.at(i));
            if(check != 1) return 0;
        }
        for(int i=5;i<8;i++){ // + 3 letters = vehicle
            check = checkchar(rn.at(i));
            if(check != 2) return 0;
        }
        if (length == 8) return 3; else return 0;
    } else return 0;
    return 0;
}
int platform::checkchar(char position){ // Note: solved like this instead of with header <cctype> because we would be using only two functions and the code isnt enlargered as much
    if (position == '0'||position == '1'||position == '2'||position == '3'||position == '4'||position == '5'||position == '6'||position == '7'||position == '8'||position == '9'){
        return 1;
    } else if (position == 'a'||position == 'b'||position == 'c'||position == 'd'||position == 'e'||position == 'f'||position == 'g'||position == 'h'||position == 'i'||position == 'j'||position == 'k'||position == 'l'||position == 'm'||position == 'n'||position == 'o'||position == 'p'||position == 'q'||position == 'r'||position == 's'||position == 't'||position == 'u'||position == 'v'||position == 'w'||position == 'x'||position == 'y'||position == 'z'||position == 'A'||position == 'B'||position == 'C'||position == 'D'||position == 'E'||position == 'F'||position == 'G'||position == 'H'||position == 'I'||position == 'J'||position == 'K'||position == 'L'||position == 'M'||position == 'N'||position == 'Ñ'||position == 'O'||position == 'P'||position == 'Q'||position == 'R'||position == 'S'||position == 'T'||position == 'U'||position == 'V'||position == 'W'||position == 'X'||position == 'Y'||position == 'Z' ){
        return 2;
    } else return 0;
}


// -- Auxiliary functions --
int platform::vehicleposition(string rn) { // Note: will return 3301 if its not registered but shouldnt be called without previous checkvehicle
	int size = vehicles.size();
	for (int i = 0; i < size; i++) {
		if (vehicles[i]->rvrn() == rn) { return i; }
	}
	return 3301;
}
int platform::ownerposition(string rn) { // Note: will return 3301 if its not registered but shouldnt be called without previous checkvehicle
	int size = owners.size();
	for (int i = 0; i < size; i++) {
		if (owners[i]->rrn() == rn) { return i; }
	}
	return 3301;
}

int platform::vsize() { return vehicles.size(); }
int platform::osize() { return owners.size(); }
int platform::ssize() { return sales.size(); }

int platform::destroyerwsize(int position) { return vehicles[position]->nweapons(); }

int platform::stationhn(int position) { return vehicles[position]->hn(); }

int platform::checkvehicletype(int position) { return vehicles[position]->checktype(); }


// -- Formatting functions --
string platform::vregister(int position) { return vehicles[position]->reg(); }
string platform::oregister(int position) { return owners[position]->reg(); }
string platform::sregister(int position) { return sales[position].reg(); }
