#ifndef DRAW_AND_RENDER_H
#define DRAW_AND_RENDER_H
#include <string>

int generaterandomnumber(int min, int max);
void clear_main_board ();
void draw_shapes ();
void rendering_shapes ();
void clearScreen();
void set_colour (std::string a);
void random_colour_picker();
void draw_upcoming_shape();
void draw_stored_shape ();

#endif