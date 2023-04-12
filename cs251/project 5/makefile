ctest:
	rm -f tests.exe
	g++ -Wall -std=c++20 tests.cpp -o tests.exe

gtest:
	rm -f tests.exe
	g++ -g -std=c++20 -Wall gtests.cpp -o tests.exe -lgtest -lgtest_main -lpthread

runtest:
	./tests.exe

clean:
	rm -f main.exe
	rm -f tests.exe

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./main.cpp
