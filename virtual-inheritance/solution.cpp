#include <string>
#include <iostream>

using namespace std;

struct Class {
    // default constructor
};

struct Base : Class {
    Base() : name("Base") { cout<<"Base()"<<endl; };
    Base(string s) : name(s) { cout<<"Base(string s)"<<endl; };
    Base(const Base& b) : name(b.name) {};
protected:
    string name;
};

struct Derived1 : virtual Base {
    Derived1() : Base("Derived1") { cout<<"Derived1()"<<endl; };
    Derived1(string s) : Base(s) {};
    Derived1(const Derived1& d) : Base(d) {};
};

struct Derived2 : virtual Base {
    Derived2() : Base("Derived2") { cout<<"Derived2()"<<endl; };
    Derived2(string s) : Base(s) {};
    Derived2(const Derived2& d) : Base(d) {};
};

struct MI : Derived1, Derived2 {
    MI() : Base("MI"), Derived1(), Derived2() { cout<<"MI()"<<endl; };
    MI(string s) : Base(s), Derived1(s), Derived2(s) {};
    MI(const MI& m) : Base(m), Derived1(m), Derived2(m) {};
};

struct Final : MI, Class {
    Final() : Base("Final"), MI() { cout<<"Final()"<<endl; };
    Final(string s) : Base(s), MI(s) {};
    Final(const Final& f) : Base(f), MI(f) {};
};

int main() {

    Final a;

}
