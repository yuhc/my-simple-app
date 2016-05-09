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

private:
    int data;
};

int main() {
    unique_ptr<int> uptr(new int);
    unique_ptr<int []> uptr_array(new int[5]);

    unique_ptr<Test> p(new Test(100));
    cout << "assign to another one\n";
    unique_ptr<Test> p1;

    // this will throw an error
    // p1 = p;

    p1 = move(p);

    // this will throw an fault
    // cout << p->get() << endl;

    return 0;
}
