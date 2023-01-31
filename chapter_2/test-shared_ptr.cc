
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

    //origin pointer
    Sample *s2 { new Sample{} };
    s2->setAge(2);

    Sample *s3 { s2 };
    s3->setAge(3);

    delete s2;
    //delete s3; //二次释放crash


    return 0;
}

