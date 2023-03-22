
#include <fmt/core.h>

#include <iostream>
#include <utility>

// 嵌套类

using namespace std;

// 嵌套类：在类中声明， 在类外定义
class Spreadssheet {
public:
    Spreadssheet(){};
    ~Spreadssheet(){};

    class Cell;

private:
    /* data */
};

class Spreadssheet::Cell {
public:
    Cell(){};
    ~Cell(){};

private:
};

// 嵌套类： 直接类类中定义
class Spreadssheet2 {
public:
    Spreadssheet2(){};
    ~Spreadssheet2(){};

    class Cell2 {
    public:
	Cell2(){};
	~Cell2(){};

    private:
    };

private:
    /* data */
};

int main(int argc, char **argv) {
    Spreadssheet2 s2;

    Spreadssheet s;

    return 0;
}

