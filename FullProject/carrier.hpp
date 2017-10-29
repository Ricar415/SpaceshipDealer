#ifndef CARRIER_HPP
#define CARRIER_HPP
#include "vehicle.hpp"

class carrier: public vehicle{
    friend class platform;
private:
    int maxload;
    bool energyshield;
    int cruisingspeed;
public:
    carrier(int x, int y, bool z);
    ~carrier();
    void modifyml(int);
    void modifycs(int);
    void modifyes(bool);
};

#endif
