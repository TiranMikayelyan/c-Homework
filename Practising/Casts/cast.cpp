#include <iostream>

int main() {
    int a = 5;
    double b = static_cast<double>(a);   // int → double
    std::cout << "static_cast: b = " << b << std::endl;

    const int x = 10;
    const int* c = &x; //const-y hanum enq
    std::cout << "const read:  c= " << *c << std::endl;

    int* p = const_cast<int*>(&x);
    *p = 11;
    std::cout << "const_cast read: *p = " << *p << std::endl;
    
    int n = 65; 
    unsigned char*  k= reinterpret_cast<unsigned char*>(&n);
    std::cout << "reinterpret_cast: char= " << *k << std::endl;
    std::cout << "reinterpret_cast:int  = " << static_cast<int>(*k)
              << std::endl;
              
              
    long long bits = 0x0110; 
    double d = *reinterpret_cast<double*>(&bits); // bitery kardum em vorpes double tiv
    std::cout<<"d="<<d<<std::endl;
    return 0;
}
