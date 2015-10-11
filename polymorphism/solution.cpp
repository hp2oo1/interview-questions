#include <iostream>

class A {
public:
    A() { foo(); }
    virtual void foo(int a = 10) {
        std::cout<<"A = "<<a<<std::endl;
    }
};

class B : public A {
public:
    B() { foo(); }
    virtual void foo(int b = 20) {
        std::cout<<"B = "<<b<<std::endl;
    }
};

int main() {
    A* aPtr = new B();
    aPtr->foo();
    delete aPtr;
    return 0;
}
