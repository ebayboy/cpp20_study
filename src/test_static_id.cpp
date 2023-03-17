
//静态成员auto_id给id赋值

#include <iostream>
#include <utility>
#include <fmt/core.h>

using namespace std;


class Demo
{
public:
	Demo () : m_id(m_auto_id++)
	{
		cout << "construct m_id:" << m_id << endl;	
	};
	~Demo (){};
	void Show()
	{
		cout << "md_id:" << m_id << endl;
	}
	void SetId(int id)
	{
		m_id = id;
	};

private:
	/* data */
	int const m_id;
	static inline int m_auto_id {0};
};

int main(int argc, char **argv)
{
	for(int i = 0; i < 5; i++)
	{
		Demo d;
		d.Show();
		d.SetId(10);
		d.Show();
	}

	return 0;
}

