
#include <fmt/core.h>

#include <iostream>
#include <utility>

using namespace std;

class SpreadsheetCell {
public:
    SpreadsheetCell() { fmt::print("construct..."); };
    SpreadsheetCell(int data) : m_data(data) { fmt::print("construct..."); };
    ~SpreadsheetCell(){};

#if 1
    // 1. 通过add函数实现对象add
    SpreadsheetCell add(SpreadsheetCell &c) {
	return SpreadsheetCell(getData() + c.getData());
    };
#else

    SpreadsheetCell operator+(SpreadsheetCell &c) {
	return SpreadsheetCell(getData() + c.getData());
    };
#endif

    SpreadsheetCell operator+(SpreadsheetCell &c1, SpreadsheetCell &c2) {
	return SpreadsheetCell(c1.getData() + c.getData());
    };

    void setData(int data) { m_data = data; };
    int getData() { return m_data; };

private:
    int m_data;
};

int main(int argc, char **argv) {
    SpreadsheetCell s1{2};
    SpreadsheetCell s2{2};
    SpreadsheetCell s3;

    s3 = s1 + s2;

    fmt::println("operator+: {}", s3.getData());

#if 0
    SpreadsheetCell s, a;
    SpreadsheetCell s1{2};
    SpreadsheetCell s2{2};

    s.setData(1);
    fmt::println("data:{}", s.getData());

    a = s.add(s1);
    fmt::println("add: {}", a.getData());

    a = s + s2;
    fmt::println("operator+: {}", a.getData());
    a = s + s2;
    fmt::println("operator+: {}", a.getData());
#endif
    return 0;
}

