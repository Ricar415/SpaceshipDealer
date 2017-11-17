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
void platform::lbyowner(string o){}
void platform::lforalien(){}
void platform::lforhuman(){}
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
        cout<<"The action has been performed successfully";
    } else {
        cout<<"There has been a problem performing the action";
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
    int length = rn.strlenght();
    if (length>11) return 0;
    int position = 0;
    int check = checkchar(rn.at(position));
    if (check == 1){
        for(i=0;i<7;i++){
            check = checkchar(rn.at(position));
            if(check != 1) return 0;
        }
        check = checkchar(rn.at(position));
        if (check == 1){
            for(i=0;i<2;i++){
                check = checkchar(rn.at(position));
                if(check != 1) return 0;
            }
            if (length == 11) return 2; else return 0;
        } else if (check == 2) {
            if (length == 10) return 1; else return 0;
        }
    } else if (check == 2){
        for(i=0;i<4;i++){
            check = checkchar(rn.at(position));
            if(check != 1) return 0;
        }
        for(i=0;i<3;i++){
            check = checkchar(rn.at(position));
            if(check != 2) return 0;
        }
        if (length == 9) return 3; else return 0;
    } else return 0;
}
int platform::checkchar(char position){ // returns 0 if not a letter or a number, 1 if a number and 2 if a letter.
    if (position == '0'||position == '1'||position == '2'||position == '3'||position == '4'||position == '5'||position == '6'||position == '7'||position == '8'||position == '9'){
        return 1;
    } else if (position == 'a'||position == 'b'||position == 'c'||position == 'd'||position == 'e'||position == 'f'||position == 'g'||position == 'h'||position == 'i'||position == 'j'||position == 'k'||position == 'l'||position == 'm'||position == 'n'||position == 'ñ'||position == 'o'||position == 'p'||position == 'q'||position == 'r'||position == 's'||position == 't'||position == 'u'||position == 'v'||position == 'w'||position == 'x'||position == 'y'||position == 'z'||position == 'A'||position == 'B'||position == 'C'||position == 'D'||position == 'E'||position == 'F'||position == 'G'||position == 'H'||position == 'I'||position == 'J'||position == 'K'||position == 'L'||position == 'M'||position == 'N'||position == 'Ñ'||position == 'O'||position == 'P'||position == 'Q'||position == 'R'||position == 'S'||position == 'T'||position == 'U'||position == 'V'||position == 'W'||position == 'X'||position == 'Y'||position == 'Z' ){
        return 2;
    } else return 0;
}
bool platform::modifyowner(){
    string rn,nrn;
    int a = 0, i = 0;
    bool b = 0;
    do{
        i = 0;
        cout<<"Introduce owner's register number (0 to restart):";
        cin>>rn;
        if (rn == "0"){
            return 0;
        }
        a = checktype(rn);
        if (a == 1||a == 2){
            do {
                if (owners(i).rn == rn){
                    b = 1;
                } else {
                    b = 0;
                    i++;
                }
            } while (i<owners.size || b == 0);
        }
    } while(a != 1 || a!= 2);
    do{
        cout<<"Introduce owner's new register number (0 to restart):";
        cin>>nrn;
        if (nrn == "0"){
            return 0;
        }
        a = checktype(nrn);
        if (a == 1 || a == 2){
            owners(i).rn = nrn;
        }
    } while(a != 1 || a!= 2);
    return 1;
}
bool platform::createowner(){
    string rn;
    int type;
    cout<<"Introduce the register number (NNNNNNNNL for human and NNNNNNNNNN for alien):";
    cin>> rn;
    type = checktype(rn);
    if (type == 1){
        human b(rn);
        owners.push_back(b);
        return 1;
    } else if (type == 2) {
        alien a(rn);
        owners.push_back(a);
        return 1;
    } else {
        cout<<"-- Invalid register number --" << endl;
        return 0;
    }
}
void platform::menu(){
    int a;
    bool check, check2;
    do{
        cout<<" 0 - create owner \n 1 - modify owner"<<endl;
        cin>>a;
        switch (a){
        case 0:
            do{
                check2 = platform::createowner();
            } while (check2 == 0);
            check = platform::ask(check2);
            break;
        case 1:
            do{
                check2 = platform::modifyowner();
            } while (check2 == 0);
            check = platform::ask(check2);
            break;
        default:
            check = platform::ask(0);
            break;
        }
    } while (check == 0);
}
