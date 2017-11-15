#include "station.hpp"

station::station(int mp, int hn, bool es, string n){
    hangarn = hn;
    energyshield = es;
    strcpy(&vrn, n);
};
station::~station(){};
void station::modifymp(int mp){};
void station::modifyhn(int hn){};
void station::modifyes(bool es){};
