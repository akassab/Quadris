#include "newblock.h"
#include <cstdlib>
#include <time.h>
using namespace std;


newBlock::newBlock(): level{0}, random{false}, type{' '} {}

void newBlock::rando(bool random){
	this->random = random;
}

void newBlock::replace(char type){
	this->type = type;
}

void newBlock::setLvl(int lvl){
	level = lvl;
}

char newBlock::generatenew(){
	int v1;
	srand (time(NULL));
	v1 = rand() % 7;
	if(v1 == 0){
		return 'I';
	}
	else if (v1==1){
		return 'S';
	}
	else if (v1==2){
		return 'L';
	}
	else if (v1==3){
		return 'O';
	}
	else if (v1 == 4){
		return 'Z';
	}
	else if (v1 == 5){
		return 'T';
	}
	else if (v1 == 6){
		return 'J';
	} 

	
	if(level ==0){

	}else if(level == 1){

	}else if(level == 2){

	}else if(level == 3){

	}else if(level == 4){

	}else if(level ==5){

	}else if(level == 6){

	}
	return 'I';

}
