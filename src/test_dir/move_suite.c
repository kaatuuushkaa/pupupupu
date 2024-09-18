#include "test.h"

START_TEST(test_move_1) {
  int action = ' ';
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = MOVING;
  figure_type fig_type;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      MOVING);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

START_TEST(test_move_2) {
  int action = KEY_DOWN;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = MOVING;
  figure_type fig_type;
  fig_type.is = 1;
  fig_type.js = 1;
  fig_type.ls = 1;
  fig_type.os = 0;
  fig_type.ss = 1;
  fig_type.ts = 1;
  fig_type.zs = 1;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  figure.figx = 19;
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      COLLIDED);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

START_TEST(test_move_3) {
  int action = KEY_LEFT;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = MOVING;
  figure_type fig_type;
  fig_type.is = 1;
  fig_type.js = 1;
  fig_type.ls = 1;
  fig_type.os = 0;
  fig_type.ss = 0;
  fig_type.ts = 1;
  fig_type.zs = 1;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  figure.figy = 0;
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      MOVING);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

START_TEST(test_move_4) {
  int action = KEY_RIGHT;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = MOVING;
  figure_type fig_type;
  fig_type.is = 1;
  fig_type.js = 1;
  fig_type.ls = 1;
  fig_type.os = 0;
  fig_type.ss = 1;
  fig_type.ts = 1;
  fig_type.zs = 1;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  figure.figy = 9;
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      MOVING);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

START_TEST(test_move_5) {
  int action = 27;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = MOVING;
  figure_type fig_type;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      EXIT_GAME);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

// START_TEST(test_move_6) {
//   int action = 1;
//   figure_t figure;
//   GameInfo_t info;
//   zero_stuct_info(&info);
//   create_field(&info);
//   State fsm_state = MOVING;
//   figure_type fig_type;
//   create_figure_now(&figure, 0, 0);
//   generation_and_formation_figure(&info, &fig_type, &figure);
//   ck_assert_int_eq(get_signal(&figure, userInput(action), &info, &fsm_state,
//   &fig_type), SHIFTING); remove_field_and_next(&info);
//   remove_figure_now(&figure);
// }
// END_TEST

Suite *move_suite(void) {
  Suite *suite = suite_create("move");
  TCase *tcase_core = tcase_create("move_case");
  tcase_add_test(tcase_core, test_move_1);
  tcase_add_test(tcase_core, test_move_2);
  tcase_add_test(tcase_core, test_move_3);
  tcase_add_test(tcase_core, test_move_4);
  tcase_add_test(tcase_core, test_move_5);
  // tcase_add_test(tcase_core, test_move_6);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
