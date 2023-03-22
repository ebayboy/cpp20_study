
#include <fmt/core.h>

#include <iostream>
#include <utility>

using namespace std;

// 类中嵌入枚举类(enum class)

class SpreadsheetCell {
public:
    SpreadsheetCell(){};
    ~SpreadsheetCell(){};

    enum class Color { Red = 1, Green, Blue, Yellow };
    void setColor(Color c) { m_color = c; };
    Color getColor() { return m_color; };

private:
    Color m_color;
};

int main(int argc, char **argv) {
    SpreadsheetCell c;

    c.setColor(SpreadsheetCell::Color::Blue);

    auto color = c.getColor();

    fmt::println("color:{}", int(color));

    return 0;
}

