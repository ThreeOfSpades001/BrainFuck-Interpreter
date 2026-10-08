#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char** argv) {
	if (argc <= 1){
		std::cerr << "Please attach a file." << std::endl;
		return 0;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cerr << "File did not open." << std::endl;
		return 1;
	}
}
