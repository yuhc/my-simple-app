#include <string>
#include <vector>
#include <iostream>
#include "address.h"

using namespace std;

FuncAddressBook ab;

vector<string> lambda2() {
    string name = "21";
    return ab.findMatchingAddress(
            [&] (const string &number) {
                return number.find(name) != string::npos;
            }
    );
}

int main() {
    ab.set("11234123");
    ab.set("2123123");
    ab.set("123313123");

    std::vector<std::string> result = lambda2();

    for (auto itr = result.begin(), end = result.end(); itr != end; ++itr)
        std::cout << *itr << std::endl;

    return 0;
}
