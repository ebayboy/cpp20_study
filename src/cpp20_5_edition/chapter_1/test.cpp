/****************************************************************************
@file:limit_test.cpp 
@author:ebayboy@163.com 
@date:2023-01-13 22:23 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define DEBUG 

int main(int argc, char **argv)
{
	//max_min_val:  numeric_limits<T>::max()  min() lowest() 用法
	cout << "max int:" << numeric_limits<int>::max() << endl;
	cout << "min int:" << numeric_limits<int>::min() << endl;
	cout << "lowest int:" << numeric_limits<int>::lowest() << endl;

	cout << "max double:" << numeric_limits<double>::max() << endl; //最大正数
	cout << "min double:" << numeric_limits<double>::min() << endl; //最小正数
	cout << "lowest double:" << numeric_limits<double>::lowest() << endl; //最小负数

	//Zero init: {}
	int myInt {};
	float myFloat {};
	char myChar {};
	cout << "myInt:" << myInt << endl;
	cout << "myFloat:" << myFloat << endl;
	cout << "myChar:" << myChar << endl;

	//type convert: static_cast<T>()
	float f1 { 3.14f };
	int i1 { static_cast<int>(f1) };
	cout << "i1:" << i1 << endl;

	//inf(无穷) && nan(非数字, 例如: 0/0)
	float i3 { numeric_limits<float>::infinity() };
	float i4 {}, i5{};
	float i2 { i4/i5 };
	cout << "i2 [" << i2 << "] isnan:" << isnan(i2) << " isinf:" << isinf(i2) << endl;
	cout << "i3:" << i3 << " isinf:" << isinf(i3) << endl;

	return 0;
}

