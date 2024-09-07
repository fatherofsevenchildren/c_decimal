#include "s21_decimal_test.h"

#define s21_TRUE 1
#define IS_POS_INF 1

#define ERROR_P_INF 1
#define ERROR_N_INF 2

s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

// Положительные числа c одинаковыми степенями
START_TEST(s21_add_positive_numbers_1) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 1000;

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_2) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 600;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 1100;

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_3) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 600;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 1100;

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_4) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 500;

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_5) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 500;

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_6) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 0;

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
// Положительные числа c разными степенями
START_TEST(s21_add_positive_numbers_7) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 50000500;
  s21_set_scale(&check, 5);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_8) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 600;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 60000500;
  s21_set_scale(&check, 5);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_9) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 600;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 50000600;
  s21_set_scale(&check, 5);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_10) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 500;

  int return_value = s21_add(value_1, value_2, &result);

  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_11) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 500;
  s21_set_scale(&check, 5);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_12) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 0;

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
// Отрицательные числа c одинаковыми степенями
START_TEST(s21_add_positive_numbers_13) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 1000;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_14) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 600;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 1100;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_15) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 600;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 1100;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_16) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_17) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_18) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
// Отрицательные числа c разными степенями
START_TEST(s21_add_positive_numbers_19) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 50000500;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 5);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_20) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 600;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 60000500;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 5);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_21) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 600;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 50000600;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 5);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_22) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_add(value_1, value_2, &result);

  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_23) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 5);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_24) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_25) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 5);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 50000500;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 5);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_26) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 600;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 5);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 50000600;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 5);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_27) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 600;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 5);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 60000500;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 5);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_28) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 5);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 500;

  s21_set_scale(&check, 5);

  s21_set_bit(&check, 127, 1);

  int return_value = s21_add(value_1, value_2, &result);

  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_29) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 5);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_positive_numbers_30) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
// Переполнение
START_TEST(s21_add_inf_1) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}};
  // value_1 = max.;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  s21_set_scale(&value_1, 0);  // 700.000
  s21_set_bit(&value_1, 127, 0);
  // value_2 = 2.;
  value_2.bits[0] = 0b00000000000000000000000000000010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_set_scale(&value_2, 0);  // 0.00060
  s21_set_bit(&value_2, 127, 0);
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(return_value, ERROR_P_INF);
}
END_TEST

START_TEST(s21_add_inf_2) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), s21_TRUE);
  ck_assert_int_eq(return_value, ERROR_N_INF);
}
END_TEST

// Положительные и отрицательные с одинаковыми степеняим
START_TEST(s21_add_positive_and_negative_numbers_1) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_add_positive_and_negative_numbers_2) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 100;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 100;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_add_positive_and_negative_numbers_3) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 100;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 100;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_add_positive_and_negative_numbers_4) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 100;
  value_2.bits[0] = 100;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_add_positive_and_negative_numbers_5) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 200;
  value_2.bits[0] = 100;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 100;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

// Банковское округление
START_TEST(s21_add_bank_round_1) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;

  value_2.bits[0] = 0b00000000000000000000000000000001;

  s21_set_scale(&value_1, 1);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 0);

  check.bits[0] = 0b10011001100110011001100110011010;
  check.bits[1] = 0b10011001100110011001100110011001;
  check.bits[2] = 0b00011001100110011001100110011001;

  s21_set_bit(&check, 127, 0);
  s21_set_bit(&check, 127, 0);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_bank_round_2) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;

  value_2.bits[0] = 0b00000000000000000000000000000110;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 1);

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 0b11111111111111111111111111111110;
  check.bits[1] = 0b11111111111111111111111111111111;
  check.bits[2] = 0b11111111111111111111111111111111;

  s21_set_bit(&check, 127, 0);
  s21_set_bit(&check, 127, 0);

  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
