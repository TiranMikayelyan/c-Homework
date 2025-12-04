#include <iostream>

class Test {
public:
    Test() { std::cout << "Ctor\n"; }
    Test(const Test&) { std::cout << "Copy\n"; }
};

Test make_rvo() {
    return Test();   // (RVO) Copy constructor չի կանչվում, որովհետև RVO-ն սկզբնարժեքավորումը անում է միանգամից obj-ի մեջ։
}

int main() {
    Test ex = make_rvo();
}
