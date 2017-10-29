#ifndef WEAPON_HPP
#define WEAPON_HPP

class weapon{
    friend class fighter;
    friend class destructor;
    friend class platform;
private:
    int capacity;
};

#endif
