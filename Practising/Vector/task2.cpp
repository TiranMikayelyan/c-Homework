#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int,int>> 
freq(std::vector<int> a) {
    std::vector<std::pair<int,int>> arr;
    if (a.empty()) return arr;

    std::sort(a.begin(), a.end()); // sort ըստ արժեքի աճման

    int count = 1;
    for (int i = 1; i <= a.size(); i++) {
        if (i < a.size() && a[i] == a[i - 1])
            count++;
        else {
            arr.push_back({a[i - 1], count});
            count = 1;
        }
    }
    return arr;
}

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
    std::vector<std::pair<int,int>> օ = freq(a); 


    std::cout <<"number - frequnecy"<<std::endl;
    std::cout << "[";
    for (int i = 0; i < օ.size(); i++) {
        std::cout << "(" << օ[i].first << "," << օ[i].second << ")";
        if (i + 1 != օ.size()) 
        std::cout << ",";
    }
    std::cout << "]\n";

    return 0;
}
