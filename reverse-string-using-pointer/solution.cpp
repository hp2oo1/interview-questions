// Example program
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char s[256];
    cin>>s;
    //cout<<s<<endl;
    
    char* p = s;
    char* q = s;
    char* q_prev = s;
    while( *q!='\0' ) {
        //cout<<*q<<endl;
        q_prev = q;
        ++q;
    }
    q = q_prev;
    while( p!=q && p!=q_prev ) {
        //cout<<*p<<endl;
        char tmp = *p;
        *p = *q;
        *q = tmp;
        ++p;
        q_prev = q;
        --q;
    }
    cout<<s<<endl;
    
    return 0;
}
