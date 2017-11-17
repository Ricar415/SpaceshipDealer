#ifndef DESTROYER_HPP
#define DESTROYER_HPP
#include "vehicle.hpp"
#include <string>
#include <vector>
using namespace std;
struct weapon{
    int destructivecapacity;
    string type;
};
class destroyer: public vehicle{
private:
    vector<weapon> weapons; //this will store the number of weapons the vehicle has assigned to be used so that every weapon is destroyed when the object is destroyed and to check every weapon for the offensive attack list
public:
    destroyer(int);
    void modify(int);
};

#endif
