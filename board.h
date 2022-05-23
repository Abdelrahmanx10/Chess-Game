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
	void add_move(int plyer, spot* start1, spot* end1);
	piece* getpiecemoved(){
		return piece_moved;
	}
	piece* getpiecekilled(){
		return piece_killed;
	}
	spot* getsource() {
		return start;
	}
	spot* getdest() {
		return end;
	}
	int getplayer() {
		return player;
	}
};


class list {
	list* top;
private:
	move mov;
		list* next;
public:
	list() { top = 0; };
	void push(move mov);
	bool is_empty() ;
	move peek();
	void pop();
	}
;

class game {
	player playr[2];
	board bord;
	int playerturn;
	gamestatus status;
	list moves;
public: 
	void intialize();
	bool logical_move(int x1,int y1, int x2,int y2);
	void domove(int player,int x1, int y1, int x2, int y2);
	spot* getbox(int x, int y);
	int getturn() {
		return playerturn;
	}
	player getplayer() {
		if (playerturn % 2 == 0)
			return playr[0];
		else  {
			return playr[1];
		}
	}
	void domoveredo(int player, int x1, int y1, int x2, int y2);
	void redo();
};
#endif // !BOARD_H
