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

class B : protected A {
public:
    void testB() {
        x = 10;   // կաշխատի, A-ի public անդամն է, բայց protected ժառանգմամբ դառնում է protected
        y = 20;   // կաշխատի, A-ի protected անդամը կմնա protected
        // z = 30; // Error A-ի private անդամին ժառանգ դասից հասանելիություն չկա
    }
};

int main() {
    B obj;

    // obj.x = 5;     // Error՝ protected ժառանգության դեպքում A-ի public անդամը դառնում է protected
    // obj.y = 5;     // Error՝ protected անդամը դրսից հասանելի չէ
    // obj.z = 5;     // Error՝ private անդամը դրսից հասանելի չէ

    return 0;
}
