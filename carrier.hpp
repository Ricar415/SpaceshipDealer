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
public:
    carrier(int ml, int cs, bool es, int propulsiont, int maxcrewt, int pricet, string vn);
    void modifyml(int ml);
    void modifycs(int cs);
    void modifyes(bool es);
	void show();
	bool check(string vrn);
	string reg();
};
#endif
