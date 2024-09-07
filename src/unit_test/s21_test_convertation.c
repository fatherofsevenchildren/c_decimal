#include "s21_decimal_test.h"

START_TEST(int_to_dec_1) {
  s21_decimal result, origin;
  int src = 1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_2) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_3) {
  s21_decimal result, origin;
  int src = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_4) {
  s21_decimal result, origin;
  int src = 2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_5) {
  s21_decimal result, origin;
  int src = -2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_6) {
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_7) {
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_8) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_9) {
  s21_decimal result, origin;
  int src = 45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_10) {
  s21_decimal result, origin;
  int src = -45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_11) {
  s21_decimal result, origin;
  int src = 5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_12) {
  s21_decimal result, origin;
  int src = -5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_13) {
  s21_decimal result, origin;
  int src = 127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_14) {
  s21_decimal result, origin;
  int src = -127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_15) {
  s21_decimal result, origin;
  int src = 34567898;
  origin.bits[0] = 0b00000010000011110111011011011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_16) {
  s21_decimal result, origin;
  int src = -34567898;
  origin.bits[0] = 0b00000010000011110111011011011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_17) {
  s21_decimal result, origin;
  int src = 999;
  origin.bits[0] = 0b00000000000000000000001111100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_18) {
  s21_decimal result, origin;
  int src = -999;
  origin.bits[0] = 0b00000000000000000000001111100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_19) {
  s21_decimal result, origin;
  int src = -3254754;
  origin.bits[0] = 0b00000000001100011010100111100010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_20) {
  s21_decimal result, origin;
  int src = 3436425;
  origin.bits[0] = 0b00000000001101000110111110001001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_int_1) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000110010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 5;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_2) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 3;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_3) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 0;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_4) {
  s21_decimal src;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int result = 0;
  int origin = -2;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_5) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  int result = 0;
  int origin = 0;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_6) {
  s21_decimal src;
  src.bits[0] = 0b00111011100110101100100111111001;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  int result = 0;
  int origin = -99999999;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_7) {
  s21_decimal src;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int result = 0;
  int origin = 652;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_8) {
  s21_decimal src;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int result = 0;
  int origin = 4;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_9) {
  s21_decimal src;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int result = 0;
  int origin = 65658654;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_10) {
  s21_decimal src;
  src.bits[0] = 0b00010101101111011001110101001110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int result = 0;
  int origin = -364748;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_11) {
  s21_decimal src;
  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int result = 0;
  int origin = 1;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_12) {
  s21_decimal src;
  src.bits[0] = 0b00010110010010101110101011000000;
  src.bits[1] = 0b00000000000000000000100011111100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int result = 0;
  int origin = -98;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_13) {
  s21_decimal src;
  src.bits[0] = 0b00111011100110101100100111111001;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 99999999;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_14) {
  s21_decimal src;
  src.bits[0] = 0b11001010011010010001110011000010;
  src.bits[1] = 0b10011001110101001010110100100110;
  src.bits[2] = 0b10110000001111100010111010011101;
  src.bits[3] = 0b10000000000101110000000000000000;
  int result = 0;
  int origin = -545445;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_15) {
  s21_decimal src;
  src.bits[0] = 0b11101010011100001110100101000111;
  src.bits[1] = 0b10100010011001110000111100001010;
  src.bits[2] = 0b10110000001111101111000100010000;
  src.bits[3] = 0b00000000000101100000000000000000;
  int result = 0;
  int origin = 5454545;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_16) {
  s21_decimal src;
  src.bits[0] = 0b11101010001011100110110001010100;
  src.bits[1] = 0b00100111000110111110101011111001;
  src.bits[2] = 0b00011001101111000001110101101001;
  src.bits[3] = 0b00000000000101000000000000000000;
  int result = 0;
  int origin = 79645421;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_17) {
  s21_decimal src;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b00000000000101010000000000000000;
  int result = 0;
  int origin = 12345677;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_18) {
  s21_decimal src;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b10000000000101010000000000000000;
  int result = 0;
  int origin = -12345677;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_19) {
  s21_decimal src;
  src.bits[0] = 0b10011100101100011101000110000101;
  src.bits[1] = 0b01100001100101011101011101110110;
  src.bits[2] = 0b00000000000000000000000011101010;
  src.bits[3] = 0b00000000000100000000000000000000;
  int result = 0;
  int origin = 432356;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_20) {
  s21_decimal src;
  src.bits[0] = 0b01100001011111010111001111001001;
  src.bits[1] = 0b00000000100111100100000111010001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010010000000000000000;
  int result = 0;
  int origin = 44545413;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_21) {
  s21_decimal src;
  src.bits[0] = 0b01011100000110001011011001101010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  int result = 0;
  int origin = -1545123434;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_22) {
  s21_decimal src;
  src.bits[0] = 0b01011100000110001011011001101010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000000000000000000000;
  int result = 0;
  int origin = 1545123434;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_23) {
  s21_decimal src;
  src.bits[0] = 0b10101001101110110110011111111111;
  src.bits[1] = 0b00001010111111101100000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011000000000000000000;
  int result = 0;
  int origin = 792281;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_24) {
  s21_decimal src;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  int result = 0;
  int origin = 2;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_25) {
  s21_decimal src;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  int *result = NULL;
  int result_error = 1;
  int my_error = s21_from_decimal_to_int(src, result);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_1) {
  s21_decimal number;
  // decimal: 2.0
  // float: 2
  number.bits[0] = 0b00000000000000000000000000010100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000010000000000000000;
  float origin_float = 2.0;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  ck_assert_uint_eq(origin_float, my_float);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_2) {
  s21_decimal number;
  // decimal: -0.8
  // float: -0.8
  // int: -1085485875
  number.bits[0] = 0b00000000000000000000000000001000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  int result_int = -1085485875;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_3) {
  s21_decimal number;
  // decimal: 0
  // float: 0
  // int: 0
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 0;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_4) {
  s21_decimal number;
  // decimal: 1
  // float: 1
  // int: 1065353216
  number.bits[0] = 0b00000000000000000000000000000001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1065353216;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_5) {
  s21_decimal number;
  // decimal: 0.0
  // float: 0
  // int: -2147483648
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000010000000000000000;
  int result_int = -2147483648;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_6) {
  s21_decimal number;
  // decimal: -1.75
  // float: -1.75
  // int: -1075838976
  number.bits[0] = 0b00000000000000000000000010101111;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000100000000000000000;
  int result_int = -1075838976;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_7) {
  s21_decimal number;
  // decimal: 6521
  // float: 6521
  // int: 1170982912
  number.bits[0] = 0b00000000000000000001100101111001;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1170982912;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_8) {
  s21_decimal number;
  // decimal: 4
  // float: 4
  // int: 1082130432
  number.bits[0] = 0b00000000000000000000000000000100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1082130432;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_9) {
  s21_decimal number;
  // decimal: 65658654
  // float: 6.565866E+07
  // int: 1283094472
  number.bits[0] = 0b00000011111010011101111100011110;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1283094472;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_10) {
  s21_decimal number;
  // decimal: -364748
  // float: -364748
  // int: -927852160
  number.bits[0] = 0b00000000000001011001000011001100;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -927852160;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_11) {
  s21_decimal number;
  // decimal: 0.003
  // float: 0.003
  // int: 994352038
  number.bits[0] = 0b00000000000000000000000000000011;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000110000000000000000;
  int result_int = 994352038;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_12) {
  s21_decimal number;
  // decimal: -9878798789
  // float: -9.878798E+09
  // int: -804047712
  number.bits[0] = 0b01001100110100101000000111000101;
  number.bits[1] = 0b00000000000000000000000000000010;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -804047712;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_13) {
  s21_decimal number;
  // decimal: 9959999999999999999
  // float: 9.96E+18
  // int: 1594505479
  number.bits[0] = 0b11001010111000111111111111111111;
  number.bits[1] = 0b10001010001110010000011100111010;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1594505479;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_14) {
  s21_decimal number;
  // decimal: 18446744073709551615
  // float: 1.844674E+19
  // int: 1602224128
  number.bits[0] = 0b11111111111111111111111111111111;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1602224128;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_15) {
  s21_decimal number;
  // decimal: 5.4564654654864768465454654846
  // float: 5.456465
  // int: 1085184861
  number.bits[0] = 0b01101110100110100110010101111110;
  number.bits[1] = 0b11100010111000110111110100101010;
  number.bits[2] = 0b10110000010011101101001100001111;
  number.bits[3] = 0b00000000000111000000000000000000;
  int result_int = 1085184861;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_16) {
  s21_decimal number;
  // decimal: -79228162514264337593543950330
  // float: -7.922816E+28
  // int: -276824064
  number.bits[0] = 0b11111111111111111111111111111010;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b11111111111111111111111111111111;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -276824064;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_17) {
  s21_decimal number;
  // decimal: -5454545545352456454545645464
  // float: -5.454546E+27
  // int: -309526744
  number.bits[0] = 0b10001000100000001001111110011000;
  number.bits[1] = 0b10000010011101100000001010011001;
  number.bits[2] = 0b00010001100111111110010011110010;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -309526744;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_18) {
  s21_decimal number;
  // decimal: 79228162514264337593543950335
  // float: 7.922816E+28
  // int: 1870659584
  number.bits[0] = 0b11111111111111111111111111111111;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b11111111111111111111111111111111;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1870659584;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_19) {
  s21_decimal number;
  // decimal: 1234.5677987654345678987654346
  // float: 1234.568
  // int: 1150964267
  number.bits[0] = 0b10010001000010101111010011001010;
  number.bits[1] = 0b11000000010001011101010111110010;
  number.bits[2] = 0b00100111111001000001101100000000;
  number.bits[3] = 0b00000000000110010000000000000000;
  int result_int = 1150964267;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_20) {
  s21_decimal number;
  // decimal: -123458677.98765434567898765435
  // float: -1.234587E+08
  // int: -856982897
  number.bits[0] = 0b10111001000000010001100001111011;
  number.bits[1] = 0b01101110100110001001011011101100;
  number.bits[2] = 0b00100111111001000100001100110010;
  number.bits[3] = 0b10000000000101000000000000000000;
  int result_int = -856982897;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_21) {
  s21_decimal number;
  // decimal: 123445677.98765434567898765435
  // float: 1.234457E+08
  // int: 1290499126
  number.bits[0] = 0b00110100100000010001100001111011;
  number.bits[1] = 0b01001010011100100010011000011110;
  number.bits[2] = 0b00100111111000110010111111101001;
  number.bits[3] = 0b00000000000101000000000000000000;
  int result_int = 1290499126;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_22) {
  s21_decimal number;
  // decimal: -12345677.987654533456789876543
  // float: -1.234568E+07
  // int: -885235378
  number.bits[0] = 0b11111110001111011010111100111111;
  number.bits[1] = 0b11000000010001101000000010111010;
  number.bits[2] = 0b00100111111001000001101100000000;
  number.bits[3] = 0b10000000000101010000000000000000;
  int result_int = -885235378;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_23) {
  s21_decimal number;
  // decimal: -784510454.7989898652154545652
  // float: -7.845105E+08
  // int: -834991432
  number.bits[0] = 0b00110101111110110100010111110100;
  number.bits[1] = 0b10110111000111111011101111011100;
  number.bits[2] = 0b00011001010110010101000110000001;
  number.bits[3] = 0b10000000000100110000000000000000;
  int result_int = -834991432;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_24) {
  s21_decimal number;
  // decimal: 32323465785678987654
  // float: 3.232346E+19
  // int: 1608534530
  number.bits[0] = 0b00000000111000111000000110000110;
  number.bits[1] = 0b11000000100101000000010011100000;
  number.bits[2] = 0b00000000000000000000000000000001;
  number.bits[3] = 0b00000000000000000000000000000000;
  int result_int = 1608534530;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_25) {
  s21_decimal number;
  // decimal: 0.0000000000000000000000000000
  // float: 0
  // int: -2147483648
  number.bits[0] = 0b00000000000000000000000000000000;
  number.bits[1] = 0b00000000000000000000000000000000;
  number.bits[2] = 0b00000000000000000000000000000000;
  number.bits[3] = 0b10000000000111000000000000000000;
  int result_int = -2147483648;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_26) {
  s21_decimal number;
  // decimal: -79228162514264337593543950335
  // float: -7.922816E+28
  // int: -276824064
  number.bits[0] = 0b11111111111111111111111111111111;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b11111111111111111111111111111111;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -276824064;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_27) {
  s21_decimal number;
  // decimal: -792.28162514264337593543950335
  // float: -792.2816
  // int: -1002040826
  number.bits[0] = 0b11111111111111111111111111111111;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b11111111111111111111111111111111;
  number.bits[3] = 0b10000000000110100000000000000000;
  int result_int = -1002040826;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_28) {
  s21_decimal number;
  // decimal: -79228162514264337593543950335
  // float: -7.922816E+28
  // int: -276824064
  number.bits[0] = 0b11111111111111111111111111111111;
  number.bits[1] = 0b11111111111111111111111111111111;
  number.bits[2] = 0b11111111111111111111111111111111;
  number.bits[3] = 0b10000000000000000000000000000000;
  int result_int = -276824064;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_29) {
  s21_decimal number;
  // decimal: 2.7986531268974139743
  // float: 2.798653
  // int: 1077091618
  number.bits[0] = 0b11111110100100001101100101011111;
  number.bits[1] = 0b10000100011001000010000111101000;
  number.bits[2] = 0b00000000000000000000000000000001;
  number.bits[3] = 0b00000000000100110000000000000000;
  int result_int = 1077091618;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(dec_to_float_30) {
  s21_decimal number;
  // decimal: 5.4564654654864768465454654846
  // float: 5.456465
  // int: 1085184861
  number.bits[0] = 0b01101110100110100110010101111110;
  number.bits[1] = 0b11100010111000110111110100101010;
  number.bits[2] = 0b10110000010011101101001100001111;
  number.bits[3] = 0b00000000000111000000000000000000;
  int result_int = 1085184861;
  int result_error = 0;
  float my_float;
  int my_error = s21_from_decimal_to_float(number, &my_float);
  int my_int = *(int *)(void *)&my_float;
  ck_assert_int_eq(result_int, my_int);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(float_to_dec__1) {
  float num = 829834.3;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 8298343);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 65536);
}
END_TEST

