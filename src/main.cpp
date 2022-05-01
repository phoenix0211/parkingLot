#include "inputManagement/include/InputProcessor.hpp"
#include <string>

int main(int argc, char** argv) {
	
	if(argc == 1) {
		InputProcessor ip;
		ip.processInteractiveInput();
	} else {
		std::string filename(argv[0]);
		InputProcessor ip(filename);
		ip.processFileInput();
	}
	return 0;
}