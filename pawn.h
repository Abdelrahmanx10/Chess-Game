#pragma once
#ifndef PAWN_H
#define PAWN_H

class spot;
class board;
#include"piece.h"
class pawn : public piece {
public:
	pawn(int col,char c) :piece(col,c) {
	
};
	bool can_move(board board,spot start, spot end);

};


#endif 