#pragma once
#pragma once
#ifndef BISHOP_H
#define BISHOP_H

class spot;
class board;
#include"piece.h"
class bishop : public piece {

public:
	bishop(int col,char c) :piece(col,c) {

	};
	bool can_move(board board,spot start, spot end);

};


#endif 