CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g

all: my_math.a

my_math.a: my_math.o
	ar rcs my_math.a my_math.o
	ranlib my_math.a

my_math.o:
	$(CC) $(CFLAGS) -c my_math.c

test_math.o:
	$(CC) $(CFLAGS) -c test_math.c

test: my_math.a test_math.o
	$(CC) $(CFLAGS) -lcheck test_math.o my_math.a my_math.a -o test
	./test
    
gcov_report: test_math.o
	$(CC) $(CFLAGS) -lcheck test_math.o my_math.c --coverage -o tests
	./tests
	lcov -t "tests" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

check: test_math.o my_math.a
	cppcheck my_math.c my_math.h test_math.c
	$(CC) $(CFLAGS) -lcheck test_math.o my_math.a -o test
	CK_FORK=no leaks --atExit -- ./test

clang-check:
	cp ../materials/linters/.clang-format .
	clang-format -n -style=Google my_math.c test_math.c my_math.h

	rm -f .clang-format
	
clang-format:
	cp ../materials/linters/.clang-format .
	clang-format -i -style=Google my_math.c test_math.c my_math.h

	rm -f .clang-format

clean:
	rm -rf *.o *.a *.css *.html *.gcno *.gcda *.out *.info test tests report *.dSYM

rebuild: clean all