#include <string>
#include <vector>
#include <iostream>
#include "address.h"

bool func(std::string s) {
    return (s[0] == '1');
}

int main() {
    AddressBook ab;
    ab.set("11234123");
    ab.set("2123123");
    ab.set("123313123");

    std::vector<std::string> result = ab.findMatchingAddress(func);
    for (auto itr = result.begin(), end = result.end(); itr != end; ++itr)
        std::cout << *itr << std::endl;

    return 0;
}
