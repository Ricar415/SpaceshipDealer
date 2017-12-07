#include <iostream>
#include <string>
#include <vector>

#include "platform.hpp"
#include "weapon.hpp"
#include "interface.hpp"
#include "init.hpp"

using namespace std;

// -- Constructor --
interface::interface(platform *platform) { platforme = platform; }

// -- Menu --
void interface::menu() {
	int a;
	bool check, check2;
	do {
		cout << endl << " 0 - Create owner\n 1 - Modify owner\n 2 - Remove owner\n 3 - Create vehicle\n 4 - Modify vehicle\n 5 - Remove vehicle\n 6 - Show list options\n 7 - Sell\n 8 - Load information from external files" << endl << "Introduce option number: ";
		cin >> a;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce option number: ";
			cin >> a;
		}
		cout << endl;
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
			int b;
			cout << endl << "\n\n\n 0 - List registered vehicles\n 1 - List registered owners\n 2 - List performed sales" << endl;
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce option number: ";
				cin >> b;
			} while (cin.fail());
			cout << endl;
			switch (b) {
			case 0:
				cout << endl << "\n\n -List Option Menu-\n 0 - Available vehicles by register number\n 1 - All registered vehicles by register number\n 2 - All registered vehicles by offensive capacity" << endl;
				int c;
				do {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduce option number: ";
					cin >> c;
				} while (cin.fail());
				switch (c) {
				case 0:
					platforme->lavailable();
					check = ask();
					break;
				case 1:
					platforme->lall();
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
				cout << endl << "\n -Sales List Option Menu-\n 0 - List all sales\n 1 - List sales made by owner\n 2 - List sales made in a period of time" << endl;
				do {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduce option number: ";
					cin >> a;
				} while (cin.fail());
				cout << endl;
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
		case 8:
			initfile();
			check = ask();
			break;
		default:
			check = ask();
			break;
		}
	} while (check == 0);
}
void interface::initfile() {
	init TempInit(platforme);
	string VehicleFile, OwnerFile, SaleFile;
	cout << "\n\nIntroduce the names of the files you want to load into the program" << endl;
	cout << "Vehicles file: ";
	cin >> VehicleFile;
	cout << "Owners file: ";
	cin >> OwnerFile;
	cout << "Sales file: ";
	cin >> VehicleFile;
	TempInit.initialize(VehicleFile, OwnerFile, SaleFile);
}
bool interface::ask() {
	bool check;
	string answer;
	do {
		cout << endl << "Do you want to exit the program?";
		cin >> answer;
		if (answer == "Y" || answer == "y" || answer == "YES" || answer == "yes" || answer == "Yes" || answer == "Si" || answer == "si" || answer == "SI" || answer == "s") {
			return 1;
		}
		else if (answer == "N" || answer == "n" || answer == "no" || answer == "No" || answer == "NO") {
			return 0;
		}
		else {
			cerr << "Not a valid answer (Y/N)" << endl;
			check = 0;
		}
	} while (check == 0);
	return 0;
}

// -- List functions --
bool interface::lbydate() {
	bool check = false;
	date start, end;
	cout << "--Introduce time interval--\n-Start date-" << endl;
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Day: ";
		cin >> start.day;
	} while (cin.fail());
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Month: ";
		cin >> start.month;
	} while (cin.fail());
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Year: ";
		cin >> start.year;
	} while (cin.fail());
	cout << endl;
	check = platforme->checkdate(start); // check if valid
	if (check == 0) {
		cerr << "Invalid date" << endl;
		return 0; // loop
	}
	do {
		check = false;
		cout << "\n-End date- " << endl;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Day: ";
			cin >> end.day;
		} while (cin.fail());
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Month: ";
			cin >> end.month;
		} while (cin.fail());
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Year: ";
			cin >> end.year;
		} while (cin.fail());
		check = platforme->checkdate(end); // check if valid
		if (check == 0) cerr << "Invalid date" << endl;
	} while (check == 0);
	cout << endl << "Registered sales between " << start.day << "/" << start.month << "/" << start.year << " and " << end.day << "/" << end.month << "/" << end.year << ":" << endl;
	platforme->lsales(start, end);
	return 1;
}
bool interface::lbyowner() {
	string temp;
	int check;
	do {
		check = 0;
		cout << endl << "Introduce the register number of the owner you want the sales to be displayed (0 to break): ";
		cin >> temp;
		if (temp == "0\0") return 1; // Default break
		check = platforme->checktype(temp);
		if (check == 1 || check == 2) { // if an owner rn check if registered
			check = platforme->checkowner(temp);
			cerr << "Not a registered owner" << endl;
		}
		else cerr << "Invalid type" << endl;
	} while (check == 0);
	platforme->lbyowner(temp);
	return 1;
}

