#include "test.h"

START_TEST(test_collided_1) {
  int action = KEY_DOWN;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = COLLIDED;
  figure_type fig_type;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  info.field[2][1] = 1;
  info.field[2][2] = 1;
  info.field[2][3] = 1;
  info.field[2][4] = 1;
  info.field[2][5] = 1;
  info.field[2][6] = 1;
  info.field[2][7] = 1;
  info.field[2][8] = 1;
  info.field[2][9] = 1;
  info.field[2][10] = 1;
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      SPAWN);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

START_TEST(test_collided_2) {
  int action = KEY_LEFT;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = COLLIDED;
  figure_type fig_type;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  info.field[1][4] = 1;
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      GAMEOVER);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

START_TEST(test_collided_3) {
  int action = KEY_DOWN;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = COLLIDED;
  figure_type fig_type;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  info.field[2][1] = 1;
  info.field[2][2] = 1;
  info.field[2][3] = 1;
  info.field[2][4] = 1;
  info.field[2][5] = 1;
  info.field[2][6] = 1;
  info.field[2][7] = 1;
  info.field[2][8] = 1;
  info.field[2][9] = 1;
  info.field[2][10] = 1;
  info.field[3][1] = 1;
  info.field[3][2] = 1;
  info.field[3][3] = 1;
  info.field[3][4] = 1;
  info.field[3][5] = 1;
  info.field[3][6] = 1;
  info.field[3][7] = 1;
  info.field[3][8] = 1;
  info.field[3][9] = 1;
  info.field[3][10] = 1;
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      SPAWN);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

START_TEST(test_collided_4) {
  int action = KEY_DOWN;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = COLLIDED;
  figure_type fig_type;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  info.field[2][1] = 1;
  info.field[2][2] = 1;
  info.field[2][3] = 1;
  info.field[2][4] = 1;
  info.field[2][5] = 1;
  info.field[2][6] = 1;
  info.field[2][7] = 1;
  info.field[2][8] = 1;
  info.field[2][9] = 1;
  info.field[2][10] = 1;
  info.field[3][1] = 1;
  info.field[3][2] = 1;
  info.field[3][3] = 1;
  info.field[3][4] = 1;
  info.field[3][5] = 1;
  info.field[3][6] = 1;
  info.field[3][7] = 1;
  info.field[3][8] = 1;
  info.field[3][9] = 1;
  info.field[3][10] = 1;
  info.field[4][1] = 1;
  info.field[4][2] = 1;
  info.field[4][3] = 1;
  info.field[4][4] = 1;
  info.field[4][5] = 1;
  info.field[4][6] = 1;
  info.field[4][7] = 1;
  info.field[4][8] = 1;
  info.field[4][9] = 1;
  info.field[4][10] = 1;
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      SPAWN);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

START_TEST(test_collided_5) {
  int action = KEY_DOWN;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = COLLIDED;
  figure_type fig_type;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  info.field[2][1] = 1;
  info.field[2][2] = 1;
  info.field[2][3] = 1;
  info.field[2][4] = 1;
  info.field[2][5] = 1;
  info.field[2][6] = 1;
  info.field[2][7] = 1;
  info.field[2][8] = 1;
  info.field[2][9] = 1;
  info.field[2][10] = 1;
  info.field[3][1] = 1;
  info.field[3][2] = 1;
  info.field[3][3] = 1;
  info.field[3][4] = 1;
  info.field[3][5] = 1;
  info.field[3][6] = 1;
  info.field[3][7] = 1;
  info.field[3][8] = 1;
  info.field[3][9] = 1;
  info.field[3][10] = 1;
  info.field[4][1] = 1;
  info.field[4][2] = 1;
  info.field[4][3] = 1;
  info.field[4][4] = 1;
  info.field[4][5] = 1;
  info.field[4][6] = 1;
  info.field[4][7] = 1;
  info.field[4][8] = 1;
  info.field[4][9] = 1;
  info.field[4][10] = 1;
  info.field[5][1] = 1;
  info.field[5][2] = 1;
  info.field[5][3] = 1;
  info.field[5][4] = 1;
  info.field[5][5] = 1;
  info.field[5][6] = 1;
  info.field[5][7] = 1;
  info.field[5][8] = 1;
  info.field[5][9] = 1;
  info.field[5][10] = 1;
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      SPAWN);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

Suite *collided_suite(void) {
  Suite *suite = suite_create("colleded");
  TCase *tcase_core = tcase_create("colleded_case");
  tcase_add_test(tcase_core, test_collided_1);
  tcase_add_test(tcase_core, test_collided_2);
  tcase_add_test(tcase_core, test_collided_3);
  tcase_add_test(tcase_core, test_collided_4);
  tcase_add_test(tcase_core, test_collided_5);
  suite_add_tcase(suite, tcase_core);
  return suite;
}