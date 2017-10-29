#ifndef OWNER_HPP
#define OWNER_HPP

class owner{
    friend class platform;
public:
    bool check(char*); //check if an owner is registered
};

#endif
