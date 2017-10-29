#include "carrier.hpp"

carrier::carrier(int x,int y ,bool z){
    cruisingspeed = x;
    maxload = y;
    energyshield = z;
};
carrier::~carrier(){};
void carrier::modifyml(int){};
void carrier::modifycs(int){};
void carrier::modifyes(bool){};
