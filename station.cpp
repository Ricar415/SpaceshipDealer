#include "station.hpp"
#include <string>
using namespace std;
station::station(int mp, int hn, bool es, string n){
    hangarn = hn;
    energyshield = es;
    vrn = n;
	maxp = mp;
}
void station::modifymp(int mp){
	maxp = mp;
}
void station::modifyhn(int hn){
	hangarn = hn;
}
void station::modifyes(bool es){
	energyshield = es;
}
void station::modifyvrn(string nvrn) {
	vrn = nvrn;
}