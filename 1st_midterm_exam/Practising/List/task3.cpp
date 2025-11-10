
//listi gumar
#include <iostream>

struct Node {
    int value;
    Node* next;
};

int main() {
    Node a{8};
    Node b{10};
    Node c{18};

    a.next = &b;
    b.next = &c;

    int sum = a.value + b.value + c.value;

    std::cout << sum;  
}
