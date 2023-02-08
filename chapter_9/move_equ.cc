
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <vector>

using namespace std;

class Spreadsheet 
{
	public:
		Spreadsheet(int w, int h) : m_width {w}, m_height{h} 
		{
			fmt::print("construct... {} {}\n", m_width, m_height);
		};
		~Spreadsheet() 
		{
			fmt::print("destruct... {} {}\n", m_width, m_height);
		};

		void show()
		{
			fmt::print("===show\nm_width:{} m_height:{}\n", m_width, m_height);
		}

#if 1
		//语义移动构造函数
		Spreadsheet(Spreadsheet && src) noexcept
		{
			std::swap(m_width, src.m_width);
			std::swap(m_height, src.m_height);
			fmt::print("Spreadsheet rvalue construct...{} {} , src:{} {}\n", m_width, m_height, src.m_width, src.m_height);
		};

		//普通赋值运算
		Spreadsheet& operator=(Spreadsheet const & src)
		{
			m_width = src.m_width;
			m_height = src.m_height;
			fmt::print("普通 operator= {} {}, src:{} {}\n", m_width, m_height, src.m_width, src.m_height);
			return *this;
		}

		//语义移动赋值运算符
		Spreadsheet & operator=(Spreadsheet && src) noexcept
		{
			std::swap(m_width, src.m_width);
			std::swap(m_height, src.m_height);
			fmt::print("Spreadsheet rvalue operator=... {} {}, src:{} {}\n", m_width, m_height, src.m_width, src.m_height);
			return *this;
		};
#endif

	private:
		int m_width;
		int m_height;
};

vector<Spreadsheet> test()
{
	//创建一组对象， 从一个vecotr移动到另一个vecotr， 如果对象实现了语义移动（ &&构造函数  &&赋值）， 则不会复制对象， 直接移动语义
	vector<Spreadsheet> v;

	for(int i = 0; i < 5; i++)
	{
		fmt::print("push_back i:{} {} v.size:{} capacity:{}\n", i + 1, i + 1, v.size(), v.capacity());
		v.push_back(Spreadsheet {i + 1, i + 1});
	}

#if 0
	for ( auto & i : v) 
	{
		i.show();
	}
#endif

	cout << "====test return\n";

	return v;
}

Spreadsheet createObject()
{
	return Spreadsheet {3,4};
}

int main(int argc, char **argv)
{
	//测试vecotr扩容后， 语义移动不进行复制
	test();

	Spreadsheet s {1,2};
	s = createObject(); //调用语义赋值运算 &&operator=

	Spreadsheet s2 {5,6};

	s2 = s; //调用普通赋值运算 operator=

	return 0;
}

