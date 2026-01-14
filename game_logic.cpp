#include "game_logic.h"
#include "global_vars.h"
#include "draw_and_render.h"
#include "include.h"

void game_start () {
	draw_shapes();
	rendering_shapes();
}//draws and renders first piece 

void game_running () {
	game_end = false;
	for (int i = 0;i < board_column; i++) {
		if (main_board [0][i] == 1) {
			 game_end = true;
			 std::cout << std::endl;
			 set_colour("red");
			 std::cout << " [ GAME-OVER!] "<< std::endl;
			 set_colour ("reset");

			break;
		}
}
}
bool player_quit () {
	return true;
}

void spawn_new_piece() {
	if (collision == true) {
	piece_x = (board_column/2) - 4/2;
    piece_y = 0;
	clearScreen();
	draw_shapes();
	rendering_shapes();
	collision = false;
		}
}

void lock_piece () {
	for (int shape_row = 0; shape_row <4 ; shape_row++) {
		for ( int shape_column = 0; shape_column < 4 ; shape_column ++) {
		int board_r = piece_y + shape_row;
	    int board_c = piece_x + shape_column;//coords of shape in main board
	    if (tetris_shapes [shape_row] [shape_column] == 0) continue;
	    main_board [board_r] [board_c] = 1;
	  }//for column		
	}//for row
}

void clear_row () {
	for (int i = 0;  i < board_row ; i++) {
		for (int j = 0; j < board_column ; j++) {
		 if ( main_board [i][j] == 1 ) {clear_current_row = true;}
		 else {clear_current_row = false;
		   break;}
	      }//for j
		 if (clear_current_row == false) continue;
		 if (clear_current_row == true) {
			 cleared_row = i;//storing the information to use later
			for (int k = 0; k < board_column ; k++) {
				main_board [i][k] = 0;
			}//for k
			clear_current_row = false;
			drop_above_blocks = true;
		}
		 delay = 350; // dropping delay for fast rendering as gravity handles my rendering
		 Beep(1500,400);//beep after clearing a row for sound effect
			break;
    }//for i
}

void drop_blocks () {
	if (drop_above_blocks == true) {
		drop_above_blocks = false;
		for (int i = cleared_row - 1; i >= 0 ; i--) {
			for (int j = 0 ; j < board_column ; j++) {
			 if (( main_board [i][j] == 1) && (main_board [i+1] [j] == 0 )) {
				main_board [i+1] [j] = 1;
				main_board [i] [j] = 0;

			 }
			}//for j
		}//for i
		score += 100;
	}

}

void clear_and_drop () {
		  while (true) {
	   clear_row();
	   if (drop_above_blocks == false) break;
	   drop_blocks();
	   }
}
