
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <string_view>

using namespace std;

//转换器构造函数

class SpreadsheetCell
{
	public:
		SpreadsheetCell() = default;
		SpreadsheetCell(double init)
		{
			cout <<"double ...\n";
		};

		//explicit: 禁用隐式转换
		explicit SpreadsheetCell(string_view init)
		{
			cout <<"string_view ...\n";
		}
		SpreadsheetCell(const SpreadsheetCell & src);
};

int main(int argc, char **argv)
{
	SpreadsheetCell myCell { 4 };
	myCell = 5;
	//myCell = "6"sv; //隐式调用

	SpreadsheetCell myCell2 { "hello" }; //显示调用

	return 0;
}

