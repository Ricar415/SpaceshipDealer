#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "owner.hpp"

class human: public owner{
    friend class platform;
private:
    char hrn[10];
public:
    human(char*);
    ~human();
    void modify(char*);
};

#endif
