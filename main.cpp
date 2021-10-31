
#include<iostream>
#include "board.h"
#include "four.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int width, height;
    cout << "Input board dimensions." << endl;
    bool correct_input = false;
    while(!correct_input) {
        correct_input = true;
        cout << "Width: ";
        cin >> width;
        cout << "Height: ";
        cin >> height; 
        if(width <= 0 || height <= 0) {
            correct_input = false;
            cout << "Incorrect input, try again." << endl;
        }
    }
    
    Four four_game(2, width, height);
    four_game.play();
    return 0;
}
