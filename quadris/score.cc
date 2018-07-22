#include "score.h"


int Score::getScore(){
	return score;
}

void Score::genScoreBlock(int lvl){
	lvl = 0;
}

void Score::setLvl(int lvl){
	level = lvl;
}

void Score::genScoreRows(int rows){
	score = score + (level + rows) * (level + rows);

}

