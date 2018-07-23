#ifndef SCORE_H_
#define SCORE_H_

//maybe #include something later

class Score {
	int level;
	int cscore;
	int hscore;
public:
	int getScore();
	void genScoreBlock(int lvl);
	void setLvl(int lvl);
	void genScoreRows(int rows);
	Score();
};

#endif
