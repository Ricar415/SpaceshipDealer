#ifndef STATION_HPP
#define STATION_HPP
#include "vehicle.hpp"

class station: public vehicle{
    friend class platform;
private:
    int maxp;
    int hangarn;
    bool energyshield;
public:
    station(int,int,bool);
    ~station();
    void modifymp(int);
    void modifyhn(int);
    void modifyes(bool);
};

#endif
