#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    // Սովորական iterator
    cout << "Normal iterator:\n";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    // Const iterator 
    cout << "\nConst iterator:\n";
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;

    //  Reverse iterator
    cout << "\nReverse iterator:\n";
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
        cout << *it << " ";
    cout << endl;

    // Random access
    cout << "\nRandom access:\n";
    auto it = v.begin();
    cout << it[2] << endl;   // 30

    // Output iterator
    cout << "\nOutput iterator:\n";
    ostream_iterator<int> out(cout, " ");
    for (auto it2 = v.begin(); it2 != v.end(); it2++)
        *out = *it2;

    return 0;
}
