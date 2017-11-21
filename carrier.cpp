#include "carrier.hpp"
#include <string>
using namespace std;
carrier::carrier(int ml, int cs , bool es, string vn){
    cruisingspeed = cs;
    maxload = ml;
    energyshield = es;
    vrn = vn;
}
void carrier::modifyml(int ml){
    maxload = ml;
}
void carrier::modifycs(int cs){
    cruisingspeed = cs;
}
void carrier::modifyes(bool es){
    energyshield = es;
}
void carrier::modifyvrn(string nvrn) {
	vrn = nvrn;
}