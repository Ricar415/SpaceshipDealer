#include "interface.hpp"

using namespace std;

// -- Constructor --
interface::interface(platform *platform) { platforme = platform; }

// -- Menu --
void interface::menu() {
	int a;
	bool check, check2;
	do {
		cout << endl << " 1 - Create owner\n 2 - Modify owner\n 3 - Remove owner\n 4 - Create vehicle\n 5 - Modify vehicle\n 6 - Remove vehicle\n 7 - Show list options\n 8 - Sell\n 9 - Load information from external files" << endl << endl << "Introduce option number: ";
		cin >> a;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Introduce option number: ";
			cin >> a;
		}
		cout << endl;
		switch (a) {
		case 1:
			do {
				check2 = createowner();
			} while (check2 == 0);
			check = ask();
			break;
		case 2:
			do {
				check2 = modifyowner();
			} while (check2 == 0);
			check = ask();
			break;
		case 3:
			do {
				check2 = removeowner();
			} while (check2 == 0);
			check = ask();
			break;
		case 4:
			do {
				check2 = createvehicle();
			} while (check2 == 0);
			check = ask();
			break;
		case 5:
			do {
				check2 = modifyvehicle();
			} while (check2 == 0);
			check = ask();
			break;
		case 6:
			do {
				check2 = removevehicle();
			} while (check2 == 0);
			check = ask();
			break;
		case 7:
			int b;
			cout << endl << " -- List Option Menu --\n\n 1 - List registered vehicles\n 2 - List registered owners\n 3 - List performed sales" << endl << endl;
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce option number: ";
				cin >> b;
			} while (cin.fail());
			cout << endl;
			switch (b) {
			case 1:
				cout << endl << " - Vehicle List Option Menu -\n\n 1 - Available vehicles by register number\n 2 - All registered vehicles by register number\n 3 - All registered vehicles by offensive capacity\n 4 - Sold vehicles by date" << endl << endl;
				int c;
				do {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduce option number: ";
					cin >> c;
				} while (cin.fail());
				switch (c) {
				case 1:
					platforme->lavailable();
					check = ask();
					break;
				case 2:
					platforme->lall();
					check = ask();
					break;
				case 3:
					platforme->lbyocapacity();
					check = ask();
					break;
				case 4:
					date date;
					do {
						cout << "--Introduce saledate--" << endl;
						do {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Day: ";
							cin >> date.day;
						} while (cin.fail() || date.day < 0);
						do {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Month: ";
							cin >> date.month;
						} while (cin.fail() || date.month < 0 || date.month > 12);
						do {
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Year: ";
							cin >> date.year;
						} while (cin.fail() || date.year < 0);
						check = platforme->checkdate(date);
						if (check == 0) cerr << "Invalid date" << endl;
					} while (check == 0);
					platforme->lfordate(date);
					check = ask();
					break;
				default:
					check = ask();
					break;
				}
				break;
			case 2:
				platforme->listowners();
				check = ask();
				break;
			case 3:
				int a;
				cout << endl << " - Sale List Option Menu -\n\n 1 - List all sales\n 2 - List sales made by owner\n 3 - List sales made in a period of time" << endl << endl;
				do {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Introduce option number: ";
					cin >> a;
				} while (cin.fail());
				cout << endl;
				switch (a) {
				case 1:
					platforme->lsales();
					break;
				case 2:
					do {
						check2 = lbyowner();
					} while (check2 == 0);
					break;
				case 3:
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
		case 8:
			do {
				check2 = sell();
			} while (check2 == 0);
			check = ask();
			break;
		case 9:
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
		cout << endl << "Introduce the NIE/NIF of the owner you want the sales to be displayed (0 to break): ";
		cin >> temp;
		if (temp == "0\0") return 1; // Default break
		check = platforme->checktype(temp);
		if (check == 1 || check == 2) { // if an owner rn check if registered
			check = platforme->checkowner(temp);
			if (check == 0) cerr << "Not a registered owner" << endl;
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
	string rn, planet;
	int type;
	bool check;
	cout << "Introduce the NIE/NIF (NNNNNNNNL for human and NNNNNNNNNN for alien)(0 to break):";
	cin >> rn;
	if (rn == "0\0") return 1;
	type = platforme->checktype(rn);
	if (type == 1) {
		check = platforme->checkowner(rn);
		if (check == 0) {
			cout << "Introduce the planet of origin: ";
			cin >> planet;
			platforme->createhuman(rn, planet);
			cout << "\nHuman with NIE " << rn << " has been created" << endl;
			return 1;
		}
		else {
			cerr << "A human with the NIE already exists" << endl;
			return 0;
		}
	}
	else if (type == 2) {
		check = platforme->checkowner(rn);
		if (check == 0) {
			cout << "Introduce the planet of origin: ";
			cin >> planet;
			platforme->createalien(rn, planet);
			cout << "\nAlien with NIF " << rn << " has been created" << endl;
			return 1;
		}
		else {
			cerr << "An alien with the given NIF already exists" << endl;
			return 0;
		}
	}
	else {
		cerr << "Invalid NIE/NIF" << endl;
		return 0; // loop
	}
	return 1; // Wont happen
}
bool interface::createvehicle() { // 1.Carrier 2.Destroyer 3.Fighter 4.Station
	int type = 0, check = 0, price, maxcrew, propulsion;
	bool eshield;
	vector<weapon> weapons;
	string rn, owner;
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
		check = 0;
		cout << "Introduce the owner's NIE/NIF: ";
		cin >> owner;
		if (platforme->checktype(owner) == 1 || platforme->checktype(owner) == 2) {
			check = platforme->checkowner(owner);
			if (check == 0) cerr << "Not a registered owner" << endl;
		}
		else cerr << "Invalid NIE/NIF" << endl;
	} while (check == 0);
	price = modify(3);
	propulsion = modify(1);
	if (type != 3) maxcrew = modify(2);
	if (type == 1 || type == 4) eshield = modify(6);
	switch (type) {
	case 4:
		int maxp, hn;
		maxp = modify(7);
		if (maxp == 0) return 1; // Default break
		hn = modify(8);
		if (hn == 0) return 1; // Default break
		platforme->createstation(maxp, hn, eshield, propulsion, maxcrew, price, owner, rn);
		cout << "\nVehicle was successfully created\n";
		return 1;
		break;
	case 1:
		int ml, cs;
		ml = modify(5);
		if (ml == 0) return 1; // Default break
		cs = modify(4);
        if (cs == 0) return 1; // Default break
		platforme->createcarrier(ml, cs, eshield, propulsion, maxcrew, price, owner, rn);
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
			a = weapontype();
			if (a == 0) return 1; // Default break
			weapon b(a);
			weapons.push_back(b);
		}
		platforme->createdestroyer(weapons, propulsion, maxcrew, price, owner, rn);
		cout << "\nVehicle was successfully created\n";
		return 1;
		break;
	case 3:
		int ms, weapon1t, weapon2t;
		ms = modify(9);
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
		platforme->createfighter(ms, propulsion, price, weapon1, weapon2, owner, rn);
		cout << "\nVehicle was successfully created\n";
		return 1;
		break;
	}
	return 0;
}

// -- Modify functions --
bool interface::modifyowner() {
	string rn, nrn, planet;
	int a, b, position, ask;
	bool check;
	cout << "Introduce owner's NIF/NIE (0 to break):";
	cin >> rn;
	if (rn == "0\0") return 1; // Default break
	b = platforme->checktype(rn);
	if (b == 1 || b == 2) {
		check = platforme->checkowner(rn);
		if (check == 0) {
			cerr << "Introduced NIF/NIE doesnt correspond to a registered owner" << endl;
			return 0; // loop
		}
		else {
			position = platforme->ownerposition(rn);
		}
	}
	else { return 0; } // loop
	cout << "\n\n - Modification options - \n 1 - Change NIE/NIF\n 2 - Change planet of origin\nIntroduce option number: ";
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduce option number: ";
		cin >> ask;
	} while (cin.fail() || ask < 0 || ask > 2);
	if (ask == 0) return 1; // Default break
	switch (ask) {
	case 1:
		do {
			cout << "Introduce owner's new NIF/NIE (0 to break): ";
			cin >> nrn;
			if (nrn == "0\0") return 1; // Default break
			a = platforme->checktype(nrn);
			if ((a == 1 && b == 1) || (a == 2 && b == 2)) {
				platforme->modifyowner(position, nrn);
				cout << "\nChange has been successfully made\n";
			}
			else cerr << "Invalid NIE/NIF" << endl;
		} while (a != 1 && a != 2);
		return 1;
		break;
	case 2:
		cout << "Introduce owner's new planet of origin (0 to break): ";
		cin >> planet;
		if (planet == "0\0") return 1;
		platforme->modifyowner(position, planet, 0);
		cout << "\nChange has been successfully made\n";
		return 1;
	default:
		return 1;
		break;
	}
	return 0;
}
bool interface::modifyvehicle() {
	string vrn, nvrn, owner;
	weapon w;
    int check = 0, position, nweapons, type, ask, value, pos;
	bool es;
	cout << "Introduce the register number of the vehicle you want to modify (0 to break): ";
	cin >> vrn;
	if (vrn == "0\0") return 1; // Default break
	check = platforme->checktype(vrn);
	if (check != 3) {
		cerr << "Invalid register number" << endl; 
		return 0; 
	}
	check = platforme->checkvehicle(vrn);
	if (check == 0) { 
		cerr << "Not a registered vehicle" << endl;  
		return 0; 
	} // Default loop
	position = platforme->vehicleposition(vrn);
	type = platforme->checkvehicletype(position);
	cout << "\n\n 1 - Change register number \n 2 - Change owner\n 3 - Change propulsion type \n 4 - Change maximum crew number \n 5 - Change price";
	switch (type) {
	case 1:
		cout << "\n 6 - Change cruising speed \n 7 - Change maximum load \n 8 - Remove/Add energy shield" << endl;
		break;
	case 2:
		cout << "\n 6 - Increase number of weapons \n 7 - Change weapon type \n 8 - Remove weapons" << endl;
		break;
	case 3:
		cout << "\n 6 - Change maximum speed \n 7 - Change weapon type " << endl;
		break;
	case 4:
		cout << "\n 6 - Change maximum passenger number \n 7 - Change number of hangars \n 8 - Remove/Add energy shield" << endl;
		break;
	default:
		cerr << "This vehicle has an invalid type and cant be accessed" << endl;
		return 1;
		break;
	}
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduce option number: ";
		cin >> ask;
	} while (cin.fail() || ask < 0 || ask > 7 || (ask > 6 && type == 3));
	if (ask == 0) return 1; // Default break
	switch (ask) {
	case 1:
		do {
			check = 1;
			cout << "Introduce new vehicle register number: ";
			cin >> nvrn;
			if (nvrn == "0\0") return 1; // Default break
			if (platforme->checktype(nvrn) == 3) check = platforme->checkvehicle(nvrn);
			else cerr << "Invalid register number" << endl;
			if (check == 1) cerr << "Register number already in use" << endl;
		} while (check == 1);
		if (nvrn == "0\0") return 1;
		platforme->modifyvehicle(position, nvrn);
		return 1;
		break;
	case 2:
		do {
			check = 0;
			cout << "Introduce new owner's NIE/NIF: ";
			cin >> owner;
			if (owner == "0\0") return 1;
			if (platforme->checktype(owner) == 1 || platforme->checktype(owner) == 2) {
				check = platforme->checkowner(owner);
				if (check == 0) cerr << "Not a registered owner" << endl;
			}
			else cerr << "Invalid NIE/NIF" << endl;
		} while (check == 0);
		platforme->modifyvehicleowner(position, platforme->ownerposition(owner));
		return 1;
		break;
	case 3:
		value = modify(1);
		if (value == 0) return 1;
		platforme->modifypropulsion(position, value);
		return 1;
		break;
	case 4:
		if (type == 3) { cerr << "Fighters have a fixed crew number of 1" << endl; return 1; }
		value = modify(2);
		if (value == 0) return 1;
		platforme->modifymcrew(position, value);
		return 1;
		break;
	case 5:
		value = modify(3);
		if (value == 0) return 1;
		platforme->modifyprice(position, value);
		return 1;
		break;
	case 6:
		switch (type) {
		case 1:
			value = modify(4);
			if (value == 0) return 1;
			platforme->modifyvehicle(position, 1, value);
			return 1;
			break;
		case 2:
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce number of weapons to add: ";
				cin >> nweapons;
			} while (cin.fail() || nweapons < 0);
			if (nweapons == 0) return 1;
            for (int i = 0; i < nweapons; i++) {
				value = weapontype();
				platforme->modifyvehicle(position, 3, value);
			}
			return 1;
			break;
		case 3:
			value = modify(9);
			if (value == 0) return 1;
			platforme->modifyvehicle(position, 5, value);
			return 1;
			break;
		case 4:
			value = modify(7);
			if (value == 0) return 1;
			platforme->modifyvehicle(position, 6, value);
			return 1;
			break;
		}
	case 7:
		switch (type) {
		case 1:
			value = modify(5);
			if (value == 0) return 1;
			platforme->modifyvehicle(position, 2, value);
			return 1;
			break;
		case 2:
			platforme->showweapons(position);
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce the position of the weapon you want to modify: ";
				cin >> pos;
			} while (cin.fail() || pos < 0);
			value = weapontype();
			if (value == 0) return 1;
			w.modify(value);
			platforme->modifyvehicle(position, pos, w);
			return 1;
			break;
		case 3:
			platforme->showweapons(position);
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce the position of the weapon you want to modify: ";
				cin >> pos;
			} while (cin.fail() || pos < 0);
			value = weapontype();
			if (value == 0) return 1;
			w.modify(value);
			platforme->modifyvehicle(position, pos, w);
		case 4:
			value = modify(8);
			if (value == 0) return 1;
			platforme->modifyvehicle(position, 7, value);
			return 1;
			break;
		}
	case 8:
		switch (type) {
		case 1:
			es = modify(6);
			platforme->modifyvehicle(position, es);
			return 1;
			break;
		case 2:
			platforme->showweapons(position);
			do {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Introduce the position of the weapon you want to remove: ";
				cin >> pos;
			} while (cin.fail() || pos < 0);
			platforme->modifyvehicle(position, 4, pos);
			return 1;
			break;
		case 4:
			es = modify(6);
			platforme->modifyvehicle(position, es);
			return 1;
			break;
		}
	}
	return 1;
}