START_TEST(s21_add_bank_round_3) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;

  value_2.bits[0] = 0b00000000000000000000000000001110;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 1);

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 0);

  check.bits[0] = 0b11111111111111111111111111111110;
  check.bits[1] = 0b11111111111111111111111111111111;
  check.bits[2] = 0b11111111111111111111111111111111;

  s21_set_bit(&check, 127, 0);
  s21_set_bit(&check, 127, 0);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_1) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  s21_set_scale(&value_2, 2);
  s21_decimal result = {{0}};
  s21_decimal check = {{416, 0, 0, 0}};
  s21_set_scale(&check, 2);
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_add_2) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_bit(&value_2, 127, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_add_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_scale(&value_2, 1);
  s21_decimal result;
  s21_decimal check = {{0x1, 0x0, 0x1, 0}};
  s21_set_scale(&check, 1);
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_add_4) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_set_scale(&value_1, 2);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  s21_set_scale(&value_2, 1);
  s21_decimal result;
  s21_decimal check = {{2873, 0, 0, 0}};
  s21_set_scale(&check, 2);
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_add_5) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_scale(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{0x9999999a, 0x99999999, 0x19999999, 0}};
  s21_add(value_1, value_2, &result);

  ck_assert_int_eq(s21_is_equal(result, check), 1);
}
END_TEST

START_TEST(s21_add_7) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, IS_POS_INF);
}
END_TEST

//  negativ + positiv == sub
START_TEST(s21_add_8) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_set_scale(&value_1, 2);
  s21_set_bit(&value_1, 127, 1);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  s21_set_scale(&value_2, 1);
  s21_decimal result;
  s21_decimal check = {{2847, 0, 0, 0}};
  s21_set_scale(&check, 2);
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

// nagativ + negativ == add
START_TEST(s21_add_9) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_set_bit(&value_1, 127, 1);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  s21_set_scale(&value_2, 2);
  s21_set_bit(&value_2, 127, 1);
  s21_decimal result = {{0}};
  s21_decimal check = {{416, 0, 0, 0}};
  s21_set_scale(&check, 2);
  s21_set_bit(&check, 127, 1);
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_add_10) {
  s21_decimal value_1 = {{1614, 0, 0, 0}};
  s21_set_scale(&value_1, 3);
  s21_decimal value_2 = {{46071, 0, 0, 0}};
  s21_set_scale(&value_2, 2);
  s21_decimal result;
  s21_decimal check = {{462324, 0, 0, 0}};
  s21_set_scale(&check, 3);
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_add_11) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal test = {{1535}};
  value_1.bits[0] = 150;
  value_2.bits[0] = 35;
  s21_set_scale(&value_2, 1);
  int res = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_scale(result), 1);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_add_12) {
  s21_decimal value_1 = {{150, 0, 0, 0}};
  s21_decimal value_2 = {{35, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal test = {{1535}};
  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);
  s21_set_scale(&value_2, 1);
  int res = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_scale(result), 1);
  ck_assert_int_eq(s21_get_sign(result), 1);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(s21_add_13) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 35;
  int res = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(res, 1);
  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);
  memset(&result, 0, sizeof(s21_decimal));
  res = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(res, 2);
}
END_TEST

// вычитание
START_TEST(s21_add_14) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 540;
  value_2.bits[0] = 560;
  s21_decimal test = {{20}};
  s21_set_bit(&value_2, 127, 1);
  s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_sign(result), 1);
}
END_TEST

START_TEST(s21_add_15) {
  s21_decimal value_1 = {{150}};
  s21_decimal value_2 = {{50}};
  s21_decimal result = {0};
  s21_decimal test = {{100}};
  s21_set_bit(&value_1, 127, 1);
  s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_scale(result), 0);
  ck_assert_int_eq(s21_get_sign(result), 1);
  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);
  memset(&result, 0, sizeof(s21_decimal));
  int res = s21_add(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(s21_get_scale(result), 0);
  ck_assert_int_eq(s21_get_sign(result), 0);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_s21_add_1) {
  s21_decimal test_v_1 = {{0, 0, 0, 0}};
  s21_decimal test_v_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int = 0;
  s21_from_int_to_decimal(1899999, &test_v_1);
  s21_from_int_to_decimal(100001, &test_v_2);
  s21_add(test_v_1, test_v_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 2000000);
}
END_TEST

