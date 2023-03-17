
//利用类的静态成员全局特性，做auto_id, 给id赋值

#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;


class Demo
{
public:
	Demo () : m_id(m_auto_id++)
	{
		cout << "construct m_id:" << m_id << endl;	
	};
	~Demo (){};
	void Show()
	{
		cout << "md_id:" << m_id << endl;
	}

private:
	/* data */
	int const m_id; //const 类型, 在初始化后不能改变
	static inline int m_auto_id {0};
};

int main(int argc, char **argv)
{
	for(int i = 0; i < 5; i++)
	{
		Demo d;
		d.Show();
	}

	return 0;
}

