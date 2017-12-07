#include <fstream>
#include <iostream>

#include "init.hpp"
#include "sale.hpp"
#include "vehicle.hpp"
#include "owner.hpp"
#include "platform.hpp"
#include "weapon.hpp"

init::init(platform *_platforme) { platforme = _platforme; }

void init::initialize() { // Note: any non-valid parameter will make the program to ignore the following text in the file
	cout << "Initializing registered values..." << endl;
	ifstream vehicle("VehicleRegister.txt");
	if (!vehicle) { cerr << "Error: No vehicle register files encountered" << endl; }
	else {
		string vrn;
		int i = 0, type, price, maxcrew, propulsion, maxload, maxp, hn, cs, size, wtype, maxspeed, wt1, wt2;
		bool es, empty = 0;
		vector<weapon> weapons;
		weapon w1(1), w2(2);
		vehicle.seekg(0, ios_base::end);
		size_t len = vehicle.tellg(); // get the lenght of the file to check if it is 0
		vehicle.seekg(0, ios_base::beg); // returns to the beginning of the file before reading values
		if (len == 0) {
			cerr << "Error: empty file" << endl;
		}
		while (!vehicle.eof()) {
			vrn = " ";
			vehicle >> vrn >> type >> propulsion >> maxcrew >> price;
			if (platforme->checktype(vrn) != 3) {
				type = 5;
			}
			switch (type) {
			case 1 :
				vehicle >> maxload >> es >> cs;
				platforme->createcarrier(maxload, cs, es, propulsion, maxcrew, price, vrn);
				break;
			case 2:
				vehicle >> size;
				weapons.clear(); // Important so that if there is more than one destroyer the weapons dont stack each loop
				for (int i = 0; i < size; i++) {
					vehicle >> wtype;
					weapon a(wtype);
					weapons.push_back(a);
				}
				platforme->createdestroyer(weapons, propulsion, maxcrew, price, vrn);
				break;
			case 3:
				vehicle >> maxspeed >> wt1 >> wt2;
				w1.modify(wt1);
				w2.modify(wt2);
				platforme->createfighter(maxspeed, propulsion, price, w1, w2, vrn);
				break;
			case 4:
				vehicle >> maxp >> hn >> es;
				platforme->createstation(maxp, hn, es, propulsion, maxcrew, price, vrn);
			case 5:
				i--;
				break;
			default:
				cerr << "Error: Corrupted register" << endl;
				i--;
				break;
			}
			i++;
		}
		cout << i << " vehicles initialized" << endl;
	}
	vehicle.close();
	ifstream owner("OwnerRegister.txt");
	if (!owner) { cerr << "Error: No owner register files encountered" << endl; }
	else {
		string rn;
		int type, i = 0;
		bool check, empty = 0;
		while (!owner.eof()) {
			owner >> rn;
			if (rn == "") {
				cerr << "Error: Empty file" << endl;
				i--;
				empty = 1;
			}
			type = platforme->checktype(rn);
			check = platforme->checkowner(rn);
			if (type == 1 && check == 0) {
				platforme->createhuman(rn);
			}
			else if (type == 2 && check == 0) {
				platforme->createalien(rn);
			}
			else if (empty == 0 && type == 0){
				cerr << "Error: Corrupted register" << endl;
				i--;
			}
			i++;
		}
		cout << i << " owners initialized" << endl;
	}
	owner.close();
	ifstream sale("SaleRegister.txt");
	if (!sale) { cerr << "Error: No sale register files encountered" << endl; }
	else {
		string rn, vrn;
		int i = 0;
		bool checksold, checkrn, checkvrn, empty = 0;
		date date;
		while(!sale.eof()) {
			sale >> vrn >> rn >> date.day >> date.month >> date.year;
			if (vrn == "") {
				cerr << "Error: Empty file" << endl;
				empty = 1;
				i--;
			}
			checkrn = platforme->checkowner(rn);
			checkvrn = platforme->checkvehicle(vrn);
			checksold = platforme->checksales(vrn);
			if (checkrn == 1 && checkvrn == 1 && checksold == 0) {
				platforme->sell(vrn, rn, date);
			} else if (empty == 0){
				if (checkrn == 0) {
					cerr << "Error: Sale with unregistered owner" << endl;
					i--;
				}
				else if (checkvrn == 0) {
					cerr << "Error: Sale with unregistered vehicle" << endl;
					i--;
				}
				else if (checksold == 1) {
					cerr << "Error: Repeated sale" << endl;
					i--;
				}
			}
			i++;
		}
		cout << i << " sales initialized" << endl;
	}
	sale.close();
}
void init::initialize(string VehicleFile, string OwnerFile, string SaleFile) {
	cout << "Initializing registered values..." << endl;
	ifstream vehicle(VehicleFile);
	if (!vehicle) { cerr << "Error: No vehicle register files encountered" << endl; }
	else {
		string vrn;
		int i = 0, type, price, maxcrew, propulsion, maxload, maxp, hn, cs, size, wtype, maxspeed, wt1, wt2;
		bool es, empty = 0;
		vector<weapon> weapons;
		weapon w1(1), w2(2);
		vehicle.seekg(0, ios_base::end);
		size_t len = vehicle.tellg(); // get the lenght of the file to check if it is 0
		vehicle.seekg(0, ios_base::beg); // returns to the beginning of the file before reading values
		if (len == 0) {
			cerr << "Error: empty file" << endl;
		}
		while (!vehicle.eof()) {
			vrn = " ";
			vehicle >> vrn >> type >> propulsion >> maxcrew >> price;
			if (platforme->checktype(vrn) != 3) {
				type = 5;
			}
			switch (type) {
			case 1:
				vehicle >> maxload >> es >> cs;
				platforme->createcarrier(maxload, cs, es, propulsion, maxcrew, price, vrn);
				break;
			case 2:
				vehicle >> size;
				weapons.clear(); // Important so that if there is more than one destroyer the weapons dont stack each loop
				for (int i = 0; i < size; i++) {
					vehicle >> wtype;
					weapon a(wtype);
					weapons.push_back(a);
				}
				platforme->createdestroyer(weapons, propulsion, maxcrew, price, vrn);
				break;
			case 3:
				vehicle >> maxspeed >> wt1 >> wt2;
				w1.modify(wt1);
				w2.modify(wt2);
				platforme->createfighter(maxspeed, propulsion, price, w1, w2, vrn);
				break;
			case 4:
				vehicle >> maxp >> hn >> es;
				platforme->createstation(maxp, hn, es, propulsion, maxcrew, price, vrn);
			case 5:
				i--;
				break;
			default:
				cerr << "Error: Corrupted register" << endl;
				i--;
				break;
			}
			i++;
		}
		cout << i << " vehicles initialized" << endl;
	}
	vehicle.close();
	ifstream owner(OwnerFile);
	if (!owner) { cerr << "Error: No owner register files encountered" << endl; }
	else {
		string rn;
		int type, i = 0;
		bool check, empty = 0;
		while (!owner.eof()) {
			owner >> rn;
			if (rn == "") {
				cerr << "Error: Empty file" << endl;
				i--;
				empty = 1;
			}
			type = platforme->checktype(rn);
			check = platforme->checkowner(rn);
			if (type == 1 && check == 0) {
				platforme->createhuman(rn);
			}
			else if (type == 2 && check == 0) {
				platforme->createalien(rn);
			}
			else if (empty == 0 && type == 0) {
				cerr << "Error: Corrupted register" << endl;
				i--;
			}
			else {
				i--;
			}
			i++;
		}
		cout << i << " owners initialized" << endl;
	}
	owner.close();
	ifstream sale(SaleFile);
	if (!sale) { cerr << "Error: No sale register files encountered" << endl; }
	else {
		string rn, vrn;
		int i = 0;
		bool checksold, checkrn, checkvrn, empty = 0;
		date date;
		while (!sale.eof()) {
			sale >> vrn >> rn >> date.day >> date.month >> date.year;
			if (vrn == "") {
				cerr << "Error: Empty file" << endl;
				empty = 1;
				i--;
			}
			checkrn = platforme->checkowner(rn);
			checkvrn = platforme->checkvehicle(vrn);
			checksold = platforme->checksales(vrn);
			if (checkrn == 1 && checkvrn == 1 && checksold == 0) {
				platforme->sell(vrn, rn, date);
			}
			else if (empty == 0) {
				if (checkrn == 0) {
					cerr << "Error: Sale with unregistered owner" << endl;
					i--;
				}
				else if (checkvrn == 0) {
					cerr << "Error: Sale with unregistered vehicle" << endl;
					i--;
				}
				else if (checksold == 1) {
					cerr << "Error: Repeated sale" << endl;
					i--;
				}
			}
			i++;
		}
		cout << i << " sales initialized" << endl;
	}
	sale.close();
}

void init::registry() { // Note: files are overwritten with the new status each complete program execution
	ofstream vehicle("VehicleRegister.txt");
	for (int i = 0; i < platforme->vsize(); i++) {
		vehicle << platforme->vregister(i);
	}
	vehicle.close();
	ofstream owner("OwnerRegister.txt");
	for (int i = 0; i < platforme->osize(); i++) {
		owner << platforme->oregister(i);
	}
	owner.close();
	ofstream sale("SaleRegister.txt");
	for (int i = 0; i < platforme->ssize(); i++) {
		sale << platforme->sregister(i);
	}
	sale.close();
}