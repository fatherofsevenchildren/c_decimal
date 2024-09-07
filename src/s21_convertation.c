#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL || src > INT_MAX) return 1;
  s21_zero_decimal(dst);
  if (src < 0) {
    s21_set_bit(dst, 127, 1);
    src *= -1;
  }
  dst->bits[0] = src;
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  s21_truncate(src, &src);
  if (src.bits[1] || src.bits[2] || s21_get_bit(src, 31) || !dst) return 1;
  *dst = src.bits[0];
  *dst /= pow(10, s21_get_scale(src));  // отбрасываем дробную часть
  if (s21_get_bit(src, 127)) *dst *= -1;
  return 0;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (dst == NULL) return 1;
  long double result = 0;
  for (int i = 0; i != 96; i++) {
    result += s21_get_bit(src, i) * pow(2, i);
  }
  int scale = s21_get_scale(src);
  result /= pow(10, scale);
  *dst = (float)result;
  if (s21_get_bit(src, 127)) *dst *= -1;
  return 0;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (!dst || src != src || fabs(src) < powl(10.0, -28.0) ||
      fabs(src) >= powl(2.0, 96))
    return 1;
  s21_zero_decimal(dst);
  int scale_float = 0;
  double abs_src = fabs(src);
  while ((abs_src / 100000000) < 1.0 && scale_float < 28) {
    abs_src *= 10;
    scale_float++;
  }
  if (scale_float > 0) {
    abs_src = abs_src / 10;
    scale_float--;
  }
  abs_src = floor(abs_src);  // Округляем number в меньшую сторону.
  // Если дробная часть числа больше или равна 0.5, округляем число вверх.
  if (fmod(abs_src, 10.0) >= 5)
    abs_src = round(abs_src + 10 - fmod(abs_src, 10.0));
  if (scale_float > 0) {
    abs_src /= 10;
    scale_float--;
  }
  // Уменьшаем масштаб, пока дробная часть числа меньше, чем 10^(-8).
  while (scale_float > 0 && (fmod(abs_src, 10.0) < pow(10.0, -8))) {
    abs_src /= 10;
    abs_src = round(abs_src);
    scale_float--;
  }
  for (int i = 0; i < 96; i++) {  // загоняем биты из флоата
    double copy_src =
        abs_src;  // создаем копию нашего src флоата, т.к. будет меняться
    for (int j = 0; j < i; j++) {
      copy_src = floor(copy_src / 2);  // делим число до нужной степени
    }
    int current_bit =
        (int)fmod(copy_src, 2.0);  // записываем остаток его деления в бит;
    s21_set_bit(dst, i, current_bit);  // устанавливаем бит в наш
  }
  s21_set_scale(dst, scale_float);        // заносим степень
  if (src < 0) s21_set_bit(dst, 127, 1);  // заносим знак
  return 0;
}
