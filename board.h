
#ifndef BOARD_H
#define BOARD_H

class Board {
    const int HEIGHT;
    const int WIDTH;
    const int size;
    int* const mem;
public:
    Board();
    Board(const int width, const int height);
    ~Board();

    int get(const int& r, const int& c) const;
    int set(const int& r, const int& c, const int value);

    inline int get_height() const {return HEIGHT;}
    inline int get_width() const {return WIDTH;}
    
};

#endif