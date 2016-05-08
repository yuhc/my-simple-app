#include <string>
#include <vector>
#include <iostream>
#include "address.h"
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // without lambda
    cout << "no lambda\n";
    for (auto itr = v.begin(), end = v.end(); itr != end; ++itr)
        cout << *itr << endl;

    // with lambda
    cout << "lambda\n";
    for_each(v.begin(), v.end(), [] (int val) { cout << val << endl; });
    return 0;
}
