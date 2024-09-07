#include "s21_decimal_test.h"

#define N_INF 2
#define ERROR_P_INF 1
#define ERROR_N_INF 2

// Положительные числа c одинаковыми степенями
START_TEST(s21_sub_positive_numbers_1) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_2) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 600;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 100;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_3) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 600;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 100;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_4) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_5) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_6) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
// Положительные числа c разными степенями
START_TEST(s21_sub_positive_numbers_7) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 49999500;

  s21_set_scale(&check, 5);

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_8) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 600;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 59999500;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 5);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_9) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 600;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 49999400;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 5);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_10) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_11) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 0);

  s21_set_scale(&check, 5);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_12) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
// Отрицательные числа c одинаковыми степенями
START_TEST(s21_sub_positive_numbers_13) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_14) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 600;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 100;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_15) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 600;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 100;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_16) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_17) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_18) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
// Отрицательные числа c разными степенями
START_TEST(s21_sub_positive_numbers_19) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 49999500;

  s21_set_bit(&check, 127, 0);

  s21_set_scale(&check, 5);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_20) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 600;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 59999500;

  s21_set_bit(&check, 127, 0);

  s21_set_scale(&check, 5);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_21) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 600;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 49999400;

  s21_set_bit(&check, 127, 0);

  s21_set_scale(&check, 5);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_22) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_23) {
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

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_24) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 5);
  s21_set_scale(&value_2, 0);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_25) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 5);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 49999500;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 5);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_26) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 600;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 5);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 49999400;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 5);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_27) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 600;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 5);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 59999500;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 5);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_28) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 500;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 5);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 0);

  s21_set_scale(&check, 5);

  int return_value = s21_sub(value_1, value_2, &result);

  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_29) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 5);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 1);

  s21_set_scale(&check, 0);

  int return_value = s21_sub(value_1, value_2, &result);
  // printf("\n");
  // print_decimal(result);
  // printf("\n");
  // print_decimal(check);
  // printf("\n");
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_positive_numbers_30) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 5);

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

// Переполнение
START_TEST(s21_sub_inf_1) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}};
  // value_1 = max.;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  s21_set_scale(&value_1, 0);
  s21_set_bit(&value_1, 127, 0);
  // value_2 = 2.;
  value_2.bits[0] = 0b00000000000000000000000000000010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  s21_set_scale(&value_2, 0);
  s21_set_bit(&value_2, 127, 1);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(return_value, ERROR_P_INF);
}
END_TEST

START_TEST(s21_sub_inf_2) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 0);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), s21_TRUE);
  ck_assert_int_eq(return_value, ERROR_N_INF);
}
END_TEST

// Тесты на сложение
START_TEST(s21_add_sub_on_add_1) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 500;

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 1000;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_sub(value_1, value_2, &result);
  // printf("\n");
  // print_decimal(result);
  // printf("\n");
  // print_decimal(check);
  // printf("\n");
  // printf("%d", return_value);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_sub_on_add_2) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 600;

  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);

  check.bits[0] = 1100;

  s21_set_bit(&check, 127, 0);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_sub_on_add_3) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 600;
  value_2.bits[0] = 500;

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 0);

  check.bits[0] = 1100;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  // printf("\n");
  // print_decimal(result);
  // printf("\n");
  // print_decimal(check);
  // printf("\n");
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_sub_on_add_4) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 500;

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 0);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_sub_on_add_5) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 500;
  value_2.bits[0] = 0;

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 0);

  check.bits[0] = 500;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_add_sub_on_add_6) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}}, result = {{0}}, check = {{0}};

  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 0);

  check.bits[0] = 0;

  s21_set_bit(&check, 127, 1);

  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}

