
#include <iostream>
#include <string>
#include <string_view>
#include <charconv>

using namespace std;

//C++20 直接在类内部定义，方法会隐式标记为inline
class InlineTest
{
	public:
		double getValue() const 
		{ 
			m_numAccesses++; 
			return m_value; 
		};
		string getString() const 
		{ 
			m_numAccesses++;
			return doubleToString(m_value);
		};
		inline string getString2() const 
		{ 
			m_numAccesses++;
			return doubleToString(m_value);
		};
		string getString3() const;
		string getString4() const;

		string doubleToString(double value) const
		{
			return to_string(value);
		}

		double stringToDouble(string_view value) const
		{
			double number{ 0 };
			from_chars(value.data(), value.data() + value.size(), number);
			return number;
		}

	private:
		mutable int m_numAccesses{0};
		double m_value{1.12};
};

string InlineTest::getString3() const 
{ 
	m_numAccesses++;
	return doubleToString(m_value);
};

inline string InlineTest::getString4() const 
{ 
	m_numAccesses++;
	return doubleToString(m_value);
};

int main(int argc, char **argv)
{
	InlineTest it;

	auto a = it.getString();
	auto b = it.getString2();
	auto c = it.getString3();
	auto d = it.getString4();

	return 0;
}

