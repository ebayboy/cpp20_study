/****************************************************************************
@file:main.cpp 
@author:ebayboy@163.com 
@date:2023-01-17 15:40 
@version: 1.0  
@description: cpp file 
@Copyright (c)  all right reserved 
**************************************************************************/

import <iostream>;
import employee;

using namespace std;

int main(int argc, char **argv)
{
	Employee e;

	e.firstInitial = 'J';
	e.lastInitial = 'D';
	e.employeeNumber = 42;
	e.salary = 8000;

	cout << "e.firstInitial:" << e.firstInitial << endl;
	
	return 0;
}

