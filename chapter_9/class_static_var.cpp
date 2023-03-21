
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

class Demo
{
public:
	//类的静态长岭数据成员 static const 
	static inline int const MaxWidth { 100 }; //inline 保证避免要在类的外部申请内存
	static inline int const MaxHeight { 100 };
	Demo (int width, int height) : m_width { min(width, MaxWidth) }, m_height { min(height, MaxHeight) }
	{
		fmt::print("m_width:{} m_height:{}", m_width, m_height);
	};
	~ Demo ()
	{
	}

private:
	int m_width;
	int m_height;
};

int main(int argc, char **argv)
{
	Demo d(1, 2);

	return 0;
}

