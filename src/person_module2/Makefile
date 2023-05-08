
# 需要先编译person.o, 编译person.o时会生成gcm.cache/smd.person.gcm

main: person.o main.o
	g++ -o main main.o person.o

main.o : main.cpp 
	g++ -fPIC -fmodules-ts -std=c++20 -o main.o -c main.cpp

# build person module
person.o : person.cpp
	g++ -fPIC -std=c++20 -fmodules-ts -xc++-system-header iostream 
	g++ -fPIC -std=c++20 -fmodules-ts -xc++-system-header string
	g++ -fPIC -fmodules-ts -std=c++20 -o person.o -c person.cpp



gcm.cache/smd.person.gcm: person.o
	@test -f $@ || rm -rf $<
	@test -f $@ || $(MAKE) $<

clean:
	rm -rf gcm.cache/ person.o main.o main 

test:
	./main

all: 
	main

