#include "../../gui/tetris.h"

void create_field (GameInfo_t *A) {
    A->field = (int **)calloc(WIDTH, sizeof(int *)+ LENGHT*sizeof(int));
    A->field[0] = (int *)(A->field+WIDTH);
    for (int i=1; i<WIDTH; i++) {
        A->field[i]=A->field[0]+i*LENGHT;
    }
    for (int i=0; i<WIDTH; i++) {
        for (int j=0; j<LENGHT; j++) {
            if (j==0 || j ==LENGHT-1) {
                //'|'
                A->field[i][j]=1;
            }
            
            if (i==0 || i==WIDTH-1) {
                //'_'
                A->field[i][j]=1;
            }
        }
    }
    //массив для следующей фигуры
    A->next= (int **)calloc(FIG_ROWS, sizeof(int *) + FIG_ROWS*sizeof(int));
    for (int i=1; i<FIG_ROWS; i++) {
        A->next[i]=A->next[0] +i*FIG_ROWS;
    }
}

void delete_field (GameInfo_t *A) {
    if (A!=NULL || A->field!=NULL || A->next!=NULL) {
        free(A->field);
        free(A->next);
    }
}

//выделение памяти под фигуру
void create_fig(figure_t *A, int rows, int columns) {
    A->rows = rows;
    A->columns=columns;
    A->figure_now=(int **)calloc(rows, sizeof(int*)+columns*sizeof(int));
    //выделяем память по rows
    A->figure_now[0]=(int*)(A->figure_now+rows);
    for (int i=1; i<rows; i++) {
        A->figure_now[i]=A->figure_now[0]+i*columns;
    }
}

//очищаем фигуру
void delete_fig(figure_t *A) {
    if (A!=NULL || A->figure_now!=NULL) {
        free(A->figure_now);
        A->rows = 0;
        A->columns=0;
    }
}