/*
write a function to compare 2 strings of the same length
find the number of different chars.
e.g.
myCompare('bond','debt') = 2
myCompare('xxxx','yyyy') = 1
*/

#include <string>
#include <set>
#include <iostream>

using namespace std;

string removeDuplicate(string word) {
    set<char> myset;
    string new_word("");
    for(int i=0; i<word.size(); ++i) {
        //if( myset.count(word[i])>0 ) {
        if( myset.find(word[i]) != myset.end() ) {
            // duplicate skip
        }
        else {
            myset.insert(word[i]);
            new_word += word[i];
        }
    }
    return new_word;
}

int compare(string word1, string word2) {
    int count(0);
    for(int i=0; i<word1.size(); ++i)
        for(int j=0; j<word2.size(); ++j)
            if( word1[i]==word2[j] )
                count++;
    return count; // number of same characters
}

int main() {
    string word1,word2;
    while(cin>>word1>>word2) {
        word1 = removeDuplicate(word1);
        word2 = removeDuplicate(word2);
        cout<<word1<<" "<<word2<<endl;
        int count = compare(word1,word2);
        int result = max(word1.size(),word2.size()) - count;
        cout<<count<<" "<<result<<endl;
    }
}
