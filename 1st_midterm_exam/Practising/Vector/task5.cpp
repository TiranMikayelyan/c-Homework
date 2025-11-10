#include <iostream>
#include <vector>

int main() {
    std::vector<int> a;
    int n;
    do{ std::cout<<"n="; std::cin >> n;} while( n < 2 );
    for(int i = 0; i < n; i++)
    {
        std::cout << "a["<<i<<"]=";
        int x;
        std::cin >> x;
        a.push_back(x);
    }

    std::cout << "Reversed Vector "<<std::endl;
    for (int i = a.size()-1; i >= 0; i--)
        std::cout << a[i] << " ";

    std::cout << std::endl;
    return 0;
}
