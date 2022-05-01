#include"pawn.h"
#include"piece.h"
#include"spot.h"
#include"board.h"
#include"bishop.h"
bool bishop::can_move(board board, spot start, spot end) {
	int x1, y1;
	int x2, y2;
	
	x1 = start.get_x();
	y1 = start.get_y();
	x2 = end.get_x();
	y2 = end.get_y();
	int m = y1;
	bool cond1; 
	cond1 = y2 ==( x2 + (y1 - x1));///check on the diagonal
	///cehcking route
	      //first quad
	if (x1 < x2 && y1 < y2&&cond1) 
	{
		{
			for (int i = x1 + 1; i < x1; i++) {
				if (board.getbox(i, m)->get_piece() != 0)
					return false;
				m++;
			}

		}
		  }
	///2nd quad
	else if (x1 > x2 && y1 < y2 && cond1)
	{
		{
			for (int i = x1 - 1; i > x1; i--) {
				if (board.getbox(i, m)->get_piece() != 0)
					return false;
				m++;
			}

		}
	}
	///3rd quad
	else if (x1 > x2 && y1 > y2 && cond1)
	{
		{
			for (int i = x1 + 1; i > x1; i--) {
				if (board.getbox(i, m)->get_piece() != 0)
					return false;
				m--;
			}

		}
	}
	//4th quad
	else if (x1 < x2 && y1 > y2 && cond1)
	{
		{
			for (int i = x1 + 1; i < x1; i++) {
				if (board.getbox(i, m)->get_piece() != 0)
					return false;
				m--;
			}

		}
	}

	return cond1;




};
/*
equation


*/