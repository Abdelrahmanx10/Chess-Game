#pragma once
#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H
class board;
class spot;
#include"piece.h"
class knight : public piece {
public:
	knight(int col,char c) :piece(col,c) {

	};
	bool can_move(board board,spot start, spot end);

};


#endif 
