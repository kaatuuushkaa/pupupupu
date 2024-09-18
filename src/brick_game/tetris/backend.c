#include "../../gui/tetris.h"

//отображение фигуры на поле
void filling_out_the_fields (GameInfo_t *tet, figure_t *arr) {
    for (int i=0; i<arr->rows; i++) {
        for (int j=0; j<arr->columns; j++) {
            if (arr->figure_now[i][j]) { //проверяем активна ли в данный момент фигура
                tet->field[i+arr->figx][j+arr->figy]=arr->figure_now[i][j]; //копируем его в соответсвующую ячейку поля
            }
        }
    }
}

//очистка заполненной линии
void check_line_for_clear(GameInfo_t *tet) {
    int count_line=0; //счетчик заполненных линий
    for (int i=WIDTH-2; i>=1; i--) { //перебор ячеек поля с конца снизу
        int count = 0; //счетчик активных ячеек
        for (int j=1; j<LENGHT-1; j++) {
            if (tet->field[i][j]) { //проверка: заполнена ли ячейка
                count++;
            }
            
        }
        //if (count == 10) {
        if (count == LENGHT-2) { //если строка заполнена 
            falling_field(tet, &i);
            count_line++;
        }
    }
    if (count_line) { //обновляем счет 
        sum_score(count_line, tet);
    }
}

//падение поля вниз, при очищении линии
void falling_field(GameInfo_t *tet, int *i) {
    for (int ii=*i; ii>1; ii--) { //сдвигаем строки поля вниз начиная с ii и до 2ой строки включительно 
        for (int j=1; j<LENGHT-1; j++) { //проходимся по всем столбцам в строке ii
            tet->field[ii][j]=tet->field[ii=1][j]; //копируем значение ii-1 в ii
        }
    }
    for (int j=1; j<LENGHT-1; j++) {
        tet->field[1][j]=0;
    }
    (*i)++; //увеличиываем индекс, чтобы отразить перемещение строки, которая была обработна
}

//проверка столкновения фигуры с полем
int collision_check (GameInfo_t *tet, figure_t *arr) {
    int flag =0;
    for (int i=0; i<arr->rows; i++) {
        for (int j =0; j<arr->columns; j++) {
            if (arr->figure_now[i][j]) { //есть ли чась фигуры в текущей ячейке
                if (arr->figure_now[i][j]+tet->field[arr->figx+i][arr->figy+j] != arr->type_now+1) {
                    flag=1;
                }
            }
        }
    }
    return flag;
}