
CXX := g++

CXXFLAGS := -lpthread -O0 -g  -std=c++20

TARGET := future async package_task

all: $(TARGET)

future: future.o
	$(CXX) $(CXXFLAGS) -o $@ $^

async: async.o
	$(CXX) $(CXXFLAGS) -o $@ $^

package_task: package_task.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	rm -rf *.o $(TARGET)
