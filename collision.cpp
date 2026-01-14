#include "collision.h"
#include "global_vars.h"

bool hit_bottom (int arr [4] [4]) {
	  	for (unsigned int shape_row = 0; shape_row < 4 ; shape_row++) {
	  		for (unsigned int shape_column = 0; shape_column < 4 ; shape_column ++) {
	  		int board_r = piece_y + shape_row;
	  		int board_c = piece_x + shape_column;
	  		if ( arr [shape_row] [shape_column] == 0) continue;
	  					int next_row = piece_y + shape_row + 1;
	  			if (next_row >= board_row || main_board [next_row] [board_c] == 1) {
	  				return true;}
	  			}//for column	  			  		
	  		}//for row
	  		return false;
}

bool hit_left (int arr [4] [4]) {
	for ( int shape_row = 0; shape_row <4 ; shape_row++) {
		for ( int shape_column = 0; shape_column < 4 ; shape_column ++) {
		int board_r = piece_y + shape_row;
	    int board_c = piece_x + shape_column;
	    if (arr [shape_row] [shape_column] == 0) continue;
	        int next_column = piece_x + shape_column - 1;
	    if (next_column < 0) {
	    	return true;
	    }
        if (main_board[board_r][next_column]==1) {
            return true;
        }
		}//for column		
	}//for row
	return false;
}

bool hit_right (int arr [4] [4]) {
	for ( int shape_row = 0; shape_row <4 ; shape_row++) {
		for (unsigned int shape_column = 0; shape_column < 4 ; shape_column ++) {
		int board_r = piece_y + shape_row;
	    int board_c = piece_x + shape_column;
	    if (arr [shape_row] [shape_column] == 0) continue;
	    int next_column = piece_x + shape_column + 1;
	    if (next_column >= board_column) return true;
        if ( main_board [board_r] [next_column] == 1 ) {
	    	return true;
	    }
	    
		}//for column		
	}//for row
	return false;
}

