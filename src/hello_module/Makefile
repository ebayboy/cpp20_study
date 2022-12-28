
# 需要先编译hello.o, 编译hello.o时会生成gcm.cache/smd.hello.gcm

main: hello.o main.o
	g++ -o main main.o hello.o

#main.o 会依赖 gcm.cache/smd.hello.gcm
main.o : main.cpp 
	g++ -fPIC -fmodules-ts -std=c++20 -o main.o -c main.cpp

hello.o : hello.cpp
	g++ -fPIC -fmodules-ts -std=c++20 -o hello.o -c hello.cpp

gcm.cache/smd.hello.gcm: hello.o
	@test -f $@ || rm -rf $<
	@test -f $@ || $(MAKE) $<

clean:
	rm hello.o main.o

clean-gcm:
	rm gcm.cache/smd.hello.gcm

test:
	./main

all: 
	main

