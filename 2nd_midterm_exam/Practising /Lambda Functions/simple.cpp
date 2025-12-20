#include <iostream>
using namespace std;

int main() {
    auto hello = []() { // []-> capture list () -> պարամետրեր
        cout << "Hello\n";
    };

    hello();
}
