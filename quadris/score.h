#ifndef SCORE_H_
#define SCORE_H_

//maybe #include something later

class Score {
	int level;
	int cscore; //current score
	int hscore; //high score
public:
	int getScore();
	void genScoreBlock(int lvl);
	void setLvl(int lvl);
	void genScoreRows(int rows); //increase score based on rows cleared
	int getHscore();
	void restart(); //restart score, but keep highscore same
	Score();
};

#endif