START_TEST(test_s21_add_2) {
  s21_decimal test_v_1 = {{0, 0, 0, 0}};
  s21_decimal test_v_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;
  s21_from_int_to_decimal(199421, &test_v_1);
  s21_from_int_to_decimal(-4433, &test_v_2);
  s21_add(test_v_1, test_v_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 199421 + (-4433));
}
END_TEST

START_TEST(test_s21_add_3) {
  s21_decimal test_v_1 = {{0, 0, 0, 0}};
  s21_decimal test_v_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;
  s21_from_int_to_decimal(-199421, &test_v_1);
  s21_from_int_to_decimal(4433, &test_v_2);
  s21_add(test_v_1, test_v_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, -199421 + 4433);
}
END_TEST

START_TEST(test_s21_add_4) {
  s21_decimal test_v_1 = {{0, 0, 0, 0}};
  s21_decimal test_v_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(-199421, &test_v_1);
  s21_from_int_to_decimal(-4433, &test_v_2);
  s21_add(test_v_1, test_v_2, &result_dec);
}
END_TEST

START_TEST(test_s21_add_5) {
  s21_decimal test_v_1 = {{10000, 3, 10, 0}};
  s21_decimal test_v_2 = {{5000, 2, 500, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_v_1, test_v_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 10000 + 5000);
  ck_assert_uint_eq(result_dec.bits[1], 3 + 2);
  ck_assert_uint_eq(result_dec.bits[2], 10 + 500);
}
END_TEST

START_TEST(test_s21_add_6) {
  s21_decimal test_v_1 = {{4294967295, 10, 10, 0}};
  s21_decimal test_v_2 = {{1, 2, 20, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_v_1, test_v_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 0);
  ck_assert_uint_eq(result_dec.bits[1], 13);
  ck_assert_uint_eq(result_dec.bits[2], 30);
}
END_TEST

START_TEST(test_s21_add_7) {
  s21_decimal test_v_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal test_v_2 = {{1, 1, 1, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = s21_add(test_v_1, test_v_2, &result_dec);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_s21_add_8) {
  s21_decimal test_v_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal test_v_2 = {{1, 1, 1, 0}};
  s21_set_bit(&test_v_1, 127, 1);
  s21_set_bit(&test_v_2, 127, 1);
  s21_decimal result_dec = {{0, 0, 0, 0}};

  int result = s21_add(test_v_1, test_v_2, &result_dec);

  // print_decimal(result_dec);
  // printf("\n");
  // print_decimal(check);
  // printf("\n%d", result);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(test_s21_add_9) {
  s21_decimal test_v_1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal test_v_2 = {{1, 1, 1, 0}};
  s21_set_bit(&test_v_1, 127, 1);
  s21_set_bit(&test_v_2, 127, 1);
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result = s21_add(test_v_1, test_v_2, &result_dec);
  ck_assert_int_eq(result, 2);
}
END_TEST

START_TEST(test_s21_add_10) {
  s21_decimal test_v_1 = {{4294967294, 4294967295, 4294967295, 0}};
  s21_decimal test_v_2 = {{1, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_v_1, test_v_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 4294967295);
  ck_assert_uint_eq(result_dec.bits[1], 4294967295);
  ck_assert_uint_eq(result_dec.bits[2], 4294967295);
  ck_assert_uint_eq(result_dec.bits[3], 0);
}
END_TEST

START_TEST(test_s21_add_11) {
  s21_decimal src1, src2, result;
  int a = -1234;
  float b = 1.234;
  float res_origin = -1232.766;
  float res_our;
  s21_from_int_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_12) {
  s21_decimal src1, src2, result;

  int a = -1234;
  float b = -1.234;
  float res_origin = -1235.234;
  float res_our;
  s21_from_int_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_13) {
  s21_decimal src1, src2, result;
  float a = -1234;
  float b = -221.23401;
  float res_origin = -1455.234;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_14) {
  s21_decimal src1, src2, result;
  float a = -9403;
  float b = 0.00234;
  float res_origin = -9402.9976600;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_15) {
  s21_decimal src1, src2, result;
  float a = -940.3;
  float b = 0.234;
  float res_origin = -940.0660000;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_16) {
  s21_decimal src1, src2, result;
  float a = -0.940301;
  float b = 22.023401;
  float res_origin = 21.0831;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_17) {
  s21_decimal src1, src2, result;
  float a = -0.9403;
  float b = -112.0234;
  float res_origin = -112.9637;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_18) {
  s21_decimal src1, src2, result;
  float a = -0.94e03;
  float b = -112.0234;
  float res_origin = -1052.0234;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_19) {
  s21_decimal src1, src2, result;
  float a = -0.94e03;
  float b = -112.0e2;
  float res_origin = -12140;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_add_21) {
  s21_decimal src1, src2, result;
  src1.bits[3] = 0x30000;
  src1.bits[2] = 0;
  src1.bits[1] = 0xFF;
  src1.bits[0] = 0x67E4F;
  src2.bits[3] = 0x60000;
  src2.bits[2] = 0;
  src2.bits[1] = 0xEA;
  src2.bits[0] = 0x67E4F;
  s21_decimal result_origin;
  result_origin.bits[3] = 0x60000;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0x3E502;
  result_origin.bits[0] = 0x1963E2E7;
  s21_add(src1, src2, &result);
  ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_add_22) {
  s21_decimal test_v_1 = {{4294967295, 4294967295, 4294967290, 0}};
  s21_decimal test_v_2 = {{100, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_v_1, test_v_2, &result_dec);
  ck_assert_int_eq(result_dec.bits[0], 99);
  ck_assert_int_eq(result_dec.bits[1], 0);
  ck_assert_int_eq(result_dec.bits[2], 4294967291);
  ck_assert_int_eq(result_dec.bits[3], 0);
}
END_TEST

START_TEST(test_s21_add_23) {
  s21_decimal test_v_1 = {{4294967295, 4294967295, 4294967290, 131072}};
  s21_decimal test_v_2 = {{0, 1, 0, 131072}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_v_1, test_v_2, &result_dec);
  ck_assert_int_eq(result_dec.bits[0], 4294967295);
  ck_assert_int_eq(result_dec.bits[1], 0);
  ck_assert_int_eq(result_dec.bits[2], 4294967291);
  ck_assert_int_eq(result_dec.bits[3], 131072);
}
END_TEST

START_TEST(test_s21_add_24) {
  s21_decimal test_v_1 = {{4294967295, 4294967295, 4294967290, 131072}};
  s21_decimal test_v_2 = {{5, 0, 1, 131072}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_v_1, test_v_2, &result_dec);
  ck_assert_int_eq(result_dec.bits[0], 4);
  ck_assert_int_eq(result_dec.bits[1], 0);
  ck_assert_int_eq(result_dec.bits[2], 4294967292);
  ck_assert_int_eq(result_dec.bits[3], 131072);
}
END_TEST

START_TEST(test_s21_add_25) {
  s21_decimal test_v_1 = {{428, 0, 0, 0}};
  s21_decimal test_v_2 = {{165, 0, 0, 131072}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_v_1, test_v_2, &result_dec);
  ck_assert_int_eq(result_dec.bits[0], 42965);
  ck_assert_int_eq(result_dec.bits[1], 0);
  ck_assert_int_eq(result_dec.bits[2], 0);
  ck_assert_int_eq(result_dec.bits[3], 131072);
}
END_TEST

Suite *suite_add(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_ADD \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_add \033[0;0;0m");
  suite_add_tcase(suite, test_case);
  tcase_add_test(test_case, s21_add_positive_numbers_1);
  tcase_add_test(test_case, s21_add_positive_numbers_2);
  tcase_add_test(test_case, s21_add_positive_numbers_3);
  tcase_add_test(test_case, s21_add_positive_numbers_4);
  tcase_add_test(test_case, s21_add_positive_numbers_5);
  tcase_add_test(test_case, s21_add_positive_numbers_6);
  tcase_add_test(test_case, s21_add_positive_numbers_7);
  tcase_add_test(test_case, s21_add_positive_numbers_8);
  tcase_add_test(test_case, s21_add_positive_numbers_9);
  tcase_add_test(test_case, s21_add_positive_numbers_10);
  tcase_add_test(test_case, s21_add_positive_numbers_11);
  tcase_add_test(test_case, s21_add_positive_numbers_12);
  tcase_add_test(test_case, s21_add_positive_numbers_13);
  tcase_add_test(test_case, s21_add_positive_numbers_14);
  tcase_add_test(test_case, s21_add_positive_numbers_15);
  tcase_add_test(test_case, s21_add_positive_numbers_16);
  tcase_add_test(test_case, s21_add_positive_numbers_17);
  tcase_add_test(test_case, s21_add_positive_numbers_18);
  tcase_add_test(test_case, s21_add_positive_numbers_19);
  tcase_add_test(test_case, s21_add_positive_numbers_20);
  tcase_add_test(test_case, s21_add_positive_numbers_21);
  tcase_add_test(test_case, s21_add_positive_numbers_22);
  tcase_add_test(test_case, s21_add_positive_numbers_23);
  tcase_add_test(test_case, s21_add_positive_numbers_24);
  tcase_add_test(test_case, s21_add_positive_numbers_25);
  tcase_add_test(test_case, s21_add_positive_numbers_26);
  tcase_add_test(test_case, s21_add_positive_numbers_27);
  tcase_add_test(test_case, s21_add_positive_numbers_28);
  tcase_add_test(test_case, s21_add_positive_numbers_29);
  tcase_add_test(test_case, s21_add_positive_numbers_30);
  //Переполнение
  tcase_add_test(test_case, s21_add_inf_1);
  tcase_add_test(test_case, s21_add_inf_2);
  tcase_add_test(test_case, s21_add_positive_and_negative_numbers_1);
  tcase_add_test(test_case, s21_add_positive_and_negative_numbers_2);
  tcase_add_test(test_case, s21_add_positive_and_negative_numbers_3);
  tcase_add_test(test_case, s21_add_positive_and_negative_numbers_4);
  tcase_add_test(test_case, s21_add_positive_and_negative_numbers_5);

  tcase_add_test(test_case, s21_add_bank_round_3);
  tcase_add_test(test_case, s21_add_bank_round_2);
  tcase_add_test(test_case, s21_add_bank_round_1);
  tcase_add_test(test_case, s21_add_1);
  tcase_add_test(test_case, s21_add_2);
  tcase_add_test(test_case, s21_add_3);
  tcase_add_test(test_case, s21_add_4);
  tcase_add_test(test_case, s21_add_5);
  tcase_add_test(test_case, s21_add_7);
  tcase_add_test(test_case, s21_add_8);
  tcase_add_test(test_case, s21_add_9);
  tcase_add_test(test_case, s21_add_10);
  tcase_add_test(test_case, s21_add_11);
  tcase_add_test(test_case, s21_add_12);
  tcase_add_test(test_case, s21_add_13);
  tcase_add_test(test_case, s21_add_14);
  tcase_add_test(test_case, s21_add_15);
  tcase_add_test(test_case, test_s21_add_1);
  tcase_add_test(test_case, test_s21_add_2);
  tcase_add_test(test_case, test_s21_add_3);
  tcase_add_test(test_case, test_s21_add_4);
  tcase_add_test(test_case, test_s21_add_5);
  tcase_add_test(test_case, test_s21_add_6);
  tcase_add_test(test_case, test_s21_add_7);
  tcase_add_test(test_case, test_s21_add_8);
  tcase_add_test(test_case, test_s21_add_9);
  tcase_add_test(test_case, test_s21_add_10);
  tcase_add_test(test_case, test_s21_add_11);
  tcase_add_test(test_case, test_s21_add_12);
  tcase_add_test(test_case, test_s21_add_13);
  tcase_add_test(test_case, test_s21_add_14);
  tcase_add_test(test_case, test_s21_add_15);
  tcase_add_test(test_case, test_s21_add_16);
  tcase_add_test(test_case, test_s21_add_17);
  tcase_add_test(test_case, test_s21_add_18);
  tcase_add_test(test_case, test_s21_add_19);
  tcase_add_test(test_case, test_s21_add_21);
  tcase_add_test(test_case, test_s21_add_22);
  tcase_add_test(test_case, test_s21_add_23);
  tcase_add_test(test_case, test_s21_add_24);
  tcase_add_test(test_case, test_s21_add_25);

  suite_add_tcase(suite, test_case);
  return suite;
}
