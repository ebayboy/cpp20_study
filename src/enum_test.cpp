/****************************************************************************
@file:enum_test.cpp
@author:ebayboy@163.com
@date:2023-01-17 15:21
@version: 1.0
@description: cpp file
@Copyright (c)  all right reserved
**************************************************************************/

#include <iostream>

using namespace std;

//强类型枚举 enum class xxx， 作用域小， 类型安全
//旧式枚举enum xxx, 作用域会被导出到外层的作用域， 非类型安全（只是int类型）
enum class PieceType  : unsigned long
{
    King = 1,
    Queen,
    Rook = 10,
    Pawn
};

using enum PieceType;

int main(int argc, char **argv)
{
    // enum::member
    PieceType piece { PieceType::Rook };
    cout << static_cast<unsigned long>(piece) << endl;

    //using enum PieceType,  just use member
    PieceType piece_2 { Pawn };
    cout << static_cast<unsigned long>(piece_2) << endl;

    return 0;
}

