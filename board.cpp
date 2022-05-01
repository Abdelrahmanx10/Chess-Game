#include"board.h"
#include"piece.h"
#include"bishop.h"
#include"rook.h"
#include"knight.h"
#include"queen.h"
#include"king.h"
#include"pawn.h"
spot* board::getbox(int x, int y) {

	return boxes[x][y];
}
void board:: setboard()
{//// white intialization
	boxes[0][0] = new spot(0, 0, new rook(0,'r'));
	boxes[1][0] = new spot(1, 0, new knight(0,'h'));
	boxes[2][0] = new spot(2, 0, new bishop(0,'b'));
	boxes[3][0] = new spot(3, 0, new queen(0,'q'));
	boxes[4][0] = new spot(4, 0, new king(0,'k'));
	boxes[5][0] = new spot(5, 0, new bishop(0,'q'));
	boxes[6][0] = new spot(6, 0, new knight(0,'h'));
	boxes[7][0] = new spot(7, 0, new rook(0,'r'));
	boxes[0][1] = new spot(0, 1, new pawn(0,'p'));
	boxes[1][1] = new spot(1, 1, new pawn(0, 'p'));
	boxes[2][1] = new spot(2, 1, new pawn(0, 'p'));
	boxes[3][1] = new spot(3, 1, new pawn(0, 'p'));
	boxes[4][1] = new spot(4, 1, new pawn(0, 'p'));
	boxes[5][1] = new spot(5, 1, new pawn(0, 'p'));
	boxes[7][1] = new spot(7, 1, new pawn(0, 'p'));
	//////black setting
	boxes[0][7] = new spot(0, 7, new rook(1,'r'));
	boxes[1][7] = new spot(1, 7, new knight(1,'h'));
	boxes[2][7] = new spot(2, 7, new bishop(1,'b'));
	boxes[3][7] = new spot(3, 7, new queen(1,'q'));
	boxes[4][7] = new spot(4, 7, new king(1,'k'));
	boxes[5][7] = new spot(5, 7, new bishop(1,'b'));
	boxes[6][7] = new spot(6, 7, new knight(1,'h'));
	boxes[7][7] = new spot(7, 7, new rook(1,'r'));
	boxes[0][6] = new spot(0, 6, new pawn(1,'p'));
	boxes[1][6] = new spot(1, 6, new pawn(1, 'p'));
	boxes[2][6] = new spot(2, 6, new pawn(1, 'p'));
	boxes[3][6] = new spot(3, 6, new pawn(1, 'p'));
	boxes[4][6] = new spot(4, 6, new pawn(1, 'p'));
	boxes[5][6] = new spot(5, 6, new pawn(1, 'p'));
	boxes[6][6] = new spot(6, 6, new pawn(1, 'p'));
	boxes[7][6] = new spot(7, 6, new pawn(1, 'p'));
	///empty spots
	for(int i=2;i<6;i++)
		for(int m=0;m<8;m++)
			boxes[m][i] = new spot(m, i, 0);

}

int player::getcolor() {
	return color;
}
void player::setcolor(int col) {
	color = col;
}

move::move(int plyer, spot* start1, spot* end1) {
	player = plyer;
	piece_moved = start->get_piece();
	piece_killed = end->get_piece();
	start = start1;
	end = end1;
}



void game::intialize() {
	playr[0].setcolor(0);
	playr[1].setcolor(1);

	bord.setboard();
	}
	void game:: domove(player ply, spot*start11,spot*end11){
		

		end11->set_piece(start11->get_piece());

		start11->set_piece(0);

    };












