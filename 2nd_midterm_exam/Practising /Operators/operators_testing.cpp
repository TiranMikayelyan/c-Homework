#include <iostream>


int test() {
    return 0;
}

int& testRef() {
    static int ch = 0;
    return ch;     // վերադարձնում է X-ին հղում, ոչ թե copy
}


int main()
{
    int i = 0;

    std::cout << (++i)++ << std::endl; //1  կաշխատի փակագծից հետո ++  կաշխատի կդարձնի 2 , բայց կտա 1-ը
    std::cout << i << std::endl; //2


    int a = 5;
    int b = 6;

    //int& x = (a + b); //error ժամանակավոր օբյեկտի վրա չի կարելի հղում կիրառել
    const int& x = (a + b);
    std::cout << "x=" << x<< std::endl; //11

    bool y = false;
    bool a1 = true;
    bool b1 = false;


   //bool& z = (a1 || b1) = y; // error որվոհետև a1||b1 արժեք է , ու արժեքի վրա չի կարելի վերագրում անել ժամանակավոր է նորից


    //int տ++ = 5; //error a++–ը արժեք է, ոչ փոփոխական, դրա վրա = անել չի կարելի։

    //test() = 5; //error Assign անել կարելի է միայն reference-returning ֆունկցիայի արդյունքում։

    testRef() = 10;
    std::cout << testRef();   // 10

}

