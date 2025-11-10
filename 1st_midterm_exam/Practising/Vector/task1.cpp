#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr;
    int n;
    do{ std::cout<<"n="; std::cin >> n;} while( n < 2 );
    for(int i = 0; i < n; i++)
    {
        std::cout << "arr["<<i<<"]=";
        int x;
        std::cin >> x;
        arr.push_back(x);
    }

     for (int i = 0; i < (int)arr.size();) {
        if (arr[i] % 2 == 0) {
            arr.erase(arr.begin() + i);
        } else 
            i++;                         
        }
    
std::cout<<"New vector without even numbers "<<std::endl;
    for (int i = 0; i < arr.size(); i++)
        std::cout<<arr[i]<<"\t";

    return 0;
}

