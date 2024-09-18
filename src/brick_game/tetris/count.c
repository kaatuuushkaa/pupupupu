#include "../../gui/tetris.h"

//запись рекорда
void get_record (GameInfo_t *info) {
    FILE *rec = NULL;
    if ((rec=fopen("gui/save/record.txt", "r"))==NULL) { //если файла нет
        rec = fopen("gui/save/record.txt", "w"); //создаем файл
        fprintf(rec, "%d", info->high_score);
    } else {
        fscanf(rec, "%d", info->high_score); //иначе читаем файл и в инфо записываем рекорд
    }
    fclose(rec);
}

//перезапись рекорда
void set_record (GameInfo_t *info) {
    FILE *rec = NULL;
    rec = fopen ("gui/save/record.txt", "w");
    fprintf(rec, "%d", info->high_score);
    fclose(rec);
}

//заполнение инфо нулевыми значениями 
void struct_info (GameInfo_t *info) {
    info->field=NULL;
    info ->high_score=0;
    info->level=1;
    info ->next=NULL;
    info->pause=0;
    info ->score=0;
    info->speed=0;
    get_record(info);
}

//обновление скора в зависимости от очищенных линий
void sum_score(int count, GameInfo_t *tet_info) {
    switch(count) {
        case 1:
            tet_info->score+=100;
            break;
        case 2:
            tet_info->score+=200;
            break;
        case 3:
            tet_info ->score+=300;
            break;
        case 4:
            tet_info->score+=400;
            break;
        default:
            break;
    }
    if (tet_info->score > tet_info->high_score) {
        tet_info->high_score=tet_info->score;
    }
}

//при увеличении lvl растет и speed
void up_level_speed (GameInfo_t *tet_info) {
    tet_info->level = tet_info->score/300+1;
    if (tet_info->level>10) {
        tet_info->level=10;
    }
    tet_info->speed = tet_info->level;
}

int rand_fig (figure_type *fig) {
    int r = rand()%7;
    int flag =1;
    if (check_type(fig)) {
        zero_fig(fig);
    }
    while(flag) {
        flag =0;
        if (r==0 && !fig->f1) {
            fig ->f1=1;
        } else if (r==1 && !fig ->f2) {
            fig->f2=1;
        }else if (r==2 && !fig ->f3) {
            fig->f3=1;
        }else if (r==3 && !fig ->f4) {
            fig->f4=1;
        }else if (r==4 && !fig ->f5) {
            fig->f5=1;
        }else if (r==5 && !fig ->f6) {
            fig->f6=1;
        }else if (r==6 && !fig ->f7) {
            fig->f7=1;
        } else {
            flag =1;
            r=rand()%7;
        }
    }
    return r;
}

//проверка: были ли использованы все флаги
int check_type(figure_type *fig) {
    int flag = 0;
    if (fig->f1 && fig->f2 && fig->f3 && fig->f4 && fig->f5 && fig->f6 && fig->f7) {
        flag =1;
    }
    return flag;
}

//обнуление типа фиугры
void zero_fig(figure_type *fig) {
    fig->f1=0;
    fig->f2=0;
    fig->f3=0;
    fig->f4=0;
    fig->f5=0;
    fig->f6=0;
    fig->f7=0;
}

//фигуру переписываем во временную
void fil_fig(figure_t *tet, figure_t *tmp) {
    for (int i=0; i<tet->rows; i++) {
        for (int j=0; j<tet->columns; j++) {
            tmp->figure_now[i][j] = tet ->figure_now[i][j];
        }
    }
}

//вращение фигуры
void rotation_fig (figure_t *tet, GameInfo_t *info) {
    if(!rotation_check(tet, info)) { //проверяем возможно ли вращение
        figure_t tmp;
        create_fig(&tmp, tet->rows, tet->columns); //выделяем память для tmp
        fil_fig(tet, &tmp); //переписываем данные tet в tmp
        delete_fig(tet);
        create_fig(tet, tmp.columns, tmp.rows); //подготавливаем tet для записи после переворота фигуры
        for (int i=0; i<tet->rows; i++) {
            for (int j=0; j<tet->columns; j++) {
                tet->figure_now[i][j]=tmp.figure_now[tmp.rows-1-j][i]; //перреворачиваем
            }
        }
        delete_fig(&tmp);
    }
}

int rotation_check(figure_t *tet, GameInfo_t *info) {
    int flag = 0;
    //создаем временную фигуру по подобию tet
    figure_t check;
    create_fig(&check, tet->rows, tet->columns);

    //поворот матрицы на 90
    for (int i=0; i<tet->rows; i++) {
        for (int j=0; j<tet->columns; j++) {
            //транспонирование матрицы
            check.figure_now[i][j]=tet->figure_now[check.rows-1-j][i];
        }
    }    

    //проверка: не накладывается ли фигура на существующее поле
    for (int i=0; i<tet->rows; i++) {
        for (int j=0; j<tet->columns; j++) {
            if (check.figure_now[i][j]) { //активна ли клетка
                //+где будет размещена фигура[коор фиг + блоки в фиг]
                if(check.figure_now[i][j]+info->field[tet->figx+i][tet->figy+j] > tet->type_now+1) {
                    flag =1;
                }
            }
        }
    }
    delete_fig(&check);
    return flag;
}

//пауза
int pause_game(UserAction_t action, GameInfo_t *info) {
    //tab && esc
    while (action !='\t' && action != 27) {
        mvpritw(10, 3, "Pause");
        action = getch(); //считываем ввод пользователя
    }
    if (action == 27) {
        action = Terminate;
    }
    //снимаем паузу
    if (action == '\t') {
        info ->pause =0;
        action = NoAction;
    }
    return action;
}

int check_game_over (GameInfo_t *info) {
    int flag =1;
    //проверяем: чиста ли верхняя строка
    for (int i=1; i<LENGHT-1; i++) {
        if (i>3 && i<8) {
            if (info->field[1][i]) {
                flag = 0;
            }
        } 
    }
    return flag;
}