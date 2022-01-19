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
all: s21_cat s21_grep test

s21_cat:
	$(CC) $(LFLAGS) cat/s21_cat.c -o cat/a.out

s21_grep:
	$(CC) $(LFLAGS) grep/s21_grep.c -o grep/a.out

test: s21_cat s21_grep
	sh test.sh -o s21_cat
	$(CC) $(LFLAGS) test.c -o test $(CHECK_FLAGS)
	./test

clean:
	rm -rf *.o *.out *.txt s21_cat test

leaks: test
	CK_FORK=no leaks --atExit -- /Users/estaedmo/C3_SimpleBashUtils-0/src/grep/./a.out
	CK_FORK=no leaks --atExit -- /Users/estaedmo/C3_SimpleBashUtils-0/src/cat/./a.out
	CK_FORK=no leaks --atExit -- ./test