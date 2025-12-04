#include <iostream>

class Test {
public:
    Test() { std::cout << "Ctor\n"; }
    Test(const Test&) { std::cout << "Copy\n"; }
};

Test make_nrvo() { //copy constructor չի կանչվում, որովհետև 't' օբյեկտը անմիջապես ex-ի memory-ի մեջ է կառուցվում։
    Test t;      
    return t;    
    
}

int main() {
    Test ex = make_nrvo();
}
