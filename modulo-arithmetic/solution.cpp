/*
N numbers are arranged in a circle,
given K, devise a function that returns the number opposite.
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> oppositeIndex(int index, int N) {
    if( N==1 )
        return vector<int>();
    vector<int> result;
    int oppIndex = index%N + N/2;
    result.push_back( oppIndex );
    //cout<<N<<endl;
    if( N%2==1 ) // N is odd
        result.push_back( oppIndex+1 );
    //cout<<result.size()<<endl;
    return result;
}

int main() {
    
    vector<int> numbers;
    
    int number;
    while(cin>>number) {
        numbers.push_back(number);
    }

    int index = numbers.back();
    vector<int> result = oppositeIndex(index,numbers.size()-1);
    for( int i=0; i<result.size(); ++i ) {
        cout<<numbers[result[i]]<<" ";
    }
    if( result.empty() ) {
        cout<<numbers[0]<<" has no opposite.."<<endl;
    }
}
