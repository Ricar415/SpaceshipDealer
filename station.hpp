#ifndef STATION_HPP
#define STATION_HPP
#include "vehicle.hpp"
#include <string>
using namespace std;

class station: public vehicle{
private:
    int maxp;
    int hangarn;
    bool energyshield;
	int const type = 4;
public:
    station(int mp,int hn,bool es, string n);
    void modifymp(int mp);
    void modifyhn(int hn);
    void modifyes(bool es);
	void modifyvrn(string nvrn);
};

#endif