bool hit_bottom (int a) {
	int demo_piece [4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	if (a == 1) {
	  	demo_piece [1][1] = 2;//   *    
	  	demo_piece [2][0] = 2;// * * * *   
	  	demo_piece [2][1] = 2;
	  	demo_piece [2][2] = 2;
	  	demo_piece [2][3] = 2;
	  }
      else if (a == 2) {
	  	demo_piece [0][1] = 2;// *
	  	demo_piece [1][1] = 2;// *
	  	demo_piece [2][1] = 2;// * * *
	  	demo_piece [2][2] = 2;
	  	demo_piece [2][3] = 2;
	  }
	  else if (a == 3) {
	  	demo_piece [1][0] = 2;// * * * *
	  	demo_piece [1][1] = 2;
	  	demo_piece [1][2] = 2;
	  	demo_piece [1][3] = 2;
	  }
	  else if (a == 4) {
	  	demo_piece [1][1] = 2;// * *
	  	demo_piece [1][2] = 2;// * *
	  	demo_piece [2][1] = 2;
	  	demo_piece [2][2] = 2;
	  }
	  else if (a == 5) {
	  	demo_piece [0][1] = 2;//   *
	  	demo_piece [1][1] = 2;//   *
	  	demo_piece [2][0] = 2;// * * *
	  	demo_piece [2][1] = 2;
	  	demo_piece [2][2] = 2;
	  }	 
	  	for (unsigned int shape_row = 0; shape_row < 4 ; shape_row++) {
	  		for (unsigned int shape_column = 0; shape_column < 4 ; shape_column ++) {
	  		int board_r = piece_y + shape_row;
	  		int board_c = piece_x + shape_column;
	  		if ( demo_piece [shape_row] [shape_column] == 0) continue;
	  					int next_row = piece_y + shape_row + 1;
	  			if (next_row >= board_row || main_board [next_row] [board_c] == 1) {
	  				return true;}
	  			}//for column	  			  		
	  		}//for row
	  		return false;
}

bool hit_left (int a) {
	int demo_piece [4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	if (a == 1) {
	  	demo_piece [1][1] = 2;//   *    
	  	demo_piece [2][0] = 2;// * * * *   
	  	demo_piece [2][1] = 2;
	  	demo_piece [2][2] = 2;
	  	demo_piece [2][3] = 2;
	  }
      else if (a == 2) {
	  	demo_piece [0][1] = 2;// *
	  	demo_piece [1][1] = 2;// *
	  	demo_piece [2][1] = 2;// * * *
	  	demo_piece [2][2] = 2;
	  	demo_piece [2][3] = 2;
	  }
	  else if (a == 3) {
	  	demo_piece [1][0] = 2;// * * * *
	  	demo_piece [1][1] = 2;
	  	demo_piece [1][2] = 2;
	  	demo_piece [1][3] = 2;
	  }
	  else if (a == 4) {
	  	demo_piece [1][1] = 2;// * *
	  	demo_piece [1][2] = 2;// * *
	  	demo_piece [2][1] = 2;
	  	demo_piece [2][2] = 2;
	  }
	  else if (a == 5) {
	  	demo_piece [0][1] = 2;//   *
	  	demo_piece [1][1] = 2;//   *
	  	demo_piece [2][0] = 2;// * * *
	  	demo_piece [2][1] = 2;
	  	demo_piece [2][2] = 2;
	  }

	for ( int shape_row = 0; shape_row <4 ; shape_row++) {
		for ( int shape_column = 0; shape_column < 4 ; shape_column ++) {
		int board_r = piece_y + shape_row;
	    int board_c = piece_x + shape_column;
	    if (demo_piece [shape_row] [shape_column] == 0) continue;
	        int next_column = piece_x + shape_column - 1;
	    if (next_column < 0) {
	    	return true;
	    }
        if (main_board[board_r][next_column]==1) {
            return true;
        }
		}//for column		
	}//for row
	return false;
}

bool hit_right (int a) {
	int demo_piece [4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	if (a == 1) {
	  	demo_piece [1][1] = 2;//   *    
	  	demo_piece [2][0] = 2;// * * * *   
	  	demo_piece [2][1] = 2;
	  	demo_piece [2][2] = 2;
	  	demo_piece [2][3] = 2;
	  }
      else if (a == 2) {
	  	demo_piece [0][1] = 2;// *
	  	demo_piece [1][1] = 2;// *
	  	demo_piece [2][1] = 2;// * * *
	  	demo_piece [2][2] = 2;
	  	demo_piece [2][3] = 2;
	  }
	  else if (a == 3) {
	  	demo_piece [1][0] = 2;// * * * *
	  	demo_piece [1][1] = 2;
	  	demo_piece [1][2] = 2;
	  	demo_piece [1][3] = 2;
	  }
	  else if (a == 4) {
	  	demo_piece [1][1] = 2;// * *
	  	demo_piece [1][2] = 2;// * *
	  	demo_piece [2][1] = 2;
	  	demo_piece [2][2] = 2;
	  }
	  else if (a == 5) {
	  	demo_piece [0][1] = 2;//   *
	  	demo_piece [1][1] = 2;//   *
	  	demo_piece [2][0] = 2;// * * *
	  	demo_piece [2][1] = 2;
	  	demo_piece [2][2] = 2;
	  }

	for ( int shape_row = 0; shape_row <4 ; shape_row++) {
		for (unsigned int shape_column = 0; shape_column < 4 ; shape_column ++) {
		int board_r = piece_y + shape_row;
	    int board_c = piece_x + shape_column;
	    if (demo_piece [shape_row] [shape_column] == 0) continue;
	    int next_column = piece_x + shape_column + 1;
	    if (next_column >= board_column) return true;
        if ( main_board [board_r] [next_column] == 1 ) {
	    	return true;
	    }
	    
		}//for column		
	}//for row
	return false;
}