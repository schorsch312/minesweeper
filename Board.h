//
// Created by gwe on 11/12/2020.
//

#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include "assert.h"

constexpr int bomb = -1;

class Board {
public:
    Board(unsigned int N, unsigned int B):N(N) {
        assert(N * N > B);
        assert(N<100);
        cells.resize(N * N, 0);
        std::fill_n(cells.begin(), B, bomb);

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cells.begin(), cells.end(), g);
        count_bombs_in_neighbour();
    };
    unsigned int getSize () const {return cells.size();};

    int& getCell(unsigned int x, unsigned int y)  {
        return cells[x + N * y];
    };

private:
    void count_bombs_in_neighbour();
    void increment_bomb_counter( int i, int j);

private:
    std::vector<int> cells;
    int N;
};

#endif // UNTITLED_BOARD_H
