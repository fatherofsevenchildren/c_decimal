#include "s21_decimal.h"

// СЛОЖЕНИЕ //
/**
 * @brief Эта функция выполняет сложение аргументов и записывает в отдельную
 * переменную;
 * @param value_1 Первый аргумент функции в битовом представление;
 * @param value_2 Второй аргумент функции в битовом представление;
 * @param result Переменая для записи результата операции сложения;
 * @return 0 - ОК:
 *         1 - Число слишком велико или равно бесконечности;
 *         2 - Число слишком мало или равно отрицательной бесконечности;
 *         3 - Деление на 0;
 *         // Промежуточные значения для игнорирования блоков:
 *         4 - Одно из чисел равно "0"
 */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int out = 0;
  struct ch_value ch_value_1 = {1, 1};
  struct ch_value ch_value_2 = {1, 1};
  s21_big_decimal big_value_1, big_value_2, big_result;

  start(value_1, value_2, result, &big_value_1, &big_value_2, &big_result);

  sign_value(value_1, value_2, &ch_value_1, &ch_value_2);

  // Вычитание при сложении. Если отрицательное число по модулю больше в
  // результате меняем знак на "-"
  if (((ch_value_1.sign_value == 0 && ch_value_2.sign_value == 1) ||
       (ch_value_1.sign_value == 1 && ch_value_2.sign_value == 0)) &&
      (ch_value_1.flag_null_value != 1 && ch_value_2.flag_null_value != 1)) {
    int flag = 0;
    if (ch_value_1.sign_value == 0 && ch_value_2.sign_value == 1) {
      if (s21_is_greater_or_equal_abs(value_1, value_2) == 1) flag = 1;
      s21_set_bit(&value_1, 127, 0);
    }
    if (ch_value_1.sign_value == 1 && ch_value_2.sign_value == 0) {
      if (s21_is_greater_or_equal_abs(value_2, value_1) == 1) flag = 2;
      s21_set_bit(&value_2, 127, 0);
    }
    out = s21_sub(value_1, value_2, result);
    if (flag == 1 || flag == 2)
      s21_set_bit(result, 127, 1);
    else
      s21_set_bit(result, 127, 0);
  }
  // Если одно из чисел "0"
  else {
    if (ch_value_1.flag_null_value == 1 || ch_value_2.flag_null_value == 1) {
      if (ch_value_1.flag_null_value == 0)
        big_result = big_value_1;
      else if (ch_value_2.flag_null_value == 0)
        big_result = big_value_2;
    } else {
      // Нормализация отдает нормализованное число в формате decimal
      normalization(&value_1, &value_2, &big_value_1, &big_value_2,
                    &big_result);
      s21_add_big_mantis(big_value_1, big_value_2, &big_result);
      if (ch_value_1.sign_value == 0 && ch_value_2.sign_value == 0)
        s21b_set_bit(&big_result, 223, 1);
      else
        s21b_set_bit(&big_result, 223, 0);
    }
    out = s21_big_decimal_to_decimal(big_result, result);
  }
  return out;
}

