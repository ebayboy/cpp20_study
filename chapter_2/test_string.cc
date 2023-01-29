
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <string>
#include <stdio.h>
#include <vector>
#include <exception>
#include <charconv>


using namespace std;

char const * getStr()
{
    string s {"getStr test"};
    return s.c_str();
}

int main(int argc, char **argv)
{
    //原始字面量 R"()"
    char const * str { "hello \"world" };
    char const * str2 { R"(hello "world2")" };
    string const str3 { R"(hello "world3")" };
    fmt::print("str:{} str2:{} str3:{}\n", str, str2, str3);

    //字符串比较， 返回值表达意义明确
    string a {"12"};
    string b {"34"};
    auto result { a <=> b };
    if (is_gt(result))
    {
        cout << ">" << endl;
    }
    else if (is_lt(result))
    {
        cout << "<" << endl;
    }
    else if (is_eq(result))
    {
        cout << "=" << endl;
    }
    else
    {
        cout << "unknown" << endl;
    }
    cout << "type:" << typeid(decltype(result)).name() << endl;

    //string 内存自动扩充，不会溢出
    string myString {"hello"};
    myString += ", there";

    //优先使用string.data()，而不是c_str();
    //不要在函数中返回基于栈上的string调用c_str()
    printf("myString.c_str()::%s\n", myString.c_str()); //before C++14
    printf("myString.data():%s\n", myString.data()); //after C++17
    printf("getStr:%s\n", getStr()); //危险，栈上的string在函数返回时有可能被销毁

    //string 查找
    string strHello { "Hello!!" };
    string strWrold { "The World..." };
    auto pos { strHello.find("!!") };
    if (pos != string::npos)
    {
        strHello.replace(pos, 2, strWrold.substr(3, 6));
    }
    cout << "strHello:" << strHello << endl;

    //std::string 字面量
    auto string1 { "hello world" };
    auto string2 { "hello world"s };

    //type1:PKc type2:NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
    //可见type1是char类型的， type2是string类型的
    fmt::print("type1:{} type2:{}\n", typeid(decltype(string1)).name(), typeid(decltype(string2)).name());

    //字面量与类模板参数推导CTAD
    vector names { "rose", "fanpf", "lilong" };   //注意： 此处name的类型是char *,  不是string
    for(auto & name : names)
    {
        fmt::print("name:{} type:{}\n", name, typeid(decltype(name)).name());
    }

    vector names2 { "rose"s, "fanpf"s, "lilong"s };    //此处names的类型是string
    for(auto & name : names2)
    {
        fmt::print("name:{} type:{}\n", name, typeid(decltype(name)).name());
    }

    /** 高级数值转换 **/
    //数字转string
    long double d { 3.14L };
    string s { to_string(d) };
    fmt::print("s:{}\n", s);

    //字符串转数字
    string s2 { "3.14" };
    fmt::print("int:{} long:{} float:{} double:{}\n", stoi(s2), stol(s2), stof(s2), stod(s2));

    //字符串转16进制
    string s3 { "0xffxzxz" };
    size_t idx { 0 };
    fmt::print("s3:{} idx:{}\n", stoi(s3, &idx, 16), idx);

	//转换失败， 抛出异常, 一定要catch
    string s4 { "xxe" };
    int s4_i { 0 };
    try
    {
        s4_i = stoi(s4);
    }
	catch (const std::invalid_argument& e)
    {
		fmt::print("invalid_argument:{}\n", e.what());
    }
    catch (const std::out_of_range& e)
    {
		fmt::print("out_of_range:{}\n", e.what());
    }
    catch (const std::exception& e)
    {
		fmt::print("exception:{}\n", e.what());
    }
    fmt::print("s4_i:{}\n", s4_i);



    return 0;
}

