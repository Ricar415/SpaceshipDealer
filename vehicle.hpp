#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include <string>
using namespace std;

class vehicle{
protected:
    string vrn;
    int propulsion;
    int maxcrew;
    int price;
    string owner;
    int type;
    bool available;
public:
    virtual void modifyp(int);
    void modifymc(int);
    void modifytype(int);
    void modifyprice(int);
    void modifyowner(string o);
    void modifyavailability();
    void modifylist(string n); //will produce a list of possibilities of modification for an specific vehicle, ask for the new value and then call for the corresponding function with the new value as argument.
};

#endif
