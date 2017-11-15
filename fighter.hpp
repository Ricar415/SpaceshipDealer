#ifndef FIGHTER_HPP
#define FIGHTER_HPP
#include "vehicle.hpp"
#include <string>
using namespace std;

class fighter:public vehicle{
private:
    int weapon; //this will store the number of weapons the vehicle has assigned to be used so that every weapon is destroyed when the object is destroyed and to check every weapon for the offensive attack list
    int maxspeed;
    const int crewn = 1;
public:
    fighter(int w,int ms, string n);
    ~fighter();
    void modifyw(int w);
    void modifyms(int ms);
};

#endif
