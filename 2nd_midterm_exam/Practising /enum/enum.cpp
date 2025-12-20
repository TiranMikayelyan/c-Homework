/*enum-ը անվանված ամբողջ թվերի հավաքածու է, որից կարող ես ընտրել միայն նախապես տրված արժեքներից մեկը։*/
#include <iostream>
using namespace std;

enum State {
    OFF,
    ON
};

int main() {
    State s = OFF;

    if (s == OFF)
        cout << "Device is OFF\n";

    s = ON;

    if (s == ON)
        cout << "Device is ON\n";
}
