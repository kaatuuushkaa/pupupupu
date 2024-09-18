#include "../tetris.h"

//переписать имена переменных в фронтенде

int main () {
    srand(time(NULL));
    initscr();
    nodelay(stdscr, true);
    scrollok(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
    noecho();
    create_play();
    endwin();
    return 0;
}

void create_play() {
    GameInfo_t kek;
    struct_info(&kek);
    create_field(&kek);
    gameplay(&kek);
}

void gameplay(GameInfo_t *kek) {
    WINDOW *field_info = newwin(WIDTH, LENGHT, 0, 0);
    WINDOW *win = newwin(WIDTH, LENGHT, 0, 12);
    figure_type st_type;
    figure_t tipa;
    create_fig(&tipa, 0, 0);
    bool flag_tet = TRUE;
    State fsm_st = START;
    int sign=0;

    while (flag_tet) {
        delay_output(50);
        if (fsm_st == GAMEOVER || fsm_st == EXIT) {
            print_gameover(&flag_tet, &fsm_st, sign , kek, &tipa);
        } else {
            if (fsm_st ==MOVING || fsm_st ==START) {
                sign = getch();
            }
            get_signal(&tipa, UserInput(sign), kek, &fsm_st, &type_st);
            if (fsm_st ==START) {
                print_start(kek, field_info, win);
            } else if {
                print_field(kek, field_info, win, &tipa);
            }
        }
    }
}