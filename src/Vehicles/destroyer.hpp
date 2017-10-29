#ifndef DESTROYER_HPP
#define DESTROYER_HPP
#include "vehicle.hpp"

class destroyer: public vehicle{
    friend class platform;
private:
    int weapon; //this will store the number of weapons the vehicle has assigned to be used so that every weapon is destroyed when the object is destroyed and to check every weapon for the offensive attack list
public:
    destroyer(int);
    ~destroyer();
    void modify(int);
};

#endif
