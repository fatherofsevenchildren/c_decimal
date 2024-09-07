#include "s21_decimal_test.h"

#define s21_TRUE 1
#define s21_FALSE 0

START_TEST(s21_greater_0) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_1) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_2) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_3) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_4) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 1;

  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_5) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_6) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_7) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_8) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 1.;
  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 0.;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_9) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 4294967297.;
  value_1.bits[0] = 0b00000000000000000000000000000001;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 1.;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000001;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_10) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 18446744078004518913.;
  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000001;
  value_1.bits[2] = 0b00000000000000000000000000000001;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = 4294967297.;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000001;
  value_2.bits[2] = 0b00000000000000000000000000000001;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_11) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_12) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_13) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_14) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 7922665135699263405684238108; scale = 14;
  value_1.bits[0] = 0b10011001100110010010011100011100;
  value_1.bits[1] = 0b10011001100110101001100110011001;
  value_1.bits[2] = 0b00011001100110010111100110011001;
  value_1.bits[3] = 0b00000000000011100000000000000000;
  // value_2 = 7922816251426433759354362493; scale = 16;
  value_2.bits[0] = 0b10011001100110010001101001111101;
  value_2.bits[1] = 0b10011001100110101001100110011001;
  value_2.bits[2] = 0b00011001100110010111100110011001;
  value_2.bits[3] = 0b00000000000100000000000000000000;
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_15) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  // 79226651356992
  // 110683279192024
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_16) {
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
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_17) {
  s21_decimal value_1, value_2;
  // value_1 = -776890.75455454213415678965898;
  // value_2 = -7.7545545454546589781677545545;
  value_1.bits[0] = 0b11000010010111101111100010001010;
  value_1.bits[1] = 0b01011100000101000111000011011000;
  value_1.bits[2] = 0b11111011000001101110010110100011;
  value_1.bits[3] = 0b10000000000101110000000000000000;

  value_2.bits[0] = 0b00000101101101111001100001001001;
  value_2.bits[1] = 0b01101011011011011010110110010010;
  value_2.bits[2] = 0b11111010100100000010101111111010;
  value_2.bits[3] = 0b10000000000111000000000000000000;
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_18) {
  s21_decimal value_1, value_2;
  // value_1 = -754567488438.97816770;
  // value_2 = -754554545454658.9781677;
  value_1.bits[0] = 0b01011010011001011000011011000010;
  value_1.bits[1] = 0b00010111001011000011100101001001;
  value_1.bits[2] = 0b00000000000000000000000000000100;
  value_1.bits[3] = 0b10000000000010000000000000000000;
  value_2.bits[0] = 0b10011100110111110000111010101101;
  value_2.bits[1] = 0b00001011011110101000110011100101;
  value_2.bits[2] = 0b00000000000000000000000110011001;
  value_2.bits[3] = 0b10000000000001110000000000000000;
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_TRUE;
  // origin = 1;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_19) {
  s21_decimal value_1, value_2;
  // value_1 = -2.514475768684753643;
  // value_2 = -2.514264337593542;
  value_1.bits[0] = 0b10101100110010000011001011101011;
  value_1.bits[1] = 0b00100010111001010011011001100011;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b10000000000100100000000000000000;

  value_2.bits[0] = 0b11001000101101101011010011000110;
  value_2.bits[1] = 0b00000000000010001110111010110101;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000011110000000000000000;
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(s21_greater_20) {
  s21_decimal value_1 = {{0}}, value_2 = {{0}};
  // value_1 = 0.;
  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // value_2 = -0.;
  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b10000000000000000000000000000000;
  int check = s21_is_greater(value_1, value_2);
  int check_origin = s21_FALSE;
  // origin = 0;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

Suite *suite_greater(void) {
  Suite *suite = suite_create("\033[1;30;47m S21_IS_GREATER \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_is_greater \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, s21_greater_0);
  tcase_add_test(test_case, s21_greater_1);
  tcase_add_test(test_case, s21_greater_2);
  tcase_add_test(test_case, s21_greater_3);
  tcase_add_test(test_case, s21_greater_4);
  tcase_add_test(test_case, s21_greater_5);
  tcase_add_test(test_case, s21_greater_6);
  tcase_add_test(test_case, s21_greater_7);
  tcase_add_test(test_case, s21_greater_8);
  tcase_add_test(test_case, s21_greater_9);
  tcase_add_test(test_case, s21_greater_10);
  tcase_add_test(test_case, s21_greater_11);
  tcase_add_test(test_case, s21_greater_12);
  tcase_add_test(test_case, s21_greater_13);
  tcase_add_test(test_case, s21_greater_14);
  tcase_add_test(test_case, s21_greater_15);
  tcase_add_test(test_case, s21_greater_16);
  tcase_add_test(test_case, s21_greater_17);
  tcase_add_test(test_case, s21_greater_18);
  tcase_add_test(test_case, s21_greater_19);
  tcase_add_test(test_case, s21_greater_20);

  suite_add_tcase(suite, test_case);
  return suite;
}