// ВЫЧИТАНИЕ
/**
 * @brief Эта функция выполняет вычитание аргументов и записывает в отдельную
 * переменную;
 * @param value_1 Первый аргумент функции в битовом представление;
 * @param value_2 Второй аргумент функции в битовом представление;
 * @param result Переменая для записи результата операции сложения;
 * @return 0 - ОК:
 *         1 - Число слишком велико или равно бесконечности;
 *         2 - Число слишком мало или равно отрицательной бесконечности;
 *         3 - Деление на 0;
 *         // Промежуточные значения для игнорирования блоков:
 *         4 - Одно из чисел равно "0"
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int out = 4;

  struct ch_value ch_value_1 = {1, 1};
  struct ch_value ch_value_2 = {1, 1};

  s21_big_decimal big_value_1, big_value_2, big_result;

  start(value_1, value_2, result, &big_value_1, &big_value_2, &big_result);

  sign_value(value_1, value_2, &ch_value_1, &ch_value_2);

  // Сложение при вычитании. Устанавливаем знак второго слогаемого после
  // изменения
  if (((ch_value_1.sign_value == 0 && ch_value_2.sign_value == 1) ||
       (ch_value_1.sign_value == 1 && ch_value_2.sign_value == 0)) &&
      (ch_value_1.flag_null_value != 1 && ch_value_2.flag_null_value != 1)) {
    int flag_sign = 2;

    if ((ch_value_1.sign_value == 0 && ch_value_2.sign_value == 1))
      flag_sign = 1;
    else
      flag_sign = 0;
    // Меняем знаки аргументов на положительный
    s21_set_bit(&value_1, 127, 0);
    s21_set_bit(&value_2, 127, 0);
    out = s21_add(value_1, value_2, result);
    // Устанавливаем знак результату
    if (out == 0)
      s21_set_bit(result, 127, flag_sign);
    else
      out = (flag_sign == 1 ? 2 : 1);
  } else {
    // Если одно из чисел равно "0"
    if (ch_value_1.flag_null_value == 1 || ch_value_2.flag_null_value == 1) {
      // Определение аргумента != "0"
      if (ch_value_1.flag_null_value == 0) {
        big_result = big_value_1;
        // Определение знак
        s21b_set_bit(&big_result, 223, s21b_get_bit(big_result, 223));
      } else if (ch_value_2.flag_null_value == 0) {
        big_result = big_value_2;
        // Определение знак
        if (ch_value_2.sign_value == 1)
          s21b_set_bit(&big_result, 223, 1);
        else if (ch_value_2.sign_value == 0)
          s21b_set_bit(&big_result, 223, 0);
      }
    } else {
      // printf("out = %d", out);
      int flag_big = 2;
      // Определим большее число по модулю
      if (s21_is_greater_or_equal_abs(value_1, value_2) == 1)
        flag_big = 1;
      else
        flag_big = 0;
      // Нормализуем число
      normalization(&value_1, &value_2, &big_value_1, &big_value_2,
                    &big_result);
      s21_sub_big_mantis((flag_big == 1 ? big_value_1 : big_value_2),
                         (flag_big == 1 ? big_value_2 : big_value_1),
                         &big_result);
      // Определяем знак
      if (ch_value_1.sign_value == 1 && ch_value_2.sign_value == 1)
        s21b_set_bit(&big_result, 223,
                     (flag_big == 1 ? s21b_get_bit(big_value_1, 127) : 1));
      else if (ch_value_1.sign_value == 0 && ch_value_2.sign_value == 0)
        s21b_set_bit(&big_result, 223,
                     (flag_big == 1 ? 1 : s21b_get_bit(big_value_1, 127)));
    }
    out = s21_big_decimal_to_decimal(big_result, result);
  }
  return out;
}

// УМНОЖЕНИЕ
/**
 * @brief Эта функция выполняет перемножение аргументов и записывает в отдельную
 * переменную;
 * @param value_1 Первый аргумент функции в битовом представление;
 * @param value_2 Второй аргумент функции в битовом представление;
 * @param result Переменая для записи результата операции сложения;
 * @return 0 - ОК:
 *         1 - Число слишком велико или равно бесконечности;
 *         2 - Число слишком мало или равно отрицательной бесконечности;
 *         3 - Деление на 0;
 */
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result) {  // celestiv 20.07
  s21_decimal zero = {{0, 0, 0, 0}}, one = {{1, 0, 0, 0}};
  int sign = s21_get_sign(value_1) ^ s21_get_sign(value_2);
  int final = 0;
  if (s21_is_equal(value_1, zero) || s21_is_equal(value_2, zero)) {
    *result = zero;
  } else if (s21_is_equal(value_1, one)) {
    *result = value_2;
  } else if (s21_is_equal(value_2, one)) {
    *result = value_1;
  } else {
    int sum_scale = s21_get_scale(value_2) + s21_get_scale(value_1);
    s21_set_sign(&value_1, 0);
    s21_set_sign(&value_2, 0);
    s21_big_decimal big_value_1, big_value_2, big_result;
    s21_zero_decimal(result);
    s21_dec_copy_to_big_dec(value_1, &big_value_1);
    s21_dec_copy_to_big_dec(value_2, &big_value_2);
    s21_dec_copy_to_big_dec(*result, &big_result);
    // начало основного цикла умножения
    int current_bit = 0;
    s21_big_decimal temp = big_value_1;
    for (int i = 0; i < 192; i++) {
      current_bit = s21b_get_bit(big_value_2, i);
      if (current_bit == 0) continue;
      temp = big_value_1;
      shift_left(&temp, i);
      s21_add_big_mantis(big_result, temp, &big_result);
    }
    s21b_set_bit(&big_result, 223, sign);
    s21b_set_scale(&big_result, sum_scale);
    final = s21_big_decimal_to_decimal(big_result, result);
  }
  return final;
}

