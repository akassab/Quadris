#include "score.h"

Score::Score(): level{0}, cscore{0}, hscore{0} {}

int Score::getScore(){
	return cscore;
}

void Score::setLvl(int lvl){
	level = lvl;
}

void Score::genScoreRows(int rows){
	cscore += ((level + rows)*(level + rows));
	if(cscore > hscore){
		hscore = cscore;
	}
}

void Score::genScoreBlock(int lvl){
	cscore += ((lvl+1) * (lvl+1));
	if(cscore > hscore){
		hscore = cscore;
	}
}

