#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
	std::vector<int> loop_pos = {0};
	int loop_num = 0;
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
				case '[':
					loop_pos.push_back(i);
					loop_num++;
					break;
				case ']':
					if (mem.out() == '\0'){
						loop_pos.pop_back();
						loop_num--;
					}
					else {
						i = (loop_pos[loop_num]+0);
					}
					break;
				default:
					break;
			}
		}
	}
}
