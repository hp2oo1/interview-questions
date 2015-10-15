#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
    Node* Append(int data) {
        Node* new_node = new Node(data);
        next = new_node;
        return new_node;
    }
//
friend void print( const Node* p );
};

void print( const Node* p ) {
    int count = 0;
    while( p!=0 ) {
        cout<<p->data<<"->";
        p = p->next;
        ++count;
        if( count>10 ) {
            cout << "...\n";
            return;
        }
    }
    cout<<"nullptr"<<endl;
}

const Node* hasLoop( const Node* head ) {
    const Node* p1(head);
    const Node* p2(head);
    while( p1!=nullptr && p2!=nullptr ) {
        p1 = p1->next;
        p2 = p2->next;
        if( p2==nullptr )
            return nullptr;
        p2 = p2->next;
        if( p1==p2 )
            break;
    }
    if( p2==nullptr )
        return nullptr;
    // find first node starting the loop
    // find pL = head + loop
    const Node* pL(head);
    while(1) {
        pL = pL->next;
        p1 = p1->next;
        if( p1==p2 )
            break;
    }
    // find p0 = head + x and p0+x == pL+x
    const Node* p0(head);
    while(1) {
        p0 = p0->next;
        pL = pL->next;
        if( p0==pL )
            break;
    }
    return p0;
}

int main() {
    
    Node head(0);
    (&head)->Append(1)->Append(2)->Append(3);
    // make a loop
    (&head)->next = (&head);
    //(&head)->next->next->next->next = (&head)->next->next;
    // check
    print( &head );
    
    // hasLoop?
    const Node* p = hasLoop( &head );
    if( p==nullptr ) {
        cout<<"no loop\n";
    }
    else {
        cout<<"has loop starting at "<< p->data << endl;
    }
    
}
