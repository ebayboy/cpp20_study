
#include <iostream>
#include <optional>

using namespace std;

int main() {

    //
    std::optional<unsigned> opt = {10};;
    std::optional<unsigned> opt2;
	std::optional<int> opt3 = std::nullopt;

    //has_value()来判断对应的optional是否处于已经设置值的状态
    if (opt.has_value()) {
        cout << "set opt: " << opt.value() << endl; //set number: 10
    }  else {
        cout << "not set opt!\n";
    }

    if (opt2.has_value()) {
        cout << "set opt2: " << opt2.value() << endl; 
    }  else {
        cout << "not set opt2!\n";
    }

#if 0
	if (opt3 == nullptr) {
		cout << "opt3 nullptr\n";
	} else {
		cout << "opt3 not nullptr\n";
	}
#endif
}

