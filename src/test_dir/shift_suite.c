#include "test.h"

START_TEST(test_shifting_1) {
  int action = KEY_DOWN;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = SHIFTING;
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

START_TEST(test_shifting_2) {
  int action = KEY_LEFT;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = SHIFTING;
  figure_type fig_type;
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

Suite *shifting_suite(void) {
  Suite *suite = suite_create("shifting");
  TCase *tcase_core = tcase_create("shifting_case");
  tcase_add_test(tcase_core, test_shifting_1);
  tcase_add_test(tcase_core, test_shifting_2);
  suite_add_tcase(suite, tcase_core);
  return suite;
}