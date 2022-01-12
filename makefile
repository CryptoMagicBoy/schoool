CC=gcc -std=c11
LFLAGS=-Wall -Werror -Wextra
CHECK_FLAGS=
TEST_FLAG=
# TEST_FLAG=-fsanitize=address

OS=$(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS=-lcheck -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS=-lcheck
endif

rebuild: clean all
all: s21_cat test

s21_cat: s21_cat.c
	$(CC) $(LFLAGS) $(TEST_FLAG) s21_cat.c -o s21_cat

test: s21_cat
	$(CC) $(LFLAGS) test_cat.c -o test $(CHECK_FLAGS)
	./test

clean:
	rm -rf *.o *.out s21_cat test

leaks: test
	CK_FORK=no leaks --atExit -- ./test

check:
	python3 ../../materials/linters/cpplint.py --extensions=c ./*.c
