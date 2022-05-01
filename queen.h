#pragma once
#pragma once
#pragma once
#ifndef QUEEN_H
#define QUEEN_H

class spot;
class board;
#include"piece.h"
class queen : public piece {
public:
	queen(int col,char c) :piece(col,c) {

	};
	bool can_move(board board, spot start, spot end);

};


#endif 
