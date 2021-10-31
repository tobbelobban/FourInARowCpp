
#include "board.h"

Board::Board() : WIDTH(10), HEIGHT(8), size(80), mem(new int[size]{0}) {}

Board::Board(const int width, const int height) : WIDTH(width), HEIGHT(height), size(WIDTH*HEIGHT), mem(new int[size]{0}){}

Board::~Board() {
    delete[] mem;
}

int Board::get(const int& r, const int& c) const {
    if(r < 0 || r >= HEIGHT) return -1;
    if(c < 0 || c >= WIDTH) return -1;
    return mem[r*WIDTH + c];
}

int Board::set(const int& r, const int& c, const int value) {
    if(r < 0 || r >= HEIGHT) return -1;
    if(c < 0 || c >= WIDTH) return -1;
    mem[r*WIDTH + c] = value;
    return 1;
}