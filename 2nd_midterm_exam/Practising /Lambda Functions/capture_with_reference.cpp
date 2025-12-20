#include <iostream>
using namespace std;

int main() {
    int x = 5;

    auto add = [&x]() {
        x += 10;
    };

    add();
    cout << x;   // 15
}
