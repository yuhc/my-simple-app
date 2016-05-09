#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
    Test(int a = 0): data(a) {
    }

    int get() {
        return data;
    }

    ~Test() {
        cout << "deconstructed\n";
    }

private:
    int data;
};

void div() {
    int a = 0, b = 1, c;
    if (!a) {
        throw "Invalid divisor!";
    }
    c = a / b;
}

void owner(auto_ptr<Test> p1) {
    cout << "in owner: " << p1->get() << endl;
}

int main() {
    cout << "first try\n";
    try {
        auto_ptr<Test> p (new Test(1));
        div();
        cout << p->get() << endl;
    }
    catch (const exception &e) {
        cout << "Catch: " << e.what() << endl;
    }
    catch (...) {
        cout << "Something is wrong\n";
    }

    cout << "\nsecond try\n";
    try {
        auto_ptr<Test> p (new Test(1));
        owner(p);
        // this line reports an error
        // cout << p->get() << endl;
    }
    catch (...) {
        cout << "p is deconstructed" << endl;
    }

    cout << "\nthird try\n";
    // cannot be used for array
    // this will cause an error
    auto_ptr<Test> p (new Test[5]);

    return 0;
}
