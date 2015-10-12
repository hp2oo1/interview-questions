#include <string>
#include <sstream>
#include <iostream>

using namespace std;

bool isPal(string word) {
    int i=0, j=word.size()-1;
    while( i<j ) {
        if( word[i++]!=word[j--] )
            return false;
    }
    return true;
}

string convert(int number) {
    string word="";
    int i;
    while( number>0 ) {
        i = number%10;
        char c[1];
        c[0] = '0'+i;
        word = string(c)+word;
        number = number/10;
    }
    return word;
}

int main() {
    
    int number;
    while(cin>>number) {
        //stringstream ss;
        //ss<<number;
        //string word = ss.str();
        string word = convert(number);
        cout<<isPal(word)<<endl;
    }
    
}
