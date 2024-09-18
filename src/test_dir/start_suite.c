#include "test.h"

START_TEST(test_start_1) {
  int action = KEY_DOWN;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = START;
  figure_type fig_type;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      START);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

START_TEST(test_start_2) {
  int action = 1;
  userInput(action);
  action = '\n';
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = START;
  figure_type fig_type;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      SPAWN);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

START_TEST(test_start_3) {
  int action = '\t';
  userInput(action);
  action = 27;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = START;
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

Suite *start_suite(void) {
  Suite *suite = suite_create("starting");
  TCase *tcase_core = tcase_create("starting_case");
  tcase_add_test(tcase_core, test_start_1);
  tcase_add_test(tcase_core, test_start_2);
  tcase_add_test(tcase_core, test_start_3);
  suite_add_tcase(suite, tcase_core);
  return suite;
}