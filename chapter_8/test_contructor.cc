
#include <iostream>
#include <memory>
#include <utility>

#include <fmt/core.h>

using namespace std;


class Sample
{
public:

    Sample() : m_age {5}
    {
        cout << "Sample construct ...\n";
    };
    //Sample() = default; //显示添加默认构造函数
    //Sample() = delete; //删除默认构造函数, Sample s不能编译通过

    void setAge(int age)
    {
        m_age = age;
    };
    int getAge()
    {
        return m_age;
    }

private:
    /* data */
    int m_age;
};

int main(int argc, char **argv)
{
    Sample s;
    cout << s.getAge() << endl;

    s.setAge(10);
    cout << s.getAge() << endl;

    return 0;
}

