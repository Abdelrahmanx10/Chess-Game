#pragma once
// white 0  black   1
#ifndef PIECE_H
#define PIECE_H
class spot;
class board;
 class piece {
protected: int color;
        	bool status;
             char type;
public:
    piece(int col,char c);
    virtual bool can_move(board board,spot start,spot end)=0;
    bool read_status();
    void set_status(bool z);
    char get_type();
    int read_color();

};
#endif // !PIECE_H