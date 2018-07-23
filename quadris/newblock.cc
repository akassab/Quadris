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

int newBlock::ran(int min, int max) //range : [min, max)
{
   static bool first = true;
   if (first) 
   {  
      srand(time(NULL)); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

char newBlock::generatenew(){
	/*if(v1 == 0){
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
	} */
	//remove the above and the bottom line return I at the end	
	if(level ==0){
	return 'I';
	// read in sequence from file provided on command line how do I do this every generatenew()
	}else if(level == 1){
	//S and Z = 1/12, rest = 1/6
		int n = newBlock::ran(1,12);
		if(n == 1){
			return 'Z';
		}
		else if (n==2){
			return 'S';
		}
		else if (n==3 || n==4){
			return 'L';
		}
		else if (n==5 || n==6){
			return 'O';
		}
		else if (n==7 || n==8){
			return 'I';
		}
		else if (n==9 || n==10){
			return 'T';
		}
		else if (n==11 || n==12){
			return 'J';
		} 

	}else if(level == 2){
	//equal probable all
		int v1 = newBlock::ran(1,7);
		if(v1 == 7){
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

	}else if(level == 3){
	//S and Z = 2/9, rest = 1/9, HEAVY
		int n = newBlock::ran(1,9);
		if(n == 1 || n==2){
			return 'Z';
		}
		else if (n==3 || n==4){
			return 'S';
		}
		else if (n==5){
			return 'L';
		}
		else if (n==6){
			return 'O';
		}
		else if (n==7){
			return 'I';
		}
		else if (n==8){
			return 'T';
		}
		else if (n==9){
			return 'J';
		}
	
	}else if(level == 4){
	//Same as lvl3 and multiple of 5 blocks dropped w/o one row cleared = drop * center
		int n = newBlock::ran(1,9);
		if(n == 1 || n==2){
			return 'Z';
		}
		else if (n==3 || n==4){
			return 'S';
		}
		else if (n==5){
			return 'L';
		}
		else if (n==6){
			return 'O';
		}
		else if (n==7){
			return 'I';
		}
		else if (n==8){
			return 'T';
		}
		else if (n==9){
			return 'J';
		}

	}
	return 'I';

}
