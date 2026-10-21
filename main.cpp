#include <iostream>
#include <fstream>
#include <string>
#include "memory.h"

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
	memory mem;
	std::string line;
	while (std::getline(file, line)) {
		for (int i = 0; i < line.length(); i++) {
			switch (line[i]){
				case '+':
					mem++;
					break;
				case '-':
					mem--;
					break;
				case '>':
					mem.right();
					break;
				case '<':
					mem.left();
					break;
				case '.':
					std::cout << mem.out();
					break;
				case ',':
					mem = getchar();
					break;
				default:
					break;
			}
		}
	}
}
