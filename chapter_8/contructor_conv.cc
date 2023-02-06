
#include <iostream>
#include <utility>
#include <fmt/core.h>
#include <vector>

using namespace std;

//初始化列表构造函数
class EventSequence
{
public:
    EventSequence(initializer_list<double> args)
    {
        if (args.size() %2 != 0)
        {
            throw invalid_argument { "initializer_list should contain event number of elements." };
        }
        for (const auto & v : args)
        {
            m_sequence.push_back(v);
        }
    }

    void dump()
    {
        for (const auto & v : m_sequence)
        {
            cout << v << ",";
        }
        cout << endl;
    }

private:
    vector<double> m_sequence;

};

int main(int argc, char **argv)
{
    EventSequence p1 { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
    p1.dump();

    try
    {
        EventSequence p2 { 1.0, 2.0, 3.0 };
        p2.dump();
    }
    catch(const invalid_argument & e )
    {
        cout << e.what() << endl;
    }

    return 0;
}

