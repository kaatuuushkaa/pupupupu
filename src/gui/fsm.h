#ifndef FSM_H
#define FSM_H

#include "tetris.h"

//fsm.c
void move_fig_r (figure_t *tet, GameInfo_t *info);
void move_fig_l(figure_t *tet, GameInfo_t *info);
int move_fig_d (figure_t *tet, GameInfo_t *info);
int move_fig_d (figure_t *tet, GameInfo_t *info);
int pause_action(UserAction_t action, GameInfo_t *info);
void spawn_fun(State *fsm_st, figure_t *fig, figure_type *fig_type, GameInfo_t *info);
void shift_fun (figure_t *fig, GameInfo_t *info, State *fsm_st);
void start_fun (UserAction_t sign, State *fsm_st);
void collided_fun(State *fsm_st, figure_t *fig, GameInfo_t *info);
void move_fun (UserAction_t action, State *fsm_st, figure_t *fig, GameInfo_t *info);
UserAction_t UserInput(int action);
State get_signal (figure_t *fig, UserAction_t action, State *fsm_st, figure_type *fig_type, GameInfo_t *info);

#endif