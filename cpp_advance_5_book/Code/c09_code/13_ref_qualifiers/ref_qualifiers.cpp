#include <iostream>
#include <string>

using namespace std;

class TextHolder
{
public:
    TextHolder(string text) : m_text{ move(text) } {}

    //const string& getText() const { return m_text; }

	// 后面&为左值引用限定符
    const string& getText() const &
    {
		cout << "string&" << endl;
        return m_text;
    }
	
	// 后面&&为右值引用限定符
    string&& getText() && 
	{ 
		cout << "string&&" << endl;
		return move(m_text); 
	}

private:
    string m_text;
};

int main()
{
    TextHolder textHolder{ "Hello world!" };
    cout << textHolder.getText() << endl;

    cout << TextHolder{ "Hello world!" }.getText() << endl;

    cout << move(textHolder).getText() << endl;
}
