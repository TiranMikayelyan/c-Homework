#include <iostream>

class Ptr {
    int* p;

public:
    Ptr(int* x) {    // constructor 
        p = x;
    }

    ~Ptr() {         // destructor
        delete p;
    }

    int& operator*() {    // կարանք ստանանք  pointer-ի միջի արժեքը։
        return *p;
    }

    int* operator->() {   // վերադարձնում է իրական pointer-ը
        return p;
    }
};

int main() {
    Ptr a(new int(10));

    std::cout << *a << std::endl;   // operator* -> 10


    return 0;
}
