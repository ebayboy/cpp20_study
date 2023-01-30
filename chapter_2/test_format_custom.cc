
#include <iostream>
#include <utility>
#include <string>
#include <string_view>
#include <exception>
#include <type_traits>

#include <fmt/core.h>
#include <fmt/format.h>

using namespace std;

//自定义类型格式化, 特例化模板

class KeyValue 
{
	public:
		KeyValue(string_view key, int value) : m_key {key}, m_value {value} { /* pass */ };
		const string & getKey() const { return m_key; }; //TODO: 第二个const的含义, 任何不会修改数据的成员函数都应该声明为const函数
		int getValue() const { return m_value; }; 

	private:
		string m_key;
		int m_value;
};

//类模板fmt::formatter特例化
template<>
class fmt::formatter<KeyValue>
{
	public:
		constexpr auto parse(auto & context)
		{
			auto iter  { context.begin() };
			const auto end { context.end() };
			if (iter == end || *iter == '}') {
				m_outputType = OutputType::KeyAndValue;
				return iter;
			}

			switch (*iter) {
				case 'a':
					m_outputType = OutputType::KeyOnly;
					break;
				case 'b':
					m_outputType = OutputType::ValueOnly;
					break;
				case 'c':
					m_outputType = OutputType::KeyAndValue;
					break;
				default:
					//TODO: test_format_custom.cc:55:41: error: expression ‘<throw-expression>’ is not a constant expression
					throw fmt::format_error {"Invalid kv format specifier."};
			}

			++iter;
			if (iter != end && *iter != '}') {
				throw fmt::format_error {"Invalid kv format specifier."};
			}
			
			return iter;
		};
		
		auto format(const KeyValue & kv, auto &context)
		{
			switch (m_outputType) {
				case OutputType::KeyOnly:
					return fmt::format_to(context.out(), "{}", kv.getKey());
				case OutputType::ValueOnly:
					return fmt::format_to(context.out(), "{}", kv.getValue());
				default:
					return fmt::format_to(context.out(), "{} - {}", kv.getValue(), kv.getValue());
			}
		};

		//format
	
	private:
		enum class OutputType
		{
			KeyOnly,
			ValueOnly,
			KeyAndValue
		};
		//私有成员m_outputType， 设置默认值, Parse解析格式存储到m_outputType， format函数使用m_outputType
		OutputType m_outputType { OutputType::KeyAndValue };
};

int main(int argc, char **argv)
{
	KeyValue kv1 {"key1", 11};
	fmt::print("{}:{}\n", kv1.getKey(), kv1.getValue());

	//TODO: 格式化KeyValue, :a输出key,  :b输出value, :c或{}输出k + v
	try {
		cout << fmt::format("key:{:a}", kv1) << endl;	
		cout << fmt::format("value:{:b}", kv1) << endl;	
		cout << fmt::format("kv:{:c}", kv1) << endl;	
		cout << fmt::format("kv2:{}", kv1) << endl;	
		
		//cout << fmt::format("kv2:{:d}", kv1) << endl;	 //测试未通过
	} 
	catch (exception & ex)
	{
		cout << "exception:" << ex.what() << endl;
	}

	return 0;
}

