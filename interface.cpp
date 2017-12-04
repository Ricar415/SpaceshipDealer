#include <string>
#include "interface.hpp"
#include <iostream>
#include <vector>
#include "platform.hpp"
#include "weapon.hpp"

using namespace std;
interface::interface(platform *platform) {
	platforme = platform;
}
void interface::menu() { //main conducting part of the user interface
	int a;
	bool check, check2;
	do {
		cout << endl << " 0 - Create owner\n 1 - Modify owner\n 2 - Remove owner\n 3 - Create vehicle\n 4 - Modify vehicle\n 5 - Remove vehicle\n 6 - Show list options\n 7 - Sell\nOption number:  ";
		cin >> a;
		switch (a) {
		case 0:
			do {
				check2 = createowner();
			} while (check2 == 0);
			check = ask();
			break;
		case 1:
			do {
				check2 = modifyowner();
			} while (check2 == 0);
			check = ask();
			break;
		case 2:
			do {
				check2 = removeowner();
			} while (check2 == 0);
			check = ask();
			break;
		case 3:
			do {
				check2 = createvehicle();
			} while (check2 == 0);
			check = ask();
			break;
		case 4:
			do {
				check2 = modifyvehicle();
			} while (check2 == 0);
			check = ask();
			break;
		case 5:
			do {
				check2 = removevehicle();
			} while (check2 == 0);
			check = ask();
			break;
		case 6:
			cout << endl << "\n\n\n 0 - List available vehicles\n 1 - List registered owners\n 2 - List performed sales\nOption number: ";
			int b;
			cin >> b;
			switch (b) {
			case 0:
				cout << endl << "\n\n -List Option Menu-\n 0 - Vehicles by register number\n 1 - Vehicle sale history\n 2 - Vehicles by offensive capacity\nOption number: ";
				int c;
				cin >> c;
				switch (c) {
				case 0:
					platforme->lavailable();
					check = ask();
					break;
				case 1:
					platforme->lsales();
					check = ask();
					break;
				case 2:
					platforme->lbyocapacity();
					check = ask();
					break;
				default:
					check = ask();
					break;
				}
				break;
			case 1:
				platforme->listowners();
				check = ask();
				break;
			case 2:
				int a;
				cout << endl << "\n -Sales List Option Menu-\n 0 - List all sales\n 1 - List sales made by owner\n 2 - List sales made in a period of time\nOption number: ";
				cin >> a;
				switch (a) {
				case 0:
					platforme->lsales();
					break;
				case 1:
					do {
						check2 = lbyowner();
					} while (check2 == 0);
					break;
				case 2:
					do {
						check2 = lbydate();
					} while (check2 == 0);
					break;
				default:
					break;
				}
				check = ask();
				break;
			default:
				check = ask();
				break;
			}
			break;
		case 7:
			do {
				check2 = sell();
			} while (check2 == 0);
			check = ask();
			break;
		default:
			check = ask();
			break;
		}
	} while (check == 0);
}
bool interface::lbydate() {
	bool check, check2;
	date start, end;
	check = false;
	cout << "-Introduce time interval-\nStart date:\nDay: ";
	cin >> start.day;
	cout << "\nMonth: ";
	cin >> start.month;
	cout << "\nYear: ";
	cin >> start.year;
	check = platforme->checkdate(start);
	if (check == 0) {
		return 0; // Default loop
	}
	do{
		check2 = false;
		cout << "\nEnd date:\nDay: ";
		cin >> end.day;
		cout << "\nMonth: ";
		cin >> end.month;
		cout << "\nYear: ";
		cin >> end.year;
		check2 = platforme->checkdate(end);
	} while (check2 == 0);
	cout << endl << "Registered sales between " << start.day << "/" << start.month << "/" << start.year << " and " << end.day << "/" << end.month << "/" << end.year << ":" << endl;
	platforme->lsales(start, end);
	return 1;
} // asks date of start and end and then calls platform::lbydate with given parameters
bool interface::lbyowner() {
	string temp;
	int check;
	do {
		check = 0;
		cout << endl << "Introduce the register number of the owner you want the sales to be displayed (0 to break): ";
		cin >> temp;
		if (temp == "0\0") return 1; // Default break
		check = platforme->checktype(temp);
		if (check == 1 || check == 2) {
			check = platforme->checkowner(temp);
		}
		else {
			return 0; // Default loop
		}
	} while (check == 0);
	platforme->lbyowner(temp);
	return 1;
} // asks the owner to list and then calls platform::lbyowner with given
bool interface::createowner() { //asks register number and then calls platform::createowner after checking the parameters
	string rn;
	int type;
	bool check;
	cout << "Introduce the register number (NNNNNNNNL for human and NNNNNNNNNN for alien)(0 to break):";
	cin >> rn;
	if (rn == "0\0") return 1;
	type = platforme->checktype(rn);
	if (type == 1) {
		check = platforme->checkowner(rn);
		if (check == 0) {
			platforme->createhuman(rn);
			cout << "\nHuman with register number " << rn << " has been created\n" << endl;
			return 1;
		}
		else {
			cout << "\nA human with the given register number already exists\n" << endl;
			return 0;
		}
	}
	else if (type == 2) {
		check = platforme->checkowner(rn);
		if (check == 0) {
			platforme->createalien(rn);
			cout << "\nAlien with register number " << rn << " has been created\n" << endl;
			return 1;
		}
		else {
			cout << "\nAn alien with the given register number already exists\n" << endl;
			return 0;
		}
	}
	else {
		cout << "-- Invalid register number --" << endl;
		return 0; // Default loop
	}
	return 1; // Wont happen
}
bool interface::modifyowner() { // asks owner to modify and new register number and then calls platform::modifyowner after checking the parameters
	string rn, nrn;
	int a = 0;
	int position;
	bool check;
	cout << "Introduce owner's register number (0 to break):";
	cin >> rn;
	if (rn == "0\0") return 1; // Default break
	a = platforme->checktype(rn);
	if (a == 1 || a == 2) {
		check = platforme->checkowner(rn);
		if (check == 0) {
			cout << "\nIntroduced register number doesnt correspond to a registered owner\n";
			return 0; // Default loop
		}
		else {
			position = platforme->ownerposition(rn);
		}
	}
	else { return 0; } // Default loop
	do {
		cout << "Introduce owner's new register number (0 to break):";
		cin >> nrn;
		if (nrn == "0\0") return 1; // Default break
		a = platforme->checktype(nrn);
		if (a == 1 || a == 2) {
			platforme->modifyowner(position,nrn);
			cout << "\nChange has been successfully made\n";
		}
	} while (a != 1 && a != 2);
	return 1; // Wont happen
}
bool interface::removeowner() { // asks owner to remove , checks if it exists, checks its position in platform?s owners vector and calls platform::removeowner(position)
	string rn;
	int check;
	int position;
	cout << "\nIntroduce the register number of the owner to remove (0 to break): ";
	cin >> rn;
	if (rn == "0\0") return 1; // Default break
	check = platforme->checktype(rn);
	if (check == 1 || check == 2) {
		if (platforme->checkowner(rn) == 0) {
			cout << "\nIntroduced register number doesnt correspond to a registered owner\n";
			return 0;
		}
		else {
			position = platforme->ownerposition(rn);
			platforme->removeowner(position);
			cout << "\nOwner with register number " << rn << " has been successfully removed\n";
			return 1;
		}
	}
	else return 0; // Default loop
}
bool interface::createvehicle() {//asks every part of the vehicle information needed and then calls the corresponding creator funcion of platform with given parameters .. 1.Carrier 2.Destroyer 3.Fighter 4.Station
	int type = 0,eshield;
	int check = 0, check2 = 0;
	bool check3;
	vector<weapon> weapons;
	string rn;
	int price, maxcrew, propulsion;
	do {
		cout << "\n- Create vehicle -\nType N list\n\t1\tCarrier\n\t2\tDestroyer\n\t3\tFighter\n\t4\tStation\n\nIntroduce the vehicle type: ";
		cin >> type;
		if (type == 0) return 1; /* Default break */ else if (type == 1 || type == 2 || type == 3 || type == 4) check = 1; else {
			cout << "\n-Invalid introduced type-";
			check = 0;
		}
	} while (check == 0);
	do {
		cout << "\nIntroduce the vehicle register number: ";
		cin >> rn;
		if (rn == "0\0") return 1; //Default break
		check = platforme->checktype(rn);
		if (check == 3) {
			check2 = platforme->checkvehicle(rn);
		} else {
			cout << "\n --Invalid register number--";
			check2 = 1;
		}
	} while (check2 == 1);
	do {
		cout << "\nIntroduce price: ";
		cin >> price;
		if (price <= 0) check = 0; else check = 1;
	} while (check == 0);
	do {
		cout << "\nIntroduce propulsion type(1.Warp drive 2.Trace compressor 3. FTL engine 4. Solar sails 5. Ion engine): ";
		cin >> propulsion;
		if (propulsion <= 0) return 1;
		if (propulsion > 5) check = 0; else check = 1;
	} while (check == 0);
	if (type != 3) {
		do{
			cout << "\nIntroduce the maximum crew number: ";
			cin >> maxcrew;
			if (maxcrew <= 0) check = 0; else check = 1;
		} while (check == 0);
	} 
	if (type == 1 || type == 4) {
		do {
			cout << "\nIntroduce wether or not there is energy shield (1/0): ";
			cin >> eshield;
			if (eshield == 1 || eshield == 0){
				check = 1;
			}
			else {
				check = 0;
			}
		} while (check == 0);
	}
	switch (type) {
	case 4:
		int maxp, hn;
		cout << "\nIntroduce the maximum number of passengers: ";
		cin >> maxp;
		if (maxp == 0) return 1; // Default break
		cout << "\nIntroduce the number of hangars: ";
		cin >> hn;
		if (hn == 0) return 1; // Default break
		platforme->createstation(maxp, hn, eshield, propulsion, maxcrew, price, rn);
		cout << "\nVehicle was successfully created\n";
		return 1;
		break;
	case 1:
		int ml, cs;
		cout << "\nIntroduce the maximum load capacity: ";
		cin >> ml;
		if (ml == 0) return 1; // Default break
		cout << "\nIntroduce cruising speed: ";
		cin >> cs;
		if (cs == 0) return 1; // Default break
		platforme->createcarrier(ml, cs, eshield, propulsion, maxcrew, price, rn);
		cout << "\nVehicle was successfully created\n";
		return 1;
		break;
	case 2:
		int size;
		cout << "\nIntroduce the number of weapons: ";
		cin >> size;
		for (int i = 0; i < size; i++) {
			int a = 0;
			do {
				cout << "\nIntroduce the type of weapon (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15))" << i << ": "; // 1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)
				cin >> a;
				if (a == 0) return 1; /* Default break */ else if (a == 1 || a == 2 || a == 3 || a == 4) {
					check3 = 1;
				}
				else {
					cout << "\n-- Invalid type --";
					check3 = 0;
				}
			} while (check3 == 0);
			weapon b(a);
			weapons.push_back(b);
		}
		platforme->createdestroyer(weapons, propulsion, maxcrew, price, rn);
		cout << "\nVehicle was successfully created\n";
		return 1;
		break;
	case 3:
		int ms,weapon1t,weapon2t;
		cout << "\nIntroduce the maximum speed: ";
		cin >> ms;
		if (ms == 0) return 1; // Default break
		do {
			cout << "\nIntroduce the first weapon type (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)): ";
			cin >> weapon1t;
			if (weapon1t == 0) return 1; /* Default break */ else if (weapon1t == 1 || weapon1t == 2 || weapon1t == 3 || weapon1t == 4) {
				check3 = 1;
			}
			else {
				cout << "\n-- Invalid type --";
				check3 = 0;
			}
		} while (check3 == 0);
		do {
			cout << "\nIntroduce the second weapon type (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)): ";
			cin >> weapon2t;
			if (weapon2t == 0) return 1; /* Default break */ else if (weapon2t == 1 || weapon2t == 2 || weapon2t == 3 || weapon2t == 4) {
				check = 1;
			}
			else {
				cout << "\n-- Invalid type --";
				check = 0;
			}
		} while (check3 == 0);
		weapon weapon1(weapon1t), weapon2(weapon2t);
		platforme->createfighter(ms, propulsion, price, weapon1, weapon2, rn);
		cout << "\nVehicle was successfully created\n";
		return 1;
		break;
	}
	return 0;
}
bool interface::modifyvehicle() { // asks vehicle to remove, lists options depending on type and then calls vehicle::*needed function* with given parameters
	string vrn, nvrn;
	weapon d;
	int price, maxcrew, propulsion;
	bool check = 0, es;
	int position, type, ask, value, code = 0, pos;
	cout << "\nIntroduce the register number of the vehicle you want to modify (0 to break): ";
	cin >> vrn;
	if (vrn == "0\0") return 1; // Default break
	check = platforme->checkvehicle(vrn);
	if (check == 0) return 0; // Default loop
	position = platforme->vehicleposition(vrn);
	type = platforme->checkvehicletype(position);
	if (type == 1) {
		cout << "\n\n 1 - Change register number \n 2 - Change cruising speed \n 3 - Change maximum load \n 4 - Remove/Add energy shield\n 5 - Change propulsion type\n 6 - Change maximum crew number\n 7 - Change price\nIntroduce option number: ";
		cin >> ask;
		if (ask == 0) return 1;
		switch (ask) {
		case 1:
			do {
				cout << "\nIntroduce new register number: ";
				cin >> nvrn;
				if (nvrn == "0\0") return 1;
				if (nvrn == vrn) return 1;
				check = platforme->checkvehicle(nvrn);
				if (check == 1) {
					cout << "\nIntroduced register number already corresponds to a registered vehicle";
				}
			} while (check == 1);
			platforme->modifyvehicle(position, nvrn);
			return 1;
			break;
		case 2:
			code = 1;
			cout << "\nIntroduce new cruising speed: ";
			cin >> value;
			platforme->modifyvehicle(position, code, value);
			return 1;
			break;
		case 3:
			code = 2;
			cout << "\nIntroduce new maximum load: ";
			cin >> value;
			platforme->modifyvehicle(position, code, value);
			return 1;
			break;
		case 4:
			cout << "\nIntroduce wether or not the vehicle has energy shield (1/0): ";
			cin >> es;
			platforme->modifyvehicle(position, code, es);
			return 1;
			break;
		case 5:
			cout << "\nIntroduce new propulsion type (1.Warp drive 2.Trace compressor 3. FTL engine 4. Solar sails 5. Ion engine): ";
			cin >> propulsion;
			platforme->modifypropulsion(position, propulsion);
			return 1;
			break;
		case 6:
			cout << "\nIntroduce new maximum number of crew: ";
			cin >> maxcrew;
			platforme->modifymcrew(position, maxcrew);
			return 1;
			break;
		case 7: cout << "\nIntroduce new price: ";
			cin >> price;
			platforme->modifyprice(position, price);
			break;
		default:
			return 1;
			break;
		}
	}
	else if (type == 2) {
		cout << "\n\n 1 - Change register number \n 2 - Increase number of weapons \n 3 - Change weapon type \n 4 - Remove weapons \n 5 - Change propulsion type\n 6 - Change maximum crew number\n 7 - Change price\nIntroduce option number:  ";
		cin >> ask;
		if (ask == 0) return 1;
		switch (ask) {
		case 1:
			do {
				cout << "\nIntroduce new register number: ";
				cin >> nvrn;
				if (nvrn == "0\0") return 1;
				if (nvrn == vrn) return 1;
				check = platforme->checkvehicle(nvrn);
				if (check == 1) {
					cout << "\nIntroduced register number already corresponds to a registered vehicle";
				}
			} while (check == 1);
			platforme->modifyvehicle(position, nvrn);
			return 1;
			break;
		case 2:
			code = 3;
			int add;
			cout << "\nIntroduce number of weapons to add: ";
			cin >> add;
			for (int i = 0; i < add; i++) {
				do {
					cout << "\nIntroduce the type of new weapon number " << i + 1 << " (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)): ";
					cin >> value;
					if (value == 0) return 1; else if (value == 1 || value == 2 || value == 3 || value == 4) {
						check = 1;
					}
					else {
						cout << "\n --Invalid type--";
						check = 0;
					}
				} while (check == 0);
				platforme->modifyvehicle(position, code, value);
			}
			return 1;
			break;
		case 3:
			cout << "\nWeapon positions >>\n";
			showweapons(vrn);
			cout << "\nIntroduce the position of the weapon you want to change (0 to break): ";
			cin >> pos;
			do {
				cout << "\nIntroduce the new type of weapon (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)): ";
				cin >> value;
				if (value == 0) return 1; else if (value == 1 || value == 2 || value == 3 || value == 4) {
					check = 1;
				}
				else {
					cout << "\n --Invalid type--";
					check = 0;
				}
			} while (check == 0);
			d.modify(value);
			platforme->modifyvehicle(position, code, d);
			return 1;
			break;
		case 4:
			code = 4;
			cout << "\nWeapon positions >>\n";
			showweapons(vrn);
			cout << "\nIntroduce the position of the weapon you want to change (0 to break): ";
			cin >> value;
			platforme->modifyvehicle(position, code, value);
			return 1;
			break;
		case 5:
			cout << "\nIntroduce new propulsion type (1.Warp drive 2.Trace compressor 3. FTL engine 4. Solar sails 5. Ion engine): ";
			cin >> propulsion;
			platforme->modifypropulsion(position, propulsion);
			return 1;
			break;
		case 6:
			cout << "\nIntroduce new maximum number of crew: ";
			cin >> maxcrew;
			platforme->modifymcrew(position, maxcrew);
			return 1;
			break;
		case 7: cout << "\nIntroduce new price: ";
			cin >> price;
			platforme->modifyprice(position, price);
			break;
		default:
			return 1;
			break;
		}
	}
	else if (type == 3) {
		cout << "\n\n 1 - Change register number \n 2 - Change maximum speed \n 3 - Change weapon \n 4 - Change propulsion type\n 5 - Change price\nIntroduce option number: ";
		cin >> ask;
		if (ask == 0) return 1;
		switch (ask) {
		case 1:
			do {
				cout << "\nIntroduce new register number: ";
				cin >> nvrn;
				if (nvrn == "0\0") return 1;
				if (nvrn == vrn) return 1;
				check = platforme->checkvehicle(nvrn);
				if (check == 1) {
					cout << "\nIntroduced register number already corresponds to a registered vehicle";
				}
			} while (check == 1);
			platforme->modifyvehicle(position, nvrn);
			return 1;
			break;
		case 2:
			code = 5;
			cout << "\nIntroduce new maximum speed: ";
			cin >> value;
			platforme->modifyvehicle(position, code, value);
			return 1;
			break;
		case 3:
			cout << "\nWeapon positions >>\n";
			showweapons(vrn);
			cout << "\nIntroduce the position of the weapon you want to change (0 to break): ";
			cin >> pos;
			do {
				cout << "\nIntroduce the new type of weapon (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)): ";
				cin >> value;
				if (value == 0) return 1; else if (value == 1 || value == 2) {
					check = 1;
				}
				else {
					cout << "\n --Invalid type--";
					check = 0;
				}
			} while (check == 0);
			d.modify(value);
			platforme->modifyvehicle(position, pos, d);
			return 1;
			break;
		case 4:
			cout << "\nIntroduce new propulsion type (1.Warp drive 2.Trace compressor 3. FTL engine 4. Solar sails 5. Ion engine): ";
			cin >> propulsion;
			platforme->modifypropulsion(position, propulsion);
			return 1;
			break;
		case 5: cout << "\nIntroduce new price: ";
			cin >> price;
			platforme->modifyprice(position, price);
			break;
		default:
			return 1;
			break;
		}
	}
	else if (type == 4) {
		cout << "\n\n 1 - Change register number \n 2 - Change maximum p \n 3 - Change number of hangars \n 4 - Remove/Add energy shield \n 5 - Change propulsion type\n 6 - Change maximum crew number\n 7 - Change price\nIntroduce option number: ";
		cin >> ask;
		if (ask == 0) return 1;
		switch (ask) {
		case 1:
			do {
				cout << "\nIntroduce new register number: ";
				cin >> nvrn;
				if (nvrn == "0\0") return 1;
				if (nvrn == vrn) return 1;
				check = platforme->checkvehicle(nvrn);
				if (check == 1) {
					cout << "\nIntroduced register number already corresponds to a registered vehicle";
				}
			} while (check == 1);
			platforme->modifyvehicle(position, nvrn);
			return 1;
			break;
		case 2:
			code = 6;
			cout << "\nIntroduce new maximum p: ";
			cin >> value;
			platforme->modifyvehicle(position, code, value);
			return 1;
			break;
		case 3:
			code = 7;
			cout << "\nIntroduce new number of hangars: ";
			cin >> value;
			platforme->modifyvehicle(position, code, value);
			return 1;
			break;
		case 4:
			cout << "\nIntroduce wether or not the vehicle has energy shield (1/0): ";
			cin >> es;
			platforme->modifyvehicle(position, code, es);
			return 1;
			break;
		case 5:
			cout << "\nIntroduce new propulsion type (1.Warp drive 2.Trace compressor 3. FTL engine 4. Solar sails 5. Ion engine): ";
			cin >> propulsion;
			platforme->modifypropulsion(position, propulsion);
			return 1;
			break;
		case 6:
			cout << "\nIntroduce new maximum number of crew: ";
			cin >> maxcrew;
			platforme->modifymcrew(position, maxcrew);
			return 1;
			break;
		case 7: cout << "\nIntroduce new price: ";
			cin >> price;
			platforme->modifyprice(position, price);
			break;
		default:
			return 1;
			break;
		}
	}
	return 0;
}
bool interface::removevehicle() { //asks vehicle to remove and calls platform::removevehicle
	string rn;
	bool check;
	int position;
	cout << "\n Introduce the register number of the vehicle you want to remove (0 to break): ";
	cin >> rn; 
	if (rn == "0\0") return 1; else {
		check = platforme->checkvehicle(rn);
		if (check == 1) {
			position = platforme->vehicleposition(rn);
			platforme->removevehicle(position);
			return 1;
		}
		else return 0;
	}
}
bool interface::ask() {
	bool x;
	string a;
	do {
		cout << "Do you want to exit the program?";
		cin >> a;
		if (a == "Y" || a == "y" || a == "YES" || a == "yes" || a == "Yes" || a == "Si" || a == "si" || a == "SI" || a == "s") {
			return 1;
		}
		else if (a == "N" || a == "n" || a == "no" || a == "No" || a == "NO") {
			return 0;
		}
		else {
			x = 0;
		}
	} while (x == 0);
	return 0;
}
bool interface::sell() {
	string rn,vrn;
	int check,otype,vtype;
	cout << "\nIntroduce owner register number (0 to break): ";
	cin >> rn;
	if (rn == "0\0") return 1; // Default break
	check = platforme->checktype(rn);
	if (check == 1 || check == 2) {
		check = platforme->checkowner(rn);
	}
	else {
		return 0;
	}
	check = 0;
	do {
		cout << "\nIntroduce vehicle register number (0 to break): ";
		cin >> vrn;
		if (vrn == "0\0") return 1; // Default break
		check = platforme->checktype(vrn);
		if (check == 3) {
			check = platforme->checkvehicle(vrn);
			if (check == 1) {
				vtype = platforme->checkvehicletype(platforme->vehicleposition(vrn));
				otype = platforme->checktype(rn);
				if (otype == 1 && vtype != 2) {
					check = 1;
				}
				else if (otype == 2 && vtype != 4){
					check = 1;
				}
				else {
					cout << endl << "This type of owner is not authorised to buy this type of vehicle";
					check = 0;
				}
			}
		}
		else {
			check = 0;
		}
	} while (check == 0);
	if (platforme->checksales(vrn) == 0) {
		date date;
		do {
			cout << "\nIntroduce saledate \nDay: ";
			cin >> date.day;
			cout << "\nMonth: ";
			cin >> date.month;
			cout << "\nYear: ";
			cin >> date.year;
			check = platforme->checkdate(date);
		} while (check == 0);
		platforme->sell(vrn, rn, date);
		cout << endl << "Sale was successfully registered";
		if (vtype == 4 && otype == 1) {
			int hn = platforme->vehicleposition(vrn);
			do {
				check = addfighter(rn, date, hn);
			} while (check == 0);
		}
		return 1;
	}
	else return 0;
}
void interface::showweapons(string vrn) {
	int position = platforme->vehicleposition(vrn);
	platforme->showweapons(position);
}
bool interface::addfighter(string rn, date saledate, int hn) {
	int fighteradd;
	int check2;
	string fvrn;
	cout << endl << "You can add fighters to your purchase, the station you bought has " << platforme->stationhn(hn) << " hangars, introduce the number of fighters you want to add: ";
	cin >> fighteradd;
	for (int i = 0; i < fighteradd; i++) {
		do {
			cout << endl << "Introduce the register number of fighter number " << i + 1 << ": ";
			cin >> fvrn;
			if (fvrn == "0\0") return 1;
			check2 = platforme->checktype(fvrn);
			if (check2 == 3) {
				check2 = platforme->checkvehicle(fvrn);
				if (check2 == 1) {
					check2 = platforme->checkvehicletype(platforme->vehicleposition(fvrn));
					if (check2 == 3) {
						if (platforme->checksales(fvrn) == 0) {
							check2 = 1;
						}
						else {
							cout << endl << "Introduced vehicle is not available";
							check2 = 0;
						}
					}
					else {
						check2 = 0;
					}
				}
				else {
					check2 = 0;
				}
			}
			else {
				cout << endl << "--Invalid register number--";
				check2 = 0;
			}
		} while (check2 == 0);
		platforme->sell(fvrn, rn, saledate);
		cout << endl << "Sale was successfully registered" << endl;
	}
	return 1;
}
