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
	int loop_num = -1;
	memory mem;
	std::string line;
	while (std::getline(file, line)) {
		for (int i = 0; i < line.length(); i++) {
			switch (line[i]){
				case '+':
					std::cout << "plus ";
					mem++;
					break;
				case '-':
					mem--;
					break;
				case '>':
					std::cout << "right ";
					mem.right();
					break;
				case '<':
					std::cout << "left ";
					mem.left();
					break;
				case '.':
					std::cout << mem.out();
					break;
				case ',':
					mem = getchar();
					break;
				case '[':
					std::cout << "open ";
					loop_pos.push_back(i);
					loop_num++;
					break;
				case ']':
					i = (loop_pos[loop_num]+1);
					mem--;
					if (mem.out() == '\0'){
						loop_pos.pop_back();
						loop_num--;
					}
					std::cout << "close ";
					break;
				default:
					break;
			}
		}
	}
}
