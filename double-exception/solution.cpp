#include <iostream>

using namespace std;

class A {
    char c;
    int i;
public:
    A() { cout<<"constructor A"<<endl; }
   ~A() {
        cout<<"destructor A"<<endl;
        cout<<"throw bomb A"<<endl;
        throw "bomb A";
    }
};

class B {
    char c;
    int i;
public:
    B() {
        try {
            cout<<"constructor B"<<endl;
            cout<<"throw bomb B"<<endl;
            throw "bomb B";
        }
        catch(const char *c) {
            cout<<"catch "<<c<<" in B()"<<endl;
        }
    }
   ~B() { cout<<"destructor B"<<endl; }
};

int main() {
    try{
        A a;
        B b;
    }
    catch(const char *c) {
        cout<<"catch "<<c<<" in main()"<<endl;
    }
}
