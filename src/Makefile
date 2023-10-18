CC = gcc
CFLAGC =  -Wall -Werror -Wextra  
SOURCES = viewer.c
OBJECTS = viewer.o


all: tests 

tests:
	$(CC) $(CFLAGC) -lcheck viewer.c transf.c parser_tests.c s21_main_test.c -o test
	./test

gcov_report:
	gcc -lcheck --coverage parser_tests.c s21_main_test.c $(SOURCES) -o gcov_report
	./gcov_report
	lcov -t "./gcov_report" -o gcov_report.info -c -d .
	genhtml -o report gcov_report.info
	open ./report/index.html

install:
	make clean
	mkdir build
	cd 3DWieve && qmake && make && make clean && rm Makefile && cd ../ && mv 3DWieve/3DWieve.app build

uninstall:
	make clean

dvi:
	open doc.html

dist:
	rm -rf Archive_3DWieve_1.0/
	mkdir Archive_3DWieve_1.0/
	mkdir Archive_3DWieve_1.0/src
	mv ./build/3DWieve.app Archive_3DWieve_1.0/src/
	tar cvzf Archive_3DWieve_1.0.tgz Archive_3DWieve_1.0/
	rm -rf Archive_3DWieve_1.0/

clang:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -n *.c *.h 
	rm .clang-format

clangset:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -style=Google -i *.c *.h
	rm .clang-format

clean:
	rm -rf *.{a,o,dSYM,out}
	rm -rf gcov_report
	rm -rf report
	rm -rf CPPLINT.cfg
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf Archive_3DWieve_1.0 
	rm -rf *tgz
	rm -rf build
	rm -rf 3DWieve/qmake_qmake_qm_files.qrc
	rm -rf 3DWieve/.qmake.stash
	rm -rf 3DWieve/*.o

rebuild: clean all