
#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;

//operator=
//swap

class SpreadSheet
{
public:
	SpreadSheet (int width, int height): m_width{ width }, m_height { height }
	{
		fmt::print("construct ... {} {}\n", m_width, m_height);
	};
	~SpreadSheet ()
	{

	};
	void printSpreadSheet()
	{
		fmt::print("{}{}\n", m_width, m_height);
	};

private:
	int m_width;
	int m_height;
	int **m_cells;
};

int main(int argc, char **argv)
{
	SpreadSheet s1 {3, 4};

	return 0;
}

