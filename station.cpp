#include "station.hpp"
#include <string>
using namespace std;
station::station(int mp, int hn, bool es, string n){
    hangarn = hn;
    energyshield = es;
    vrn = n;
}
void station::modifymp(int mp){}
void station::modifyhn(int hn){}
void station::modifyes(bool es){}
