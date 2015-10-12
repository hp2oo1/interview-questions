/*
write a function to compare 2 strings of the same length,
find the number of different chars.
e.g.
myCompare('bond','debt')=2
myCompare('xxxx','yyyy')=2 (this may be wrong, should be 1)
*/

#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<char> sortWord(const string& w) {
    vector<char> v;
    for(int i=0; i<w.size(); ++i)
        v.push_back(w[i]);
    sort(v.begin(),v.end());
    return move(v);
}

int compareWord(const vector<char>& v1, const vector<char>& v2) {
    set<pair<char,char> > s;
    for(int i=0; i<v1.size(); ++i) {
        //cout<<v1[i]<<" "<<v2[i]<<endl;
        if( v1[i]!=v2[i] )
            s.insert(make_pair(v1[i],v2[i]));
    }
    return s.size();
}

int main() {
    string word1, word2;
    while(cin>>word1>>word2) {
        cout<<compareWord( sortWord(word1), sortWord(word2) )<<endl;
    }
}
