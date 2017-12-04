#include "platform.hpp"
#include <string>
#include "interface.hpp"
#include "init.hpp"
using namespace std;
int main (){
	platform *platforme = new platform;
	init init(platforme);
	init.initialize();
    interface interface(platforme);
	interface.menu();
	delete platforme;
    return 0;
}
