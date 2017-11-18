#include <string>
#include "interface.hpp"
#include "platform.hpp"

void interface::menu() { //main conducting part of the user interface
	int a;
	bool check, check2;
	do {
		cout << " 0 - Create owner\n 1 - Modify owner\n 2 - Remove owner\n 3 - Create vehicle\n 4 - Modify vehicle\n 5 - Remove vehicle\n 6 - List options\n" << endl;
		cin >> a;
		switch (a) {
		case 0:
			do {
				check2 = interface::createowner();
			} while (check2 == 0);
			check = interface::ask();
			break;
		case 1:
			do {
				check2 = interface::modifyowner();
			} while (check2 == 0);
			check = interface::ask();
			break;
		case 2:
			do {
				check2 = interface::removeowner();
			} while (check2 == 0);
			check = interface::ask();
			break;
		case 3:
			do {
				check2 = interface::createvehicle();
			} while (check2 == 0);
			check = interface::ask();
			break;
		case 4:
			do {
				check2 = interface::modifyvehicle();
			} while (check2 == 0);
			check = interface::ask();
			break;
		case 5:
			do {
				check2 = interface::removevehicle();
			} while (check2 == 0);
			check = interface::ask();
			break;
		case 6:
			cout << "\n\n\n 0 - List available vehicles\n 1 - List registered owners\n 2 - List performed sales\n";
			int b;
			cin >> b;
			switch (b) {
			case 0:
				cout << "\n\n -List available vehicles-\n0 - List by register number\n 1 - List by saledate\n 2 - List by owner\n 3 - List by offensive capacity\n";
				int c;
				cin >> c;
				switch (c) {
				case 0:
					do {
						check2 = platform::lavailable();
					} while (check2 == 0);
					check = interface::ask();
					break;
				case 1:
					do {
						check2 = interface::lbydate();
					} while (check2 == 0);
					check = interface::ask();
					break;
				case 2:
					do {
						check2 = interface::lbyowner();
					} while (check2 == 0);
					check = interface::ask();
					break;
				case 3:
					do {
						check2 = platform::lbyocapacity();
					} while (check2 == 0);
					check = interface::ask();
					break;
				default:
					check = interface::ask();
					break;
				}
				break;
			case 1:
				do {
					check2 = platform::listowners();
				} while (check2 == 0);
				check = interface::ask();
				break;
			case 2:
				do {
					check2 = platform::lsales();
				} while (check2 == 0);
				check = interface::ask();
				break;
			default:
				check = interface::ask();
				break;
			}
			break;
		default:
			check = platform::ask(0);
			break;
		}
	} while (check == 0);
}
void lbydate() // asks date of start and end and then calls platform::lbydate with given parameters
void lbyowner() // asks the owner to list and then calls platform::lbyowner with given
bool createowner() { //asks register number and then calls platform::createowner
	string rn;
	int type;
	bool a = 0,check;
	cout << "Introduce the register number (NNNNNNNNL for human and NNNNNNNNNN for alien)(0 to break):";
	cin >> rn;
	if (rn == "0\0") return 0;
	type = platform::checktype(rn);
	if (type == 1) {
		check = bool platform::createhuman(rn);
		if (check == 1) {
			cout << "\nHuman with register number " << rn << " has been created\n" << endl;
			return 1;
		}
		else {
			cout << "\nA human with the given register number already exists\n" << endl;
			return 0;
		}
	}
	else if (type == 2) {
		check = bool platform::createalien(rn);
		if (check == 1) {
			cout << "\nAlien with register number " << rn << " has been created\n" << endl;
			return 1;
		}
		else {
			cout < "\nAn alien with the given register number already exists\n" << endl;
			return 0;
		}
	}
	else {
		cout << "-- Invalid register number --" << endl;
		a = 0;
	}
	return 0;
}
bool modifyowner() {//asks owner to modify and new register number and then calls platform::modifyowner
	string rn, nrn;
	int a = 0, i = 0;
	bool b = 0;
	do {
		i = 0;
		cout << "Introduce owner's register number (0 to break):";
		cin >> rn;
		if (rn == "0\0") {
			return 0;
		}
		a = checktype(rn);
		if (a == 1 || a == 2) {
			bool check = platform::checkowner(rn);
			if (check == 0) {
				cout << "\nIntroduced register number doesnt correspond to a registered owner\n";
				return 0;
			}
			else {
				int position = platform::ownerposition(rn);
			}
		}
	} while (a != 1 && a != 2);
	do {
		cout << "Introduce owner's new register number (0 to break):";
		cin >> nrn;
		if (nrn == "0\0") {
			return 0;
		}
		a = checktype(nrn);
		if (a == 1 || a == 2) {
			platform::modifyowner(position,rn);
			cout << "\nChange has been successfully made\n";
		}
	} while (a != 1 && a != 2);
	return 1;
}
bool removeowner() {//asks owner to remove and calls platform::removeowner
	string rn;
	cout << "\nIntroduce the register number of the owner to remove (0 to break): ";
	cin >> rn;
	if (rn == "0\0") return 0;
	check = checktype(rn);
	if (check == 1 || check == 2) {
		if (platform::checkowner(rn) == 0) {
			cout << "\nIntroduced register number doesnt correspond to a registered owner\n";
			return 0;
		}
		else {
			int position = platform::ownerposition(rn);
			void platform::removeowner(position);
			cout << "\nOwner with register number " << rn << " has been successfully removed\n";
		}
	}
	else return 0;
}
bool createvehicle() //asks every part of the vehicle information needed and then calls vehicle(*given parameters*)
bool modifyvehicle() //asks vehicle to remove, lists options depending on type and then calls vehicle::*needed function* with given parameters
bool removevehicle() //asks vehicle to remove and calls platform::removevehicle
bool ask() // asks if the user wants to continue with the program