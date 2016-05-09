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
        cout << "deconstructed " << data << "\n";
    }

    shared_ptr<Test> p;
    weak_ptr<Test> wp;

private:
    int data;
};

int main() {
    shared_ptr<Test> p1 (new Test(200));
    weak_ptr<Test> wp1(p1);
    weak_ptr<Test> wp2 = wp1;

    // Casting
    shared_ptr<Test> p2 = wp1.lock();

    // Solve cyclic reference
    p2->wp = p2;

    return 0;
}
