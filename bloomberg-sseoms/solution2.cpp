template<bool>
class A;

template<>
class A<true> {
    
};

#define a 1;
int b = 2;

int main() {
    
    A< a==1 > ();
    //A< b==1 > a1;
    //A< b==2 > a2;
    
}