void interface::showweapons(string vrn) {
	int position = platforme->vehicleposition(vrn);
	platforme->showweapons(position);
}

// -- Create functions --
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
			cout << "\nHuman with register number " << rn << " has been created" << endl;
			return 1;
		}
		else {
			cerr << "A human with the given register number already exists" << endl;
			return 0;
		}
	}
	else if (type == 2) {
		check = platforme->checkowner(rn);
		if (check == 0) {
			platforme->createalien(rn);
			cout << "\nAlien with register number " << rn << " has been created" << endl;
			return 1;
		}
		else {
			cerr << "An alien with the given register number already exists" << endl;
			return 0;
		}
	}
	else {
		cerr << "Invalid register number" << endl;
		return 0; // loop
	}
	return 1; // Wont happen
}
bool interface::createvehicle() { // 1.Carrier 2.Destroyer 3.Fighter 4.Station
	int type = 0, check = 0, price, maxcrew, propulsion;
	bool eshield;
	vector<weapon> weapons;
	string rn;
	do {
		cout << "\n- Create vehicle -\n\t1\tCarrier\n\t2\tDestroyer\n\t3\tFighter\n\t4\tStation" << endl;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce type: ";
			cin >> type;
		} while (cin.fail());
		if (type == 0) return 1; /* Default break */ else if (type == 1 || type == 2 || type == 3 || type == 4) check = 1; else {
			cerr << "-Invalid introduced type-" << endl;
			check = 0;
		}
	} while (check == 0);
	do {
		cout << "Introduce the vehicle register number: ";
		cin >> rn;
		if (rn == "0\0") return 1; //Default break
		check = platforme->checktype(rn);
		if (check == 3) {
			check = platforme->checkvehicle(rn);
			if (check == 1) cerr << "Register number already in use" << endl;
		}
		else {
			cerr << "Invalid register number" << endl;
			check = 1;
		}
	} while (check == 1);
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduce price: ";
		cin >> price;
	} while (cin.fail() || price <= 0);
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduce propulsion type (1.Warp drive 2.Trace compressor 3. FTL engine 4. Solar sails 5. Ion engine): ";
		cin >> propulsion;
	} while (cin.fail() || propulsion <= 0 || propulsion > 5);
	if (type != 3) {
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce the maximum crew number: ";
			cin >> maxcrew;
		} while (cin.fail() || maxcrew <= 0);
	}
	if (type == 1 || type == 4) {
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce wether or not there is energy shield (1/0): ";
			cin >> eshield;
		} while (cin.fail());
	}
	switch (type) {
	case 4:
		int maxp, hn;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce the maximum number of passengers: ";
			cin >> maxp;
		} while (cin.fail() || maxp < 0);
		if (maxp == 0) return 1; // Default break
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce the number of hangars: ";
			cin >> hn;
		} while (cin.fail() || hn < 0);
		if (hn == 0) return 1; // Default break
		platforme->createstation(maxp, hn, eshield, propulsion, maxcrew, price, rn);
		cout << "\nVehicle was successfully created\n";
		return 1;
		break;
	case 1:
		int ml, cs;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce the maximum load capacity: ";
			cin >> ml;
		} while (cin.fail() || ml < 0);
		if (ml == 0) return 1; // Default break
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce cruising speed: ";
			cin >> cs;
		} while (cin.fail() || cs < 0);
		if (cs == 0) return 1; // Default break
		platforme->createcarrier(ml, cs, eshield, propulsion, maxcrew, price, rn);
		cout << "\nVehicle was successfully created\n";
		return 1;
		break;
	case 2:
		int size;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce the number of weapons: ";
			cin >> size;
		} while (cin.fail() || size < 0);
		for (int i = 0; i < size; i++) {
			int a = 0;
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce the type of weapon (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15))" << i << ": "; // 1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)
				cin >> a;
			} while (cin.fail() || a < 0 || a > 4);
			if (a == 0) return 1; // Default break
			weapon b(a);
			weapons.push_back(b);
		}
		platforme->createdestroyer(weapons, propulsion, maxcrew, price, rn);
		cout << "\nVehicle was successfully created\n";
		return 1;
		break;
	case 3:
		int ms, weapon1t, weapon2t;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce the maximum speed: ";
			cin >> ms;
		} while (cin.fail() || ms < 0);
		if (ms == 0) return 1; // Default break
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce the first weapon type (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)): ";
			cin >> weapon1t;
		} while (cin.fail() || weapon1t < 0 || weapon1t > 4);
		if (weapon1t == 0) return 1; // Default break
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce the second weapon type (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)): ";
			cin >> weapon2t;
		} while (cin.fail() || weapon2t < 0 || weapon2t > 4);
		if (weapon2t == 0) return 1; // Default break
		weapon weapon1(weapon1t), weapon2(weapon2t);
		platforme->createfighter(ms, propulsion, price, weapon1, weapon2, rn);
		cout << "\nVehicle was successfully created\n";
		return 1;
		break;
	}
	return 0;
}

