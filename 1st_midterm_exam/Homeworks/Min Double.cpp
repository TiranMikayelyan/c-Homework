#include <iostream>
//#include <iomanip> irakan tivy tesnelu hamar

int main() {
     long long bits = 0x0010000000000000; // double-i amenapoqr drakan tivy
    double d = *reinterpret_cast<double*>(&bits); // bitery kardum em vorpes double tiv

    //std::cout << std::fixed << std::setprecision(400); esi ete grem cuyc kta irakan tivy
    std::cout << "min double =  " << d << std::endl;
}
