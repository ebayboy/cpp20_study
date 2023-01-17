/****************************************************************************
@file:if_init_test.cpp 
@author:ebayboy@163.com 
@date:2023-01-17 17:36 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <format>

using namespace std;

int main(int argc, char **argv)
{
	if(int x {2}; x > 1) {
		cout << "ok\n";
	}
	
	string s = std::format("{} {}!", "Hello", "world", "something");
	cout << "s:"  << s << endl;

	return 0;
}

