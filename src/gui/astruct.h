#ifndef ASTRUCT_H
#define ASTRUCT_H

#include "tetris.h"

//текущая фигура
typedef struct {
    int rows;
    int columns;
    int **figure_now;
    int type_now;
    int figx, figy;
} figure_t;

//игровое поле
typedef struct {
    int **field; 
    int **next;
    int score;
    int high_score;
    int level;
    int speed;
    int pause;
} GameInfo_t;

//типы фигуры
typedef struct {
    int f1, f2, f3, f4, f5, f6, f7;
    int used_count;
    int next_type;
} figure_type;

//конструкция нового типа данных
//действия
typedef enum {
    Start,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action,
    NoAction
} UserAction_t;

typedef enum {
    START,
    SPAWN,
    MOVING,
    SHIFTING,
    COLLIDED,
    GAMEOEVER,
    EXIT
} State;

typedef struct {
    int x, y;
} cord_fig;

//описание каждой фигуры
//7-кол-во фигур
//1-кол-во ориентаций
//4-кол-во болков для фигуры
static const cord_fig fig_tet[7][1][4] = {
    {
        {{1,0}, {1, 1}, {1, 2}, {1, 3}},
    },
    {
        {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    },
    {
        {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    },
    {
        {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
    },
    {
        {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
    },
    {
        {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
    },
    {
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    }
};

typedef struct {
    int type;
    int position;
    cord_fig type_cord;
} tet_fig;

typedef struct {
    GameInfo_t *slay_tet;
    UserAction_t *slay_action;
    figure_type *slay_type;
    tet_fig *slay_tet_fig;
    figure_t *slay_fig;
} slay_fsm;

#endif