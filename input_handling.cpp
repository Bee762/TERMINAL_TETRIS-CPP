#include "input_handling.h"
#include "global_vars.h"
#include "collision.h"
#include "include.h"
#include "game_logic.h"
#include "draw_and_render.h"
#include "output_formatting.h"

char get_input () {
    if (!_kbhit())
    return 0;

    return _getch();
}

void handle_input() {
    char key = get_input();

    if ((key == 'a' || key == 'A') && !hit_left(tetris_shapes)) {piece_x --;
	                                                             delay = 150;}//dropping the delay time from default gravity one for
    if ((key == 'd' || key == 'D') && !hit_right(tetris_shapes)) {piece_x ++; // faster input processing
	                                                             delay = 150;}
	if ((key == 'w' || key == 'W')) {rotation ();
	                                 delay = 100;}
	if ((key == 'e' || key == 'E')) {hard_drop();
	                                 delay = 150;}
	if ((key == 'q' || key == 'Q')) {update_score();
		                             game_quit = player_quit();}

	if ((key == 'p' || key == 'P')) {game_pause();}

	if ((key == 'f' || key == 'F')) {store_shape();}

   std::this_thread::sleep_for(std::chrono::milliseconds(70));

}

void hard_drop () {
	while (true){
	 if (hit_bottom(tetris_shapes)) break;
	  piece_y++;}
}

void rotation () {
	int demo_piece [4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	//formula for clockwise 90 deg rotation of a 4x4 matrix
	//new row = old column
	//new column = (n-1)-old row where n is size of matrix,we add a -1 coz array index starts from 0 
	//n is 4 here as we r using 4x4 matrix
	    for (int i = 0; i < 4 ; i++) {
  		for (int j = 0; j < 4 ; j++) {
  		       if (tetris_shapes [i] [j] > 0) {
				demo_piece [j] [3-i] = tetris_shapes [i] [j];
			   }
  			}
  		}//making a image of rotated piece
		bool can_rotate = false;
		 can_rotate = (!hit_bottom(demo_piece) && !hit_left(demo_piece) && !hit_right(demo_piece));//checking if rot is possible 

		 if (can_rotate) {
		  for (int i = 0; i < 4 ; i++) {
  		  for (int j = 0; j < 4 ; j++) {
			 tetris_shapes [i] [j] = demo_piece [i] [j];
  			}
  		   }
		 }// copying the image if rotation is possible
}
void game_pause () {
    clearScreen();
	set_colour ("green");
	for (int i = 0; i < terminal_width; i++)  {
    std::cout << ":";
    }
    std::cout << std::endl;

	std::cout << std::endl << std::endl << std::endl;
	horizontal_padding(terminal_width/2 - 20);
    std::cout << "GAME IS PAUSED. PRESS ANY KEY TO RESUME" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

	for (int i = 0; i < terminal_width; i++)  {
    std::cout << ":";
    }
    std::cout << std::endl;

    while (true) {
        if (_kbhit()) {
            _getch();
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
	set_colour("reset");
  }

  void store_shape() {
	
	if (!stored_shape) {

		bool can_store = (!hit_bottom(next_shape) && !hit_left(next_shape) && !hit_right(next_shape));

		if (can_store) {
		stored_shape = block_shape; // storing current shape
		block_shape = 0; // reseting current shape info
		draw_shapes();   // draw a new shape from same position as the position is not reset
		}

	}
	else {
		int save_next_shape = next_shape;
		   bool can_replace = (!hit_bottom(stored_shape) && !hit_left(stored_shape) && !hit_right(stored_shape));
		   if (can_replace) {
		     next_shape = stored_shape;
		     stored_shape = 0;
			 draw_shapes();
			 next_shape = save_next_shape;
		   }
	     
    }
}

