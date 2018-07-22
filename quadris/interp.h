#ifndef INTERP_H_
#define INTERP_H_
#include <vector>
#include <string>
class Interp{
	std::vector<std::string> cmdnames;
	public:
	std::string interpret(std::string str);
	void init();
};







#endif
