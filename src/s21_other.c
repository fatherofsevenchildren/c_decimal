
#include "s21_decimal.h"

/// @brief Округление числа вниз в сторону минус бесконечности
/// @param value исходная структура
/// @param result структура, в которую мы записываем результат выполнения
/// @return 0 - OK. 1 - ошибка
int s21_floor(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;
  if (s21_get_scale(value) == 0) {
    *result = value;
    return 0;
  }
  s21_truncate(value, result);
  if (s21_get_sign(value) && value.bits[0] != 0) {
    result->bits[0] += 1;
  }
  return 0;
}

/// @brief Отбрасывает дробную часть числа
/// @param value исходная структура, содержащая число в двоичном представлении
/// @param result структура, в которую мы записываем результат выполненных
/// действий
/// @return 0 - OK. 1 - ошибка
int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;
  if (s21_get_scale(value) == 0) {
    *result = value;
    return 0;
  }
  *result = value;
  int scale = s21_get_scale(*result);
  int sign = s21_get_sign(*result);
  while (scale != 0) {
    scale--;
    *result = s21_div_integer(*result, 10);
  }
  s21_set_scale(result, 0);
  s21_set_bit(result, 127, sign);
  return 0;
}

/// @brief Округляет число до ближайшего целого. Математическое
/// @param value исходная структура, содержащая число в двоичном представлении
/// @param result структура, в которую мы записываем результат выполненных
/// действий
/// @return 0 - OK. 1 - ошибка
int s21_round(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;
  if (s21_get_scale(value) == 0) {
    *result = value;
    return 0;
  }
  *result = value;
  int sign = s21_get_sign(value);
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal half = {{0}};
  s21_decimal remainder = {{0}};
  s21_set_sign(&value, 0);
  s21_from_float_to_decimal(0.50, &half);
  s21_truncate(value, result);
  s21_set_sign(result, 0);
  s21_sub(value, *result, &remainder);
  if (s21_is_greater_or_equal(remainder, half)) {
    s21_add(*result, one, result);
  }
  s21_set_scale(result, 0);
  s21_set_sign(result, sign);
  return 0;
}

/// @brief Возвращает число, обратное исходному, то есть умножает на -1.
/// @param value исходная структура, содержащая число в двоичном представлении
/// @param result структура, в которую мы записываем результат выполненных
/// действий
/// @return 0 - OK. 1 - ошибка
int s21_negate(s21_decimal value, s21_decimal *result) {  //Макс
  s21_zero_decimal(result);
  if (s21_get_bit(value, 127))
    s21_set_bit(&value, 127, 0);
  else
    s21_set_bit(&value, 127, 1);
  *result = value;
  return 0;
}
