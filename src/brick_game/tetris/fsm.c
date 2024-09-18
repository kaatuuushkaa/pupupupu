#include "../../gui/tetris.h"

void move_fig_r (figure_t *tet, GameInfo_t *info) {
    tet->figy++;
    //если возможно столкновение с другими фигурами - возращаем в исходное состояние
    if (collision_check(info, tet)) {
        tet->figy--;
    }
}

void move_fig_l(figure_t *tet, GameInfo_t *info) {
    tet->figy--;
    if (collision_check(info, tet)) {
        tet->figy++;
    }
}

//возвращаем, потому что нужно сигнализировать - завершилось ли столкновение
int move_fig_d (figure_t *tet, GameInfo_t *info) {
    int flag =1;
    tet->figx++;
    if (collision_check(info, tet)) {
        tet->figx--;
        flag=0;
    }
    return flag;
}

int pause_action(UserAction_t action, GameInfo_t *info) {
    //int flag = action;
    if (action ==Pause) {
        if (info->pause==0) {
            info->pause=1;
        }
        //flag = pause_game(action, info);
        action = pause_game(action, info);
    }
    //return flag;
    return action;
}

//создаем новую фигуру и даем ей статус moving
void spawn_fun(State *fsm_st, figure_t *fig, figure_type *fig_type, GameInfo_t *info) {
    generate_figure(info, fig_type, fig);
    *fsm_st = MOVING;
}

void shift_fun (figure_t *fig, GameInfo_t *info, State *fsm_st) {
    if (!move_fig_d(fig, info)) {
        //если столкнулись - статус:столкновение
        *fsm_st=COLLIDED;
    } else {
        *fsm_st = MOVING;
    }
}

void start_fun (UserAction_t sign, State *fsm_st) {
    switch(sign) {
        case Start:
            //начало новой игры, где происходит генерация новой фигуры
            *fsm_st = SPAWN;
            break;
        case Terminate:
            *fsm_st= EXIT;
            break;
        default:
            //игра еще не начата
            *fsm_st = START;
            break;
    }
}

void collided_fun(State *fsm_st, figure_t *fig, GameInfo_t *info) {
    if (!check_game_over(info)) {
        *fsm_st=GAMEOEVER;
    } else {
        up_level_speed(info);
        //текущая фигура становится частью уже существующих фигур
        filling_out_the_fields(info, fig);
        check_line_for_clear(info);
        *fsm_st=SPAWN;
    }
}

void move_fun (UserAction_t action, State *fsm_st, figure_t *fig, GameInfo_t *info) {
    int slay_fig =1;
    switch (action) {
        case Down:
            if (!(slay_fig=move_fig_d(fig, info))) {
                *fsm_st = COLLIDED;
            }
            break;
        case Left:
            move_fig_l(fig, info);
            break;
        case Right:
            move_fig_r(fig, info);
            break;
        case Action:
            rotation_fig(fig, info);
            break;
        case Pause:
            if (pause_action(action, info)==Terminate) {
                *fsm_st=EXIT;
            }
            break;
        case Terminate:
            *fsm_st = EXIT;
            break;
        default:
            delay_output(300-(info->level*25));
            if (*fsm_st!=EXIT) {
                if (!slay_fig) {
                    *fsm_st=COLLIDED;
                } else {
                    *fsm_st=SHIFTING;
                }
            }
            break;
    }
}

UserAction_t UserInput(int action) {
    UserAction_t sign;
    switch(action) {
        case KEY_DOWN:
            sign = Down;
            break;
        case KEY_LEFT:
            sign = Left;
            break;
        case KEY_RIGHT:
            sign = Right;
            break;
        case ' ':
            sign = Action;
            break;
        case '\n':
            sign = Start;
            break;
        case '\t':
            sign = Pause;
            break;
        case 27:
            sign = Terminate;
            break;
        default:
            sign = NoAction;
            break;
    }
    return sign;
}

State get_signal (figure_t *fig, UserAction_t action, State *fsm_st, figure_type *fig_type, GameInfo_t *info) {
    switch (*fsm_st) {
        case START:
            start_fun(action, fsm_st);
            break;
        case SPAWN:
            spawn_fun(fsm_st, fig, fig_type,info);
            break;
        case MOVING:
            move_fun(action, fsm_st, fig, info);
            break;
        case SHIFTING:
            shift_fun(fig, info, fsm_st);
            break;
        case COLLIDED:
            collided_fun(fsm_st, fig, info);
            break;
        case GAMEOEVER:
            break;
        default:
            break;
    }
    return *fsm_st;
}

