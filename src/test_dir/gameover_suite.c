#include "test.h"

START_TEST(test_gameover_1) {
  int action = KEY_DOWN;
  figure_t figure;
  GameInfo_t info;
  zero_stuct_info(&info);
  create_field(&info);
  State fsm_state = GAMEOVER;
  figure_type fig_type;
  create_figure_now(&figure, 0, 0);
  generation_and_formation_figure(&info, &fig_type, &figure);
  ck_assert_int_eq(
      get_signal(&figure, userInput(action), &info, &fsm_state, &fig_type),
      GAMEOVER);
  remove_field_and_next(&info);
  remove_figure_now(&figure);
}
END_TEST

Suite *gameover_suite(void) {
  Suite *suite = suite_create("starting");
  TCase *tcase_core = tcase_create("starting_case");
  tcase_add_test(tcase_core, test_gameover_1);
  suite_add_tcase(suite, tcase_core);
  return suite;
}