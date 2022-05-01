#include"rook.h"
#include"piece.h"
#include"spot.h"
#include"board.h"
bool rook::can_move(board board, spot start, spot end) {
	int x1, y1;
	int x2, y2;

	x1 = start.get_x();
	y1 = start.get_y();
	x2 = end.get_x();
	y2 = end.get_y();
	bool cond1; 
	////cond 1 move available cond2 route
	cond1 = (y2 == y1) || (x2 == x1);//doable move
	//checking every spot in the route is empty
	if (y2 == y1 && cond1)//horizontal move
	{
		if (x1 < x2)//to the right
		{
			for (int i = x1 + 1; i < x2; i++)
			{
				if (board.getbox(i, y1)->get_piece() != 0)
					return false;

			}
		}
		else//to the left
		{
			for (int i = x1 - 1; i > x2; i--)
			{
				if (board.getbox(i, y1)->get_piece() != 0)
					return false;
			}
		}


	}
	if (x2 == x1 && cond1)//vertical
	{
		if (y1 < y2)//upwards
		{
			for (int i = y1 + 1; i < y2; i++)
			{
				if (board.getbox(x1, i)->get_piece() != 0)
					return false;

			}
		}
		else///downwards
		{
			for (int i = y1 - 1; i > y2; i--)
			{
				if (board.getbox(x1, i)->get_piece() != 0)
					return false;
			}
		}


	}
	return cond1;
}



/*
equations of motions
y=y1
x=x1

*/