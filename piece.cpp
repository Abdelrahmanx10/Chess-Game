#include"piece.h"
piece::piece(int col,char c) {

    color = col;
    status = true;
    type = c;
}
char piece :: get_type() {
    return type;
}


bool piece::read_status() {
    return status;
};
void piece::set_status(bool z) {
    status = z;
}
int piece::read_color() {
    return color;
}
