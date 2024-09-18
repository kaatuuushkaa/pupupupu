#include "test.h"

int main() {
  int failed = 0;

  Suite* tetris_test[] = {move_suite(),  collided_suite(), shifting_suite(),
                          spawn_suite(), start_suite(),    gameover_suite(),
                          NULL};

  for (int i = 0; tetris_test[i] != NULL; i++) {
    printf("-----------------------------------------------\n      ");

    SRunner* sr = srunner_create(tetris_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);

    srunner_free(sr);
  }

  if (failed == 0) {
    printf(
        "\033[32m------------------- SUCCESS -------------------\033[0m\n\n");
  } else {
    printf("\033[31m------------------ FAILED: %d -----------------\033[0m\n\n",
           failed);
  }

  return (failed == 0) ? 0 : 1;
}
