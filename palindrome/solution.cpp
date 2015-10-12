/*
Find minimum number of characters that need to be inserted into a string (anywhere in the string)
to make it a palindrome..(Hint: Interviewer expected a Dynamic Programming kind of solution)
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool isPalindrome(string word) {
    int L=0, R=word.size()-1;
    bool result = true;
    while( L<R ) {
        if( word[L]!=word[R] ) {
            result = false;
            break;
        }
        else {
            ++L;
            --R;
        }
    }
    return result;
}

pair<int,int> recursive(int first, int last, string word, vector<vector<int> >& matrix) {
    
    if( matrix[first][last]>0 )
        return make_pair(0,0);
    else
        matrix[first][last]=1;
    
    if( isPalindrome(word.substr(first,last-first+1)) )
        return make_pair(first,last);
    
    auto p1 = recursive(first+1,last,word,matrix);
    auto p2 = recursive(first,last-1,word,matrix);
    
    auto p = p1.second-p1.first>p2.second-p2.first?p1:p2;
    return p;
}

int compare(string word1, string word2) {
    map<char,int> my_map;
    for(int i=0; i<word2.size(); ++i) {
        ++my_map[word2[i]];
    }
    int count = word1.size() + word2.size();
    //cout<<word1<<" "<<word2<<endl;
    //cout<<count<<endl;
    for(int i=0; i<word1.size(); ++i) {
        if( my_map[word1[i]]>0 ) {
            count--;
        }
    }
    return count;
}

int main() {
    string word;
    while(cin>>word) {
        //cout<<isPalindrome(word)<<endl;
        vector<vector<int> > matrix(word.size(),vector<int>(word.size(),0));
        auto p = recursive(0,word.size()-1,word,matrix);
        //cout<<p.first<<" "<<p.second<<endl;
        cout<<word.substr(p.first,p.second-p.first+1)<<endl;
        int result;
        string word1 = (p.first-1>=0)?word.substr(0,p.first):"";
        string word2 = (p.second+1<=word.size()-1)?word.substr(p.second+1,word.size()-p.second):"";
        result = compare( word1, word2 );
        cout<<result<<endl;
    }
}