// -- Modify functions --
bool interface::modifyowner() {
	string rn, nrn;
	int a = 0, position;
	bool check;
	cout << "Introduce owner's register number (0 to break):";
	cin >> rn;
	if (rn == "0\0") return 1; // Default break
	a = platforme->checktype(rn);
	if (a == 1 || a == 2) {
		check = platforme->checkowner(rn);
		if (check == 0) {
			cerr << "Introduced register number doesnt correspond to a registered owner" << endl;
			return 0; // loop
		}
		else {
			position = platforme->ownerposition(rn);
		}
	}
	else { return 0; } // loop
	do {
		cout << "Introduce owner's new register number (0 to break):";
		cin >> nrn;
		if (nrn == "0\0") return 1; // Default break
		a = platforme->checktype(nrn);
		if (a == 1 || a == 2) {
			platforme->modifyowner(position, nrn);
			cout << "\nChange has been successfully made\n";
		}
		else cerr << "Invalid register number" << endl;
	} while (a != 1 && a != 2);
	return 1;
}
bool interface::modifyvehicle() {
	string vrn, nvrn;
	weapon d;
	int check = 0, price, maxcrew, propulsion, position, type, ask, value, code = 0, pos;
	bool es;
	cout << "Introduce the register number of the vehicle you want to modify (0 to break): ";
	cin >> vrn;
	if (vrn == "0\0") return 1; // Default break
	check = platforme->checktype(vrn);
	if (check != 3) cerr << "Invalid register number" << endl; return 0;
	check = platforme->checkvehicle(vrn);
	if (check == 0) cerr << "Not a registered vehicle" << endl;  return 0; // Default loop
	position = platforme->vehicleposition(vrn);
	type = platforme->checkvehicletype(position);
	if (type == 1) {
		cout << "\n\n 1 - Change register number \n 2 - Change cruising speed \n 3 - Change maximum load \n 4 - Remove/Add energy shield\n 5 - Change propulsion type\n 6 - Change maximum crew number\n 7 - Change price" << endl;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce option number: ";
			cin >> ask;
		} while (cin.fail() || ask < 0 || ask > 7);
		if (ask == 0) return 1; // Default break
		cout << endl;
		switch (ask) {
		case 1:
			do {
				cout << "Introduce new register number: ";
				cin >> nvrn;
				if (nvrn == "0\0") return 1;
				if (nvrn == vrn) return 1;
				check = platforme->checkvehicle(nvrn);
				if (check == 1) {
					cerr << "Introduced register number already corresponds to a registered vehicle" << endl;
				}
			} while (check == 1);
			platforme->modifyvehicle(position, nvrn);
			return 1;
			break;
		case 2:
			code = 1;
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce new cruising speed: ";
				cin >> value;
			} while (cin.fail() || value < 0);
			if (value == 0) return 1; // Default break
			platforme->modifyvehicle(position, code, value);
			return 1;
			break;
		case 3:
			code = 2;
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce new maximum load: ";
				cin >> value;
			} while (cin.fail() || value < 0);
			if (value == 0) return 1; // Default break
			platforme->modifyvehicle(position, code, value);
			return 1;
			break;
		case 4:
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce wether or not the vehicle has energy shield (1/0): ";
				cin >> es;
			} while (cin.fail() || (es != 0 && es != 1));
			platforme->modifyvehicle(position, code, es);
			return 1;
			break;
		case 5:
			propulsion = modifypropulsion();
			if (propulsion == 0) return 1; // Default break
			platforme->modifypropulsion(position, propulsion);
			break;
		case 6:
			maxcrew = modifymaxcrew();
			if (maxcrew == 0) return 1; // Default break
			platforme->modifymcrew(position, maxcrew);
			break;
		case 7:
			price = modifyprice();
			if (price == 0) return 1; // Default break
			platforme->modifyprice(position, price);
			break;
		default:
			return 1;
			break;
		}
	}
	else if (type == 2) {
		cout << "\n\n 1 - Change register number \n 2 - Increase number of weapons \n 3 - Change weapon type \n 4 - Remove weapons \n 5 - Change propulsion type\n 6 - Change maximum crew number\n 7 - Change price" << endl;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce option number:  ";
			cin >> ask;
		} while (cin.fail() || ask < 0);
		if (ask == 0) return 1; // Default break
		cout << endl;
		switch (ask) {
		case 1:
			do {
				cout << "Introduce new register number: ";
				cin >> nvrn;
				if (nvrn == "0\0") return 1;
				if (nvrn == vrn) return 1;
				check = platforme->checkvehicle(nvrn);
				if (check == 1) {
					cerr << "Introduced register number already corresponds to a registered vehicle" << endl;
				}
			} while (check == 1);
			platforme->modifyvehicle(position, nvrn);
			return 1;
			break;
		case 2:
			code = 3;
			int add;
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce number of weapons to add: ";
				cin >> add;
			} while (cin.fail() || add < 0);
			if (add == 0) return 1; // Default break
			for (int i = 0; i < add; i++) {
				do {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduce the type of new weapon number " << i + 1 << " (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)): ";
					cin >> value;
				} while (cin.fail() || value < 0);
				if (value == 0) return 1; // Default break
				platforme->modifyvehicle(position, code, value);
			}
			return 1;
			break;
		case 3:
			cout << "Weapon positions >>" << endl;
			showweapons(vrn);
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce the position of the weapon you want to change: ";
				cin >> pos;
			} while (cin.fail() || pos < 0 || pos >= platforme->destroyerwsize(position));
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce the new type of weapon (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)): ";
				cin >> value;
			} while (cin.fail() || value < 0);
			d.modify(value);
			platforme->modifyvehicle(position, pos, d);
			return 1;
			break;
		case 4:
			code = 4;
			cout << "\nWeapon positions >>\n";
			showweapons(vrn);
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce the position of the weapon you want to remove: ";
				cin >> value;
			} while (cin.fail() || value < 0 || value >= platforme->destroyerwsize(position));
			platforme->modifyvehicle(position, code, value);
			return 1;
			break;
		case 5:
			propulsion = modifypropulsion();
			if (propulsion == 0) return 1; // Default break
			platforme->modifypropulsion(position, propulsion);
			break;
		case 6:
			maxcrew = modifymaxcrew();
			if (maxcrew == 0) return 1; // Default break
			platforme->modifymcrew(position, maxcrew);
			break;
		case 7:
			price = modifyprice();
			if (price == 0) return 1; // Default break
			platforme->modifyprice(position, price);
			break;
		default:
			return 1;
			break;
		}
	}
	else if (type == 3) {
		cout << "\n\n 1 - Change register number \n 2 - Change maximum speed \n 3 - Change weapon \n 4 - Change propulsion type\n 5 - Change price" << endl;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce option number: ";
			cin >> ask;
		} while (cin.fail() || ask < 0 || ask > 5);
		if (ask == 0) return 1; // Default break
		cout << endl;
		switch (ask) {
		case 1:
			do {
				cout << "Introduce new register number: ";
				cin >> nvrn;
				if (nvrn == "0\0") return 1;
				if (nvrn == vrn) return 1;
				check = platforme->checkvehicle(nvrn);
				if (check == 1) {
					cerr << "Introduced register number already corresponds to a registered vehicle" << endl;
				}
			} while (check == 1);
			platforme->modifyvehicle(position, nvrn);
			return 1;
			break;
		case 2:
			code = 5;
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce new maximum speed: ";
				cin >> value;
			} while (cin.fail() || value < 0);
			if (value == 0) return 1; // Default break
			platforme->modifyvehicle(position, code, value);
			return 1;
			break;
		case 3:
			cout << "Weapon positions >>" << endl;
			showweapons(vrn);
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce the position of the weapon you want to change: ";
				cin >> pos;
			} while (cin.fail() || pos < 0 || pos > 2);
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce the new type of weapon (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)): ";
				cin >> value;
			} while (cin.fail() || value < 0);
			d.modify(value);
			platforme->modifyvehicle(position, pos, d);
			return 1;
			break;
		case 4:
			propulsion = modifypropulsion();
			if (propulsion == 0) return 1; // Default break
			platforme->modifypropulsion(position, propulsion);
			break;
		case 5:
			price = modifyprice();
			if (price == 0) return 1; // Default break
			platforme->modifyprice(position, price);
			break;
		default:
			return 1;
			break;
		}
	}
	else if (type == 4) {
		cout << "\n\n 1 - Change register number \n 2 - Change maximum passenger number \n 3 - Change number of hangars \n 4 - Remove/Add energy shield \n 5 - Change propulsion type\n 6 - Change maximum crew number\n 7 - Change price" << endl;
		do {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce option number: ";
			cin >> ask;
		} while (cin.fail() || ask < 0 || ask > 7);
		if (ask == 0) return 1; // Default break
		cout << endl;
		switch (ask) {
		case 1:
			do {
				cout << "Introduce new register number: ";
				cin >> nvrn;
				if (nvrn == "0\0") return 1;
				if (nvrn == vrn) return 1;
				check = platforme->checkvehicle(nvrn);
				if (check == 1) {
					cerr << "Introduced register number already corresponds to a registered vehicle" << endl;
				}
			} while (check == 1);
			platforme->modifyvehicle(position, nvrn);
			return 1;
			break;
		case 2:
			code = 6;
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce new maximum passenger number: ";
				cin >> value;
			} while (cin.fail() || value < 0);
			if (value == 0) return 1; // Default break
			platforme->modifyvehicle(position, code, value);
			return 1;
			break;
		case 3:
			code = 7;
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce new number of hangars: ";
				cin >> value;
			} while (cin.fail() || value < 0);
			if (value == 0) return 1; // Default break
			platforme->modifyvehicle(position, code, value);
			return 1;
			break;
		case 4:
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce wether or not the vehicle has energy shield: ";
				cin >> es;
			} while (cin.fail());
			platforme->modifyvehicle(position, code, es);
			return 1;
			break;
		case 5:
			propulsion = modifypropulsion();
			if (propulsion == 0) return 1; // Default break
			platforme->modifypropulsion(position, propulsion);
			return 1;
			break;
		case 6:
			maxcrew = modifymaxcrew();
			if (maxcrew == 0) return 1; // Default break
			platforme->modifymcrew(position, maxcrew);
			return 1;
			break;
		case 7:
			price = modifyprice();
			if (price == 0) return 1; // Default break
			platforme->modifyprice(position, price);
			break;
		default:
			return 1;
			break;
		}
	}
	return 0;
}

