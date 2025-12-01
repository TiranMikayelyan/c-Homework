#include <iostream>

class A {
public:
    int value;

    A(int v){
        value = v;
        std::cout << "Ctor, value = " << value << std::endl;
    }

    // Copy constructor
    A(const A& other) { //other = a , aysinqn nuyn mer objecti referencna
        value = other.value;
        std::cout << "Copy ctor, value = " << value << std::endl;
    }

    // Move constructor
    A(A&& other)  {
        value = other.value;
        std::cout << "Move ctor, value = " << value << std::endl;
        other.value = 0;
    }

    ~A() {
        std::cout << "Dtor, value = " << value << std::endl;
    }
};

int main() {
    std::cout << "creating an object" << std::endl; // uxxaki a = 10
    A a(10);      // Ctor

    std::cout << "copy a to b" << std::endl; //sovorakan uxxakin a-n copy klini b-i mej
    A b = a;      // Copy ctor 

    std::cout << "move a to c" << std::endl; //a-n gnum e c-i mej , u a=0 klini
    A c = std::move(a); // Move ctor

    return 0;
}
