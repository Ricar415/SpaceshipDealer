#ifndef ALIEN_HPP
#define ALIEN_HPP
#include "owner.hpp"

class alien: public owner{
    friend class platform;
private:
    char arn[11];
public:
    alien(char a[11]);
    ~alien();
    void modify(char*);
};

#endif
