#include "s21_decimal_test.h"
// Деление на "0"
START_TEST(s21_div_1) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 3);
}
// Делимое равно "0"
START_TEST(s21_div_2) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
// Делитель "1"
START_TEST(s21_div_3) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 1;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_div_4) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 10;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 50;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_5) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 12;
  value_2.bits[0] = 3;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 4;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_6) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 30;
  value_2.bits[0] = 3;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 10;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_7) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 300;
  value_2.bits[0] = 3;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 100;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_8) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 303;
  value_2.bits[0] = 3;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 101;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_9) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 3;
  value_2.bits[0] = 3;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 1;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_10) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 15;
  value_2.bits[0] = 3;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 5;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_11) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 18;
  value_2.bits[0] = 3;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 6;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_div_12) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 10;

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 50;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_13) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 12;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 4;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_14) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 30;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 10;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_15) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 300;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 100;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_16) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 303;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 101;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_17) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 3;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 1;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_18) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 15;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 5;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_19) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 18;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 6;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_20) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 10;

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 50;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_21) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 12;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 4;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_22) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 30;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 10;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_23) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 300;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 100;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_24) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 303;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 101;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_25) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 3;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 1;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_26) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 15;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 5;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_div_27) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 18;
  value_2.bits[0] = 3;

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 6;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

Suite *suite_div(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_DIV \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_add \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_div_1);
  tcase_add_test(test_case, s21_div_2);
  tcase_add_test(test_case, s21_div_3);
  tcase_add_test(test_case, s21_div_4);
  tcase_add_test(test_case, s21_div_5);
  tcase_add_test(test_case, s21_div_6);
  tcase_add_test(test_case, s21_div_7);
  tcase_add_test(test_case, s21_div_8);
  tcase_add_test(test_case, s21_div_9);
  tcase_add_test(test_case, s21_div_10);
  tcase_add_test(test_case, s21_div_11);
  tcase_add_test(test_case, s21_div_12);
  tcase_add_test(test_case, s21_div_13);
  tcase_add_test(test_case, s21_div_14);
  tcase_add_test(test_case, s21_div_15);
  tcase_add_test(test_case, s21_div_16);
  tcase_add_test(test_case, s21_div_17);
  tcase_add_test(test_case, s21_div_18);
  tcase_add_test(test_case, s21_div_19);
  tcase_add_test(test_case, s21_div_20);
  tcase_add_test(test_case, s21_div_21);
  tcase_add_test(test_case, s21_div_22);
  tcase_add_test(test_case, s21_div_23);
  tcase_add_test(test_case, s21_div_24);
  tcase_add_test(test_case, s21_div_25);
  tcase_add_test(test_case, s21_div_26);
  tcase_add_test(test_case, s21_div_27);

  return suite;
}
