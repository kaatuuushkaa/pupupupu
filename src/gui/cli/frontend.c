#include "../tetris.h"

//переписать имена переменных в фронтенде

void print_gameover (bool *flag_tet, State *fsm_st, int sign, GameInfo_t *info, figure_t *tet) {
    *flag_tet = FALSE;
    delete_field(info);
    delete_fig(tet);
    if (*fsm_st == GAMEOEVER) {
        set_record(info);
        clear();
        while (sign != '\n' && sign != 27) {
            refresh();
            mvprintw(7, 2, "GameOver");
            mvprintw(9, 3, "Return");
            mvprintw(10, 2, "To enter");
            mvprintw(12, 4, "Exit");
            mvprintw(13, 3, "To Esc");
            sign = getch();
            if (sign == '\n') {
                struct_info(info);
                create_fig(tet, 0, 0);
                create_field(info);
                *flag_tet = TRUE;
                *fsm_st = START;
            }
        }
        clear();
    }
}

void print_start (GameInfo_t *info, WINDOW *field_info, WINDOW *win) {
    clear();
    refresh();
    box(field_info, 0, 0);
    box(win, 0, 0);
    mvwprintw(field_info, 10, 2, "Press To");
    mvwprintw(field_info, 11, 3, "Enter");
    print_win(win, info);
    wrefresh(win);
    wclear(win);
    wclear(field_info);
}

void print_field(GameInfo_t *info, WINDOW *field_info, WINDOW *win, figure_t *fig) {
    clear();
    refresh();
    for (int i=0; i<WIDTH-1; i++) {
        for (int j=0; j<LENGHT-1; j++) {
            if (info->field[i][j]) {
                mvwprintw(field_info, i, j, "%d", info->field[i][j]);
            } else {
                mvwprintw(field_info, i, j, " ");
            }
        }
    }
    for (int i=0; i<fig->rows; i++) {
        for (int j=0; j<fig->columns; j++) {
            if (fig->figure_now[i][j]) {
                mvwprintw(field_info, i+fig->figx, j + fig->figy, "%d", fig ->type_now+1);
            }
        }
        
    }
    wrefresh(field_info);
    box(win, 0, 0);
    box(field_info,0, 0);
    print_win(win, info);
    print_fig(win, info);
    wrefresh(win);
    wrefresh(field_info);
    wclear(win);
    wclear(field_info);
}

void print_figura (WINDOW *win, GameInfo_t *info) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            mvwprintw(win, 15+i, 2+j, "%d", info->next[i][j]);
        }
    }
}

void print_win(WINDOW *win, GameInfo_t *info) {
    mvwprintw(win, 1, 1, "Score");
    mvwprintw(win, 2, 2, "%d", info->score);
    mvwprintw(win, 4, 1, "High Score");
    mvwprintw(win, 5, 2, "%d", info->high_score);
    mvwprintw(win, 7, 1, "Level");
    mvwprintw(win, 8, 2, "%d", info->level);
    mvwprintw(win, 10, 1, "Speed");
    mvwprintw(win, 11, 2, "%d", info->speed);
    mvwprintw(win, 14, 1, "Next");
    print_fig(win, info);
}