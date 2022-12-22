
main: main.o hello.o
	g++ -o main main.o hello.o

main.o : main.cpp
	g++ -fPIC -fmodules-ts -std=c++20 -o main.o -c main.cpp

hello.o : hello.cpp
	g++ -fPIC -fmodules-ts -std=c++20 -o hello.o -c hello.cpp


clean:
	rm hello.o main.o

all: 
	main

