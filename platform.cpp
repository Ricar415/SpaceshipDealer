#include "platform.hpp"
#include <string>
#include "human.hpp"
#include "alien.hpp"
#include <vector>
#include <iostream>
#include "fighter.hpp"
#include "carrier.hpp"
#include "destroyer.hpp"
#include "station.hpp"

using namespace std;
void platform::lavailable() {
	vector<vehicle*> tempvector = vehicles;
	vehicle *temp;
	int type;
	int a;
	for (unsigned int i = 1; i < tempvector.size(); i++) { // Using insertion sorting as we are expecting low amounts of vehicles for testing
		temp = tempvector[i];
		for (a = i - 1; (a >= 0) && (lessthan(a,i)); a--)
		{
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
	int type;
	int a;
	for (unsigned int i = 1; i < tempvector.size(); i++) { // Using insertion sorting as we are expecting low amounts of vehicles for testing
		temp = tempvector[i];
		for (a = i - 1; (a >= 0) && (tempvector[a - 1]->ocapacity() < tempvector[a]->ocapacity()); a--)
		{
			tempvector[a + 1] = tempvector[a];
		}
		tempvector[a + 1] = temp;
	}
	for (unsigned int i = 0; i < tempvector.size(); i++) {
		tempvector[i]->show();
	}
}
bool platform::lessthan(int a, int b) {
	string astring, bstring;
	astring = vehicles[a]->rvrn();
	bstring = vehicles[b]->rvrn();
	for (unsigned int i = 0; i < 9; i++) {
		if (astring.at(i) < bstring.at(i)) {
			return 1;
		}
		else if (astring.at(i) > bstring.at(i)) {
			return 0;
		}
	}
	return 0;
}
void platform::listowners() {
	for (unsigned int i = 0; i < owners.size(); i++) {
		owners[i].show();
	}
}
void platform::lsales() {
	for (unsigned int i = 0; i < sales.size(); i++) {
		sales[i].showsale();
	}
}
int platform::checktype(string rn){ //returns 0 if not a valid register number, 1 if a human rn, 2 if an alien rn and 3 if a vehicle rn;
    int length = rn.length();
    if (length!=10 && length!=9 && length!=8) return 0;
    int position = 0;
    int check = checkchar(rn.at(position));
    if (check == 1){
        for(int i=1;i<8;i++){
            check = checkchar(rn.at(i));
            if(check != 1) return 0;
        }
        check = checkchar(rn.at(8));
        if (check == 1 && length == 10){
			if (checkchar(rn.at(9)) == 1 && length == 10) {
				return 2;
			}
			else {
				return 0;
			}
        } else if (check == 2 && length == 9) {
			return 1;
		}
		else return 0;
    } else if (check == 2){
        for(int i=1;i<5;i++){
            check = checkchar(rn.at(i));
            if(check != 1) return 0;
        }
        for(int i=5;i<8;i++){
            check = checkchar(rn.at(i));
            if(check != 2) return 0;
        }
        if (length == 8) return 3; else return 0;
    } else return 0;
    return 0;
}
int platform::checkchar(char position){ // returns 0 if not a letter or a number, 1 if a number and 2 if a letter.
    if (position == '0'||position == '1'||position == '2'||position == '3'||position == '4'||position == '5'||position == '6'||position == '7'||position == '8'||position == '9'){
        return 1;
    } else if (position == 'a'||position == 'b'||position == 'c'||position == 'd'||position == 'e'||position == 'f'||position == 'g'||position == 'h'||position == 'i'||position == 'j'||position == 'k'||position == 'l'||position == 'm'||position == 'n'||position == 'ñ'||position == 'o'||position == 'p'||position == 'q'||position == 'r'||position == 's'||position == 't'||position == 'u'||position == 'v'||position == 'w'||position == 'x'||position == 'y'||position == 'z'||position == 'A'||position == 'B'||position == 'C'||position == 'D'||position == 'E'||position == 'F'||position == 'G'||position == 'H'||position == 'I'||position == 'J'||position == 'K'||position == 'L'||position == 'M'||position == 'N'||position == 'Ñ'||position == 'O'||position == 'P'||position == 'Q'||position == 'R'||position == 'S'||position == 'T'||position == 'U'||position == 'V'||position == 'W'||position == 'X'||position == 'Y'||position == 'Z' ){
        return 2;
    } else return 0;
}
void platform::createhuman(string rn) { // creates human with given register number and passes it to the owners vector
	human a(rn);
	owners.push_back(a);
}
void platform::createalien(string rn){ // creates alien with given register number and includes it to the owners vector
	alien a(rn);
    owners.push_back(a);
}
bool platform::checkowner(string rn) { // returns 1 if the given register number corresponds to a registered owner and 0 otherwise
	for (unsigned int i = 0; i < owners.size(); i++) {
		if (owners[i].check(rn) == 1) {
			return 1;
		}
	}
	return 0;
}
int platform::ownerposition(string rn) { // returns the position of the given owner in the register vector (will return 3301 if its not registered but shouldnt be called without previous checkowner)
	int size = owners.size();
	for (int i = 0; i < size; i++) {
		if (owners[i].check(rn) == 1) {
			return i;
		}
	}
	return 3301;
}
void platform::modifyowner(int position, string nrn) { // modifies the register number of the given position´s owner
	owners[position].modify(nrn);
}
void platform::removeowner(int position) { //returns 0 if the given rn wasnt found or the process is stopped by the user and 1 if everything went right
	owners.erase(owners.begin()+position);	
}

void platform::removevehicle(int position) {
	vehicles.erase(vehicles.begin() + position);
}
int platform::vehicleposition(string rn) { // returns the position of the given vehicle in the register vector (will return 3301 if its not registered but shouldnt be called without previous checkvehicle)
	int size = vehicles.size();
	for (int i = 0; i < size; i++) {
		if (vehicles[i]->check(rn) == 1) {
			return i;
		}
	}
	return 3301;
}
void platform::createfighter(int ms, int propulsiont, int pricet, weapon weapon1, weapon weapon2, string rn){ // creates a fighter with given parameters and includes it in vehicles vector
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
bool platform::checkvehicle(string rn) { // returns 1 if the vehicle register number is already registered and 0 otherwise
	for (unsigned int i = 0; i < vehicles.size(); i++) {
		if (vehicles[i]->check(rn) == 1) {
			return 1;
		}
	}
	return 0;
}
bool platform::checksales(string vrn) { // returns 1 if the vehicle is already registered in a sale (independently of the owner)
	for (unsigned int i = 0; i < sales.size(); i++) {
		if (sales[i].check(vrn) == 1) {
			return 1;
		}
	}
	return 0;
}
void platform::sell(string vrn, string rn, date saledate) { // creates a sale for this scope and passes it as parameter of the selling function of platform
	sale a(vrn, rn, saledate);
	sales.push_back(a);
}
bool platform::checkdate(date d) {
	if (d.month <= 0 || d.month > 12 ||d.day <= 0 ||d.year <=0) {
		return 0;
	} else if (d.month == 1 ||d.month == 3 || d.month == 5 || d.month == 7 ||d.month == 9 ||d.month == 1) {
		if (d.day > 31) {
			return 0;
		}
	}
	else if (d.month == 2){
		if (d.year % 4 == 0 && d.year % 100 != 0) {
			if (d.day > 29) {
				return 0;
			}
		}
		else {
			if (d.day > 28) {
				return 0;
			}
		}
	}
	else {
		if (d.day > 30) {
			return 0;
		}
	}
	return 1;
} 
int platform::checkvehicletype(int position) {
	return vehicles[position]->checktype();
}

void platform::showweapons(int position) {
	int type = 0, nweapons;
	if (vehicles[position]->checktype() == 3) {
		nweapons = 2;
		cout << "\nWeapon 1 type:: ";
		vehicles[position]->showweapon(1);
		cout << "\nWeapon 2 type: ";
		vehicles[position]->showweapon(2);
	}
	else {
		nweapons = vehicles[position]->nweapons(); // function of destroyer (ask)
		for (int i = 0; i < nweapons; i++) {
			cout << "\nPosition " << i << " weapon type:";
			vehicles[position]->showweapon(i); //function of weapon in vector of destroyer (ask)
		}
	}
}
void platform::lsales(date start, date end) {
	for (unsigned int i = 0; i < sales.size(); i++) {
		if (sales[i].greaterequalthan(start) == 1 && sales[i].greaterequalthan(end) == 0) {
			sales[i].showsale();
		}
	}
}
void platform::lbyowner(string rn) {
	for (unsigned int i = 0; i < sales.size(); i++) {
		if (sales[i].checkowner(rn) == 1) {
			sales[i].showsale();
		}
	}
}
void platform::modifyvehicle(int position, string vrn) {
	vehicles[position]->modifyvrn(vrn);
}
void platform::modifyvehicle(int position, int code, int value) {
	if (code == 1) {
		vehicles[position]->modifycs(value);
	}
	else if (code == 2) {
		vehicles[position]->modifyml(value);
	}
	else if (code == 3) {
		vehicles[position]->addweapon(value);
	}
	else if (code == 4) {
		vehicles[position]->removeweapon(value);
	}
	else if (code == 5) {
		vehicles[position]->modifyms(value);
	}
	else if (code == 6) {
		vehicles[position]->modifymp(value);
	}
	else if (code == 7) {
		vehicles[position]->modifyhn(value);
	}
}
void platform::modifyvehicle(int position, int pos, weapon weapon) {
	vehicles[position]->modifyweapon(pos, weapon);
}
void platform::modifyvehicle(int position, bool es) {
	vehicles[position]->modifyes(es);
}

int platform::stationhn(int position) {
	return vehicles[position]->hn();
}
void platform::modifypropulsion(int position, int npropulsion){
  vehicles[position]->modifypropulsion(npropulsion);
}
void platform::modifymcrew(int position, int nmaxcrew){
  vehicles[position]->modifymaxcrew(nmaxcrew);
}
void platform::modifyprice(int position, int price){
  vehicles[position]->modifyprice(price);
}