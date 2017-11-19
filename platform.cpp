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
bool platform::lavailable() { return 0 ; }
bool platform::lbydate(date start, date end) { return 0; }
bool platform::lbyocapacity() { return 0; }
bool platform::lbyowner(string o) {
	return 0;
}
//void platform::lforalien(){} // will only be implemented if necessary
//void platform::lforhuman(){}
bool platform::listowners() { return 0; }
bool platform::lsales() { return 0; }
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
bool platform::createhuman(string rn) { //returns 1 if the creation was correct and 0 if the creation cant be done.
	int size = owners.size();
	for (int i = 0; i < size - 1; i++) {
		if (owners[i].rn == rn) {
			return 0;
		} 
	}
	human a(rn);
	owners.push_back(a);
	return 1;
}
bool platform::createalien(string rn){ //returns 1 if the creation was correct and 0 if the creation cant be done.
	int size = owners.size();
	for (int i = 0; i < (size - 1); i++) {
		if (owners[i].rn == rn) {
			return 0;
		}
	}
	alien a(rn);
    owners.push_back(a);
    return 1;
}
bool platform::checkowner(string rn) {
	int size = owners.size();
	for (int i = 0; i < size; i++) {
		if (owners[i].rn == rn) {
			return 1;
		}
	}
	return 0;
}
int platform::ownerposition(string rn) {
	int size = owners.size();
	for (int i = 0; i < size; i++) {
		if (owners[i].rn == rn) {
			return i;
		}
	}
	return 3301;
}
void platform::modifyowner(int position, string nrn) {
	owners[position].modify(nrn);
}
void platform::removeowner(int position) { //returns 0 if the given rn wasnt found or the process is stopped by the user and 1 if everything went right
	owners.erase(owners.begin()+position);	
}
int platform::createvehicle() { return 0; } // 
int platform::createvehicle(int type) { return 0; } //
int platform::modifyvehicle() { return 0; } // will ask the rn of the vehicle to modify and then give the posibilities of modification depending on the type
int platform::removevehicle() { return 0; } // will ask the rn of the vehicle and then remove the vehicle and the weapons if there are any
void platform::createfighter(int ms, weapon weapon1, weapon weapon2, string rn){
	fighter a(ms, weapon1, weapon2, rn);
	vehicles.push_back(a);
}
void platform::createcarrier(int ml, int cs, string rn) {}
void platform::createdestroyer() {}
void platform:: createstation(int maxp, int hn, bool eshield, string rn) {}