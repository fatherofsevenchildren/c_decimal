#include "s21_decimal_test.h"

#define s21_TRUE 1
#define s21_FALSE 0

START_TEST(is_not_equal_0) {
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
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_1) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 5.0; scale = 1;
  value_1.bits[0] = 0b00000000000000000000000000110010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000010000000000000000;
  // value_2 = 5.0; scale = 1;
  value_2.bits[0] = 0b00000000000000000000000000110010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_2) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 5 0 000 0000 000 000 000.; scale = 0;
  value_1.bits[0] = 0b11010011101100100000000000000000;
  value_1.bits[1] = 0b00000110111100000101101101011001;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 5 0 000 0000 000 000 000.; scale = 0;
  value_2.bits[0] = 0b11010011101100100000000000000000;
  value_2.bits[1] = 0b00000110111100000101101101011001;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_3) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 5 000 000 000 000 000 000 000.; scale = 0;
  value_1.bits[0] = 0b01011001001000000000000000000000;
  value_1.bits[1] = 0b00001100111100000110010011011101;
  value_1.bits[2] = 0b00000000000000000000000100001111;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 5 000 000 000 000 000 000 000.; scale = 0;
  value_2.bits[0] = 0b01011001001000000000000000000000;
  value_2.bits[1] = 0b00001100111100000110010011011101;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_4) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 0.0 000 005 000 000 000 000 000 000 000; scale = 28;
  value_1.bits[0] = 0b01011001001000000000000000000000;
  value_1.bits[1] = 0b00001100111100000110010011011101;
  value_1.bits[2] = 0b00000000000000000000000100001111;
  value_1.bits[3] = 0b00000000000111000000000000000000;
  // value_2 = 0.0 000 005 000 000 000 000 000 000 000; scale = 28;
  value_2.bits[0] = 0b01011001001000000000000000000000;
  value_2.bits[1] = 0b00001100111100000110010011011101;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b00000000000111000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_5) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 5.0; scale = 0;
  value_1.bits[0] = 0b00000000000000000000000000000101;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 50.; scale = 1;
  value_2.bits[0] = 0b00000000000000000000000000110010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000010000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_6) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 50.; scale = 1;
  value_1.bits[0] = 0b00000000000000000000000000110010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000010000000000000000;
  // value_2 = 5 00 000 000.; scale = 8;
  value_2.bits[0] = 0b00011101110011010110010100000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000010000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_7) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 5. 00 000 000; scale = 8;
  value_1.bits[0] = 0b00011101110011010110010100000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000010000000000000000000;
  // value_2 = 5. 000 000 000 000 000 000 000; scale = 24;
  value_2.bits[0] = 0b01011001001000000000000000000000;
  value_2.bits[1] = 0b00001100111100000110010011011101;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b00000000000110000000000000000000;
  s21_set_scale(&value_1, 8);
  s21_set_scale(&value_2, 21);
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_8) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 5.00 100 900; scale = 8;
  value_1.bits[0] = 0b00011101110011101110111100100100;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 500 100 900. 000 000 000 0000; scale = 13;
  value_2.bits[0] = 0b11001011011111101000000000000000;
  value_2.bits[1] = 0b00011010111100010001010100000100;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b00000000000011010000000000000000;
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 13);
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_9) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = -500 100 900.; scale = 0;
  value_1.bits[0] = 0b00011101110011101110111100100100;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;
  // value_2 = -500 100 900. 000 000 000 0000; scale = 13;
  value_2.bits[0] = 0b11001011011111101000000000000000;
  value_2.bits[1] = 0b00011010111100010001010100000100;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b10000000000011010000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_10) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = -500 100 900.; scale = 0;
  value_1.bits[0] = 0b00011101110011101110111100100100;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000000000000000000000000;
  // value_2 = -500 100 900. 000 000 000 0000; scale = 13;
  value_2.bits[0] = 0b11001011011111101000000000000000;
  value_2.bits[1] = 0b00011010111100010001010100000100;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b10000000000011010000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_11) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = -5 000 000 000 000 000 000 000.; scale = 0;
  value_1.bits[0] = 0b01011001001000000000000000000000;
  value_1.bits[1] = 0b00001100111100000110010011011101;
  value_1.bits[2] = 0b00000000000000000000000100001111;
  value_1.bits[3] = 0b10000000000000000000000000000000;
  // value_2 = -5 000 000 000 000 000 000 000.; scale = 0;
  value_2.bits[0] = 0b01011001001000000000000000000000;
  value_2.bits[1] = 0b00001100111100000110010011011101;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_12) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 5 000 000 000 000 000 000 000.; scale = 0;
  value_1.bits[0] = 0b01011001001000000000000000000000;
  value_1.bits[1] = 0b00001100111100000110010011011101;
  value_1.bits[2] = 0b00000000000000000000000100001111;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = -5 000 000 000 000 000 000 000.; scale = 0;
  value_2.bits[0] = 0b01011001001000000000000000000000;
  value_2.bits[1] = 0b00001100111100000110010011011101;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_13) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 5 000 000 000 000 000 000 000.; scale = 0;
  value_1.bits[0] = 0b01011001001000000000000000000000;
  value_1.bits[1] = 0b00001100111100000110010011011101;
  value_1.bits[2] = 0b00000000000000000000000100001111;
  value_1.bits[3] = 0b10000000000000000000000000000000;
  // value_2 = -5 000 000 000 000 000 000 000.; scale = 0;
  value_2.bits[0] = 0b01011001001000000000000000000000;
  value_2.bits[1] = 0b00001100111100000110010011011101;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_14) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 5 0 000 0000 000 000 000.; scale = 0;
  value_1.bits[0] = 0b11010011101100100000000000000000;
  value_1.bits[1] = 0b00000110111100000101101101011001;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 5 000 000 000 000 000 000 000.; scale = 0;
  value_2.bits[0] = 0b01011001001000000000000000000000;
  value_2.bits[1] = 0b00001100111100000110010011011101;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_15) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 50.; scale = 0;
  value_1.bits[0] = 0b00000000000000000000000000110010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 5 000 000 000 000 000 000 000.; scale = 0;
  value_2.bits[0] = 0b01011001001000000000000000000000;
  value_2.bits[1] = 0b00001100111100000110010011011101;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_16) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 0.; scale = 0;
  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 5 000 000 000 000 000 000 000.; scale = 0;
  value_2.bits[0] = 0b01011001001000000000000000000000;
  value_2.bits[1] = 0b00001100111100000110010011011101;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_17) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 0.; scale = 0;
  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 5 000 000 000 000 000 000 000.; scale = 0;
  value_2.bits[0] = 0b01011001001000000000000000000000;
  value_2.bits[1] = 0b00001100111100000110010011011101;
  value_2.bits[2] = 0b00000000000000000000000100001111;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_18) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 0.; scale = 0;
  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 1; scale = 28;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000111000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_19_max_mantiss_and_scale) {
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
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(is_not_equal_20_max_mantiss_and_scale) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = max; scale = 28;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000111000000000000000000;
  // value_2 = max; scale = 28;
  value_2.bits[0] = 0b11111111111111111111111111111111;
  value_2.bits[1] = 0b11111111111111111111111111111111;
  value_2.bits[2] = 0b11111111111111111111111111111111;
  value_2.bits[3] = 0b00000000000111000000000000000000;
  int check = s21_is_not_equal(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

/// negativ zero == positiv zero
START_TEST(is_not_equal_21) {
  s21_decimal src1, src2;
  // src1 = -0.000000000000000000000000000;
  // src2 = 0;
  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000110110000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000000;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000000000000000000000000;
  int result = s21_is_not_equal(src1, src2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check_origin, result);
}
END_TEST

Suite *suite_not_equal(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_IS_NOT_EQUAL \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_is_not_equal \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, is_not_equal_0);
  tcase_add_test(test_case, is_not_equal_1);
  tcase_add_test(test_case, is_not_equal_2);
  tcase_add_test(test_case, is_not_equal_3);
  tcase_add_test(test_case, is_not_equal_4);
  tcase_add_test(test_case, is_not_equal_5);
  tcase_add_test(test_case, is_not_equal_6);
  tcase_add_test(test_case, is_not_equal_7);
  tcase_add_test(test_case, is_not_equal_8);
  tcase_add_test(test_case, is_not_equal_9);
  tcase_add_test(test_case, is_not_equal_10);
  tcase_add_test(test_case, is_not_equal_11);
  tcase_add_test(test_case, is_not_equal_12);
  tcase_add_test(test_case, is_not_equal_13);
  tcase_add_test(test_case, is_not_equal_14);
  tcase_add_test(test_case, is_not_equal_15);
  tcase_add_test(test_case, is_not_equal_16);
  tcase_add_test(test_case, is_not_equal_17);
  tcase_add_test(test_case, is_not_equal_18);
  tcase_add_test(test_case, is_not_equal_19_max_mantiss_and_scale);
  tcase_add_test(test_case, is_not_equal_20_max_mantiss_and_scale);
  tcase_add_test(test_case, is_not_equal_21);

  suite_add_tcase(suite, test_case);
  return suite;
}
