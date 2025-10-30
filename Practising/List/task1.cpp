#include <iostream>
#include <list>

int main() {
    std::list<int> a;
    for (int i = 1; i <= 10; ++i)
        a.push_back(i);

    for (auto it = a.begin(); it != a.end(); ) {
        if (*it % 2 == 0)
            it = a.erase(it);  
        else
            ++it;
    }

    
    for (std::list<int>::iterator it = a.begin(); it != a.end(); ++it) {
    std::cout << *it << " ";   //
}
std::cout << std::endl;

}
