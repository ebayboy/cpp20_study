
#include <fmt/core.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

int main(int argc, char **argv) {
    unordered_map<string, string> um;

    // 1. insert
    um.insert(make_pair("key1", "val1"));
    um.insert(make_pair("key2", "val2"));
    um.insert(make_pair("key3", "val3"));

    // 2. find
    auto ret = um.find("key2");
    if (ret != um.end()) {
	fmt::println("find:{}:{}", ret->first, ret->second);
	// 3. erase
	um.erase(ret);
    }

    // 4. Traverse loop show
    fmt::println("===um==");
    for (auto it = begin(um); it != end(um); it++) {
	fmt::println("first:{} second:{}", it->first, it->second);
    }

    unordered_map<int, string> ium;
    ium.insert(std::make_pair(1, "val1"));
    ium.insert(std::make_pair(2, "val2"));
    ium.insert(std::make_pair(3, "val3"));

    // int类型key
    fmt::println("===ium==");
    for (auto it = begin(ium); it != end(ium); it++) {
	fmt::println("ium first:{} second:{}", it->first, it->second);
    }
    return 0;
}

