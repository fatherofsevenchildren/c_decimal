CC=gcc
CFLAGS= -Wall -Werror -Wextra -std=c11 
LDFLAGS=-lcheck -lpthread -lm -I /usr/local/include -L/usr/local/lib
CHECK:=$(shell pkg-config --cflags --libs check)
FS=-fsanitize=address -g

SRC=$(wildcard s21_*.c)
OBJ=$(patsubst %.c,%.o, ${SRC})
TARGET=test
FILE_TEST=$(wildcard unit_test/s21_*.c)

all: clean s21_decimal.a


s21_decimal.a:
	$(CC) $(CFLAGS) $(LDFLAGS) -c $(SRC)
	ar -rcs $@ $(OBJ)


test: clean s21_decimal.a
	$(CC) $(CFLAGS) $(LDFLAGS) --coverage $(FILE_TEST) s21_decimal.a -o $@ $(CHECK)
	./$(TARGET)


gcov_report: test
	$(CC) --coverage $(CFLAGS) $(LDFLAGS) $(FILE_TEST) s21_decimal.a $(SRC) -o test $(CHECK)
	./test
	lcov -t "test" -o tests.info -c -d .
	genhtml -o coverage tests.info
	open coverage/index.html


clean:
	rm -f *.a *.o *.gcda *.gcno *.info *.out test
	rm -rf coverage test.dSYM

clang:
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -n */*.c */*.h
	clang-format -style=Google -i */*.c */*.h
