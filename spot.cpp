#include"spot.h"
spot::spot() { };
spot ::spot(int col, int row, piece* m) {
	x = col;
	y = row;
	pice = m;

}
int spot::get_x() {

	return x;
}
int spot::get_y() {
	return y;

};
void spot::set_piece(piece* m) {
	pice = m;
};
piece *spot::get_piece() {
	return pice;
};
// row y
// column x