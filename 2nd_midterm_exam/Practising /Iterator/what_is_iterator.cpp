#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4};

    vector<int>::iterator it = v.begin();  // կարելի է ասել pointer-ի նման է , որը դնում ենք առաջին տարրի վևա , ու այդպես մեծացնելով կարանք հաջորդ տարրը ստանանք

    cout << *it << endl;   // 1

    it++;
    cout << *it << endl;   // 2
}
