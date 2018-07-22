#include "interp.h"
#include <string.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
string Interp::interpret(string str){
	int count = 0;
	string retval = "";
	for(const string &s : cmdnames){
		int f = s.find(str);
		if(f==0){
			if(count>1){
				retval = "";
				break;
			}
			retval = s;
			count ++;
		}
	}
	return retval;
}

void Interp::init(){
	cmdnames.push_back("right");
	cmdnames.push_back("left");
	cmdnames.push_back("down");
	cmdnames.push_back("clockwise");
	cmdnames.push_back("counterclockwise");
	cmdnames.push_back("drop");
	cmdnames.push_back("levelup");
	cmdnames.push_back("leveldown");
	cmdnames.push_back("norandom");
	cmdnames.push_back("random");
	cmdnames.push_back("I");
	cmdnames.push_back("J");
	cmdnames.push_back("S");
	cmdnames.push_back("Z");
	cmdnames.push_back("L");
	cmdnames.push_back("T");
	cmdnames.push_back("O");
	cmdnames.push_back("sequence");
	cmdnames.push_back("restart");
	cmdnames.push_back("hint");
}
