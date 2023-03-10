
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <memory>

#include <stdio.h>

using namespace std;

class Sample
{
public:
    Sample()
    {
        cout << "construct age:" << this->age << endl;
    };
    ~Sample()
    {
        cout << "destruct age:" << this->age << endl;
    };

    void setAge(int age)
    {
        this->age = age;
        cout << "set age:" << this->age << endl;
    };
    int getAge()
    {
        return age;
    };

private:
    int age {0};
};

class Foo
{
public:
	Foo (int value) : m_data { value }  { cout << "Foo construct:" << value << endl; };
	~Foo() { cout << "Foo destruct:" << m_data << endl; };
	int m_data;
};

void test_aliasing()
{
	//别名 aliasing
	auto f1 { make_shared<int>(10) };	
	cout << "f1:" << *f1 << endl;
	auto foo { make_shared<Foo>(42) };
	cout << "foo.m_data:" << foo->m_data << endl;
	//auto aliasing { shared_ptr<int> { foo, &foo->m_data } };
	auto aliasing { shared_ptr<int> { foo, f1.get() } };
}

/*
test_aliasing2:72 s1.cnt:1 foo.cnt:1
test_aliasing2:77 after tm3:2 s1.cnt:2 foo.cnt:1
Foo destruct:42
test_aliasing2:81 after tm3:2 s1.cnt:2 foo.cnt:0
test_aliasing2:84 after tm3:1 s1.cnt:0 foo.cnt:0
destruct age:0
test_aliasing2:87 after tm3:0 s1.cnt:0 foo.cnt:0
*/
void test_aliasing2()
{
	//别名 aliasing
	auto foo { make_shared<Foo>(42) };
	auto s1 { make_shared<Sample>() };	
	//此时： s1.cnt:1 foo.cnt:1
	fmt::print("{}:{} s1.cnt:{} foo.cnt:{}\n", __func__, __LINE__, s1.use_count(), foo.use_count());

	//tmp3 增加了s1的引用计数，同时要求foo的原始指针释放, 保证了释放foo前先释放原始指针
	auto tmp3 { shared_ptr<Foo> { s1, foo.get() } };
	//此时: tm3:2 s1.cnt:2 foo.cnt:1
	fmt::print("{}:{} after tm3:{} s1.cnt:{} foo.cnt:{}\n", __func__, __LINE__, tmp3.use_count(), s1.use_count(), foo.use_count());

	foo.reset();
	fmt::print("{}:{} after tm3:{} s1.cnt:{} foo.cnt:{}\n", __func__, __LINE__, tmp3.use_count(), s1.use_count(), foo.use_count());
	//tm3:2 s1.cnt:2 foo.cnt:0

	s1.reset();
	fmt::print("{}:{} after tm3:{} s1.cnt:{} foo.cnt:{}\n", __func__, __LINE__, tmp3.use_count(), s1.use_count(), foo.use_count());
	//tm3:1 s1.cnt:0 foo.cnt:0

	//tm3:0 s1.cnt:0 foo.cnt:0
	tmp3.reset();
	fmt::print("{}:{} after tm3:{} s1.cnt:{} foo.cnt:{}\n", __func__, __LINE__, tmp3.use_count(), s1.use_count(), foo.use_count());
}

void closefp(FILE *fp)
{
    if (fp != nullptr)
    {
        fclose(fp);
        fp = nullptr;
        cout << "fp close!\n";
    }
}

int main(int argc, char **argv)
{
	//test_aliasing();

	test_aliasing2();

	return 0;


    //shared_ptr + old C
    auto s1 { make_shared<Sample>() };
    FILE *fp { fopen("data.txt", "w") };
    shared_ptr<FILE> fp_ptr { fp, closefp };
    if (fp_ptr == nullptr)
    {
        cerr << "Error open!\n";
    }
    else
    {
        cout << "File opened!\n";
    }
	s1.reset(); //手动释放s1

    //origin pointer
    Sample *s2 { new Sample{} };
    s2->setAge(2);

    Sample *s3 { s2 };
    s3->setAge(3);

    delete s2;
    //delete s3; //二次释放crash

	//智能指针二次释放没问题
	auto s4 { make_shared<Sample>() };
	s4->setAge(4);
	auto s5 { s4 };

	cout << "s4 reset...\n";
	s4.reset(); //由于引用技术不为0， 此处不释放
	cout << "s4 reset done!\n";

	cout << "s5 reset...\n";
	s5.reset(); //真正释放s4 && s5
	cout << "s5 reset done!\n";

	//两个智能指针指向同一个原始指针
	Sample *mys1 { new Sample{} };
	mys1->setAge(6);
	shared_ptr<Sample> sp1 { mys1 };
	//shared_ptr<Sample> sp2 { mys1 }; //两次释放会crash， 安全的操作是创建shared_ptr的副本
	shared_ptr<Sample> sp2 { sp1 };  //shared_ptr的副本是安全的操作方式

    return 0;
}

