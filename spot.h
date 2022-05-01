#pragma once
#ifndef SPOT_H
#define SPOT_H
class piece;

class spot {
private: int y;
	   int x;
	   piece *pice;
public:
	spot();
	spot(int col, int row, piece *m);
	int get_x();
	int get_y();
	void set_piece(piece * m);
	piece *get_piece();

};




#endif // !SPOT_H