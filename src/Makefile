CC = gcc -Wall -Werror -Wextra -lncurses
BACK = brick_game/tetris/*.c
FRONT = gui/cli/*.c
TEST_D = test_dir/*.c
HEDR = gui/*.h
WAY_NAME = -o tetris

ifeq ($(OS),Linux)
    Flags = -lcheck  -lm -lrt -lpthread -lsubunit
else
    Flags = -lcheck -lm -lpthread
endif


all: clean install

tetris.a:
	$(CC) $(BACK) -c $(Flags)
	ar rcs tetris.a *.o
	ranlib tetris.a
	rm *.o
	mv tetris.a brick_game/tetris

test: clean
	$(CC) --coverage $(TEST_D) $(BACK) -o test $(Flags)
	./test

gcov_report: test
	lcov -t "result" -o res.info -c -d .
	genhtml -o report res.info
	open report/index.html


install:
	$(CC) $(FRONT) $(BACK) $(WAY_NAME) $(Flags)

uninstall:
	rm -rf tetris

clang_n:
	clang-format -style=Google -n $(BACK) $(FRONT) $(TEST_D)

valgrind:
	valgrind -s --tool=memcheck --leak-check=yes ./test

clean:
	rm -rf *.gcda *.gcno test tetris brick_game/tetris/tetris.a res.info report 

# dvi:

# dist:
