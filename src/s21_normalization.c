
#include "s21_decimal.h"

// НОРМАЛИЗАЦИЯ //
/**
 * @brief Эта функция выполняет приведение аргументов к одному знаменателю
 * @param value_1 Первый аргумент функции в битовом представление;
 * @param value_2 Второй аргумент функции в битовом представление;
 * @param big_value_1 Первый аргумент функции в битовом представление размера
 * big;
 * @param big_value_2 Второй аргумент функции в битовом представление размера
 * big;
 * @return 0 - ОК:
 */
int normalization(s21_decimal *value_1, s21_decimal *value_2,
                  s21_big_decimal *big_value_1, s21_big_decimal *big_value_2,
                  s21_big_decimal *big_result) {
  // Определяем степени чисел
  int pow_1 = s21_get_scale(*value_1), pow_2 = s21_get_scale(*value_2),
      delta = pow_1 - pow_2, abs_delta = abs(delta);
  // Первая вариация
  if (pow_1 <= 28 || pow_2 <= 28) {
    for (int i = 0; i < abs_delta; i++) {
      s21_scale_add((delta > 0 ? value_2 : value_1));
      s21b_scale_add((delta > 0 ? big_value_2 : big_value_1));
      normalization_multiplus((delta > 0 ? big_value_2 : big_value_1), i);
    }
    *big_result = *(delta > 0 ? big_value_2 : big_value_1);
    s21b_set_scale((delta > 0 ? big_value_2 : big_value_1),
                   (delta > 0 ? pow_1 : pow_2));
    s21b_set_scale(big_result, (delta > 0 ? pow_1 : pow_2));
  }
  return 0;
}

/// @brief Функции для увеличения на "10"
void normalization_multiplus(s21_big_decimal *big_value, int i) {
  // Подключаем и зануляем buffer
  s21_big_decimal buffer = {{0}};
  s21_big_decimal buffer_2 = {{0}};
  s21_big_decimal result_add = *big_value;
  if (i == 0) {
    buffer = *big_value;
    s21_zero_big_decimal(big_value);
  } else {
    buffer = result_add;
    s21_zero_big_decimal(&result_add);
  }
  shift_left(&buffer, 1);
  s21_add_big_mantis(buffer, buffer_2, &result_add);
  buffer_2 = result_add;
  shift_left(&buffer, 2);
  s21_add_big_mantis(buffer, buffer_2, &result_add);
  *big_value = result_add;
}

/// @brief Функции изменение мантис на "1"
void s21_scale_add(s21_decimal *value) {
  value->bits[3] += 0b10000000000000000;
}
void s21b_scale_add(s21_big_decimal *value) {
  value->bits[6] += 0b10000000000000000;
}
void s21_scale_sub(s21_decimal *value) {
  value->bits[3] -= 0b10000000000000000;
}
void s21b_scale_sub(s21_big_decimal *value) {
  value->bits[6] -= 0b10000000000000000;
}

/// @brief Сложение больших мантисс
void s21_add_big_mantis(s21_big_decimal buffer, s21_big_decimal value2,
                        s21_big_decimal *res) {
  int buffer_bit = 0, sum = 0;
  // for (int i = 0; i < 224; i++)
  for (int i = 0; i < 192; i++) {
    sum = s21b_get_bit(buffer, i) + s21b_get_bit(value2, i);
    if (sum == 1) {
      if (buffer_bit == 1) {
        s21b_set_bit(res, i, 0);
      } else {
        s21b_set_bit(res, i, 1);
      }
    } else {
      if (buffer_bit == 1) {
        s21b_set_bit(res, i, 1);
        if (sum == 0) buffer_bit = 0;
      } else {
        s21b_set_bit(res, i, 0);
        if (sum == 2) buffer_bit = 1;
      }
    }
  }
}

s21_decimal s21_div_integer(s21_decimal src, int div) {
  s21_decimal res;
  s21_zero_decimal(&res);
  long unsigned int remainder = src.bits[2] % div;  // остаток
  res.bits[2] = src.bits[2] / div;
  for (int i = 1; i >= 0; i--) {
    long unsigned int tempbit =
        (long unsigned int)src.bits[i] +
        (remainder * pow(2, 32));  // временный младший бит чтобы не было
                                   // переполнения при добавлении остатка
    remainder = tempbit % div;
    tempbit -= remainder;  // округяем чтобы при делении на 10 число не
                           // округлилось до большего
    res.bits[i] = tempbit / div;
  }
  res.bits[0] += remainder / div;
  res.bits[3] = src.bits[3];
  return res;
}

s21_big_decimal s21b_div_integer(s21_big_decimal src, int div) {
  s21_big_decimal res;
  s21_zero_big_decimal(&res);
  long unsigned int remainder = src.bits[5] % div;  // остаток
  res.bits[5] = src.bits[5] / div;
  for (int i = 4; i >= 0; i--) {
    long unsigned int tempbit =
        (long unsigned int)src.bits[i] +
        (remainder * pow(2, 32));  // временный младший бит чтобы не было
                                   // переполнения при добавлении остатка
    remainder = tempbit % div;
    tempbit -= remainder;  // округяем чтобы при делении на 10 число не
                           // округлилось до большего
    res.bits[i] = tempbit / div;
  }
  res.bits[0] += remainder / div;
  res.bits[6] = src.bits[6];
  return res;
}
