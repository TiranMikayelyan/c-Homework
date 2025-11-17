#include <iostream>

//Explicit

class test {
private:
    int c;
public:
    explicit test(int a) { 
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
    double m = k; // k-i arjeqy kveragrvi m-in u kdarna double 
    std::cout << sizeof(m) << std::endl;
    //func(5); //implicit -> error
    //test t1 = 5; //implicit; -> error

    test t(5); //konkret arjeqov u tipov objekti stexcum
    func(t);
}
