#include "carrier.hpp"

carrier::carrier(int cs, int ml , bool es, string vn){
    cruisingspeed = cs;
    maxload = ml;
    energyshield = es;
    strcpy(vrn, vn);
};
carrier::~carrier(){};
void carrier::modifyml(int ml){
    maxload = ml;
};
void carrier::modifycs(int cs){
    cruisingspeed = cs;
};
void carrier::modifyes(bool es){
    energyshield = es;
};
