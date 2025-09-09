#include <iostream>

using namespace std;

class SubSystem1 {
public:
    void method1() {
        cout << "SubSystem1 method1" << endl;
    }
};

class SubSystem2 {
public:
    void method2() {
        cout << "SubSystem2 method2" << endl;
    }
};

class Facade {
private:
    SubSystem1 *subSystem1;
    SubSystem2 *subSystem2;
public:
    Facade() {
        subSystem1 = new SubSystem1();
        subSystem2 = new SubSystem2();
    }

    void method() {
        subSystem1->method1();
        subSystem2->method2();
    }

    ~Facade() {
        delete subSystem1;
        delete subSystem2;
    }
};

int main() {
    Facade* facade = new Facade();
    facade->method();
    delete facade;
    getchar();
    return 0;
}
