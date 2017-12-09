#include "interface.hpp"
#include "init.hpp"

using namespace std;

int main (){

	// Instantiation of main classes
	platform *_MainPlatform = new platform; // Dynamically create platform we are going to use
	init _MainInit(_MainPlatform); 
    interface _MainInterface(_MainPlatform);

	// Main program
	_MainInit.initialize(); // Read files
	_MainInterface.menu(); // Execute program
	_MainInit.registry(); // Write files

	// Free memory
	delete _MainPlatform;

	return 0;
}
