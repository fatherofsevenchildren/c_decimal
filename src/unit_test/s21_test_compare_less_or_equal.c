#include "s21_decimal_test.h"

#define s21_TRUE 1
#define s21_FALSE 0

START_TEST(s21_less_or_equal_0) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 0.;
  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 0.;
  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_1) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 1.;
  value_1.bits[0] = 0b00000000000000000000000000000001;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 0.;
  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_2) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 4294967297.;
  value_1.bits[0] = 0b00000000000000000000000000000001;
  value_1.bits[1] = 0b00000000000000000000000000000001;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 1.;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_3) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 18446744078004518913.;
  value_1.bits[0] = 0b00000000000000000000000000000001;
  value_1.bits[1] = 0b00000000000000000000000000000001;
  value_1.bits[2] = 0b00000000000000000000000000000001;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 4294967297.;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000001;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_4) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = max; scale = 0;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = max; scale = 28;
  value_2.bits[0] = 0b11111111111111111111111111111111;
  value_2.bits[1] = 0b11111111111111111111111111111111;
  value_2.bits[2] = 0b11111111111111111111111111111111;
  value_2.bits[3] = 0b00000000000111000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;

  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_5) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = max; scale = 27;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000110110000000000000000;
  // value_2 = max; scale = 28;
  value_2.bits[0] = 0b11111111111111111111111111111111;
  value_2.bits[1] = 0b11111111111111111111111111111111;
  value_2.bits[2] = 0b11111111111111111111111111111111;
  value_2.bits[3] = 0b00000000000111000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_6) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 50.; scale = 0;
  value_1.bits[0] = 0b00000000000000000000000000110010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 50.; scale = 1;
  value_2.bits[0] = 0b00000000000000000000000000110010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_7) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 0; scale = 0;
  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 0; scale = 28;
  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000111000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_8) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 0.;
  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 1.;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_9) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 1.;
  value_1.bits[0] = 0b00000000000000000000000000000001;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 4294967297.;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000001;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_10) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = .;
  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000001;
  value_1.bits[2] = 0b00000000000000000000000000000001;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = .;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000001;
  value_2.bits[2] = 0b00000000000000000000000000000001;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_11) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = max; scale = 28;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000111000000000000000000;
  // value_2 = max; scale = 0;
  value_2.bits[0] = 0b11111111111111111111111111111111;
  value_2.bits[1] = 0b11111111111111111111111111111111;
  value_2.bits[2] = 0b11111111111111111111111111111111;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_12) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = max; scale = 28;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000111000000000000000000;
  // value_2 = max; scale = 27;
  value_2.bits[0] = 0b11111111111111111111111111111111;
  value_2.bits[1] = 0b11111111111111111111111111111111;
  value_2.bits[2] = 0b11111111111111111111111111111111;
  value_2.bits[3] = 0b00000000000110110000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_13) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 50.; scale = 0;
  value_1.bits[0] = 0b00000000000000000000000000110010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 50.; scale = 1;
  value_2.bits[0] = 0b00000000000000000000000000110010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_14) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 79226651356992.63405684238108; scale = 14;
  // value_2 = 792281625142.6433759354362493; scale = 16;
  value_1.bits[0] = 0b10011001100110010010011100011100;
  value_1.bits[1] = 0b10011001100110101001100110011001;
  value_1.bits[2] = 0b00011001100110010111100110011001;
  value_1.bits[3] = 0b00000000000011100000000000000000;

  value_2.bits[0] = 0b10011001100110010001101001111101;
  value_2.bits[1] = 0b10011001100110101001100110011001;
  value_2.bits[2] = 0b00011001100110010111100110011001;
  value_2.bits[3] = 0b00000000000100000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_15) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 79226651356992.63405684238108; scale = 14;
  value_1.bits[0] = 0b10011001100110010010011100011100;
  value_1.bits[1] = 0b10011001100110101001100110011001;
  value_1.bits[2] = 0b00011001100110010111100110011001;
  value_1.bits[3] = 0b00000000000011100000000000000000;
  // value_2 = 110683279192024.09085; scale = 5;
  value_2.bits[0] = 0b10011001100110010001101001111101;
  value_2.bits[1] = 0b10011001100110101001100110011001;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000001010000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  // 79226651356992
  // 110683279192024
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_less_or_equal_16) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 501; scale = 0;
  value_1.bits[0] = 0b00000000000000000000000111110101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 501 000 000 000; scale = 9;
  value_2.bits[0] = 0b10100101111011010101001000000000;
  value_2.bits[1] = 0b00000000000000000000000001110100;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000010010000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

// two negative value
START_TEST(s21_less_or_equal_17) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 50.; scale = 0;
  value_1.bits[0] = 0b00000000000000000000000000110010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;
  // value_2 = 50.; scale = 1;
  value_2.bits[0] = 0b00000000000000000000000000110010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000010000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

// two negative value
START_TEST(s21_less_or_equal_18) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 50.; scale = 1;
  value_1.bits[0] = 0b00000000000000000000000000110010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000010000000000000000;
  // value_2 = 50.; scale = 1;
  value_2.bits[0] = 0b00000000000000000000000000110010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000010000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

// negativ 1 < positiv 0
START_TEST(s21_less_or_equal_19) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 0.;
  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = -1.;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_is_less_or_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

Suite *suite_less_or_equal(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_IS_LESS_OR_EQUAL \033[0;0;0m");
  TCase *test_case =
      tcase_create("\033[1;30;47m s21_is_less_or_equal \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_less_or_equal_0);
  tcase_add_test(test_case, s21_less_or_equal_1);
  tcase_add_test(test_case, s21_less_or_equal_2);
  tcase_add_test(test_case, s21_less_or_equal_3);
  tcase_add_test(test_case, s21_less_or_equal_4);
  tcase_add_test(test_case, s21_less_or_equal_5);
  tcase_add_test(test_case, s21_less_or_equal_6);
  tcase_add_test(test_case, s21_less_or_equal_7);
  tcase_add_test(test_case, s21_less_or_equal_8);
  tcase_add_test(test_case, s21_less_or_equal_9);
  tcase_add_test(test_case, s21_less_or_equal_10);
  tcase_add_test(test_case, s21_less_or_equal_11);
  tcase_add_test(test_case, s21_less_or_equal_12);
  tcase_add_test(test_case, s21_less_or_equal_13);
  tcase_add_test(test_case, s21_less_or_equal_14);
  tcase_add_test(test_case, s21_less_or_equal_15);
  tcase_add_test(test_case, s21_less_or_equal_16);
  tcase_add_test(test_case, s21_less_or_equal_17);
  tcase_add_test(test_case, s21_less_or_equal_18);
  tcase_add_test(test_case, s21_less_or_equal_19);

  suite_add_tcase(suite, test_case);
  return suite;
}
