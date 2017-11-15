#ifndef DESTROYER_HPP
#define DESTROYER_HPP
#include "vehicle.hpp"
#include <string>
using namespace std;

class destroyer: public vehicle{
private:
    ; //this will store the number of weapons the vehicle has assigned to be used so that every weapon is destroyed when the object is destroyed and to check every weapon for the offensive attack list
public:
    destroyer(int);
    void modify(int);
};

#endif