// ДЕЛЕНИЕ //
/**
 * @brief Эта функция выполняет деление аргументов и записывает в отдельную
 * переменную;
 * @param value_1 Первый аргумент функции в битовом представление;
 * @param value_2 Второй аргумент функции в битовом представление;
 * @param result Переменая для записи результата операции сложения;
 * @return 0 - ОК:
 *         1 - Число слишком велико или равно бесконечности;
 *         2 - Число слишком мало или равно отрицательной бесконечности;
 *         3 - Деление на 0;
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int out = 0;

  int pow_1 = s21_get_scale(value_1), pow_2 = s21_get_scale(value_2),
      diff_pow = 0;
  int sign = s21_get_sign(value_1) ^ s21_get_sign(value_2);

  s21_decimal zero = {{0}};
  s21_decimal one = {{1, 0, 0, 0}};
  s21_big_decimal big_one = {{1, 0, 0, 0}};
  s21_big_decimal two = {{2, 0, 0, 0}};

  if (s21_is_equal(value_2, zero) == 1) {
    *result = zero;  // Проверка деления на "0"
    out = 3;
  } else if (s21_is_equal(value_1, zero))
    *result = zero;  // Проаерка делимого на "0"
  else if (s21_is_equal(value_2, one))
    *result = value_1;  // Проверка делителя на "1"
  else {
    s21_big_decimal big_value_1, big_value_2, big_result,
        buffer_0 = {{0}}, buffer_1 = {{0}}, buffer_2 = {{0}};
    start(value_1, value_2, result, &big_value_1, &big_value_2, &big_result);
    s21_dec_copy_to_big_dec(*result, &big_result);
    s21b_set_bit(&big_value_1, 223, 0);
    s21b_set_bit(&big_value_2, 223, 0);
    buffer_0 = big_value_2;
    buffer_1 = big_value_2;
    buffer_2 = big_value_2;
    // Деление без остатка
    // Пока делимое больше делителя
    int i = -1, flag_i = 0;

    for (; s21_is_greater_or_equal_abs_big(big_value_1, big_value_2) == 1;) {
      i++;
      shift_left(&buffer_2, 1);
      // ((Если делимое больше буфер 1 и меньше буфер 2) или (буфер 2 равен
      // делимогу) )
      if ((s21_is_greater_or_equal_abs_big(buffer_2, big_value_1) == 1 &&
           s21_is_greater_or_equal_abs_big(big_value_1, buffer_1) == 1) ||
          s21_is_equal_big(big_value_1, buffer_2)) {
        if (s21_is_equal_big(big_value_1, buffer_2)) flag_i = 1;
        if (s21_is_equal_big(big_value_1, buffer_2) == 1) {
          buffer_1 = buffer_2;
          i++;
          flag_i = 0;
        }
        s21_sub_big_mantis(big_value_1, buffer_1, &big_value_1);
        if (i == 0) {
          s21_add_big_mantis(big_result, big_one, &big_result);
        } else {
          shift_left(&two, flag_i ? i : i - 1);
          s21_add_big_mantis(big_result, two, &big_result);
          shift_right_big_decimal(&two, flag_i ? i : i - 1);
        }
        buffer_1 = buffer_0;
        buffer_2 = buffer_0;
        i = -1;
        continue;
      } else {
        buffer_1 = buffer_2;
      }
    }
    s21_big_decimal_to_decimal(big_result, result);
    s21_set_scale(result, pow_1 - diff_pow - pow_2);
    s21_set_sign(result, sign);
  }
  return out;
}
