#include <iostream>
#include <chrono>
using namespace std::chrono;

int main() {
    auto start = steady_clock::now(); //skizb
    volatile int sum = 0; //Ram
    for (int i = 0; i < 1000000; i++)
        sum += i;

    auto end = steady_clock::now();//verj
  

    auto diff = duration_cast<microseconds>(end - start).count(); 

    std::cout << "time="<< diff << "ms" << std::endl;
}
