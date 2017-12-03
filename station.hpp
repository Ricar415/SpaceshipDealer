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
public:
    station(int mp, int hn, bool es, int propulsiont, int maxcrew, int price, string n);
    void modifymp(int mp);
    void modifyhn(int hn);
    void modifyes(bool es);
	void show();
	bool check(string rn);
	int hn();
};

#endif
