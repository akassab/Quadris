#ifndef BOARDTYPE_H
#define BOARDTYPE_H
/* Board types are:
	Score -- the score has changed and must be updated on the display
	Level -- the level has changed and must be updated on the display
	Grid  -- the board has changed and must be updated on the display
	nextblock -- the nextblock has changed and must be updated
*/
enum class BoardType {Score, Level, Grid, nextblock};
enum class BlockType {I,J,O,S,Z,L,t};

struct State {
Boardtype type;
int score;
int level;
int x;
int y;
}

#endif
