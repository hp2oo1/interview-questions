// This is an implementation of LRU Cache.

#include <deque>
#include <unordered_map>
#include <iterator>
#include <iostream>

#define MAX_CACHE_SIZE 4

using namespace std;

void Enqueue( deque<int>& Q, int p ) {
    // if Q is full, pop the end of Q
    if( Q.size()>=MAX_CACHE_SIZE )
        Q.pop_back();
    // add p to the front of Q
    Q.push_front(p);
}

void ReferencePage( deque<int>& Q, unordered_map<int,deque<int>::iterator>& M, int p ) {
    // if p is not in M, add p to both Q and M
    if( M.count(p)==0 ) {
        Enqueue(Q,p);
        M[p] = Q.begin();
    }
    else {
        deque<int>::iterator it = M[p];
        Q.erase(it);
        Enqueue(Q,p);
    }
}

int main() {
    
    deque<int> mydeque;
    unordered_map<int,deque<int>::iterator> mymap;
    
    // test case: 1,2,3,1,4,5
    ReferencePage(mydeque,mymap,1);
    ReferencePage(mydeque,mymap,2);
    ReferencePage(mydeque,mymap,3);
    ReferencePage(mydeque,mymap,1);
    ReferencePage(mydeque,mymap,4);
    ReferencePage(mydeque,mymap,5);
    
    // print results
    copy(mydeque.begin(),mydeque.end(),ostream_iterator<int>(cout," "));
}