START_TEST(s21_sub_1) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_set_bit(&value_1, 127, 1);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  s21_set_scale(&value_2, 2);
  s21_set_bit(&value_2, 127, 1);
  s21_decimal result;
  s21_decimal check = {{156, 0, 0, 0}};
  s21_set_scale(&check, 2);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_2) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_set_bit(&value_1, 127, 1);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  s21_set_scale(&value_2, 2);
  s21_decimal result;
  s21_decimal check = {{416, 0, 0, 0}};
  s21_set_scale(&check, 2);
  s21_set_bit(&check, 127, 1);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_3) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_bit(&value_1, 127, 1);
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal result;
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, N_INF);
}
END_TEST

START_TEST(s21_sub_4) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_bit(&value_1, 127, 1);
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_bit(&value_2, 127, 1);
  s21_decimal result;
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, N_INF);
}
END_TEST

START_TEST(s21_sub_5) {
  s21_decimal value_1 = {{64071, 0, 0, 0}};
  s21_set_scale(&value_1, 4);
  s21_decimal value_2 = {{5919, 0, 0, 0}};
  s21_set_scale(&value_2, 1);
  s21_decimal result;
  s21_decimal check = {{5854929, 0, 0, 0}};
  s21_set_scale(&check, 4);
  s21_set_bit(&check, 127, 1);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 155;
  value_2.bits[0] = 55;
  s21_sub(value_1, value_2, &result);
  s21_decimal test = {0};
  test.bits[0] = 100;
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  memset(&result, 0, sizeof(s21_decimal));
  value_1.bits[0] = (unsigned int)50;
  value_2.bits[0] = (unsigned int)150;
  s21_sub(value_1, value_2, &result);
  int sign = s21_get_sign(result);
  ck_assert_uint_eq(result.bits[0], test.bits[0]);
  ck_assert_int_eq(sign, 1);

  memset(&value_1, 0, sizeof(s21_decimal));
  memset(&value_2, 0, sizeof(s21_decimal));
  memset(&result, 0, sizeof(s21_decimal));
  value_1.bits[0] = (unsigned int)50;
  value_2.bits[0] = (unsigned int)15;
  memset(&result, 0, sizeof(s21_decimal));
  s21_set_scale(&value_2, 1);
  s21_sub(value_1, value_2, &result);
  ck_assert_uint_eq(result.bits[0], 485);
  ck_assert_uint_eq(s21_get_scale(result), 1);
  ck_assert_uint_eq(s21_get_sign(result), 0);
}
END_TEST

START_TEST(s21_sub_7) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 4294967295;
  value_1.bits[1] = 4294967295;
  value_1.bits[2] = 4294967295;
  value_2.bits[0] = 55;
  s21_set_bit(&value_1, 127, 1);
  int res = s21_sub(value_1, value_2, &result);
  ck_assert_uint_eq(res, 2);
}
END_TEST

START_TEST(s21_sub_8) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 150;
  value_2.bits[0] = 50;
  s21_set_bit(&value_1, 127, 1);
  s21_sub(value_1, value_2, &result);
  s21_decimal test = {0};
  test.bits[0] = 200;
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign = s21_get_sign(result);
  ck_assert_int_eq(sign, 1);
  memset(&result, 0, sizeof(s21_decimal));
  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 1);
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign1 = s21_get_sign(result);
  ck_assert_int_eq(sign1, 0);
}
END_TEST

START_TEST(s21_sub_9) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  value_1.bits[0] = 150;
  value_2.bits[0] = 50;
  s21_set_bit(&value_1, 127, 1);
  s21_set_bit(&value_2, 127, 1);

  s21_sub(value_1, value_2, &result);
  s21_decimal test = {0};
  test.bits[0] = 100;
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign = s21_get_sign(result);
  ck_assert_int_eq(sign, 1);
  memset(&result, 0, sizeof(s21_decimal));
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  int sign1 = s21_get_sign(result);
  ck_assert_int_eq(sign1, 1);
  value_1.bits[0] = 50;
  value_2.bits[0] = 150;
  memset(&result, 0, sizeof(s21_decimal));
  s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], test.bits[0]);
  sign1 = s21_get_sign(result);
  ck_assert_int_eq(sign1, 0);
}
END_TEST

