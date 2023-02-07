
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

class Foo 
{
		friend class Bar;
	public:
		void setData(int x)
		{
			m_data = x;
		};
		int getData()
		{
			return m_data;
		};

	private:
		int m_data;
};

class Bar
{
	public:
		void setAge(int age)
		{
			m_age = age;
		}
		void showFoo(const Foo & f)
		{
			cout << "age:" << m_age;
			cout << "m_data:" << f.getData();
		};
		int getAge()
		{
			return m_age;
		};

	private:
			int m_age;
};

int main(int argc, char **argv)
{
	Foo f {};
	f.setData(5);

	Bar b {};
	b.setAge(10);

	b.showFoo(f);

	return 0;
}

