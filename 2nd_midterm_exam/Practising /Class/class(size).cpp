#include <iostream>
class test {
public:
    test() {};
    ~test() {};
};
int main()
{
    std::cout << sizeof(test); //պահվում է 1 բայթ
}
