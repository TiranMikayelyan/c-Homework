#include <iostream>
#include <cstddef> //offsetof-ի համար

//class test {
//private: double a;
//         int b;
//         char c;
//public:
//    test(){}
//    ~test() {}
//};
//int main()
//{
//    test x;
//    std::cout << sizeof(x);//16 կստացվի 16 % 8 == 0
//}


//class test {
//private: 
//       int b;     
//       double a;
//       char c;
//public:
//    test() {}
//    ~test() {}
//};
//int main()
//{
//    test x;
//    std::cout << sizeof(x);//24  4 int + 4 8 ic double verjum el 1 + 7 char
//}


class test {
public:
    char c;
    double a;
    int b;
    test() {}
    ~test() {}
};
int main()
{
    test x;
    std::cout << sizeof(x)<<std::endl;//24  1 char + 7 double hasnelu hamar, 8-16 double , 4 int 16-20 , +4 int 8 i hamar
    std::cout << offsetof(test, c) << std::endl;
    std::cout << offsetof(test, a) << std::endl;//ցույց է տալիս քանի բայթ հեռավորության վրա է տվյալ փոփոխականը։
    std::cout << offsetof(test, b) << std::endl;

}
