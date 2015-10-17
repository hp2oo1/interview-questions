#include <iostream>

using namespace std;

char* foo() {
    char s1[] = "ab";
    cout<<sizeof(s1)<<endl;
    
    char *s2  = "cd";
    cout<<sizeof(s2)<<endl;
    
    return s2;
}

int main() {
    char *s3 = foo();
    cout<<s3<<endl;
}
