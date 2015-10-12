#include <string>
#include <iostream>

using namespace std;

string reverseWord(string word) {
    char *p0=&word[0], *p1=&word[word.size()-1];
    while( p0!=p1 ) {
        char tmp = *p0;
        *p0 = *p1;
        *p1 = tmp;
        ++p0;
        if( p0==p1 )
            break;
        --p1;
    }
    return move(word);
}

int main() {
    string word;
    while(cin>>word) {
        cout<<word<<" --> ";
        cout<<reverseWord(move(word))<<endl;
    }
}
