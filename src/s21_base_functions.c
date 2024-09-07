#include "s21_decimal.h"

int s21_get_bit(s21_decimal dec, int index) {
  if (index > 127) return 0;
  int res = 0;
  int mask = 1u << (index % 32);
  if (dec.bits[index / 32] & mask)
    res = 1;
  else
    res = 0;
  return res;
}

void s21_set_bit(s21_decimal *dec, int index, int bit) {
  int mask = 1u << (index % 32);
  if (bit)
    dec->bits[index / 32] = dec->bits[index / 32] | mask;
  else
    dec->bits[index / 32] = dec->bits[index / 32] & ~mask;
  return;
}

int s21_get_scale(s21_decimal dec) {
  dec.bits[3] = dec.bits[3] << 1;
  int scale = dec.bits[3] >> 17;
  return scale;
}

void s21_set_scale(s21_decimal *dec, int scale) {
  int minus_flag = 0;
  if (s21_get_bit(*dec, 127)) minus_flag++;
  dec->bits[3] = ZERO;
  dec->bits[3] = scale << 16;
  if (minus_flag) s21_set_bit(dec, 127, 1);
}

/// @brief Узнать знак числа
/// @return 1 -отрицательное 0 -положительное
int s21_get_sign(s21_decimal dec) { return s21_get_bit(dec, 127); }

/// @brief Заполняем все значения битов в структуре типа s21_decimal нулями
/// @param dec Структура которую нужно занулить
void s21_zero_decimal(s21_decimal *dec) {
  dec->bits[0] = dec->bits[1] = dec->bits[2] = dec->bits[3] = 0;
}

/// @brief сравнивает что value_1 == value_2
/// @return 1 == равны, 0 = не равны
int data_equal(s21_decimal value_1, s21_decimal value_2) {
  int equal = s21_FALSE;
  return equal = ((value_1.bits[0] ^ value_2.bits[0]) == 0 &&
                  (value_1.bits[1] ^ value_2.bits[1]) == 0 &&
                  (value_1.bits[2] ^ value_2.bits[2]) == 0)
                     ? s21_TRUE
                     : s21_FALSE;
}

/// @brief сравнивает 0,1,2 байт с нулём
/// @return 0 структура != 0, 1 структура == 0
int data_is_null(s21_decimal value_1) {
  int equal = s21_FALSE;
  return equal = ((value_1.bits[0]) == 0 && (value_1.bits[1]) == 0 &&
                  (value_1.bits[2]) == 0)
                     ? s21_TRUE
                     : s21_FALSE;
}
int data_is_null_big(s21_big_decimal value_1) {
  int equal = s21_FALSE;
  return equal = ((value_1.bits[0]) == 0 && (value_1.bits[1]) == 0 &&
                  (value_1.bits[2]) == 0 && (value_1.bits[3]) == 0 &&
                  (value_1.bits[4]) == 0 && (value_1.bits[5]) == 0)
                     ? s21_TRUE
                     : s21_FALSE;
}

void s21_set_sign(s21_decimal *dec, int sign) { s21_set_bit(dec, 127, sign); }