#ifndef FIGHTER_HPP
#define FIGHTER_HPP
#include "vehicle.hpp"

class fighter:public vehicle{
    friend class platform;
private:
    int weapon; //this will store the number of weapons the vehicle has assigned to be used so that every weapon is destroyed when the object is destroyed and to check every weapon for the offensive attack list
    int maxspeed;
    const int crewn = 1;
public:
    fighter(int,int,int);
    ~fighter();
    void modifyw(int);
    void modifyms(int);
};

#endif
