#ifndef VEHICLE_HPP
#define VEHICLE_HPP

class vehicle{
    friend class platform;
protected:
    char vrn[9];
    int propulsion;
    int maxcrew;
    int price;
    char owner[11];
    int type;
    bool available;
public:
    void modifyp(int);
    void modifymc(int);
    void modifytype(int);
    void modifyprice(int);
    void modifyowner(char*);
    void modifyavailability();
    void modifylist(char*); //will produce a list of possibilities of modification for an specific vehicle, ask for the new value and then call for the corresponding function with the new value as argument.
};

#endif
