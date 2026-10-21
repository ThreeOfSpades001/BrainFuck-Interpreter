#include <vector>
#ifndef MEMORY_H
#define MEMORY_H
class memory {
	unsigned int cursor = 0;
	std::vector<char> data = {'\0'};
	public:
	void left(int jmp = 1){
		cursor += jmp;
	}
	void right(int jmp = 1){
		cursor	-=1;
	}
	void operator++ {
		while ((cursor+1) > data.size()) {
			data.push_back('\0');
		}
		data[cursor]++;
	}
}
#endif
