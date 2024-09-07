
#include "s21_decimal.h"

// -------------------------- BIG_DEC -------------------------- //

int s21b_get_bit(s21_big_decimal dec, int index) {
  int res = 0;
  if (index < 224 && index >= 0) {
    int mask = 1u << (index % 32);
    if (dec.bits[index / 32] & mask)
      res = 1;
    else
      res = 0;
  }
  return res;
}

void s21b_set_bit(s21_big_decimal *dec, int index, int bit) {
  int mask = 1u << (index % 32);
  if (bit)
    dec->bits[index / 32] = dec->bits[index / 32] | mask;
  else
    dec->bits[index / 32] = dec->bits[index / 32] & ~mask;
  return;
}

int s21b_get_scale(s21_big_decimal dec) {
  dec.bits[6] = dec.bits[6] << 1;
  int scale = dec.bits[6] >> 17;
  return scale;
}

void s21b_set_scale(s21_big_decimal *dec, int scale) {
  int minus_flag = 0;
  if (s21b_get_bit(*dec, 223)) minus_flag++;
  dec->bits[6] = ZERO;
  dec->bits[6] = scale << 16;
  if (minus_flag) s21b_set_bit(dec, 223, 1);
}

void print_big_decimal(s21_big_decimal dec) {
  for (int i = 223; i >= 0; i--) {
    if (s21b_get_bit(dec, i))
      printf("1");
    else
      printf("0");
    if (!(i % 32)) printf(" ");
  }
}

/// @brief Узнать знак числа
/// @return 1 -отрицательное 0 -положительное
int s21_get_big_dec_sign(s21_big_decimal dec) { return s21b_get_bit(dec, 223); }

/// @brief смещает все биты вслево на delta
void shift_left(s21_big_decimal *src, int delta) {
  s21_big_decimal res;
  s21_zero_big_decimal(&res);
  for (int i = 0; i + delta < 191; i++) {
    s21b_set_bit(&res, i + delta, s21b_get_bit(*src, i));
  }
  *src = res;
}

void s21_scale(s21_decimal *value) { value->bits[3] += 0b10000000000000000; }

/// @brief копирует децимал в биг децимал
void s21_dec_copy_to_big_dec(s21_decimal from, s21_big_decimal *to) {
  to->bits[0] = from.bits[0];
  to->bits[1] = from.bits[1];
  to->bits[2] = from.bits[2];
  to->bits[3] = 0;
  to->bits[4] = 0;
  to->bits[5] = 0;
  to->bits[6] = from.bits[3];
}

/// @brief копирует 0,1,2,6 байт биг децимал в децимал
void copy_decimal(s21_big_decimal value, s21_decimal *result) {
  result->bits[0] = value.bits[0];
  result->bits[1] = value.bits[1];
  result->bits[2] = value.bits[2];
  result->bits[3] = value.bits[6];
}

/// @brief находит индекс самого левого бита // ищет справа налево
int find_last_bit(s21_big_decimal value) {
  int result = -1;
  for (int i = 192; i >= 0 && result == -1; i--) {
    if (s21b_get_bit(value, i) == 1) {
      result = i;
    }
  }
  return result;
}

/// @brief сравнивает что value_1 == value_2
/// @return 1 == равны, 0 = не равны
int big_data_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
  int equal = s21_FALSE;
  return equal = ((value_1.bits[0] ^ value_2.bits[0]) == 0 &&
                  (value_1.bits[1] ^ value_2.bits[1]) == 0 &&
                  (value_1.bits[2] ^ value_2.bits[2]) == 0 &&
                  (value_1.bits[3] ^ value_2.bits[3]) == 0 &&
                  (value_1.bits[4] ^ value_2.bits[4]) == 0 &&
                  (value_1.bits[5] ^ value_2.bits[5]) == 0)
                     ? s21_TRUE
                     : s21_FALSE;
}

/// @brief конвертирует биг децимал в децимал
/// @return 0 - все хорошо, 1 - переполнение, 2 - отрицательное переполнение
int s21_big_decimal_to_decimal(
    s21_big_decimal value,
    s21_decimal *result) {  // celestiv // переложил в биг децимал база
  if (value.bits[3] + value.bits[4] + value.bits[5] == 0) {
    copy_decimal(value, result);
    return 0;
  }
  int sign_for_out = s21_get_big_dec_sign(value);
  if (s21b_get_scale(value) == 0 && find_last_bit(value) > 95) {
    s21_zero_decimal(result);
    return sign_for_out ? 2 : 1;
  }

  s21_big_decimal new_value = {{0}};
  int scale = s21b_get_scale(value);
  int remainder = 0;
  while (find_last_bit(value) >= 97 && scale > 1) {
    value = s21b_div_integer(value, 10);
    scale--;
  }
  new_value = s21b_div_integer(value, 10);
  scale--;
  s21b_set_scale(&new_value, scale);
  remainder = find_remainder(value, new_value, scale);

  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0}};

  if (remainder == 5 && s21b_get_bit(new_value, 0) == 1)
    s21_add_big_mantis(new_value, one, &new_value);
  else if (remainder > 5)
    s21_add_big_mantis(new_value, one, &new_value);

  value = new_value;

  if (s21b_get_bit(value, 222)) {  // add 1
    int flag = 1;
    for (int i = 0; flag && i < 192; i++) {
      if (s21b_get_bit(value, i))
        s21b_set_bit(&value, i, 0);
      else {
        s21b_set_bit(&value, i, 1);
        flag--;
      }
    }
  }

  copy_decimal(value, result);
  s21_set_scale(result, scale);
  int error = 0;

  if (find_last_bit(value) > 95) {
    s21_zero_decimal(result);
    error = sign_for_out ? 2 : 1;
  }
  return error;
}

void s21_zero_big_decimal(s21_big_decimal *dst) {
  dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = dst->bits[4] =
      dst->bits[5] = dst->bits[6] = 0;
}

int find_remainder(s21_big_decimal value, s21_big_decimal new_value,
                   int scale) {
  // dec1 dec2 нужно для функции normalization иначе не нормализует
  s21_decimal dec1 = {{1, 0, 0, 0}};
  s21_decimal dec2 = {{0}};
  s21_set_scale(&dec1, scale + 1);
  s21_set_scale(&dec2, scale);

  // ищем остаток от деления
  normalization(&dec1, &dec2, &value, &new_value, &new_value);
  s21_sub_big_mantis(value, new_value, &new_value);
  return new_value.bits[0];
}
/// @brief смещает все биты big_decimal вправо на delta
void shift_right_big_decimal(s21_big_decimal *src, int delta) {
  s21_big_decimal res;
  s21_zero_big_decimal(&res);
  for (int i = 191; i >= delta; i--) {
    s21b_set_bit(&res, i - delta, s21b_get_bit(*src, i));
  }
  *src = res;
}

int s21b_get_sign(s21_big_decimal dec) { return s21b_get_bit(dec, 223); }