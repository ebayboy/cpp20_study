
#include <fmt/core.h>

#include <iostream>
#include <utility>

using namespace std;

class SpreadsheetCell {
public:
    SpreadsheetCell() { fmt::println("construct nil"); };
    SpreadsheetCell(int data) : m_data(data) {
	fmt::println("construct {}...", data);
    };
    ~SpreadsheetCell(){};

    // 1. 通过add函数实现对象add
    SpreadsheetCell add(SpreadsheetCell &c) {
	return SpreadsheetCell(getData() + c.getData());
    };

    // 2. 实现operator+
    SpreadsheetCell operator+(SpreadsheetCell &c) {
	fmt::println("call operator+(rhs)");
	return SpreadsheetCell(getData() + c.getData());
    };

    void setData(int data) { m_data = data; };
    int getData() const { return m_data; };

private:
    int m_data;
};

// 3. 实现两个类实例operator+  lhs + rhs
SpreadsheetCell operator+(const SpreadsheetCell &lhs,
			  const SpreadsheetCell &rhs) {
    fmt::println("call operator+( lhs, rhs)");
    return SpreadsheetCell{lhs.getData() + rhs.getData()};
};

int main(int argc, char **argv) {
    SpreadsheetCell s, a;
    SpreadsheetCell s1{2};
    SpreadsheetCell s2{2};

    s.setData(1);
    fmt::println("data:{}\n", s.getData());

    a = s.add(s1);
    fmt::println("add: {}\n", a.getData());

    a = s + s2;
    fmt::println("s + s2 {}\n", a.getData());

    // 隐式转换:  1 -> SpreadsheetCell{1}, 调用operator+(rhs)
    a = s + 1;
    fmt::println("s + 1: {}\n", a.getData());

    // 隐式转换:  1 -> SpreadsheetCell{1}, 调用operator+( lhs, rhs)
    a = 1 + s;
    fmt::println("1 + s: {}\n", a.getData());

    return 0;
}