START_TEST(float_to_dec__2) {
  float num = 8934.278;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 8934278);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 196608);
}
END_TEST

START_TEST(float_to_dec__3) {
  float num = -23423.82;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 2342382);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147352576);
}
END_TEST

START_TEST(float_to_dec__4) {
  float num = -27348.28;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 2734828);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147352576);
}
END_TEST

START_TEST(float_to_dec__5) {
  float num = 823923;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 823923);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 0);
}
END_TEST

START_TEST(float_to_dec__6) {
  float num = -129312304;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 129312304);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147483648);
}
END_TEST

START_TEST(float_to_dec__7) {
  float num = 23744.78;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 2374478);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 131072);
}
END_TEST

START_TEST(float_to_dec__8) {
  float num = -2393.823;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 2393823);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147287040);
}
END_TEST

START_TEST(float_to_dec__9) {
  float num = 912479.2;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 9124792);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 65536);
}
END_TEST

START_TEST(float_to_dec__10) {
  float num = -123234.7;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 1232347);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147418112);
}
END_TEST

START_TEST(float_to_dec__11) {
  float num = 10121.7;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 101217);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 65536);
}
END_TEST

START_TEST(float_to_dec__12) {
  float num = -23748280;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 23748280);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147483648);
}
END_TEST

START_TEST(float_to_dec__13) {
  float num = 802000;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 802000);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 0);
}
END_TEST

