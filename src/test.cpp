
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	string str {"1.12"};

	string_view sv1 { str };
	
	//double num_double = std::stod(str);
	//cout << "num_double:" << num_double << endl;
	
	double num_double = std::stod(string {sv1});
	cout << "num_double:" << num_double << endl;


	return 0;
}

