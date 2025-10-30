#include <iostream>
#include <list>

int main() {
    std::list<int> t;

    for (int i = 1; i <= 10; ++i)
        t.push_back(i);

    auto it = t.begin();

   ++it; // արժեքը մեծացնենք 


    t.insert(it, 100);

  for (std::list<int>::iterator it = t.begin(); it !=t.end(); ++it) {
    std::cout << *it << " ";   
}
std::cout << std::endl;


    return 0;
}
