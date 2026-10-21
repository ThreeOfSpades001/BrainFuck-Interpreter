#include <vector>
#ifndef MEMORY_H
#define MEMORY_H
class memory {
	unsigned int cursor = 0;
	std::vector<char> data = {'\0'};
	public:
	void right(int jmp = 1){
		cursor += jmp;
	}
	void left(int jmp = 1){
		cursor -= jmp;
	}
	void operator++(int unused) {
		while ((cursor+1) > data.size()) {
			data.push_back('\0');
		}
		data[cursor]++;
	}
	void operator-- (int unused){
		while ((cursor+1) > data.size()) {
			data.push_back('\0');
		}
		data[cursor]--;
	}
	char out(){
		return data[cursor];
	}
	void operator=(char in){
		data[cursor] = in;
	}
};
#endif
