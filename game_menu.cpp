#include "include.h"
#include "global_vars.h"
#include "draw_and_render.h"
#include "collision.h"
#include "game_logic.h"
#include "input_handling.h"
#include "gravity.h"
#include "output_formatting.h"

void rulebook () {
    set_colour ("red");
    get_terminal_size();
    clearScreen();
    std::cout << "\033[1m";
    horizontal_padding(terminal_width/2 - 6);
    std::cout << "[ RULE-BOOK ]" << std::endl;

    for (int i = 0; i < terminal_width; i++)  {
    std::cout << ":";
    }
    std::cout << std::endl;
 
    set_colour ("green");
    horizontal_padding(terminal_width / 4);
    std::cout << "(1) : PLAYER GETS 100 POINTS FOR EACH ROW OF BLOCKS CLEARED" << std::endl;
    horizontal_padding(terminal_width / 4);
    std::cout << "(2) : PRESS a TO MOVE THE BLOCK LEFT" << std::endl;
    horizontal_padding(terminal_width / 4);
    std::cout << "(3) : PRESS d TO MOVE THE BLOCK RIGHT" << std::endl;
    horizontal_padding(terminal_width / 4);
    std::cout << "(4) : PRESS w TO ROTATE THE BLOCK" << std::endl;
    horizontal_padding(terminal_width / 4);
    std::cout << "(5) : PRESS d TO DROP THE BLOCK" << std::endl;
    horizontal_padding(terminal_width / 4);
    std::cout << "(6) : PRESS q TO QUIT THE GAME ANYTIME" << std::endl;
    horizontal_padding(terminal_width / 4);
    std::cout << "(7) : PRESS p TO PAUSE THE GAME" << std::endl;
    horizontal_padding(terminal_width / 4);
    std::cout << "(8) : PRESS f TO STORE A FALLING PIECE OR USE A STORED PIECE LATER" << std::endl;
     horizontal_padding(terminal_width / 4);
    std::cout << "      YOU CAN STORE MAXIMUM 1 PIECE AT A TIME " << std::endl;
    horizontal_padding(terminal_width / 4);
    std::cout << "(9) : DO NOT HOLD A KEY , ONLY KEY PRESS " << std::endl;
    set_colour (red);
    for (int i = 0; i < terminal_width; i++)  {
    std::cout << ":";
    }
    set_colour ("reset");

}

void check_highscore() {
    clearScreen();
     get_terminal_size();
     std::cout << "\033[1m";
    set_colour("red");
for (int i = 0; i < terminal_width; i++)  {
std::cout << ":";
 }
 std::cout << std::endl;
 std::cout << std::endl;

 horizontal_padding(terminal_width/2 - 15);

    std::ifstream file ("tetris_highscore.txt");
    if (!file) {
        std::cout << "[ CURRENT HIGHSCORE IS : 0]" << std::endl;
    }
    else {
    file >> high_score;
    std::cout << "[ CURRENT HIGHSCORE IS :" <<high_score<< "]" <<std::endl;
    file.close();}

    std::cout << std::endl;
for (int i = 0; i < terminal_width; i++)  {
std::cout << ":";
 }
    set_colour (reset);
}

void play_game() {

    collision = true;  //to spawn the first piece as my code spawn a piece after collision
    game_end = false;  // to reset for replability
    game_quit = false; //to reset for replability
    score = 0;
    stored_shape = 0;

    clear_main_board(); //clearing main board

	  while (true) {
	   spawn_new_piece();
	   gravity();
	   if (game_end == true) break;
	   if (game_quit == true) break;
	  }
      update_score();
      return;
}

void about_game () {
    get_terminal_size();
    clearScreen();
    set_colour ("red");
    for (int i = 0; i < terminal_width; i++)  {
    std::cout << ":";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    set_colour("yellow");

    std::cout << " HELLO! , I am Rohan Deb , currently studying in 1st year of college as of 2025 " << std::endl;
    std::cout << " i have added random shape generation,shape rendering in main board,physics in form of" << std::endl;
    std::cout << " rotation and gravity and collision detection, user input detection and movement accordingly." << std::endl;
    std::cout << " i have also added frame redrawing,colours and saving the current high score in file and also" << std::endl;
    std::cout << " reading from it in realtime in c++ terminal without using any external frameworks." << std::endl;
    std::cout << " hope you will like it :)" << std::endl;
    std::cout << " for any Feedback, drop a MAIL at : ";
    set_colour ("green");
    std::cout << "rohandeb232@gmail.com" << std ::endl;
    set_colour ("reset");
    std::cout << std::endl;

    set_colour ("red");
    for (int i = 0; i < terminal_width; i++)  {
    std::cout << ":";
    }
    set_colour ("reset");
 
}

void print_menu () {
std::cout << std::endl;
 std::cout << "\033[1m";
set_colour ("magenta");
std::cout << " [PRESS 1] : [PLAY] " << std::endl;
std::cout << " [PRESS 2] : [RULEBOOK] " << std::endl;
std::cout << " [PRESS 3] : [HIGHSCORE] " << std::endl;
std::cout << " [PRESS 4] : [ABOUT GAME] " << std::endl;
std::cout << " [PRESS 5] : [QUIT] " << std::endl;
set_colour("reset");
}

void game_loop() {
    get_terminal_size();
    //opening screen
    set_colour ("cyan");
     std::cout << "\033[1m";

for (int i = 0; i < terminal_width; i++)  {
std::cout << ":";
 }
 std::cout << std::endl;
 std::cout << std::endl;

 set_colour ("yellow");
 horizontal_padding(terminal_width/2 - 10);
 std::cout << " [ TERMINAL-TETRIS ]" << std::endl;
 horizontal_padding(terminal_width/2 - 5);
 std::cout << "~~ MADE BY BEE (ROHAN DEB)" << std::endl;
 std::cout << std::endl;

 set_colour ("cyan");
 for (int i = 0; i < terminal_width; i++)  {
std::cout << ":";
 }
 set_colour ("reset");

    while (true) {
       print_menu();
       get_terminal_size();
    int user_action = only_number();
    if (user_action == 1) play_game();
    if (user_action == 2) rulebook();
    if (user_action == 3) check_highscore();
    if (user_action == 4) about_game();
    if (user_action == 5 || game_quit) break;

    }
}