START_TEST(float_to_dec__14) {
  float num = 1.3331;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 13331);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 262144);
}
END_TEST

START_TEST(float_to_dec__15) {
  float num = -1.667283;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 1667283);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147090432);
}
END_TEST

START_TEST(float_to_dec__16) {
  float num = 0.5632482;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 5632482);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 458752);
}
END_TEST

START_TEST(float_to_dec__17) {
  float num = -0.6527385;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 6527385);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147024896);
}
END_TEST

START_TEST(float_to_dec__18) {
  float num = -4.294967E+09;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], -256);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147483648);
}
END_TEST

START_TEST(float_to_dec__19) {
  float num = 4.294967E+09;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], -256);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 0);
}
END_TEST

START_TEST(float_to_dec__20) {
  float num = -8932.617;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 8932617);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], -2147287040);
}
END_TEST

Suite *test_convertation() {
  Suite *suite = suite_create("\033[1;30;47m S21_CONVERTATION \033[0;0;0m");
  TCase *test_case = tcase_create("\033[1;30;47m s21_convertation \033[0;0;0m");
  suite_add_tcase(suite, test_case);

  tcase_add_test(test_case, int_to_dec_1);
  tcase_add_test(test_case, int_to_dec_2);
  tcase_add_test(test_case, int_to_dec_3);
  tcase_add_test(test_case, int_to_dec_4);
  tcase_add_test(test_case, int_to_dec_5);
  tcase_add_test(test_case, int_to_dec_6);
  tcase_add_test(test_case, int_to_dec_7);
  tcase_add_test(test_case, int_to_dec_8);
  tcase_add_test(test_case, int_to_dec_9);
  tcase_add_test(test_case, int_to_dec_10);
  tcase_add_test(test_case, int_to_dec_11);
  tcase_add_test(test_case, int_to_dec_12);
  tcase_add_test(test_case, int_to_dec_13);
  tcase_add_test(test_case, int_to_dec_14);
  tcase_add_test(test_case, int_to_dec_15);
  tcase_add_test(test_case, int_to_dec_16);
  tcase_add_test(test_case, int_to_dec_17);
  tcase_add_test(test_case, int_to_dec_18);
  tcase_add_test(test_case, int_to_dec_19);
  tcase_add_test(test_case, int_to_dec_20);

  tcase_add_test(test_case, dec_to_int_1);
  tcase_add_test(test_case, dec_to_int_2);
  tcase_add_test(test_case, dec_to_int_3);
  tcase_add_test(test_case, dec_to_int_4);
  tcase_add_test(test_case, dec_to_int_5);
  tcase_add_test(test_case, dec_to_int_6);
  tcase_add_test(test_case, dec_to_int_7);
  tcase_add_test(test_case, dec_to_int_8);
  tcase_add_test(test_case, dec_to_int_9);
  tcase_add_test(test_case, dec_to_int_10);
  tcase_add_test(test_case, dec_to_int_11);
  tcase_add_test(test_case, dec_to_int_12);
  tcase_add_test(test_case, dec_to_int_13);
  tcase_add_test(test_case, dec_to_int_14);
  tcase_add_test(test_case, dec_to_int_15);
  tcase_add_test(test_case, dec_to_int_16);
  tcase_add_test(test_case, dec_to_int_17);
  tcase_add_test(test_case, dec_to_int_18);
  tcase_add_test(test_case, dec_to_int_19);
  tcase_add_test(test_case, dec_to_int_20);
  tcase_add_test(test_case, dec_to_int_21);
  tcase_add_test(test_case, dec_to_int_22);
  tcase_add_test(test_case, dec_to_int_23);
  tcase_add_test(test_case, dec_to_int_24);
  tcase_add_test(test_case, dec_to_int_25);

  tcase_add_test(test_case, dec_to_float_1);
  tcase_add_test(test_case, dec_to_float_2);
  tcase_add_test(test_case, dec_to_float_3);
  tcase_add_test(test_case, dec_to_float_4);
  tcase_add_test(test_case, dec_to_float_5);
  tcase_add_test(test_case, dec_to_float_6);
  tcase_add_test(test_case, dec_to_float_7);
  tcase_add_test(test_case, dec_to_float_8);
  tcase_add_test(test_case, dec_to_float_9);
  tcase_add_test(test_case, dec_to_float_10);
  tcase_add_test(test_case, dec_to_float_11);
  tcase_add_test(test_case, dec_to_float_12);
  tcase_add_test(test_case, dec_to_float_13);
  tcase_add_test(test_case, dec_to_float_14);
  tcase_add_test(test_case, dec_to_float_15);
  tcase_add_test(test_case, dec_to_float_16);
  tcase_add_test(test_case, dec_to_float_17);
  tcase_add_test(test_case, dec_to_float_18);
  tcase_add_test(test_case, dec_to_float_19);
  tcase_add_test(test_case, dec_to_float_20);
  tcase_add_test(test_case, dec_to_float_21);
  tcase_add_test(test_case, dec_to_float_22);
  tcase_add_test(test_case, dec_to_float_23);
  tcase_add_test(test_case, dec_to_float_24);
  tcase_add_test(test_case, dec_to_float_25);
  tcase_add_test(test_case, dec_to_float_26);
  tcase_add_test(test_case, dec_to_float_27);
  tcase_add_test(test_case, dec_to_float_28);
  tcase_add_test(test_case, dec_to_float_29);
  tcase_add_test(test_case, dec_to_float_30);

  tcase_add_test(test_case, float_to_dec__1);
  tcase_add_test(test_case, float_to_dec__2);
  tcase_add_test(test_case, float_to_dec__3);
  tcase_add_test(test_case, float_to_dec__4);
  tcase_add_test(test_case, float_to_dec__5);
  tcase_add_test(test_case, float_to_dec__6);
  tcase_add_test(test_case, float_to_dec__7);
  tcase_add_test(test_case, float_to_dec__8);
  tcase_add_test(test_case, float_to_dec__9);
  tcase_add_test(test_case, float_to_dec__10);
  tcase_add_test(test_case, float_to_dec__11);
  tcase_add_test(test_case, float_to_dec__12);
  tcase_add_test(test_case, float_to_dec__13);
  tcase_add_test(test_case, float_to_dec__14);
  tcase_add_test(test_case, float_to_dec__15);
  tcase_add_test(test_case, float_to_dec__16);
  tcase_add_test(test_case, float_to_dec__17);
  tcase_add_test(test_case, float_to_dec__18);
  tcase_add_test(test_case, float_to_dec__19);
  tcase_add_test(test_case, float_to_dec__20);

  return suite;
}
