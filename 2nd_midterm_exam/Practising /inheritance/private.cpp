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

class B : private A {
public:
    void testB() {
        x = 10;   // կաշխատի, A-ի public անդամն է, բայց private ժառանգման ժամանակ դառնում է private
        y = 20;   // կաշխատի, A-ի protected անդամն է, բայց private ժառանգման ժամանակ դառնում է private
        // z = 30; // Error A-ի private անդամին ժառանգ դասից հասանելիություն չկա
    }
};

int main() {
    B obj;

    // obj.x = 5;     // Error  դարձել են private հասանելի չեն դրսից
    // obj.y = 5;     
    // obj.z = 5;     

    return 0;
}
