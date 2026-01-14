#include "global_vars.h"

// game state
int cleared_row = 0;
bool collision = false; 
bool game_end = false;
bool game_quit = false;
bool clear_current_row = false;
bool drop_above_blocks = false;
int block_shape = 0; //current shape
int next_shape = 0;
int stored_shape = 0;

// board
int main_board[board_row][board_column] = {};

// tetris piece
int tetris_shapes[4][4] =
{
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
};

int delay = 400; //default delay in gravity

// position of the shape in main board
int piece_x = board_column / 2 - 4 / 2;
int piece_y = 0;

// colors
std::string red     = "red";
std::string green   = "green";
std::string yellow  = "yellow";
std::string blue    = "blue";
std::string cyan    = "cyan";
std::string magenta = "magenta";
std::string reset   = "reset";

int random_colour = 0;
int terminal_height = 0;
int terminal_width = 0;

int score = 0;
int high_score = 0;
