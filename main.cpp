#include "platform.hpp"
#include <string>
#include "interface.hpp"
using namespace std;
int main (){
	platform *platforme = new platform;
    interface interface(platforme);
	interface.menu();
	delete platforme;
    return 0;
}
