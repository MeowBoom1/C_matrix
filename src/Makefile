CC = gcc 
FLAGS = -Wall -Werror -Wextra 
matrix = s21*.c 
OBJECTS = *.o 
TEST_LIB = ./tests/*.c
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
LINK_FLAGS = -lcheck 
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux) 
	LINK_FLAGS += -lm -lsubunit
endif

ifeq ($(UNAME_S), Darwin)
	LINK_FLAGS += $(shell pkg-config --libs --cflags check) -lm
endif

all: clean format s21_matrix.a test gcov_report

s21_matrix.a:
	$(CC) $(FLAGS) -c $(matrix)
	ar rcs s21_matrix.a $(OBJECTS)

test: clean
	$(CC) $(FLAGS) $(LEAKS) $(matrix) ${TEST_LIB} ${LINK_FLAGS} -o test
	./test

brew:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	reset
	brew install pkg-config
	brew install lcov
	brew install check
	sleep 1
	reset

leaks: test
ifeq ($(UNAME_S), Linux) 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
endif
ifeq ($(UNAME_S), Darwin) 
	leaks -quiet -atExit -- ./test
endif

clean: 
	rm -fr *.out *.o *.a *.gch *.gcno *.gcda test gcov_test s21_test.info ./report test

rebuild: clean test 

gcov_report: 
	$(CC) $(FLAGS) $(GCOV_FLAGS) ${TEST_LIB} ${matrix} ${LINK_FLAGS} -o test
	./test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open report/index.html  

style:
	clang-format -style=google -n tests/* ./*.c ./*.h

format:
	clang-format -style=google -i tests/* ./*.c ./*.h