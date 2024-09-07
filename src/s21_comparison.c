
#include "s21_decimal.h"

// ---------------------- COMPARE ---------------------- //

// int main (){

//   s21_decimal src1 = {{0}};
//   s21_decimal src2 = {{0}};

//   // src1 = 32323465788987654;
//   // src2 = 67543278.89765424354657687;

//   src1.bits[0] = 0b01011000010000110001100100000110;
//   src1.bits[1] = 0b00000000011100101101011000000101;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   src2.bits[0] = 0b10111110000100011000010110010111;
//   src2.bits[1] = 0b11011001001111010001001011000110;
//   src2.bits[2] = 0b00000000000001011001011001001000;
//   src2.bits[3] = 0b00000000000100010000000000000000;
//   int result = s21_is_greater(src1, src2);
//   int origin = 0;
//   printf("result %d||", result);
//   return 0;
// }
/// @brief Сравнение value_1 больше value_2
/// @return 1 - value_1 сравнение правдиво value_2; 0 - value_1 сравнение ложно
/// value_2
int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result = s21_FALSE;
  if (data_is_null(value_1) == 1 && data_is_null(value_2) == 1) return result;
  if (s21_get_sign(value_1) == 1 && s21_get_sign(value_2) == 0) return result;
  if (s21_get_sign(value_1) == 0 && s21_get_sign(value_2) == 1) return s21_TRUE;

  int scale_dif = s21_get_scale(value_1) - s21_get_scale(value_2);
  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;
  s21_big_decimal big_result;
  s21_zero_big_decimal(&big_value_1);
  s21_zero_big_decimal(&big_value_2);
  s21_zero_big_decimal(&big_result);

  s21_dec_copy_to_big_dec(value_1, &big_value_1);
  s21_dec_copy_to_big_dec(value_2, &big_value_2);

  normalization(&value_1, &value_2, &big_value_1, &big_value_2, &big_result);

  if (scale_dif < 0)
    big_value_1 = big_result;
  else if (scale_dif > 0)
    big_value_2 = big_result;

  // если числа отрицательные надо их развернуть
  if (s21_get_sign(value_1)) {
    big_result = big_value_1;
    big_value_1 = big_value_2;
    big_value_2 = big_result;
  }
  for (int idx_bit = 191; idx_bit > -1; idx_bit--) {
    if (s21b_get_bit(big_value_1, idx_bit) !=
        s21b_get_bit(big_value_2, idx_bit)) {
      if (s21b_get_bit(big_value_1, idx_bit) == 1) result = s21_TRUE;
      break;
    }
  }

  return result;
}

