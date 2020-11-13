//
// Created by gwe on 11/13/2020.
//

#ifndef MS_TNG_VIEWER_H
#define MS_TNG_VIEWER_H
#include "Board.h"

class Viewer {
public:
    Viewer(const Board & board):board(board){
        status.resize(board.getSize(),Status::closed);
    };

    void openCell(unsigned int i, unsigned int j);

    void markCell(unsigned int i, unsigned int j);
    void unMarkCell(unsigned int i, unsigned int j);


private:
    const Board &board;
    enum Status {open, closed, bomb};
    std::vector<Status> status;
};


#endif//MS_TNG_VIEWER_H
