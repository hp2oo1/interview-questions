#include <iostream>

using namespace std;

char* reverseWord(char* word) {
    char *p0=word;
    char *p1=word;
    //
    while(*p1!='\0')
        ++p1;
    --p1;
    //
    while( p0!=p1 ) {
        char tmp = *p0;
        *p0 = *p1;
        *p1 = tmp;
        ++p0;
        if( p0==p1 )
            break;
        --p1;
    }
    return word;
}

int main() {
    char word[4096];
    while(cin>>word) {
        cout<<word<<" --> ";
        cout<<reverseWord(word)<<endl;
    }
}