int s21_is_greater_big(s21_big_decimal big_value_1,
                       s21_big_decimal big_value_2) {
  int result = s21_FALSE;
  if (s21b_get_sign(big_value_1) == 0 && s21b_get_sign(big_value_2) == 1)
    return s21_TRUE;

  int scale_dif = s21b_get_scale(big_value_1) - s21b_get_scale(big_value_2);

  s21_big_decimal big_result;
  s21_decimal value_1;
  s21_decimal value_2;

  s21_big_decimal_to_decimal(big_value_1, &value_1);
  s21_big_decimal_to_decimal(big_value_2, &value_2);

  s21_zero_big_decimal(&big_result);

  if (scale_dif != 0)
    normalization(&value_1, &value_2, &big_value_1, &big_value_2, &big_result);

  if (scale_dif < 0)
    big_value_1 = big_result;
  else if (scale_dif > 0)
    big_value_2 = big_result;

  // если числа отрицательные надо их развернуть
  if (s21_get_sign(value_1)) {
    big_result = big_value_1;
    big_value_1 = big_value_2;
    big_value_2 = big_result;
  }

  for (int idx_bit = 191; idx_bit > -1; idx_bit--) {
    if (s21b_get_bit(big_value_1, idx_bit) !=
        s21b_get_bit(big_value_2, idx_bit)) {
      if (s21b_get_bit(big_value_1, idx_bit) == 1) result = s21_TRUE;
      break;
    }
  }
  return result;
}
/// @brief Сравнение value_1 равен value_2
/// @return 1 - value_1 равенство правдиво value_2; 0 - value_1 равенство ложно
/// value_2
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = s21_FALSE;
  int sign =
      s21_get_sign(value_1) ^ s21_get_sign(value_2);  // if (1) res == s21_FALSE
  if (sign && !data_is_null(value_1) && !data_is_null(value_2)) return result;

  int scale_dif = s21_get_scale(value_1) - s21_get_scale(value_2);
  int data_eq = 0;

  if (scale_dif != 0) {
    s21_big_decimal big_value_1;
    s21_big_decimal big_value_2;
    s21_big_decimal big_result;
    s21_zero_big_decimal(&big_value_1);
    s21_zero_big_decimal(&big_value_2);
    s21_zero_big_decimal(&big_result);
    s21_dec_copy_to_big_dec(value_1, &big_value_1);
    s21_dec_copy_to_big_dec(value_2, &big_value_2);

    normalization(&value_1, &value_2, &big_value_1, &big_value_2, &big_result);
    data_eq = big_data_equal(big_value_1, big_result);
    if (scale_dif < 0) data_eq = big_data_equal(big_value_2, big_result);
  } else
    data_eq = data_equal(value_1, value_2);

  if (data_eq) result = s21_TRUE;

  return result;
}
int s21_is_equal_big(s21_big_decimal big_value_1, s21_big_decimal big_value_2) {
  int result = s21_FALSE;
  int sign = s21b_get_sign(big_value_1) ^
             s21b_get_sign(big_value_2);  // if (1) res == s21_FALSE
  if (sign && !data_is_null_big(big_value_1) && !data_is_null_big(big_value_2))
    return result;

  int scale_dif = s21b_get_scale(big_value_1) - s21b_get_scale(big_value_2);
  int data_eq = 0;

  if (scale_dif != 0) {
    s21_big_decimal big_result;
    s21_decimal value_1;
    s21_decimal value_2;

    s21_big_decimal_to_decimal(big_value_1, &value_1);
    s21_big_decimal_to_decimal(big_value_2, &value_2);

    s21_zero_big_decimal(&big_result);
    normalization(&value_1, &value_2, &big_value_1, &big_value_2, &big_result);
    data_eq = big_data_equal(big_value_1, big_result);
    if (scale_dif < 0) data_eq = big_data_equal(big_value_2, big_result);
  } else
    data_eq = big_data_equal(big_value_1, big_value_2);

  if (data_eq) result = s21_TRUE;

  return result;
}
/// @brief Сравнение value_1 не равен value_2
/// @return 1 - value_1 равенство правдиво value_2; 0 - value_1 равенство ложно
/// value_2
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}

/// @brief Сравнение value_1 меньше value_2
/// @return 1 - value_1 сравнение правдиво value_2; 0 - value_1 сравнение ложно
/// value_2
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = s21_FALSE;
  if (data_is_null(value_1) == 0 && data_is_null(value_2) == 0)
    result = !s21_is_greater_or_equal(value_1, value_2);
  return result;
}

/// @brief Сравнение value_1 меньше или равен value_2
/// @return 1 - value_1 сравнение правдиво value_2; 0 - value_1 сравнение ложно
/// value_2
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_is_less(value_1, value_2) | s21_is_equal(value_1, value_2));
}

/// @brief Сравнение value_1 больше или равен value_2
/// @return 1 - value_1 сравнение правдиво value_2; 0 - value_1 сравнение ложно
/// value_2
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_is_greater(value_1, value_2) | s21_is_equal(value_1, value_2));
}
int s21_is_greater_or_equal_big(s21_big_decimal value_1,
                                s21_big_decimal value_2) {
  return (s21_is_greater_big(value_1, value_2) |
          s21_is_equal_big(value_1, value_2));
}
/// @brief Сравнение value_1 больше или равен value_2 по модулю
/// @return 1 - value_1 сравнение правдиво value_2; 0 - value_1 сравнение ложно
/// value_2
int s21_is_greater_or_equal_abs(s21_decimal value_1, s21_decimal value_2) {
  s21_set_bit(&value_1, 127, 0);
  s21_set_bit(&value_2, 127, 0);
  return s21_is_greater_or_equal(value_1, value_2);
}

int s21_is_greater_or_equal_abs_big(s21_big_decimal value_1,
                                    s21_big_decimal value_2) {
  s21b_set_bit(&value_1, 223, 0);
  s21b_set_bit(&value_2, 223, 0);
  return s21_is_greater_or_equal_big(value_1, value_2);
}