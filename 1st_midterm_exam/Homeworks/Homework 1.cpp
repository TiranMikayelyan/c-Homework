//առանց տրամաբանակ օպերատորի
#include <iostream>

//int main()
//{
//    int arr[50], n;
//    do { std::cout << "n = "; std::cin >> n; } while (n < 2 || n>50);
//    for (int i = 0; i < n; i++)
//    {
//        std::cout << i << " element ";
//        std::cin >> arr[i];
//    }
//    for (int i = 0; i < n; i++)
//    {
//        int count = 0;
//        for (int j = 0; j < n; j++) {
//            if (arr[i] == arr[j])
//            count += 1;
//        }
//        if (count == 1) {
//            std::cout<< "չկրկնվող տարրն է"  << arr[i]<< "ը";
//        }
//    }
//        return 0;
//}


//տրամաբանական օպերատորով 
//int main()
//{
//    int arr[50], n;
//    do { std::cout << "n = "; std::cin >> n; } while (n < 2 || n>50);
//    for (int i = 0; i < n; i++)
//    {
//        std::cout << i << " element ";
//        std::cin >> arr[i];
//    }
//    int a = 0;
//    for (int i = 0; i < n; i++)
//        a ^= arr[i];
//
//    std::cout << a ;
//}