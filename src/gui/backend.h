#ifndef BACKEND_H
#define BACKEND_H

#include "tetris.h"

//backend.c
void filling_out_the_fields(GameInfo_t *tet, figure_t *arr);
void check_line_for_clear(GameInfo_t *tet);
void falling_field(GameInfo_t *tet, int *i);
int collision_check (GameInfo_t *tet, figure_t *arr);

//count.c
void get_record (GameInfo_t *info);
void set_record (GameInfo_t *info);
void struct_info (GameInfo_t *info);
void sum_score(int count, GameInfo_t *tet_info);
void up_level_speed (GameInfo_t *tet_info);
int rand_fig (figure_type *fig);
int check_type(figure_type *fig);
void zero_fig(figure_type *fig);
void fil_fig(figure_t *tet, figure_t *tmp);
void rotation_fig (figure_t *tet, GameInfo_t *info);
int rotation_check(figure_t *tet, GameInfo_t *info);
int pause_game(UserAction_t action, GameInfo_t *info);
int check_game_over (GameInfo_t *info);

//create.c
void create_fig(figure_t *A, int rows, int columns);
void delete_fig(figure_t *A);
void create_field (GameInfo_t *A);
void delete_field (GameInfo_t *A);

//figure.c
void generate_figure (GameInfo_t *info, figure_type *fig, figure_t *fig_now);
void fil_next_fig(GameInfo_t *info, int type);
void zero_next_fig(GameInfo_t *info);
void memfig(figure_t *now_fig, GameInfo_t *info, int type);
void format_fig (GameInfo_t *info, figure_type *fig, figure_t *now_fig);

#endif