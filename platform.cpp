#include "platform.hpp"
#include <iostream>
#include <string>
#include "human.hpp"
#include "alien.hpp"
#include <vector>

using namespace std;
void platform::lavailable(){}
void platform::lbydate(date,date){}
void platform::lbyocapacity(){}
void platform::lbyowner(string o){
    if (o == "0\0"){
        cout<<"ok, esto solo es para quitar el issue y usar o";
    }
}
//void platform::lforalien(){} // will only be implemented if necessary
//void platform::lforhuman(){}
void platform::listowners() {}
void platform::lsales(){}
bool platform::ask(){
    bool x = 0;
    string a;
    do{
        cout<<"Do you want to exit the program?";
        cin>>a;
        if(a =="Y"||a=="y"||a=="YES"||a=="yes"||a=="Yes"||a=="Si"||a=="si"||a=="SI"||a=="s"){
            return 1;
        } else if (a=="N"||a=="n"||a=="no"||a=="No"||a=="NO"){
            return 0;
        }
    } while (x == 0);
    return 0;
}
bool platform::ask(bool i){
    string a;
    bool x = 0;
    if (i == 1){
        cout<<"The action has been performed successfully\n";
    } else {
        cout<<"There has been a problem performing the action\n";
    }
    do{
        cout<<"Do you want to exit the program?";
        cin>>a;
        if(a =="Y"||a=="y"||a=="YES"||a=="yes"||a=="Yes"||a=="Si"||a=="si"||a=="SI"||a=="s"){
            return 1;
        } else if (a=="N"||a=="n"||a=="no"||a=="No"||a=="NO"){
            return 0;
        }
    } while (x == 0);
    return 0;
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
int platform::modifyowner(){ //returns 1 if the modification was correct and 0 if the process was stopped by the user.
    string rn,nrn;
    int a = 0, i = 0;
    bool b = 0;
    do{
        i = 0;
        cout<<"Introduce owner's register number (0 to break):";
        cin>>rn;
        if (rn == "0\0"){
            return 0;
        }
        a = checktype(rn);
        if (a == 1||a == 2){
            do {
                if (owners[i].rn == rn){
                    b = 1;
                } else {
                    b = 0;
                    i++;
                }
            } while (i < owners.size() && b == 0);
        }
    } while(a != 1 && a!= 2);
    do{
        cout<<"Introduce owner's new register number (0 to break):";
        cin>>nrn;
        if (nrn == "0\0"){
            return 0;
        }
        a = checktype(nrn);
        if (a == 1 || a == 2){
            owners[i].rn = nrn;
        }
    } while(a != 1 && a!= 2);
    return 1;
}
int platform::createowner(){ //returns 1 if the creation was correct and 0 if the process was stopped by the user.
    string rn;
    int type;
    bool a = 0;
    do{
    cout<<"Introduce the register number (NNNNNNNNL for human and NNNNNNNNNN for alien)(0 to break):";
    cin>> rn;
    if (rn == "0\0") return 0;
    type = checktype(rn);
    if (type == 1){
        human b(rn);
        owners.push_back(b);
		cout << "\nHuman with register number " << rn << " has been created\n" << endl;
        return 1;
    } else if (type == 2) {
        alien a(rn);
        owners.push_back(a);
		cout << "\nAlien with register number " << rn << " has been created\n" << endl;
        return 1;
    } else {
        cout<<"-- Invalid register number --" << endl;
        a = 0;
    }
    } while (a == 0);
    return 0;
}
int platform::removeowner() { //returns 0 if the given rn wasnt found or the process is stopped by the user and 1 if everything went right
	string rn;
	int check = 0;
	if (owners.size() == 0) {
		cout << "\There is no registered owners in this moment \n";
		return 0;
	}
	int size = owners.size();
	do {
		cout << "\nIntroduce the register number of the owner to remove (0 to break): ";
		cin >> rn;
		if (rn == "0\0") return 0;
		check = checktype(rn);
		if (check == 1 || check == 2) {
			int i = 0;
			bool b = 0;
			do {
				if (owners[i].rn == rn) {
					b = 1;
				}
				else {
					b = 0;
					i++;
				}
			} while (b == 0 && i < (size-1));
			if (b == 1) {
				owners.erase(owners.begin()+i);
				cout << "\nThe owner with register number " << rn << " has been sucessfully removed" << endl;
				return 1;
			} else {
				cout << "\nThe introduced register number doesnt correspond to a registered owner" << endl;
				return 0;
			}
		}
	} while (check != 1 && check != 2);
	return 0;
}
int platform::createvehicle() { return 0; } // 
int platform::modifyvehicle() { return 0; } // will ask the rn of the vehicle to modify and then give the posibilities of modification depending on the type
int platform::removevehicle() { return 0; } // will ask the rn of the vehicle and then remove the vehicle and the weapons if there are any
void platform::menu(){
    int a;
    int check,check2;
    do{
        cout<<" 0 - Create owner\n 1 - Modify owner\n 2 - Remove owner\n"<<endl;
        cin>>a;
        switch (a){
        case 0:
            check2 = platform::createowner();
            check = platform::ask(check2);
            break;
        case 1:
            check2 = platform::modifyowner();
            check = platform::ask(check2);
            break;
		case 2:
			check2 = platform::removeowner();
			check = platform::ask(check2);
			break;
        default:
            check = platform::ask(0);
            break;
        }
    } while (check == 0);
}
