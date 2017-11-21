#include "owner.hpp"
#include <string>
using namespace std;

void owner::modify(string nrn) {
	rn = nrn;
}
bool owner::check(string crn) {
	if (rn == crn) return 1; else return 0;
}