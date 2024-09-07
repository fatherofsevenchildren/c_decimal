#include "s21_decimal.h"

// Проверка на знак b "0"
int sign_value(s21_decimal value_1, s21_decimal value_2,
               struct ch_value *ch_value_1, struct ch_value *ch_value_2) {
  for (int index = 0; index != 96; index++) {
    if (s21_get_bit(value_1, index)) ch_value_1->flag_null_value = 0;
    if (s21_get_bit(value_2, index)) ch_value_2->flag_null_value = 0;
  }
  if (s21_get_bit(value_1, 127) == 1) ch_value_1->sign_value = 0;
  if (s21_get_bit(value_2, 127) == 1) ch_value_2->sign_value = 0;
  return 0;
}
// Функция конвертации из decimal in big_decimal
void conversion_decimal_in_big_decimal(s21_decimal value,
                                       s21_big_decimal *big_value) {
  for (int i = 0; i < 3; i++) big_value->bits[i] = value.bits[i] & ALL_BITE;
}

// Начало арифметических функций
void start(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
           s21_big_decimal *big_value_1, s21_big_decimal *big_value_2,
           s21_big_decimal *big_result) {
  s21_zero_big_decimal(big_value_1);
  s21_zero_big_decimal(big_value_2);
  s21_zero_big_decimal(big_result);

  s21_zero_decimal(result);

  s21_dec_copy_to_big_dec(value_1, big_value_1);
  s21_dec_copy_to_big_dec(value_2, big_value_2);
}

// Вычитание мантисс
void s21_sub_big_mantis(s21_big_decimal bigger, s21_big_decimal smaller,
                        s21_big_decimal *result) {
  for (int idx = 0; idx < 191; idx++) {
    int bigger_bit = s21b_get_bit(bigger, idx),
        smaller_bit = s21b_get_bit(smaller, idx);
    if ((bigger_bit - smaller_bit == 0)) {
      // Если бит из большего и меньшего == 1 или бит большего и меньшего == 0
      s21b_set_bit(result, idx, 0);
    } else if (bigger_bit == 1 && smaller_bit == 0) {
      s21b_set_bit(result, idx, 1);
    } else if (bigger_bit == 0 && smaller_bit == 1) {
      // Если бит из большего == 0 и меньшего == 1
      int idx_zero = idx, idx_one = search_position_bit(bigger, idx_zero, 1);
      s21b_set_bit(
          &bigger, idx_one,
          0);  // меняем бит первой в большем числе встретившейся 1 на 0
      for (; idx_zero < idx_one; idx_zero++) {
        // Меняем все биты == 0 большего числа до первой еденицы в большем числе
        // на 1
        s21b_set_bit(&bigger, idx_zero, 1);
      }
      s21b_set_bit(result, idx, 1);
    }
  }
}
// void s21_sub_big_mantis(s21_big_decimal big_argument, s21_big_decimal
// big_value, s21_big_decimal *big_result) {
//   for (int index = 0; index < 191; index++) {
//     // Если необходио занимать еденицу
//     if (s21b_get_bit(big_argument, index) == 0 && s21b_get_bit(big_value,
//     index) == 1)
//     {
//       // Меняем "0" на  "1" и записываем результат в big_result
//       int index_date = index;
//       for (; s21b_get_bit(big_argument, index) != 1; index_date++)
//       {
//         s21b_set_bit(&big_argument, index_date, 1);
//       }
//       s21b_set_bit(&big_argument, index_date, 0);
//       s21b_set_bit(big_result, index, 1);
//     } else if (s21b_get_bit(big_argument, index) == 1 &&
//     s21b_get_bit(big_value, index) == 1)
//     {
//       s21b_set_bit(big_result, index, 0);
//     } else if (s21b_get_bit(big_argument, index) == 1 &&
//     s21b_get_bit(big_value, index) == 0)
//     {
//       s21b_set_bit(big_result, index, 1);
//     }
//   }
// }
/**
 * @brief Эта функция выполняет поиск первого необходмого бита;
 * @param value Аргумент в которм ведётся поиск;
 * @param start_index Индекс начало поиска;
 * @param bit Искомое значение;
 * @return x - найденный индекс:
 */
// int search_position_bit(s21_big_decimal value, int start_index, int bit) {
//   int index = start_index;
//   for (; s21b_get_bit(value, index) != bit; index++) return index;
// }
int search_position_bit(s21_big_decimal value, int start_index, int bit) {
  int index = start_index;
  for (; s21b_get_bit(value, index) != bit && index < 192 && index >= 0;
       index++)
    ;
  return index;
}
