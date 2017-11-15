#include "fighter.hpp"

fighter::fighter(int w, int ms, string n){
    vrn = n;
    weapon = w;
    maxspeed = ms;
};
void fighter::modifyw(int w){
    weapon = w;
};
void fighter::modifyms(int ms){
    maxspeed = ms;
};
