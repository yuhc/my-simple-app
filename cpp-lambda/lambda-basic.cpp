#include <iostream>

using namespace std;

int main() {
    auto func = [] () {
        cout << "Hello Lambda!\n";
    };

    func();

    return 0;
}
