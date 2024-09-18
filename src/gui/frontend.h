#ifndef FRONTEND_H
#define FRONTEND_H

#include "tetris.h"

void print_gameover (bool *flag, State *fsm_st, int sign, GameInfo_t *info, figure_t *tet);
void print_field(GameInfo_t *info, WINDOW *field_info, WINDOW *win, figure_t *fig);
void print_start (GameInfo_t *info, WINDOW *field_info, WINDOW *win);
void print_fig (WINDOW *win, GameInfo_t *info);
void print_win(WINDOW *win, GameInfo_t *info);

#endif