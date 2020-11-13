#include "Board.h"
void Board::count_bombs_in_neighbour(){
    for (int i = 0; i<N;++i){
        for (int j = 0; j<N;++j){
            if (getCell(i,j)==bomb){
                increment_bomb_counter(i-1,j-1);
                increment_bomb_counter(i-1,j);
                increment_bomb_counter(i-1,j+1);
                increment_bomb_counter(i,j-1);
                increment_bomb_counter(i,j+1);
                increment_bomb_counter(i+1,j-1);
                increment_bomb_counter(i+1,j);
                increment_bomb_counter(i+1,j+1);
            }
        }
    }
}

void Board::increment_bomb_counter( int i, int j) {
    if (!(i < 0 || i >= N || j < 0 || j >= N || getCell(i, j) == bomb))
        getCell(i, j)++;
}