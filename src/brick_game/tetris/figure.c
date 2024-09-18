#include "../../gui/tetris.h"

void generate_figure (GameInfo_t *info, figure_type *fig, figure_t *fig_now) {
    fig_now->figx=1;
    fig_now->figy=4;
    //проверка: создана ли фигура
    if (fig_now->columns==0) { //если нет
        format_fig(info, fig, fig_now);
    } else {
        //выделяем память для след фигуры
        create_memfig(fig_now, info, fig->next_type);
        //обновляем текущий тип фигуры, чтобы он соответствовал следующему выбранному типу
        fig_now->type_now=fig->next_type;
        fig->next_type=random_fig(fig);

        //заполняем информацию о след фигуре
        fil_next_fig(info, fig->next_type);
    }
}

//заполнение следующей фигуры
void fil_next_fig(GameInfo_t *info, int type) {
    zero_next_fig(info);
    for (int i=0; i<FIG_ROWS; i++) {
        //заполняем так, чтобы отобразить следующую фигуру, используя координаты fig_tet
        info->next[fig_tet[type][0][i].x][fig_tet[type][0][i].y] = type+1;
    }
}

void zero_next_fig(GameInfo_t *info) {
    for (int i=0; i<FIG_ROWS; i++) {
        for (int j=0; j<FIG_ROWS; j++) {
            if (info->next[i][j]) {
                info->next[i][j]=0;
            }
        }
    }
}

void memfig(figure_t *now_fig, GameInfo_t *info, int type) {
    if (now_fig->columns !=0) { //если фигура не пустая
        delete_fig(now_fig); //чистим
    }
    //в зависимости от типа, выделяем блоки для фигуры
    if (!type) {
        create_fig(now_fig, 4, 4);
    } else if (type==1) {
        create_fig(now_fig, 2, 2);
    } else {
        create_fig(now_fig, 3, 3);
    }
    for (int i=0; i<now_fig->rows; i++) {
        for (int j=0; j<now_fig->columns; j++) {
            //заполнение фигуры запланироваными данными
            now_fig->figure_now[i][j]=info->next[i][j];
        }
    }
}

//инициализация фигуры
void format_fig (GameInfo_t *info, figure_type *fig, figure_t *now_fig) {
    //fig->next_type=rand()%7;
    //меняем тип фигуры
    fig->next_type=rand_fig(fig);
    //текущая фигура получает выбранный ранее тип
    now_fig->type_now=fig->next_type;
    //выделяем память и заполняем данные
    fil_next_fig(info, fig->next_type);
    create_memfig(now_fig, info, fig->next_type);
    //после того, как текущая фигура создана - выбираем тип для следующей
    fig->next_type=rand_fig(fig);
    //обновляем инфу о след фигуре
    fil_next_fig(info, fig->next_type);
}