#include "init.hpp"
#include "sale.hpp"
#include "vehicle.hpp"
#include "owner.hpp"
#include "platform.hpp"
#include "weapon.hpp"
#include <fstream>
#include <iostream>
init::init(platform *_platforme) {
	platforme = _platforme;
}
void init::initialize() {
	cout << "Initializing registered values..." << endl;
	ifstream vehicle("VehicleRegister.txt");
	if (!vehicle) {
		cerr << "Error: No vehicle register files encountered" << endl;
	}
	else {
		string vrn;
		int i = 0, type, price, maxcrew, propulsion, maxload, maxp, hn, cs, size, wtype, maxspeed, wt1, wt2;
		bool es, empty = 0;
		vector<weapon> weapons;
		weapon w1, w2;
		while (!vehicle.eof()) {
			vehicle >> vrn >> type >> propulsion >> maxcrew >> price;
			if (vrn == "") {
				cerr << "Error: Empty file" << endl;
				empty = 1;
				i--;
			}
			switch (type) {
			case 1 :
				vehicle >> maxload >> es >> cs;
				platforme->createcarrier(maxload, cs, es, propulsion, maxcrew, price, vrn);
				break;
			case 2:
				vehicle >> size;
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
			default: 
				if (empty == 1) break;
				cerr << "Error: Corrupted register" << endl;
				break;
			}
			i++;
		}
		cout << i << " vehicles initialized" << endl;
	}
	vehicle.close();
	ifstream owner("OwnerRegister.txt");
	if (!owner) {
		cerr << "Error: No owner register files encountered" << endl;
	}
	else {
		string rn;
		int type, i = 0;
		bool check, empty = 0;
		while (!owner.eof()) {
			owner >> rn;
			if (rn == "") {
				cerr << "Error: Epty file" << endl;
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
			else if (empty == 0){
				cerr << "Error: Corrupted register" << endl;
			}
			i++;
		}
		cout << i << " owners initialized" << endl;
	}
	owner.close();
	ifstream sale("SaleRegister.txt");
	if (!sale) {
		cerr << "Error: No sale register files encountered" << endl;
	}
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
				}
				else if (checkvrn == 0) {
					cerr << "Error: Sale with unregistered vehicle" << endl;
				}
				else if (checksold == 1) {
					cerr << "Error: Repeated sale" << endl;
				}
			}
			i++;
		}
		cout << i << " sales initialized" << endl;
	}
	sale.close();
}
void init::registry() {
	ofstream vehicle("VehicleRegister.txt");
	ofstream owner("OwnerRegister.txt");
	ofstream sale("SaleRegister.txt");
}