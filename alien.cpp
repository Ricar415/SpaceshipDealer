#include "alien.hpp"
#include <cstring>
using namespace std;

alien::alien(string n){ // Parametrized constructor
    rn = n;
}

void alien::modify(string n){ // Modify function
    rn = n;
}
