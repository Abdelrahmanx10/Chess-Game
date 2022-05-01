#pragma once
#ifndef KING_H
#define KING_H

class spot;
class board;
#include"piece.h"
class king : public piece {
public:
	king(int col,char c) :piece(col,c) {

	};
	bool can_move(board board, spot start, spot end);

};


#endif 