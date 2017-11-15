#include "platform.hpp"

void platform::lavailable(){};
void platform::lbydate(date,date){};
void platform::lbyocapacity(){};
void platform::lbyowner(string o){};
void platform::lforalien(){};
void platform::lforhuman(){};
void platform::lsales(){};
bool platform::modifyowner(){
    string rn;
    cout<<"Introduce owner's register number:";
    cin<<rn;
    cout<<"Introduce owner's new register number:";
    cint<<rn;

}
bool platform::createowner(){
    string rn;
    bool type;
    cout<<"Introduce the register number (NNNNNNNNL for human and NNNNNNNNNN for alien):";
    cin<< rn;
    type = checktype(rn);
    if (type == 0){
        human b;
        b.human(rn);
    } else {
        alien a;
        a.alien(rn);
    }
}
void platform::menu(){
    int a;
    bool check;
    do{
        cout<<"0 - create owner \n 1 - modify owner"<<endl;
        cin>>a;
        switch (a){
        case 0:
            do{
                check = platform::createowner();
            } while (check == 0);
            break;
        case 1:
            do{
                check = platform::modifyowner();
            } while (check == 0);
            break;
        default:
            break;
        }
    } while ()
}
