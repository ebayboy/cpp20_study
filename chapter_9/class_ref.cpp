
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

// 引用数据成员
class Demo1
{
};

class Demo
{
public:
	inline static int const MaxWidth { 100 };
	inline static int const MaxHeight { 100 };
	Demo (int width, int height, Demo1 & d1) : m_width { min(width, MaxWidth) }, m_height { min(height, MaxHeight) }, m_demo1 {d1} 
	{
		fmt::print("m_width:{} m_height:{}", m_width, m_height);
	};
	~ Demo ()
	{
	}

private:
	int m_width;
	int m_height;

	Demo1 & m_demo1;
};

int main(int argc, char **argv)
{
	Demo1 d1 {};

	Demo d(1, 2, d1);

	return 0;
}

