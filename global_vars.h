#ifndef GLOBAL_VARS_H
#define GLOBAL_VARS_H

#include <string>

constexpr int board_row = 20;
constexpr int board_column = 10;

extern int terminal_height;
extern int terminal_width;

extern int score;
extern int high_score;

extern int cleared_row;
extern bool collision;
extern bool game_end; //when game naturally  ends
extern bool game_quit; // when player chooses to quit
extern bool clear_current_row;
extern bool drop_above_blocks;
extern int block_shape;
extern int next_shape; // for upcoming shape
extern int stored_shape; //for stored shape

extern int delay ;//for gravity

extern int main_board[board_row][board_column];

extern int tetris_shapes[4][4];
extern int piece_x;
extern int piece_y;

extern std::string red;
extern std::string green;
extern std::string yellow;
extern std::string blue;
extern std::string cyan;
extern std::string magenta;
extern std::string reset;
extern int random_colour;

#endif 

