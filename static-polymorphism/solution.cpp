#include <iostream>

using namespace std;

template<typename T>
class Base {
public:
    void interface() {
        static_cast<T*>(this)->implementation();
    }
    static double Foo(double rParam) {
        return T::Foo(rParam);
    }
};

class Derived1 : public Base<Derived1> {
public:
    void implementation() {
        cout<<"implementation in Derived1"<<endl;
    }
    static double Foo(double rParam) {
        return rParam;
    }
};

class Derived2 : public Base<Derived2> {
public:
    void implementation() {
        cout<<"implementation in Derived2"<<endl;
    }
    static double Foo(double rParam) {
        return rParam*rParam;
    }
};

int main()
{
    Base<Derived1>* D1 = new Derived1;
    Base<Derived2>* D2 = new Derived2;
    
    cout<<D1->Foo(1.1)<<endl;
    cout<<D2->Foo(1.1)<<endl;
    
    D1->interface();
    D2->interface();

    return 0;
}
