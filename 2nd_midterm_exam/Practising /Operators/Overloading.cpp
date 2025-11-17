#include <iostream>

class Test {
private:
    int c;
public:
    Test(int a) {
        c = a;
    }

    int get() const {
        return c; }

    // +
    Test operator+(const Test& t) const { //գերբեռնում կլասսի օբյեկտի գումարման համար, առանց սրա չենք կարա գումարում անենք
        return Test(c + t.c);
    }

    //  -
    Test operator-(const Test& t) const {
        return Test(c - t.c);
    }

    // *
    Test operator*(const Test& t) const {
        return Test(c * t.c);
    }

    //  /
    Test operator/(const Test& t) const {
        if (t.c != 0)
            return Test(c / t.c);
        else
            return 0;
    }
};

int main() {
    Test a(10);
    Test b(5);

    Test summ = a + b;
    Test sub = a - b;
    Test mul = a * b;
    Test div = a / b;

    std::cout << summ.get() << std::endl; 
    std::cout << sub.get() << std::endl;  
    std::cout << mul.get() << std::endl;  
    if (div.get() != 0)
    std::cout << div.get() << std::endl;  

    return 0;
}
