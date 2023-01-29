
#include <iostream>
#include <fmt/core.h>

using namespace std;

int main(int argc, char **argv)
{
	//1. 强排序 strong_ordering, int
	int i { 11 };
	strong_ordering r { i <=> 0 };
	if (is_gt(r)) {
		fmt::print("greater\n");
	} else if (is_lt(r)) {
		fmt::print("less\n");
	} else if (is_eq(r)) {
		fmt::print("equal\n");
	}

	//2. 偏排序 partial_ordering, float
	float f { 1.01 };
	partial_ordering rf { f <=> 1.02 };
	if (is_gt(rf)) {
		fmt::print("greater\n");
	} else if (is_lt(rf)) {
		fmt::print("less\n");
	} else if (is_eq(rf)) {
		fmt::print("equal\n");
	}

	//3. 弱排序 weak_ordering, 自定义类型compare函数
	struct Person {
		int id;
		string name;
		string email;
		//重载weak_ordering operator<=>，只根据id比较大小
		std::weak_ordering operator<=>(const Person& other) const
		{
			return id<=>other.id;
		}
	};
	Person p1 { id:15, name:"xxx", email:"xxx@163.com" };
	Person p2 { id:13, name:"yyy", email:"yyy@163.com" };
	Person p3 { id:17, name:"zzz", email:"zzz@163.com" };
	Person p4 { id:15, name:"kkk", email:"kkk@163.com" };
	cout << "p1.name:" << p1.name << endl;

	weak_ordering r1 = { p1 <=> p2 };
	weak_ordering r2 = { p1 <=> p3 };
	weak_ordering r3 = { p1 <=> p4 };

	fmt::print("r1 expect is_gt: is_gt:{} is_lt:{} is_eq:{}\n", is_gt(r1), is_lt(r1), is_eq(r1));
	fmt::print("r2 expect is_lt: is_gt:{} is_lt:{} is_eq:{}\n", is_gt(r2), is_lt(r2), is_eq(r2));
	fmt::print("r3 expect is_eq: is_gt:{} is_lt:{} is_eq:{}\n", is_gt(r3), is_lt(r3), is_eq(r3));

	return 0;
}

