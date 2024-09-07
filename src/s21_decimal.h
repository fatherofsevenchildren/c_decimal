#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned int bits[4]; /* data */
} s21_decimal;

typedef struct {
  unsigned int bits[7];
} s21_big_decimal;

struct ch_value {
  int sign_value;
  int flag_null_value;
};

#define ALL_BITE \
  0xffffffff  // Четыре бита заполненны еденицами для конвертации в обе стороны
#define MINUS 0x800000000
#define ZERO 0x000000000
#define DECIMALMAX 79228162514264337593543950335

#define SC 0x00ff0000  // 00000000 11111111 00000000 00000000
#define MAX4BITE \
  0xffffffff  // 11111111 11111111 11111111 11111111 //
              // 79228162514264337593543950335 max decimal

#define INT_MAX_32 2147483647
#define INT_MAX_64 9223372036854775807

#define BITS_MAX 96
#define ROWS 2
#define COLS 16
#define BITS_EXPONENT 8
#define BITS_MANTISSA (BITS_MAX - 1 - BITS_EXPONENT)

#define s21_TRUE 1
#define s21_FALSE 0

// --------ARITHMETIC-------- //

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// --------CONVERTATION-------- //

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);

// --------COMPARE-------- //

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_big(s21_big_decimal big_value_1,
                       s21_big_decimal big_value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal_big(s21_big_decimal big_value_1, s21_big_decimal big_value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal_big(s21_big_decimal value_1,
                                s21_big_decimal value_2);
int s21_is_greater_or_equal_abs(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal_abs_big(s21_big_decimal value_1,
                                    s21_big_decimal value_2);

// --------OTHER-------- //

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// --------BASE_DECIMAL-------- //

int s21_get_bit(s21_decimal dec, int index);
void s21_set_bit(s21_decimal *dec, int index, int bit);
int s21_get_scale(s21_decimal dec);
void s21_set_scale(s21_decimal *dec, int scale);
void s21_set_scale(s21_decimal *dec, int scale);
int s21_get_sign(s21_decimal dec);

void print_decimal(s21_decimal dec);
void s21_decimal_copy(s21_decimal from, s21_decimal *to);
int data_equal(s21_decimal value_1, s21_decimal value_2);
void s21_zero_decimal(s21_decimal *dec);
int data_is_null(s21_decimal value_1);
int data_is_null_big(s21_big_decimal value_1);
void s21_set_sign(s21_decimal *dec, int sign);
int find_last_bit_decimal(s21_decimal value);

// --------BASE_BIG_DECIMAL-------- //

int s21b_get_bit(s21_big_decimal dec, int index);
void s21b_set_bit(s21_big_decimal *dec, int index, int bit);
int s21b_get_scale(s21_big_decimal dec);
void s21b_set_scale(s21_big_decimal *dec, int scale);
int s21_get_big_dec_sign(s21_big_decimal dec);

void print_big_decimal(s21_big_decimal dec);
void shift_left(s21_big_decimal *src, int delta);
void s21_dec_copy_to_big_dec(s21_decimal from, s21_big_decimal *to);
void copy_decimal(s21_big_decimal value, s21_decimal *result);
int find_last_bit(s21_big_decimal value);
int big_data_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_big_decimal_to_decimal(s21_big_decimal value, s21_decimal *result);
void s21_zero_big_decimal(s21_big_decimal *dst);
int find_remainder(s21_big_decimal value, s21_big_decimal new_value, int scale);
void shift_right_big_decimal(s21_big_decimal *src, int delta);
int s21b_get_sign(s21_big_decimal dec);

// --------NORMALYZATION-------- //

int normalization(s21_decimal *value_1, s21_decimal *value_2,
                  s21_big_decimal *big_value_1, s21_big_decimal *big_value_2,
                  s21_big_decimal *big_result);
void normalization_multiplus_part_1(s21_big_decimal big_value_1,
                                    s21_big_decimal big_value_2,
                                    s21_big_decimal *big_result,
                                    s21_big_decimal *buffer,
                                    s21_big_decimal *buffer_2, int delta,
                                    int i);
void normalization_multiplus_part_2(s21_big_decimal *buffer,
                                    s21_big_decimal *buffer_2,
                                    s21_big_decimal *big_result);
void s21_scale_add(s21_decimal *value);
void s21b_scale_add(s21_big_decimal *value);
void s21_scale_sub(s21_decimal *value);
void s21b_scale_sub(s21_big_decimal *value);
void s21_add_big_mantis(s21_big_decimal buffer, s21_big_decimal value2,
                        s21_big_decimal *res);
s21_decimal s21_div_integer(s21_decimal src, int div);
s21_big_decimal s21b_div_integer(s21_big_decimal src, int div);
void up_value(s21_decimal *value, s21_big_decimal *big_value, int pow);
void down_value(s21_decimal *value, s21_big_decimal *big_value, int pow);
void normalization_multiplus(s21_big_decimal *big_value, int i);

// --------AUXILIARY-------- //

int sign_value(s21_decimal value_1, s21_decimal value_2,
               struct ch_value *ch_value_1, struct ch_value *ch_value_2);
void conversion_decimal_in_big_decimal(s21_decimal value,
                                       s21_big_decimal *big_value);

void start(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
           s21_big_decimal *big_value_1, s21_big_decimal *big_value_2,
           s21_big_decimal *big_result);
void s21_sub_big_mantis(s21_big_decimal big_argument, s21_big_decimal big_value,
                        s21_big_decimal *big_result);
int search_position_bit(s21_big_decimal value, int start_index, int bit);

/*

    // ____________________________OLD HEADER____________________________ //

    // int s21_get_bit(s21_decimal dec, int index);
    // void s21_set_bit(s21_decimal *dec, int index, int bit);
    // int s21_get_scale(s21_decimal dec);
    // void s21_set_scale(s21_decimal *dec, int scale);
    // void print_decimal(s21_decimal dec);
    // int s21_negate(s21_decimal value, s21_decimal *result);
    // int s21_int_to_dec(s21_decimal *dec, int int1) ;
    // void s21_dec_to_float(s21_decimal src, float*dst);
    // int s21_get_sign(s21_decimal dec);
    // void s21_decimal_copy(s21_decimal from, s21_decimal *to);
    // int data_equal(s21_decimal value_1, s21_decimal value_2);

    // int s21_from_decimal_to_int(s21_decimal src, int*dst);
    // int s21_from_decimal_to_float(s21_decimal src, float *dst);
    // int s21_from_float_to_decimal(float src, s21_decimal *dst);

    // // АРИФМЕТИКА //
    // int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal
   *result);

    // // ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ АРИФМЕТИКИ //

    // // Определение знака и проверка на "0"
    // int sign_value (s21_decimal value_1, s21_decimal value_2, struct ch_value
   *ch_value_1, struct ch_value *ch_value_2);
    // // Конвертация из decimal in big_decimal
    // void conversion_decimal_in_big_decimal(s21_decimal value, s21_big_decimal
   *big_value);
    // // Конвертация из big_decimal in decimal
    // void conversion_big_decimal_in_decimal(s21_decimal *result,
   s21_big_decimal big_value);

    // // void s21_multiplication_mantissa(s21_decimal *value, int delta,
   s21_decimal *result, int *flag_repletion);
    // // void s21_equalization_degrees(s21_decimal *value_1, s21_decimal
   *value_2, s21_decimal *result, int *flag_repletion);

    // // НЕОБХОДИМА СОРТИРОВКА //
    // void s21_dec_to_float(s21_decimal src, float*dst);
    // void s21_dec_to_int(s21_decimal src, int*dst);
    // int s21_int_to_dec(s21_decimal *dec, int int1);
    // int s21_negate(s21_decimal value, s21_decimal *result);


    // // BIG DECIMAL //
    // int s21b_get_bit(s21_big_decimal dec, int index);
    // void s21b_set_bit(s21_big_decimal *dec, int index, int bit);
    //     // Не использую
    // int s21b_get_scale(s21_big_decimal dec);
    //     // Не использую
    // void s21b_set_scale(s21_big_decimal *dec, int scale);
    // void print_big_decimal(s21_big_decimal dec);
    // int s21_get_big_dec_sign(s21_decimal dec);
    // void s21_dec_copy_to_big_dec(s21_decimal from, s21_big_decimal *to);
    // int big_data_equal(s21_big_decimal value_1, s21_big_decimal value_2);

    // // NORMALIZATION //


    // int normalization(s21_decimal *value_1, s21_decimal *value_2,
   s21_big_decimal *big_value_1, s21_big_decimal *big_value_2, s21_big_decimal
   *big_result);
    // void shift_left_decimal (s21_big_decimal *value, int delta);
    // void shift_left (s21_big_decimal *src, int delta);
    // void s21_add_big_mantis(s21_big_decimal buffer, s21_big_decimal value2,
   s21_big_decimal *res);
    // void s21_scale (s21_decimal *value);

    // void s21_scale_add (s21_decimal *value);
    // void s21b_scale_add (s21_big_decimal *value);
    // void s21_scale_sub (s21_decimal *value);
    // void s21b_scale_sub (s21_big_decimal *value);



    // s21_decimal s21_div_integer(s21_decimal src, int div);
    // s21_decimal s21_div_ten(s21_decimal src);
    // void big_decimal_to_decimal(s21_big_decimal value, s21_decimal *result);
    // int find_last_bit(s21_big_decimal value);
    // s21_big_decimal s21b_div_integer(s21_big_decimal src, int div);
    // void s21_dec_copy_to_big_dec(s21_decimal from, s21_big_decimal *to);




    // void s21_add_big_mantis(s21_big_decimal buffer, s21_big_decimal value2,
   s21_big_decimal *res);

    // // ZERO //
    // void s21_zero_decimal(s21_decimal *dst);
    // void s21_zero_big_decimal(s21_big_decimal *dst);


    // // --------------------- COMPARE --------------------- //

    // int s21_is_less(s21_decimal value_1, s21_decimal value_2);
    // int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
    // int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
    // int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
    // int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
    // int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

*/

#endif  // SRC_S21_DECIMAL_H_