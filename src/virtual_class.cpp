
//1. 抽象类： 包含纯虚函数的类
//2. 定义抽象类型容器，使用派生类实例话
//3. std::tostring   std::stod  std::stof

#include <iostream>
#include <utility>
#include <optional>
#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <fmt/core.h>

using namespace std;

class SpreadsheetCell {
	public:
	SpreadsheetCell() {};
	virtual ~SpreadsheetCell() {};	

	virtual void set(string_view s) = 0;
	virtual string getString() const = 0;
};

class SpreadsheetCellString: public SpreadsheetCell {
	public:
		SpreadsheetCellString() {};
		virtual ~SpreadsheetCellString() {};
		void set(string_view s) override {
			m_value = s;
		};
		string getString() const override {
			return m_value.value_or("null");
		};
	private:
		std::optional<std::string>  m_value;
};

class SpreadsheetCellDouble: public SpreadsheetCell {
	public:
		SpreadsheetCellDouble() {};
		virtual ~SpreadsheetCellDouble() {};
		virtual void set(double d) { m_value = d; };
		void set(string_view s) override { m_value = std::stod(string {s}); }; // stod参数必须为string，不能是string_view
		string getString() const override { 
			return std::to_string(m_value.value_or(0));
		};
	private:
		std::optional<double>  m_value;
};

int main(int argc, char **argv)
{
	// For 1
	SpreadsheetCellString sc, sc2;
	sc.set("1.11");

	fmt::println("sc:{}", sc.getString());
	fmt::println("sc2:{}", sc2.getString());

	//For 2
	vector<unique_ptr<SpreadsheetCell>> vc;	
	vc.emplace_back(make_unique<SpreadsheetCellString>());
	vc.at(0)->set("2.22");
	fmt::println("vc.at(0)->getString(){}", vc.at(0)->getString());

	//使用double实例话基类
	vc.emplace_back(make_unique<SpreadsheetCellDouble>());
	vc.at(1)->set("3.33");
	fmt::println("vc.at(1)->getString(){}", vc.at(1)->getString());

	return 0;
}

/*输出： 
sc:1.11
sc2:null
vc.at(0)->getString()2.22
vc.at(1)->getString()3.330000
*/

