#ifndef TEST_H
#define TEST_H


#include <check.h>
#include "../gui/tetris.h"

Suite *move_suite(void);
Suite *collided_suite(void);
Suite *shifting_suite(void);
Suite *spawn_suite(void);
Suite *start_suite(void);
Suite *gameover_suite(void);

#endif
