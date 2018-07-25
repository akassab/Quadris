#include "newblock.h"
#include <cstdlib>
#include <time.h>
#include <vector>
#include <fstream>
using namespace std;


newBlock::newBlock(): level{0}, random{false}, type{' '}, charpos{0}, seqfname{"sequence.txt"} {}

void newBlock::rando(){
	this->random = true;
}

void newBlock::norandom(string s){
	this->random = false;
	newseqn(s);
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
	if(newseed){
		srand(seed);
	}
	else{  
      srand(time(NULL)); //seeding for the first time only!
	}
	first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

void newBlock::newseqn(string s){//make sure to call this before generatenew() every time there is a new seqfile
	seq.clear();
	charpos = 0;
	seqfname = s;
	char x;
   	ifstream in;
    	in.open(s);
    	if (!in) {
       		cout << "Unable to open file" << endl;
    	}
    	while (in >> x) {
       		seq.push_back(x);
    	}
    	in.close();
}

void newBlock::changeSeed(int seed){
	cout << "TEST1" << endl;
	newseed = true;
	this->seed = seed;
	cout << "test2" << endl;
}

char newBlock::generatenew(){
	if(level ==0){
	// read in sequence from file provided on command line how do I do this every generatenew()
		char c;
		if(charpos < seq.size()){
			c = seq.at(charpos);
			++charpos;
		}else{
			charpos = 0;
			return generatenew();
		}
		return c;
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
	if(random){
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
	else{
		char c;
		if(charpos < seq.size()){
			c = seq.at(charpos);
			++charpos;
		}else{
			charpos = 0;
			return generatenew();
		}
		return c;
	}
	}else if(level == 4){
	//Same as lvl3 and multiple of 5 blocks dropped w/o one row cleared = drop * center
	if(random){	
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
	else{
		char c;
		if(charpos < seq.size()){
			c = seq.at(charpos);
			++charpos;
		}else{
			charpos = 0;
			return generatenew();
		}
		return c;
	}
	}
	return 'I';
}

