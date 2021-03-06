#include "init.hpp"

init::init(platform *_platforme) { platforme = _platforme; }

void init::initialize() { // Note: any non-valid parameter will make the program to ignore the following text in the file
	cout << "Initializing registered values..." << endl << endl;
	ifstream owner("OwnerRegister.txt");
	if (!owner) { cerr << "Error: No owner register files encountered" << endl; }
	else {
		string rn, planet;
		int i = 0;
		owner.seekg(0, ios_base::end);
		streamoff len = owner.tellg(); // get the lenght of the file to check if it is 0
		owner.seekg(0, ios_base::beg); // returns to the beginning of the file before reading values
		if (len == 0) { cerr << "Error: empty file" << endl; owner.ignore(); }
		while (!owner.eof()) { // duplication of the last line due to this practise will be ignored because no two owners can have the same rn
			owner >> rn >> planet;
			if (platforme->checktype(rn) == 1 && platforme->checkowner(rn) == 0) { platforme->createhuman(rn, planet); i++; }
			else if (platforme->checktype(rn) == 2 && platforme->checkowner(rn) == 0) { platforme->createalien(rn, planet); i++; }
			else if (platforme->checktype(rn) != 2 && platforme->checktype(rn) != 1) cerr << "Error: corrupted data encountered" << endl;
		}
		cout << i << " owners initialized" << endl;
	}
	owner.close();
	ifstream vehicle("VehicleRegister.txt");
	if (!vehicle) { cerr << "Error: No vehicle register files encountered" << endl; }
	else {
		string vrn, owner;
		int ii = 0, type, price, maxcrew, propulsion, maxload, maxp, hn, cs, size, wtype, maxspeed, wt1, wt2;
		bool es;
		vector<weapon> weapons;
		weapon w1(1), w2(2);
		vehicle.seekg(0, ios_base::end);
		streamoff len = vehicle.tellg(); // get the lenght of the file to check if it is 0
		vehicle.seekg(0, ios_base::beg); // returns to the beginning of the file before reading values
		if (len == 0) { cerr << "Error: empty file" << endl; vehicle.ignore(); } // ignore the first read of vehicle so that eof flag can be set to 1 and the program doesnt enter in the while loop
		while (!vehicle.eof()) { // duplication of the last line due to this practise will be ignored because no two vehicles can have the same rn
			vehicle >> vrn >> owner >> type >> propulsion >> maxcrew >> price;
			if (platforme->checktype(vrn) != 3 && !vehicle.fail()) { cerr << "Error: corrupted data encountered" << endl;  type = 5; }
			if (vehicle.fail()) type = 5;
			if (platforme->checkvehicle(vrn) == 1) { type = 5; }
			if (platforme->checktype(owner) != 1 && platforme->checktype(owner) != 2) {
				cerr << "Error: corrupted data encountered" << endl;
				type = 5;
			}
			if (platforme->checkowner(owner) == 0) {
				cerr << "Error: vehicle with unregistered owner" << endl;
				type = 5;
			}
			switch (type) {
			case 1:
				vehicle >> maxload >> es >> cs;
				if (!vehicle.fail()) { platforme->createcarrier(maxload, cs, es, propulsion, maxcrew, price, owner, vrn); ii++; }
				break;
			case 2:
				vehicle >> size;
				weapons.clear(); // Important so that if there is more than one destroyer the weapons dont stack each loop
				for (int i = 0; i < size; i++) {
					vehicle >> wtype;
					weapon a(wtype);
					weapons.push_back(a);
				}
				if (!vehicle.fail()) {
					platforme->createdestroyer(weapons, propulsion, maxcrew, price, owner, vrn);
					ii++;
				}
				break;
			case 3:
				vehicle >> maxspeed >> wt1 >> wt2;
				w1.modify(wt1);
				w2.modify(wt2);
				if (!vehicle.fail()) { platforme->createfighter(maxspeed, propulsion, price, w1, w2, owner, vrn); ii++; }
				break;
			case 4:
				vehicle >> maxp >> hn >> es;
				if (!vehicle.fail()) { platforme->createstation(maxp, hn, es, propulsion, maxcrew, price, owner, vrn); ii++; }
				break;
			case 5:
				break;
			}
		}
		cout << ii << " vehicles initialized" << endl;
	}
	vehicle.close();
	ifstream sale("SaleRegister.txt");
	if (!sale) { cerr << "Error: No sale register files encountered" << endl; }
	else {
		string rn, vrn;
		int i = 0, rntype, vrntype;
		bool checksold, checkrn, checkvrn, checkdate;
		date date;
		sale.seekg(0, ios_base::end);
		streamoff len = sale.tellg(); // get the lenght of the file to check if it is 0
		sale.seekg(0, ios_base::beg); // returns to the beginning of the file before reading values
		if (len == 0) { cerr << "Error: empty file" << endl; sale.ignore(); }
		while(!sale.eof()) { // duplication of the last line due to this practise will be ignored because no two sales can have the same vehicle rn
			sale >> vrn >> rn >> date.day >> date.month >> date.year;
			rntype = platforme->checktype(rn);
			vrntype = platforme->checktype(vrn);
			checkdate = platforme->checkdate(date);
			checkrn = platforme->checkowner(rn);
			checkvrn = platforme->checkvehicle(vrn);
			checksold = platforme->checksales(vrn);
			if (checkrn == 1 && checkvrn == 1 && checksold == 0 && vrntype == 3 && checkdate == 1 && (rntype == 1 || rntype == 2) && !sale.fail()) {
				platforme->sell(vrn, rn, date);
				i++;
			}
			else if (checkrn == 0 && !sale.fail()) { cerr << "Error: Sale with unregistered owner" << endl; }
			else if (checkvrn == 0 && !sale.fail()) { cerr << "Error: Sale with unregistered vehicle" << endl; }
			else if (checksold == 1 && !sale.fail()) { cerr << "Error: Repeated sale" << endl; }
			else if (checkdate == 0 || (rntype != 1 && rntype != 2) || vrntype != 3) cerr << "Error: corrupted data encountered" << endl;
		}
		cout << i << " sales initialized" << endl;
	}
	sale.close();
}
void init::initialize(string VehicleFile, string OwnerFile, string SaleFile) {
	cout << "Initializing registered values..." << endl << endl;
	ifstream owner(OwnerFile.c_str());
	if (!owner) { cerr << "Error: No owner register files encountered" << endl; }
	else {
		string rn, planet;
		int i = 0;
		owner.seekg(0, ios_base::end);
		streamoff len = owner.tellg(); // get the lenght of the file to check if it is 0
		owner.seekg(0, ios_base::beg); // returns to the beginning of the file before reading values
		if (len == 0) { cerr << "Error: empty file" << endl; owner.ignore(); }
		while (!owner.eof()) { // duplication of the last line due to this practise will be ignored because no two owners can have the same rn
			owner >> rn >> planet;
			if (platforme->checktype(rn) == 1 && platforme->checkowner(rn) == 0) { platforme->createhuman(rn, planet); i++; }
			else if (platforme->checktype(rn) == 2 && platforme->checkowner(rn) == 0) { platforme->createalien(rn, planet); i++; }
			else if (platforme->checktype(rn) != 2 && platforme->checktype(rn) != 1) cerr << "Error: corrupted data encountered" << endl;
		}
		cout << i << " owners initialized" << endl;
	}
	owner.close();
	ifstream vehicle(VehicleFile.c_str());
	if (!vehicle) { cerr << "Error: No vehicle register files encountered" << endl; }
	else {
		string vrn, owner;
		int ii = 0, type, price, maxcrew, propulsion, maxload, maxp, hn, cs, size, wtype, maxspeed, wt1, wt2;
		bool es;
		vector<weapon> weapons;
		weapon w1(1), w2(2);
		vehicle.seekg(0, ios_base::end);
		streamoff len = vehicle.tellg(); // get the lenght of the file to check if it is 0
		vehicle.seekg(0, ios_base::beg); // returns to the beginning of the file before reading values
		if (len == 0) { cerr << "Error: empty file" << endl; vehicle.ignore(); } // ignore the first read of vehicle so that eof flag can be set to 1 and the program doesnt enter in the while loop
		while (!vehicle.eof()) { // duplication of the last line due to this practise will be ignored because no two vehicles can have the same rn
			vehicle >> vrn >> owner >> type >> propulsion >> maxcrew >> price;
			if (platforme->checktype(vrn) != 3 && !vehicle.fail()) { cerr << "Error: corrupted data encountered" << endl;  type = 5; }
			if (vehicle.fail()) type = 5;
			if (platforme->checkvehicle(vrn) == 1) { type = 5; }
			if (platforme->checktype(owner) != 1 && platforme->checktype(owner) != 2) {
				cerr << "Error: corrupted data encountered" << endl;
				type = 5;
			}
			if (platforme->checkowner(owner) == 0) {
				cerr << "Error: vehicle with unregistered owner" << endl;
				type = 5;
			}
			switch (type) {
			case 1:
				vehicle >> maxload >> es >> cs;
				if (!vehicle.fail()) { platforme->createcarrier(maxload, cs, es, propulsion, maxcrew, price, owner, vrn); ii++; }
				break;
			case 2:
				vehicle >> size;
				weapons.clear(); // Important so that if there is more than one destroyer the weapons dont stack each loop
				for (int i = 0; i < size; i++) {
					vehicle >> wtype;
					weapon a(wtype);
					weapons.push_back(a);
				}
				if (!vehicle.fail()) {
					platforme->createdestroyer(weapons, propulsion, maxcrew, price, owner, vrn);
					ii++;
				}
				break;
			case 3:
				vehicle >> maxspeed >> wt1 >> wt2;
				w1.modify(wt1);
				w2.modify(wt2);
				if (!vehicle.fail()) { platforme->createfighter(maxspeed, propulsion, price, w1, w2, owner, vrn); ii++; }
				break;
			case 4:
				vehicle >> maxp >> hn >> es;
				if (!vehicle.fail()) { platforme->createstation(maxp, hn, es, propulsion, maxcrew, price, owner, vrn); ii++; }
				break;
			case 5:
				break;
			}
		}
		cout << ii << " vehicles initialized" << endl;
	}
	vehicle.close();
	ifstream sale(SaleFile.c_str());
	if (!sale) { cerr << "Error: No sale register files encountered" << endl; }
	else {
		string rn, vrn;
		int i = 0, rntype, vrntype;
		bool checksold, checkrn, checkvrn, checkdate;
		date date;
		sale.seekg(0, ios_base::end);
		streamoff len = sale.tellg(); // get the lenght of the file to check if it is 0
		sale.seekg(0, ios_base::beg); // returns to the beginning of the file before reading values
		if (len == 0) { cerr << "Error: empty file" << endl; sale.ignore(); }
		while (!sale.eof()) { // duplication of the last line due to this practise will be ignored because no two sales can have the same vehicle rn
			sale >> vrn >> rn >> date.day >> date.month >> date.year;
			rntype = platforme->checktype(rn);
			vrntype = platforme->checktype(vrn);
			checkdate = platforme->checkdate(date);
			checkrn = platforme->checkowner(rn);
			checkvrn = platforme->checkvehicle(vrn);
			checksold = platforme->checksales(vrn);
			if (checkrn == 1 && checkvrn == 1 && checksold == 0 && vrntype == 3 && checkdate == 1 && (rntype == 1 || rntype == 2) && !sale.fail()) {
				platforme->sell(vrn, rn, date);
				i++;
			}
			else if (checkrn == 0 && !sale.fail()) { cerr << "Error: Sale with unregistered owner" << endl; }
			else if (checkvrn == 0 && !sale.fail()) { cerr << "Error: Sale with unregistered vehicle" << endl; }
			else if (checksold == 1 && !sale.fail()) { cerr << "Error: Repeated sale" << endl; }
			else if (checkdate == 0 || (rntype != 1 && rntype != 2) || vrntype != 3) cerr << "Error: corrupted data encountered" << endl;
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
