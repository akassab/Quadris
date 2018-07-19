#include "newblock.h"

using namespace std;


newBlock::newBlock(): level{0}, random{false}, type{' '} {}

void newBlock::rand(bool random){
	this->random = random;
}

void newBlock::replace(char type){
	this->type = type;
}

void newBlock::setLvl(int lvl){
	level = lvl;
}

char newBlock::getnewBlk(){
	return type;
}

void newBlock::generatenew(){
	if(level ==0){

	}else if(level == 1){

	}else if(level == 2){

	}else if(level == 3){

	}else if(level == 4){

	}else if(level ==5){

	}else if(level == 6){

	}


}
