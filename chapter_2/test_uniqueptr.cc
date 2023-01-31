
#include <iostream>
#include <utility>
#include <fmt/core.h>

#include <memory>

using namespace std;

class Sample
{
public:
    Sample()
    {
        cout << "construct... " << this->name << endl;
    };
    ~Sample()
    {
        cout <<"destruct!" << this->name << endl;
    };
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }

private:
    string name;
};

int main(int argc, char **argv)
{
    //原始用法, 不delete释放内存, 会内存泄露
    Sample *s { new Sample{} };
    s->setName("fanpf");
    cout << s->getName() << endl;
    delete s;
    cout << "=============\n";

    //unique_ptr用法1
    auto u1 { make_unique<Sample>() };
    u1->setName("u1");
    cout << u1->getName() << endl;
    cout << "=============\n";

    //unique_ptr用法2
    unique_ptr<Sample> u2 { new Sample{} };
    u2->setName("u2");
    cout << "u2.get(): "<< u2.get() << endl; //获取unique_ptr的原始指针
    cout << u2->getName() << endl;

    //unique_ptr reset
    auto u3 { make_unique<Sample>() };
    u3->setName("u3");

#if 0
    u2.reset();//主动调用reset后， u2指向的指针内存释放
    u2.reset( new Sample{} );//主动调用reset后， u2指向的指针内存释放, 重新指向分配的内存
#endif

    //unique_ptr release
    auto p_u3 { u3.get() };
    u3.release();	// release解绑后， 需要手动释放内存，否则会内存泄露
    delete p_u3; //release后， 手动释放u3指向的内存

    return 0;
}

