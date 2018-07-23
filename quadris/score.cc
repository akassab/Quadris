#include "score.h"

Score::Score(): level{0}, score{0} {}

int Score::getScore(){
	return score;
}

void Score::setLvl(int lvl){
	level = lvl;
}

void Score::genScoreRows(int rows){
	score += ((level + rows)*(level + rows));
}

void Score::genScoreBlock(int lvl){
	score += ((lvl+1) * (lvl+1));
}