int interface::modifypropulsion() {
	int propulsion;
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduce new propulsion type (1.Warp drive 2.Trace compressor 3. FTL engine 4. Solar sails 5. Ion engine): ";
		cin >> propulsion;
	} while (cin.fail() || propulsion < 0 || propulsion > 5);
	return propulsion;
}
int interface::modifymaxcrew() {
	int maxcrew;
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduce new maximum crew: ";
		cin >> maxcrew;
	} while (cin.fail() || maxcrew < 0);
	return maxcrew;
}
int interface::modifyprice() {
	int price;
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduce new price: ";
		cin >> price;
	} while (cin.fail() || price < 0);
	return price;
}


// -- Remove functions --
bool interface::removeowner() {
	string rn;
	int check, position;
	cout << "Introduce the register number of the owner to remove (0 to break): ";
	cin >> rn;
	if (rn == "0\0") return 1; // Default break
	check = platforme->checktype(rn);
	if (check == 1 || check == 2) {
		if (platforme->checkowner(rn) == 0) {
			cerr << "Introduced register number doesnt correspond to a registered owner" << endl;
			return 0;
		}
		else {
			position = platforme->ownerposition(rn);
			platforme->removeowner(position);
			cout << "\nOwner with register number " << rn << " has been successfully removed\n";
			return 1;
		}
	}
	else cerr << "Invalid register number" << endl;  return 0; // loop
}
bool interface::removevehicle() {
	string rn;
	int position;
	cout << "Introduce the register number of the vehicle you want to remove (0 to break): ";
	cin >> rn;
	if (rn == "0\0") return 1; // Default break
	else if (platforme->checktype(rn) == 3) {
		if (platforme->checkvehicle(rn) == 1) {
			position = platforme->vehicleposition(rn);
			platforme->removevehicle(position);
			return 1;
		}
		else cerr << "Not a registered vehicle" << endl; return 0; // loop
	}
	else cerr << "Invalid register number" << endl; return 0; // loop
}

