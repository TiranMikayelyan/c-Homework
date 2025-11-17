#include <iostream>

class Test {
private:
    int c;
public:
    Test(int a){
        c = a;
    }
    Test(const Test& t) {   // copy constructor, const -> որ օբյեկտը չփոխվի, & , հակառակ դեպքում անընդհատ պատճե կստղծվեր ու  copy constructor, կդառնար  stack overflow
        c = t.c;
    }
    int get() const { //const arjeqner
        return c;
    }
};

int main()
{
    Test t1(5);          // ստեղծվում է առաջին օբյեկտը (c = 5)
    Test t2 = t1;        // copy constructor է կանչվում (t2.c = t1.c)
    std::cout << "t1=" << t1.get() << std::endl;
    std::cout << "t2=" << t2.get() << std::endl;
}
