#include "gravity.h"
#include "global_vars.h"
#include "include.h"
#include "collision.h"
#include "game_logic.h"
#include "input_handling.h"
#include "draw_and_render.h"

void gravity () {
while (true) {
	if (game_quit) break; // so if player presses q we break current gravity loop and in main func we break game loop
 std::this_thread::sleep_for(std::chrono::milliseconds (delay));
   delay = 450;// default_gravity delay;

   if (hit_bottom(tetris_shapes)) {
	  lock_piece ();
	  game_running();
	  clear_and_drop();
	  collision = true;
	  break;}
      else {
	     piece_y++;
         handle_input();
	     clearScreen();
	     rendering_shapes();
         }
 }//while
}