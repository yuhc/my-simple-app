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

private:
    int data;
};

int main() {
    shared_ptr<Test> p1 (new Test(200));
    shared_ptr<Test> p2 = make_shared<Test>(100);

    cout << p1->get() << ", " << p2->get() << endl;

    shared_ptr<Test> p3 (new Test[5], [] (Test *p) {
            cout << "in lambda\n";
            delete[] p;
            cout << "out lambda\n";
    });

    // this is fine
    shared_ptr<Test> p4 = p1;

    // the second looks like copy-on-write
    Test *p = new Test(10);
    shared_ptr<Test> p5(p);
    shared_ptr<Test> p6(p);

    // this will not be released
    shared_ptr<Test> p7 (new Test(20));
    p7->p = p7;
}

