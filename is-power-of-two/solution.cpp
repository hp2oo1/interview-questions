#include <bitset>
#include <iostream>

using namespace std;

bool isPowerOfTwo(int x) {
    bool result(false);
    bitset<32> b(x);
    //cout<<b<<endl;
    if(b.count()==1)
        result=true;
    return result;
}

int main() {
    
    int x;
    while(cin>>x) {
        //cout<<isPowerOfTwo(x)<<endl;
        cout<<[](int x){ return (x>0 && !(x&(x-1))); }(x)<<endl;
    }
    
}
