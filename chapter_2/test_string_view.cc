
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <string_view>

using namespace std;

//返回值： 值传递（因为string_view复制的成本很低，只包含字符串指针和长度
string_view getFileExt(string_view filename)
{
    return filename.substr(filename.rfind('.'));
}

//strinng_view 转string
void handleExt(string const & str)
{
	cout << "str:" << str << endl;
}

int main(int argc, char **argv)
{
    string_view filename { R"("test.txt")" };
	fmt::print("filename.data:{}\n", filename.data()); //data() method
    fmt::print("ext:{}\n", getFileExt(filename));

	handleExt(filename.data()); //1. string_view.data()隐式构建string
	handleExt(string { filename }); //2. 显式构建string

    return 0;
}

