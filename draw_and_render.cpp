#include "include.h"
#include "global_vars.h"
#include "draw_and_render.h"
#include "output_formatting.h"

int generaterandomnumber(int min, int max){
 static std::mt19937 gen(std::random_device{}());
 std::uniform_int_distribution<> dist(min, max);
 return dist(gen);
}

void clear_main_board () {
    	for (int i = 0; i < board_row ; i++) {
  		for (int j = 0; j < board_column ; j++) {
  			main_board [i] [j] = 0;
  			}
  		}
}

void draw_shapes () {
  	for (int i = 0; i < 4 ; i++) {
  		for (int j = 0; j < 4 ; j++) {
  		tetris_shapes [i] [j] = 0;
  		 }
  		}//resetting so it can be called again		
        // upcoming shape

		if (next_shape == 0) {
 // for firdt run next shape is o so we generate block shape 
		   next_shape = generaterandomnumber(1,5); // and also generate next shape so in next turn 
		}

	    block_shape = next_shape;
		next_shape = generaterandomnumber(1,5); // we are gonna assign next shape to block shape
	    											//this way i have the data on the upcoming shape in current iteration
		                                                // and i can print that data;

		random_colour = generaterandomnumber(1,5);
	  if (block_shape == 1) {
	  	tetris_shapes [1][1] = 2;//   *      // i am using 1 in array to lockshapes in main board and 2 for drawing shapes for colours only
	  	tetris_shapes [2][0] = 2;// * * * *   // random colour when drawing shapes , fixed (yellow) after locking in main board
	  	tetris_shapes [2][1] = 2;
	  	tetris_shapes [2][2] = 2;
	  	tetris_shapes [2][3] = 2;
	  }
      else if (block_shape == 2) {
	  	tetris_shapes [0][1] = 2;// *
	  	tetris_shapes [1][1] = 2;// *
	  	tetris_shapes [2][1] = 2;// * * *
	  	tetris_shapes [2][2] = 2;
	  	tetris_shapes [2][3] = 2;
	  }
	  else if (block_shape == 3) {
	  	tetris_shapes [1][0] = 2;// * * * *
	  	tetris_shapes [1][1] = 2;
	  	tetris_shapes [1][2] = 2;
	  	tetris_shapes [1][3] = 2;
	  }
	  else if (block_shape == 4) {
	  	tetris_shapes [1][1] = 2;// * *
	  	tetris_shapes [1][2] = 2;// * *
	  	tetris_shapes [2][1] = 2;
	  	tetris_shapes [2][2] = 2;
	  }
	  else if (block_shape == 5) {
	  	tetris_shapes [0][1] = 2;//   *
	  	tetris_shapes [1][1] = 2;//   *
	  	tetris_shapes [2][0] = 2;// * * *
	  	tetris_shapes [2][1] = 2;
	  	tetris_shapes [2][2] = 2;
	  }	  
	 
} 

void rendering_shapes () {	
// centering the game before printing first line
     draw_upcoming_shape(); // draws upcoing shape
     check_score(); // shows current score

	 //draws current shape
	for (unsigned int row {0} ; row < board_row ; row++){
	  	for (unsigned int column {0} ; column < board_column ; column++) {
	  		bool draw_shape = false;
	  		if (main_board [row] [column] != 0) {
	  			draw_shape = true;
	  		}
	  		
	  		 int local_r = row - piece_y;
	  		 int local_c = column - piece_x;
	  		
	  		if (local_r >= 0 && local_r < 4 && local_c >=0 && local_c < 4 && tetris_shapes [local_r] [local_c] > 0) {
	  			draw_shape = true;
	  		}
	  		if (draw_shape == true) {

				random_colour_picker();// for random colour of falling  blocks
				
				if (main_board [row] [column] == 1) {
				set_colour ("yellow");// for yellow colours of all locked blocks
				}
				
	  			std::cout << "[*]";
				set_colour ("reset");
	  		}
	  		else {
				set_colour ("red");
	  			std::cout << "[ ]";// all 0 elements will be printed in red
				set_colour ("reset");
	  		}
	  	}//for column
	  	std::cout << std::endl;
	  }//for row
	 draw_stored_shape ();
}

void clearScreen() {
    system ("cls");
    std::cout << "\033[?25l";
    //std::cout << "\033[2J\033[H";
}
void set_colour (std::string a) {
 if (a == "red") {std::cout << "\033[31m";}
 else if (a == "green") {std::cout << "\033[32m";}
 else if (a == "yellow") {std::cout << "\033[33m";}
 else if (a == "blue") {std::cout << "\033[34m";}
 else if (a == "cyan") {std::cout << "\033[36m";}
 else if (a == "magenta") {std::cout << "\033[35m";}
 else if (a == "reset") {std::cout << "\033[0m";}
}

void random_colour_picker () {
	if(random_colour == 1) {set_colour ("green");}
	else if (random_colour == 2) {set_colour ("reset");}// for white colour
	else if (random_colour == 3) {set_colour ("blue");}
	else if (random_colour == 4) {set_colour ("cyan");}
	else if (random_colour == 5) { set_colour ("magenta");
	}
 }
 void draw_upcoming_shape () {
	horizontal_padding (board_column*3 / 2 - 10); // each [ ] has  3 chars
	set_colour ("green");
	std::cout << ": [UPCOMING SHAPE] :" << std::endl;
	set_colour ("cyan");
	if (next_shape == 1) {
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "   [*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "[*][*][*][*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "            " << std::endl;
	}
	if (next_shape == 2) {
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "[*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "[*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "[*][*][*]" << std::endl;
	}
	if (next_shape == 3) {
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "[*][*][*][*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "            " << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "            " << std::endl;
	}
	if (next_shape == 4) {
		horizontal_padding (board_column*3 / 2 -  4);
		std::cout << "[*][*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  4);
		std::cout << "[*][*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  4);
		std::cout << "            " << std::endl;
	}
	if (next_shape == 5) {
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "   [*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "   [*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "[*][*][*]" << std::endl;
	}
	set_colour ("reset");
 }

 void draw_stored_shape () {
	horizontal_padding (board_column*3 / 2 - 9);
	set_colour("magenta");
	std::cout << ": [STORED-SHAPE] :" << std::endl;
	set_colour ("green");
	if (!stored_shape) {
		horizontal_padding (board_column*3 / 2 -  4);
		std::cout << "[EMPTY]" << std::endl;
	}
	if (stored_shape == 1) {
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "   [*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "[*][*][*][*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "            " << std::endl;
	}
	if (stored_shape == 2) {
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "[*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "[*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "[*][*][*]" << std::endl;
	}
	if (stored_shape == 3) {
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "[*][*][*][*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "            " << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "            " << std::endl;
	}
	if (stored_shape == 4) {
		horizontal_padding (board_column*3 / 2 -  4);
		std::cout << "[*][*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  4);
		std::cout << "[*][*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  4);
		std::cout << "            " << std::endl;
	}
	if (stored_shape == 5) {
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "   [*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "   [*]" << std::endl;
		horizontal_padding (board_column*3 / 2 -  6);
		std::cout << "[*][*][*]" << std::endl;
	}
	set_colour ("reset");

 }