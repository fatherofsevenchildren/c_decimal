#include "s21_decimal_test.h"

void test_sets(void) {
  Suite *sets[] = {suite_add(),
                   suite_sub(),
                   suite_div(),
                   test_multiplication(),
                   test_other(),
                   suite_equal(),
                   suite_not_equal(),
                   suite_greater(),
                   suite_greater_or_equal(),
                   suite_less(),
                   suite_less_or_equal(),
                   test_convertation(),
                   NULL};

  for (Suite **current_set = sets; *current_set != NULL; current_set++) {
    run_set(*current_set);
  }
}
void run_set(Suite *current_set) {
  // Представляет собой окружение для запуска тестов. Запускает наш набор
  // тестов.
  SRunner *all_test = srunner_create(current_set);

  srunner_set_fork_status(all_test, CK_NOFORK);
  srunner_run_all(all_test, CK_NORMAL);

  srunner_free(all_test);
}
int main(void) {
  test_sets();
  return 0;
}
