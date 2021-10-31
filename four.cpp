
#include<iostream>

#include "four.h"

Four::Four(const int player_count, const int board_width, const int board_height) : 
    num_players(player_count),
    current_player(1),
    current_turn(1),
    max_turns(board_width*board_height),
    board(board_width, board_height),
    history(new int[2*max_turns]) {}

Four::~Four() {
    delete[] history;
}

bool Four::check_vertical_win() const {
    const int& last_x = history[current_turn*2];
    const int& last_y = history[current_turn*2 + 1];
    int score = 0;
    int y_pos = last_y;
    while(y_pos >= 0) {
        // might win
        if(board.get(y_pos, last_x) == current_player) {
            ++score;
            // did win
            if(score >= goal) {
                return true;
            }
            --y_pos;
        // not won
        } else {
            return false;
        }
    }
    return false;
}

bool Four::check_horizontal_win() const {
    const int& last_x = history[current_turn*2];
    const int& last_y = history[current_turn*2 + 1];
    int score = 0;
    int x_pos = last_x;
    while(x_pos >= 0) {
        // might win
        if(board.get(last_y, x_pos) == current_player) {
            // did win
            if(++score >= goal) {
                return true;
            }
            --x_pos;
        // not won
        } else {
            break;
        }
    }
    x_pos = last_x + 1;
    while(x_pos < board.get_width()) {
        // might win
        if(board.get(last_y, x_pos) == current_player) {
            // did win
            if(++score >= goal) {
                return true;
            }
            ++x_pos;
        // not won
        } else {
            return false;
        }
    }
    return false;
}

bool Four::check_win() const {
    return check_horizontal_win() || check_vertical_win();
}

void Four::print_player_turn() {
    std::cout << "TURN " << current_turn << "\nPlayer " << current_player << "'s move." << std::endl;
}

void Four::print_current_board() {
    std::cout << "Current board state:\n" << *this << std::endl;
}

void Four::handle_player_move() {
    int col, curr_x_place, curr_y_place;
    while(true) {
        std::cout << "Select a column in 0-" << board.get_width()-1 << ": ";
        std::cin >> col;
        // player input too small column
        if(col < 0) {
            std::cout << "Column value too small." << std::endl;
        // player input too large column
        } else if(col >= board.get_width()) {
            std::cout << "Column value too large." << std::endl;
        // player input already full column
        } else if(board.get(board.get_height()-1, col)) {
            std::cout << "Column full, please choose another column." << std::endl;
        // column okay
        } else {
            // find row to place on
            curr_x_place = col;
            for(curr_y_place = 0; curr_y_place < board.get_height(); ++curr_y_place) {
                // found empty row
                if(!board.get(curr_y_place, curr_x_place)) {
                    board.set(curr_y_place, curr_x_place, current_player);
                    history[current_turn*2] = curr_x_place;
                    history[current_turn*2 + 1] = curr_y_place;
                    break;
                }
            }
            break;
        }
    }
}

void Four::play() {
    bool has_won = false;
    bool out_of_turns = false;
    while(!(has_won || out_of_turns)) {
        // no player won
        if(current_turn > max_turns) {
            out_of_turns = true;
            break;
        }
        // still playing
        print_player_turn();
        print_current_board();
        handle_player_move();
        std::cout << std::endl;
        if(check_win()) {
            has_won = true;
        } else {
            current_player = current_player == num_players ? 1 : current_player + 1;
            current_turn += 1;
        }
    }
    // game ended, no winner
    if(out_of_turns) {
        std::cout << "OUT OF TURNS. TIE!" << std::endl;
    } else {
        std::cout << "PLAYER " << current_player << " WINS!" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Four& f) {
    const int rows = f.board.get_height();
    const int cols = f.board.get_width();
    for(int r = rows-1; r > -1; --r) {
        os << "|\t";
        for(int c = 0; c < cols; ++c) {
            os << f.board.get(r,c) << "\t";
        }
        os << '|' << std::endl;
    }
    return os;
}