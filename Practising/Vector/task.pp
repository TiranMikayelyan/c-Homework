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
    
    std::vector<int> b;
    do{ std::cout<<"n="; std::cin >> n;} while( n < 2 );
    for(int i = 0; i < n; i++)
    {
        std::cout << "b["<<i<<"]=";
        int x;
        std::cin >> x;
        b.push_back(x);
    }
std::vector<int> c = a;
c.insert(c.end(), b.begin(), b.end());

    std::cout << "United Vector "<<std::endl;
    for (int i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";

    std::cout << std::endl;
    return 0;
}
