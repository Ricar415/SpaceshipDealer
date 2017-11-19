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
void interface::menu(platform *platforme) { //main conducting part of the user interface
	int a;
	bool check, check2;
	do {
		cout << " 0 - Create owner\n 1 - Modify owner\n 2 - Remove owner\n 3 - Create vehicle\n 4 - Modify vehicle\n 5 - Remove vehicle\n 6 - List options\n" << endl;
		cin >> a;
		switch (a) {
		case 0:
			do {
				check2 = createowner(platforme);
			} while (check2 == 0);
			check = ask();
			break;
		case 1:
			do {
				check2 = modifyowner(platforme);
			} while (check2 == 0);
			check = ask();
			break;
		case 2:
			do {
				check2 = removeowner(platforme);
			} while (check2 == 0);
			check = ask();
			break;
		case 3:
			do {
				check2 = createvehicle(platforme);
			} while (check2 == 0);
			check = ask();
			break;
		case 4:
			do {
				check2 = modifyvehicle(platforme);
			} while (check2 == 0);
			check = ask();
			break;
		case 5:
			do {
				check2 = removevehicle(platforme);
			} while (check2 == 0);
			check = ask();
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
						check2 = platforme->lavailable();
					} while (check2 == 0);
					check = ask();
					break;
				case 1:
					do {
						check2 = lbydate(platforme);
					} while (check2 == 0);
					check = ask();
					break;
				case 2:
					do {
						check2 = lbyowner(platforme);
					} while (check2 == 0);
					check = ask();
					break;
				case 3:
					do {
						check2 = platforme->lbyocapacity();
					} while (check2 == 0);
					check = ask();
					break;
				default:
					check = ask();
					break;
				}
				break;
			case 1:
				do {
					check2 = platforme->listowners();
				} while (check2 == 0);
				check = ask();
				break;
			case 2:
				do {
					check2 = platforme->lsales();
				} while (check2 == 0);
				check = ask();
				break;
			default:
				check = ask();
				break;
			}
			break;
		default:
			check = ask();
			break;
		}
	} while (check == 0);
}
bool interface::lbydate(platform *platforme) { return 0; }// asks date of start and end and then calls platform::lbydate with given parameters
bool interface::lbyowner(platform *platforme) { return 0; }// asks the owner to list and then calls platform::lbyowner with given
bool interface::createowner(platform *platforme) { //asks register number and then calls platform::createowner
	string rn;
	int type;
	bool a = 0,check;
	cout << "Introduce the register number (NNNNNNNNL for human and NNNNNNNNNN for alien)(0 to break):";
	cin >> rn;
	if (rn == "0\0") return 1;
	type = platforme->checktype(rn);
	if (type == 1) {
		check = platforme->createhuman(rn);
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
		check = platforme->createalien(rn);
		if (check == 1) {
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
		a = 0;
	}
	return 0;
}
bool interface::modifyowner(platform *platforme) {//asks owner to modify and new register number and then calls platform::modifyowner
	string rn, nrn;
	int a = 0, i = 0;
	int position;
	bool b = 0,check;
	do {
		i = 0;
		cout << "Introduce owner's register number (0 to break):";
		cin >> rn;
		if (rn == "0\0") {
			return 1;
		}
		a = platforme->checktype(rn);
		if (a == 1 || a == 2) {
			check = platforme->checkowner(rn);
			if (check == 0) {
				cout << "\nIntroduced register number doesnt correspond to a registered owner\n";
				return 0;
			}
			else {
				position = platforme->ownerposition(rn);
			}
		}
	} while (a != 1 && a != 2);
	do {
		cout << "Introduce owner's new register number (0 to break):";
		cin >> nrn;
		if (nrn == "0\0") {
			return 1;
		}
		a = platforme->checktype(nrn);
		if (a == 1 || a == 2) {
			platforme->modifyowner(position,nrn);
			cout << "\nChange has been successfully made\n";
		}
	} while (a != 1 && a != 2);
	return 1;
}
bool interface::removeowner(platform *platforme) {//asks owner to remove and calls platform::removeowner
	string rn;
	int check;
	int position;
	cout << "\nIntroduce the register number of the owner to remove (0 to break): ";
	cin >> rn;
	if (rn == "0\0") return 1;
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
	else return 0;
}
bool interface::createvehicle(platform *platforme) {//asks every part of the vehicle information needed and then calls vehicle(*given parameters*)
	int type,eshield;
	int check = 0;
	string rn;
	do {
		cout << "\n- Create vehicle -\nType N list\n\t1\tCarrier\n\t2\tDestroyer\n\t3\tFighter\n\t4\tStation\n\nIntroduce the vehicle type: ";
		cin >> type;
		if (type == 0) return 1; else if (type == 1 || type == 2 || type == 3 || type == 4) check = 1; else {
			cout << "\n-Invalid introduced type-";
			check = 0;
		}
	} while (check == 0);
	do {
		cout << "\nIntroduce the vehicle register number: ";
		cin >> rn;
		if (rn == "0\0") return 1;
		check = platforme->checktype(rn);
	} while (check != 3);
	if (type == 1 || type == 3) {
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
		cout << "\nIntroduce the number of hangars: ";
		cin >> hn;
		platforme->createstation(maxp, hn, eshield, rn);
		return 1;
		break;
	case 1:
		int ml, cs;
		cout << "\nIntroduce the maximum load capacity: ";
		cin >> ml;
		cout << "\nIntroduce cruising speed: ";
		cin >> cs;
		platforme->createcarrier(ml, cs, rn);
		return 1;
		break;
	case 2:
		int nweapons;
		cout << "\nIntroduce the number of weapons: ";
		cin >> nweapons;
		platforme->createdestroyer();
		return 1;
		break;
	case 3:
		int ms,weapon1t,weapon2t;
		cout << "\nIntroduce the maximum speed: ";
		cin >> ms;
		cout << "\nIntroduce the first weapon type: ";
		cin >> weapon1t;
		cout << "\nIntroduce the second weapon type: ";
		cin >> weapon2t;
		weapon weapon1(weapon1t), weapon2(weapon2t);
		platforme->createfighter(ms, weapon1, weapon2, rn);
		return 1;
		break;
	}
}
bool interface::modifyvehicle(platform *platforme) { return 0; }//asks vehicle to remove, lists options depending on type and then calls vehicle::*needed function* with given parameters
bool interface::removevehicle(platform *platforme) { return 0; }//asks vehicle to remove and calls platform::removevehicle
bool interface::ask() { return 0; }// asks if the user wants to continue with the program