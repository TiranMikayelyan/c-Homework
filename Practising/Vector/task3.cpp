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
int max = a[0];
    for (int i = 1; i < a.size(); i++) {
        if (a[i]>max)
        max = a[i];
    }
    std::cout<<"max="<<max<<std::endl;

    return 0;
}