int interface::modify(int code) { // 1.Propulsion 2.Maximum crew 3.Price 4.Cruising speed 5.Maximum load 6.Energy shield 7.Maximum passengers 8. Number of hangars 9. Maximum speed
	int value;
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (code) {
		case 1:
			cout << "Introduce the propulsion type (1.Warp drive 2.Trace compressor 3. FTL engine 4. Solar sails 5. Ion engine):";
			break;
		case 2:
			cout << "Introduce the maximum crew number: ";
			break;
		case 3:
			cout << "Introduce the price (billions): ";
			break;
		case 4:
			cout << "Introduce the cruising speed: ";
			break;
		case 5:
			cout << "Introduce the maximum load (tons): ";
			break;
		case 6:
			cout << "Introduce wether the vehicle has energy shield or not (1/0): ";
			break;
		case 7:
			cout << "Introduce the number of maximum passengers: ";
			break;
		case 8:
			cout << "Introduce the number of hangars: ";
			break;
		case 9:
			cout << "Introduce the maximum speed: ";
			break;
		}
		cin >> value;
	} while (cin.fail() || value < 0 || (value != 0 && value != 1 && code == 6) || (value > 5 && code == 1));
	return value;
}
int interface::weapontype() {
	int wt;
	do {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Introduce the weapon type (1.PlasmaCannon(10) 2.ThermoniclearMissiles(20) 3.LaserBeams(5) 4.PEM(15)): ";
		cin >> wt;
	} while (cin.fail() || wt < 0 || wt > 5);
	return wt;
}