START_TEST(test_s21_sub_1) {
  s21_decimal src1, src2, result;
  int a = 9403;
  int b = 202;
  int res_origin = 9201;
  int res_our;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our);
  ck_assert_int_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_sub_2) {
  s21_decimal src1, src2, result;
  int a = 9403;
  float b = 202.098;
  float res_origin = 9200.902;
  float res_our;
  s21_from_int_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_sub_3) {
  s21_decimal src1, src2, result;
  float a = -9403;
  float b = 202.098;
  float res_origin = a - b;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_sub_4) {
  s21_decimal src1, src2, result;
  float a = 9403.0;
  float b = 202.0098421232;
  float res_origin = 9200.9901578768;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_sub_5) {
  s21_decimal src1, src2, result;
  float a = -9403.000;
  float b = 202.0098421232;
  float res_origin = -9605.0098421232;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_sub_6) {
  s21_decimal src1, src2, result;
  float a = -9403.0e2;
  int b = -202;
  float res_origin = a - b;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(test_s21_sub_7) {
  s21_decimal src1, src2, result;
  src1.bits[3] = 0b00000000000000010000000000000000;
  src1.bits[2] = 0;
  src1.bits[1] = 0;
  src1.bits[0] = 0b00000000000000000110011011110000;
  src2.bits[3] = 0b00000000000000110000000000000000;
  src2.bits[2] = 0;
  src2.bits[1] = 0;
  src2.bits[0] = 0b00000000000001000101000111010110;
  s21_decimal result_origin;
  result_origin.bits[3] = 0b00000000000000110000000000000000;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0;
  result_origin.bits[0] = 0b00000000001000111110001111101010;
  s21_sub(src1, src2, &result);
  ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(test_s21_sub_8) {
  s21_decimal test_v_1 = {{1, 10, 0, 0}};
  s21_decimal test_v_2 = {{5000, 5, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_sub(test_v_1, test_v_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 4294962297);
  ck_assert_uint_eq(result_dec.bits[1], 4);
  ck_assert_uint_eq(result_dec.bits[2], 0);
}
END_TEST

START_TEST(test_s21_sub_9) {
  s21_decimal test_v_1 = {{1, 4, 5, 0}};
  s21_decimal test_v_2 = {{5000, 5, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_sub(test_v_1, test_v_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 4294962297);
  ck_assert_uint_eq(result_dec.bits[1], 4294967294);
  ck_assert_uint_eq(result_dec.bits[2], 4);
}
END_TEST

START_TEST(test_s21_sub_10) {
  s21_decimal test_v_1 = {{1, 0, 5, 0}};
  s21_decimal test_v_2 = {{5000, 5, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_sub(test_v_1, test_v_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 4294962297);
  ck_assert_uint_eq(result_dec.bits[1], 4294967290);
  ck_assert_uint_eq(result_dec.bits[2], 4);
}
END_TEST

START_TEST(test_s21_sub_11) {
  s21_decimal test_v_1 = {{1, 0, 0, 0}};
  s21_decimal test_v_2 = {{5000, 0, 0, 0}};
  s21_set_bit(&test_v_2, 127, 1);
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_sub(test_v_1, test_v_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 5001);
  ck_assert_uint_eq(result_dec.bits[1], 0);
  ck_assert_uint_eq(result_dec.bits[2], 0);
  ck_assert_uint_eq(result_dec.bits[3], 0);
}
END_TEST

Suite *suite_sub(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_SUB \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_sub \033[0;0;0m");
  suite_add_tcase(suite, test_case);
  // Положительные числа c одинаковыми степенями
  tcase_add_test(test_case, s21_sub_positive_numbers_1);
  tcase_add_test(test_case, s21_sub_positive_numbers_2);
  tcase_add_test(test_case, s21_sub_positive_numbers_3);
  tcase_add_test(test_case, s21_sub_positive_numbers_4);
  tcase_add_test(test_case, s21_sub_positive_numbers_5);
  tcase_add_test(test_case, s21_sub_positive_numbers_6);
  // Положительные числа c разными степенями
  tcase_add_test(test_case, s21_sub_positive_numbers_7);
  tcase_add_test(test_case, s21_sub_positive_numbers_8);
  tcase_add_test(test_case, s21_sub_positive_numbers_9);
  tcase_add_test(test_case, s21_sub_positive_numbers_10);
  tcase_add_test(test_case, s21_sub_positive_numbers_11);
  tcase_add_test(test_case, s21_sub_positive_numbers_12);
  // Отрицательные числа c одинаковыми степенями
  tcase_add_test(test_case, s21_sub_positive_numbers_13);
  tcase_add_test(test_case, s21_sub_positive_numbers_14);
  tcase_add_test(test_case, s21_sub_positive_numbers_15);
  tcase_add_test(test_case, s21_sub_positive_numbers_16);
  tcase_add_test(test_case, s21_sub_positive_numbers_17);
  tcase_add_test(test_case, s21_sub_positive_numbers_18);
  // Отрицательные числа c разными степенями
  tcase_add_test(test_case, s21_sub_positive_numbers_19);
  tcase_add_test(test_case, s21_sub_positive_numbers_20);
  tcase_add_test(test_case, s21_sub_positive_numbers_21);
  tcase_add_test(test_case, s21_sub_positive_numbers_22);
  tcase_add_test(test_case, s21_sub_positive_numbers_23);
  tcase_add_test(test_case, s21_sub_positive_numbers_24);
  tcase_add_test(test_case, s21_sub_positive_numbers_25);
  tcase_add_test(test_case, s21_sub_positive_numbers_26);
  tcase_add_test(test_case, s21_sub_positive_numbers_27);
  tcase_add_test(test_case, s21_sub_positive_numbers_28);
  tcase_add_test(test_case, s21_sub_positive_numbers_29);
  tcase_add_test(test_case, s21_sub_positive_numbers_30);
  // Переполнение
  tcase_add_test(test_case, s21_sub_inf_1);
  tcase_add_test(test_case, s21_sub_inf_2);

  tcase_add_test(test_case, s21_sub_1);
  tcase_add_test(test_case, s21_sub_2);
  tcase_add_test(test_case, s21_sub_3);
  tcase_add_test(test_case, s21_sub_4);
  tcase_add_test(test_case, s21_sub_5);
  tcase_add_test(test_case, s21_sub_6);
  tcase_add_test(test_case, s21_sub_7);
  tcase_add_test(test_case, s21_sub_8);
  tcase_add_test(test_case, s21_sub_9);

  tcase_add_test(test_case, test_s21_sub_1);
  tcase_add_test(test_case, test_s21_sub_2);
  tcase_add_test(test_case, test_s21_sub_3);
  tcase_add_test(test_case, test_s21_sub_4);
  tcase_add_test(test_case, test_s21_sub_5);
  tcase_add_test(test_case, test_s21_sub_6);
  tcase_add_test(test_case, test_s21_sub_7);
  tcase_add_test(test_case, test_s21_sub_8);
  tcase_add_test(test_case, test_s21_sub_9);
  tcase_add_test(test_case, test_s21_sub_10);
  tcase_add_test(test_case, test_s21_sub_11);

  // Тесты на сложение
  tcase_add_test(test_case, s21_add_sub_on_add_1);
  tcase_add_test(test_case, s21_add_sub_on_add_2);
  tcase_add_test(test_case, s21_add_sub_on_add_3);
  tcase_add_test(test_case, s21_add_sub_on_add_4);
  tcase_add_test(test_case, s21_add_sub_on_add_5);
  tcase_add_test(test_case, s21_add_sub_on_add_6);

  suite_add_tcase(suite, test_case);
  return suite;
}
