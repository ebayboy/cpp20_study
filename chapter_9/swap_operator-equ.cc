
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

//operator=
//swap

class SpreadSheet
{
public:
	SpreadSheet () : SpreadSheet { 1, 2 } { }; //使用委托构造函数
	SpreadSheet (int width, int height): m_width{ width }, m_height { height }
	{
		fmt::print("construct {} {} ...\n", m_width, m_height);
		//内存分配
		m_cells = new int*[m_width];
		for (int i = 0; i < m_width; i++) {
			m_cells[i] = new int[m_height];	
		}
	};
	~SpreadSheet ()
	{
		fmt::print("destruct {} {} !\n", m_width, m_height);
		for(int i = 0; i < m_width; i++) {
			delete [] m_cells[i];
		}
		delete [] m_cells;
	};
	void setSpreadSheet() //设置数据
	{
		for(int i = 0; i < m_width; i++) {
			for(int j = 0; j < m_height; j++) {
				m_cells[i][j] = i + j;
			}
		}
	};
	void printSpreadSheet()
	{
		fmt::print("{}{}\n", m_width, m_height);
		for(int i = 0; i < m_width; i++) {
			for(int j = 0; j < m_height; j++) {
				m_cells[i][j] = i + j;
				fmt::print("[{}][{}]:{}\n", i, j, m_cells[i][j]);
			}
		}
	};
	
	//拷贝构造函数	
	//委托调用构造函数
	SpreadSheet(SpreadSheet const & s) : SpreadSheet { s.m_width, s.m_height } 
	{
		fmt::print("copy construct...\n");
		//TODO: 深度拷贝数据	
		for(int i = 0; i < m_width; i++) {
			for(int j = 0; j < m_width; j++) {
				m_cells[i][j] = s.m_cells[i][j];
			}	
		}
	};

	//noexcept: 如果程序抛出异常，就终止
	void swapSprreatSheet(SpreadSheet & src)  noexcept
	{
		std::swap(m_width, src.m_width);
		std::swap(m_height, src.m_height);
		//	throw invalid_argument("xxxx");
		std::swap(m_cells, src.m_cells);
	}

	// operator=
	SpreadSheet & operator= (SpreadSheet const & src) {
		//防止对象复制过程中throw异常，导致对象创建不完全
		
		//创建临时对象 
		SpreadSheet tmp { src };	
		
		//swap交换
		swapSprreatSheet(tmp);
	
		//TODO: 释放内存 delete tmp;	

		//返回
		return *this;	
	};
	
private:
	int m_width;
	int m_height;
	int **m_cells;
};

int main(int argc, char **argv)
{
	cout << "===========s1\n";
	SpreadSheet s1 {3, 4};
	s1.printSpreadSheet();

	//拷贝构造函数
	cout << "===========s2\n";
	SpreadSheet s2 { s1 };
	s2.printSpreadSheet();

	//operator=
	cout << "===========s3\n";
	SpreadSheet s3 { 2, 3 };
	s3 = s2;
	s3.printSpreadSheet();

	cout << "destruct ======\n";

	return 0;
}