// -- Remove functions --
bool interface::removeowner() {
	string rn;
	int check, position;
	cout << "Introduce the NIE/NIF of the owner to remove (0 to break): ";
	cin >> rn;
	if (rn == "0\0") return 1; // Default break
	check = platforme->checktype(rn);
	if (check == 1 || check == 2) {
		if (platforme->checkowner(rn) == 0) {
			cerr << "Introduced NIE/NIF doesnt correspond to a registered owner" << endl;
			return 0;
		}
		else {
			position = platforme->ownerposition(rn);
			platforme->removeowner(position);
			cout << "\nOwner with NIE/NIF " << rn << " has been successfully removed\n";
			return 1;
		}
	}
	else { 
		cerr << "Invalid NIE/NIF" << endl; 
		return 0; 
	} // loop
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
		else { 
			cerr << "Not a registered vehicle" << endl; 
			return 0; 
		} // loop
	}
	else { 
		cerr << "Invalid register number" << endl; 
		return 0; 
	} // loop
}

// -- Sell functions --
bool interface::sell() {
	string rn, vrn;
	int check, otype, vtype;
	cout << "Introduce owner NIE/NIF (0 to break): ";
	cin >> rn;
	if (rn == "0\0") return 1; // Default break
	check = platforme->checktype(rn);
	if (check == 1 || check == 2) check = platforme->checkowner(rn);
	else { 
		cerr << "Invalid NIE/NIF" << endl;  
		return 0;
	}// loop
	if (check == 0) { 
		cerr << "Not a NIE/NIF" << endl; 
		return 0; 
	}// loop
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
				if (otype == 1 && vtype != 2) check = 1;
				else if (otype == 2 && vtype != 4) check = 1;
				else {
					cerr << "This type of owner is not authorised to buy this type of vehicle" << endl;
					check = 0;
				}
			}
			else cerr << "Not a registered vehicle" << endl;
		}
		else { cerr << "Invalid register number" << endl; check = 0; }
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
	else { 
		cerr << "Vehicle is not available" << endl;  
		return 0; 
	} // loop
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
						if (platforme->checksales(fvrn) == 0) check2 = 1;
						else { 
							cerr << "Introduced vehicle is not available" << endl; 
							check2 = 0; 
						}
					}
					else { 
						cerr << "Not a fighter" << endl; 
						check2 = 0; 
					}
				}
				else { 
					cerr << "Not a registered vehicle" << endl; 
					check2 = 0; 
				}
			}
			else { 
				cerr << "Invalid register number" << endl; 
				check2 = 0; 
			}
		} while (check2 == 0);
		platforme->sell(fvrn, rn, saledate);
		cout << endl << "Sale was successfully registered" << endl;
	}
	return 1;
}
