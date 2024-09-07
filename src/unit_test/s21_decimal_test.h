#include <check.h>

#include "../s21_decimal.h"

// Suite *test_arithmetic();
Suite *test_convertation(void);
Suite *test_other(void);
Suite *suite_equal(void);
Suite *suite_not_equal(void);
Suite *suite_greater(void);
Suite *suite_greater_or_equal(void);
Suite *suite_less(void);
Suite *suite_less_or_equal(void);
Suite *suite_add(void);
Suite *suite_sub(void);
Suite *test_multiplication(void);
Suite *suite_div(void);

void test_sets(void);
void run_set(Suite *current_set);