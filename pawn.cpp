#include"pawn.h"
#include"piece.h"
#include"spot.h"
#include"board.h"
bool pawn::can_move(board board,spot start, spot end) {
	int delta_x,delta_y;
	delta_x = end.get_x() - start.get_x();
	delta_y = end.get_y() - start.get_y();


	if (color == 0)
	{
		if (delta_x==0&& delta_y==1 && end.get_piece() == 0)///move forward for white  end.get_y() == start.get_y() + 1 && end.get_x() == start.get_x()
			return true;
		else if ((delta_x == 1||delta_x==-1) && delta_y == 1 && end.get_piece()!= 0)//move diagonal for white (end.get_y() == start.get_y() + 1 && end.get_piece() != 0) && (end.get_x() == start.get_x() + 1 || end.get_x() == start.get_x() - 1)
		{
		 return true;}

	}
	else if (color == 1)//black
	{
		if(delta_x == 0 && delta_y == -1 && end.get_piece() == 0)///move forward for black (end.get_y() == start.get_y() -1  && end.get_x() == start.get_x() 
			return true;
		else if ((delta_x == 1 || delta_x == -1) && delta_y == -1 && end.get_piece() != 0)//move diagonal for black (end.get_y() == start.get_y() + 1 && end.get_piece() != 0) && (end.get_x() == start.get_x() + 1 || end.get_x() == start.get_x() - 1)
		{
			return true;
		}
	}
	return false;
};
/*
route: can move if 
1-nothing infront of it

type: 
1-if y2==y1+1 and x1=x2 condition 1
2-spot onx2== x+1,y2==y2+1 or x2==x1-1,y2== contain a piece






*/