#pragma once
#pragma once
#ifndef ROOK_H
#define ROOK_H

class spot;
class board;
#include"piece.h"
class rook : public piece {
public:
	rook(int col,char c) :piece(col,c) {

	};
	bool can_move(board board, spot start, spot end);

};


#endif 