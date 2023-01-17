/****************************************************************************
@file:switch_test.cpp
@author:ebayboy@163.com
@date:2023-01-17 17:16
@version: 1.0
@description: cpp file
@Copyright (c)  all right reserved
**************************************************************************/

#include <iostream>

using namespace std;

enum class Mode
{
    Custom,
    Standard
};

int main(int argc, char **argv)
{
	Mode mode { Mode::Custom };
	switch (mode)
	{
		case Mode::Custom:
			//[[fallthrough]];
		default:
			cout << "Default\n";
	}

    return 0;
}

