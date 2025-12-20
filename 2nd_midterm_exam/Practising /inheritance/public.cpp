#include <iostream>
using namespace std;

class A {
public:
    int x = 1;

protected:
    int y = 2;

private:
    int z = 3;
};

class B : public A {
public:
    void testB() {
        x = 10;   // կաշխատի  A-ի public , կմնա public
        y = 20;   // կաշխատի A-ի protected-ը կմնա protected
        // z = 30; // Error A-ի private հասանելի չէ
    }
};

int main() {
    B obj;

    obj.x = 5;        // կաշխատի public member
    // obj.y = 5;     // Error protected-ը դրսից չի երևում
    // obj.z = 5;     // Error private-ը դրսից չի երևում

    return 0;
}
