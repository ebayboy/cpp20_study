
CXXFLAGS=-fPIC -std=c++20 -fmodules-ts

main: employee.o main.o
	g++ -o $@ $^

main.o: main.cpp
	g++ ${CXXFLAGS} -o $@ -c $^

employee.o: employee.cpp
	g++ ${CXXFLAGS} -o $@ -c $^

clean:
	rm -rf *.o main gcm.cache

all: 
	main
