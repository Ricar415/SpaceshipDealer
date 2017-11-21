#ifndef CARRIER_HPP
#define CARRIER_HPP
#include "vehicle.hpp"
#include <string>
using namespace std;

class carrier: public vehicle{
private:
    int maxload;
    bool energyshield;
    int cruisingspeed;
	int const type = 1;
public:
    carrier(int cs, int ml, bool es, string vn);
    void modifyml(int ml);
    void modifycs(int cs);
    void modifyes(bool es);
	void modifyvrn(string nvrn);
};

#endif
