
#ifndef FOUR_H
#define FOUR_H

#include<iostream>
#include"board.h"

class Four {
    const int num_players;
    const int max_turns;
    const int goal = 4;
    int current_player;
    int current_turn;
    int* history;
    Board board;

    int get_current_player();
    int place(const int row, const int col);
    void print_player_turn();
    void print_current_board();
    void handle_player_move();

    bool check_vertical_win() const;
    bool check_horizontal_win() const; 
    bool check_win() const;

public:
    
    Four() = delete;
    Four(const int player_count, const int board_width, const int board_height);
    ~Four();

    void play();
    
    friend std::ostream& operator<<(std::ostream& os, const Four& f);
};

#endif