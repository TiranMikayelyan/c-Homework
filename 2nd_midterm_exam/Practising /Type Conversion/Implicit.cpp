#include <iostream>
//implicit
class test {
private:
    int c;
public:
    test(int a) { // impilict int -> test
        c = a;
    }
    int get() { //որպեսզի հասկանա ոնց տպի 5-ը, թե չէ չէր հասկանա test-
        return c;
    }

};
void func(test q) {
        std::cout << q.get() << std::endl;
    }

int main()
{
    int k = 10;
    double m = k; // t-i arjeqy kveragrvi m-in u kdarna double 
    std::cout << sizeof(m)<< std::endl;
    func(5); //implicit 
    test t1 = 5; //implicit;
}
