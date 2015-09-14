// Remove duplicate characters from the string
#include <iostream>
#include <string>

int main()
{
    std::string mystring;
    std::cin>>mystring;
    
    bool visited[256];
    for(unsigned int i=0; i<256; ++i)
        visited[i] = false;     // init as not visited
    
    unsigned int count = 0;
    for(unsigned int i=0; i<mystring.size(); ++i) {
        unsigned int j = mystring[i];
        if( !visited[j] ) {
            visited[j]= true;   // mark as visited
            mystring[count] = mystring[i];
            count++;
        }
    }
    mystring.resize(count);

    // output
    std::cout<<mystring<<std::endl;
}
