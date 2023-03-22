
#include <fmt/core.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

int main(int argc, char **argv) {
    std::unordered_map<string, string> um;

    um.insert(make_pair("key1", "val1"));
    um.insert(make_pair("key2", "val2"));
    um.insert(make_pair("key3", "val3"));

    auto ret = um.find("key2");
    if (ret != um.end()) {
	fmt::println("find:{}:{}", ret->first, ret->second);
    }

    for (auto &&it : um) {
	fmt::println("first:{} second:{}", it.first, it.second);
    }

    return 0;
}

