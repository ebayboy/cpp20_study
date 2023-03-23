
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

    // 1. 实现operator+
    SpreadsheetCell operator+(SpreadsheetCell &c) {
	fmt::println("call operator+(rhs)");
	return SpreadsheetCell(getData() + c.getData());
    };

    // 2. 必须显示实现 operator +=
    SpreadsheetCell operator+=(SpreadsheetCell &c) {
	this->setData(this->getData() + c.getData());
	return this->getData();
    };

    void setData(int data) { m_data = data; };
    int getData() const { return m_data; };

private:
    int m_data;
};

int main(int argc, char **argv) {
    SpreadsheetCell s1{1};
    SpreadsheetCell s2{2};
    SpreadsheetCell s3;

    s3 = s1 + s2;
    fmt::println("s3:{}", s3.getData());

    // 必须显示实现 operator +=, 只实现operator+不行
    s1 += s2;
    fmt::println("s1 += s2:{}", s1.getData());

    return 0;
}

