#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "spot.h"
#include"board.h"
#include"piece.h"
#include"bishop.h"
#include"rook.h"
#include"knight.h"
#include"queen.h"
#include"king.h"
#include"pawn.h"
enum gamestatus {
	
	ACTIVE,
	BLACK_WIN,
	WHITE_WIN,
	FORFEIT,
	STALEMATE,
	RESIGNATION



};
class board {
	spot* boxes[8][8];
public:
	board() {
		setboard();
	}
	void setboard();
	spot* getbox(int x, int y);


};
class player {
	int color;
public :
	void setcolor(int col);
	int getcolor();
};

class move {
	int player;
	piece* piece_moved;
	piece* piece_killed;
	spot* start;
	spot* end;
public:
	move(int plyer, spot* start1, spot* end1);
};
class storemove {
	public:
		move* mov;
		storemove* next;
};
class game {
	player playr[2];
	board bord;
	int playerturn;
	gamestatus status;
	storemove mov;
public: 
	void intialize();
	void domove(player ply ,spot* start11, spot* end11);

};
#endif // !BOARD_H
