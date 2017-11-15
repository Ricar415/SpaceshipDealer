#include "platform.hpp"
#include <iostream>
#include <string>
#include "human.hpp"
#include "alien.hpp"
using namespace std;
void platform::lavailable(){};
void platform::lbydate(date,date){};
void platform::lbyocapacity(){};
void platform::lbyowner(string o){};
void platform::lforalien(){};
void platform::lforhuman(){};
void platform::lsales(){};
bool platform::ask(){
    bool x;
    do{
        cout<<"Do you want to exit the program?";
        cin>>a;
        if(a =="Y"||a=="y"||a=="YES"||a=="yes"||a=="Yes"||a=="Si"||a=="si"||a=="SI"||a=="s"){
            return 1;
        } else if (a=="N"||a=="n"||a=="no"||a=="No"||a=="NO"){
            return 0;
        }
    } while (x == 0);
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
}
int platform::checktype(string rn){

};
bool platform::modifyowner(){
    string rn;
    cout<<"Introduce owner's register number:";
    cin>>rn;
    cout<<"Introduce owner's new register number:";
    cin>>rn;

}
bool platform::createowner(){
    string rn;
    int type;
    cout<<"Introduce the register number (NNNNNNNNL for human and NNNNNNNNNN for alien):";
    cin>> rn;
    type = checktype(rn);
    if (type == 0){
        human b(rn);
        humans.push_back(b);
        return 1;
    } else if (type == 1) {
        alien a(rn);
        humans.push_back(a);
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
        cout<<"0 - create owner \n 1 - modify owner"<<endl;
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
