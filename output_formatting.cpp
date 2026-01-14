#include "include.h"
#include "global_vars.h"
#include "game_logic.h"
#include "draw_and_render.h"
void get_terminal_size() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        terminal_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        terminal_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;//this func returns the height nd width of terminal in windows
    } else {
       terminal_width = 80;
       terminal_height  = 25;//if it cant do that for some reason,this is default terminal size most terminal in windows use
    }
}

void horizontal_padding(int a) {
    get_terminal_size();  
    for (int h_padding = 0 ; h_padding < a; h_padding++) {
		std::cout << " ";                                                                        
    }
}

/*
void verticle_padding (int a) {
    get_terminal_size();  
    for (int v_padding = 0 ; v_padding <= a; v_padding++) {
		std::cout << "\n";                                                                        
	} 
}
    */

void check_score () {
    horizontal_padding (board_column * 3/2 - 11);
    std::cout << "[ CURRENT SCORE : " << score << " ]" << std::endl;
}

void update_score () {
    if  (game_end || game_quit) {
      std::ifstream file ("tetris_highscore.txt");//try to read from the file
      if (!file) {//if it doesnot exists
      std::ofstream file;//create one
      file.open ("tetris_highscore.txt");
      file << " [HIGHSCORE] : " << score;//update current score as highscore
      file.close();// close file
      }
      file >> high_score; // read from file nd store it in highscore variable
      if (score > high_score) { // if its less than current score 
        std::ofstream file ("tetris_highscore.txt");
        file << score; // update it
        file.close();
        set_colour ("green");
        std::cout << " [ CONGRATULATIONS ON MAKING NEW HIGH SCORE ] " << std::endl;
        set_colour ("reset");
    } 

   }

}

int only_number () { // it only takes number input from cin and if anything else is pressed it rejects and loops
    int number;
    while (true) {
        set_colour ("green");
        std::cin >> number;
        set_colour ("reset");
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            set_colour("red");
            std::cout << "\n INVALID INPUT! CHOOSE FROM THE MENU ABOVE \n"<< std::endl;
            set_colour ("reset");
        } else {
              std::cin. ignore(std::numeric_limits<std::streamsize> :: max () , '\n'); 
            break;}
    }
    return number;
}