// -- Sell functions --
bool interface::sell() {
	string rn, vrn;
	int check, otype, vtype;
	cout << "Introduce owner register number (0 to break): ";
	cin >> rn;
	if (rn == "0\0") return 1; // Default break
	check = platforme->checktype(rn);
	if (check == 1 || check == 2) { check = platforme->checkowner(rn); }
	else cerr << "Invalid register number" << endl;  return 0; // loop
	if (check == 0) cerr << "Not a registered owner" << endl; return 0; // loop
	do {
		cout << "Introduce vehicle register number (0 to break): ";
		cin >> vrn;
		if (vrn == "0\0") return 1; // Default break
		check = platforme->checktype(vrn);
		if (check == 3) {
			check = platforme->checkvehicle(vrn);
			if (check == 1) {
				vtype = platforme->checkvehicletype(platforme->vehicleposition(vrn));
				otype = platforme->checktype(rn);
				if (otype == 1 && vtype != 2) { check = 1; }
				else if (otype == 2 && vtype != 4) { check = 1; }
				else {
					cerr << "This type of owner is not authorised to buy this type of vehicle" << endl;
					check = 0;
				}
			}
			else cerr << "Not a registered vehicle" << endl;
		}
		else cerr << "Invalid register number" << endl; check = 0;
	} while (check == 0);
	if (platforme->checksales(vrn) == 0) {
		date date;
		do {
			cout << "--Introduce saledate--" << endl;
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Day: ";
				cin >> date.day;
			} while (cin.fail() || date.day < 0);
			if (date.day == 0) return 1; // Default break
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Month: ";
				cin >> date.month;
			} while (cin.fail() || date.month < 0 || date.month > 12);
			if (date.month == 0) return 1; // Default break
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Year: ";
				cin >> date.year;
			} while (cin.fail() || date.year < 0);
			if (date.year == 0) return 1; // Default break
			check = platforme->checkdate(date);
			if (check == 0) cerr << "Invalid date" << endl;
		} while (check == 0);
		platforme->sell(vrn, rn, date);
		cout << endl << "Sale was successfully registered" << endl;
		if (vtype == 4 && otype == 1) {
			int hn = platforme->vehicleposition(vrn);
			do {
				check = addfighter(rn, date, hn);
			} while (check == 0);
		}
		return 1;
	}
	else cerr << "Vehicle is not available" << endl;  return 0; // loop
}
bool interface::addfighter(string rn, date saledate, int hn) {
	int fighteradd;
	int check2;
	string fvrn;
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "You can add fighters to your purchase, the station you bought has " << hn << " hangars, introduce the number of fighters you want to add: ";
		cin >> fighteradd;
	} while (cin.fail() || fighteradd < 0 || fighteradd > hn);
	for (int i = 0; i < fighteradd; i++) {
		do {
			cout << "Introduce the register number of fighter number " << i + 1 << ": ";
			cin >> fvrn;
			if (fvrn == "0\0") return 1;
			check2 = platforme->checktype(fvrn);
			if (check2 == 3) {
				check2 = platforme->checkvehicle(fvrn);
				if (check2 == 1) {
					check2 = platforme->checkvehicletype(platforme->vehicleposition(fvrn));
					if (check2 == 3) {
						if (platforme->checksales(fvrn) == 0) { check2 = 1; }
						else cerr << "Introduced vehicle is not available" << endl; check2 = 0;
					}
					else cerr << "Not a fighter" << endl; check2 = 0;
				}
				else cerr << "Not a registered vehicle" << endl; check2 = 0;
			}
			else cerr << "Invalid register number" << endl; check2 = 0;
		} while (check2 == 0);
		platforme->sell(fvrn, rn, saledate);
		cout << endl << "Sale was successfully registered" << endl;
	}
	return 1;
}