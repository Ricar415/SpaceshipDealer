#include "alien.hpp"
#include <cstring>
using namespace std;

alien::alien(string n){
    rn = n;
};
alien::~alien(){
};
void alien::modify(string n){
    rn = n;
};
