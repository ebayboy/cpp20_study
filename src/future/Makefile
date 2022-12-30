
CXX := g++

CXXFLAGS := -lpthread -O0 -g  -std=c++20

TARGET := future

all: $(TARGET)

future: future.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	rm -rf *.o $(TARGET)
