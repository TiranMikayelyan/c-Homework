#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    const int N = 100000000; 
    vector<int> arr(N, 1); //RAM - ում N Հատ 1-ով վեկտոր է պահում
    int x = 1; //cpu-ի Ռեգիստրում պահվող փոփոխական
    long long sum = 0; //փոփոխական, որում կգումարենք արդյունքները

    auto t1 = high_resolution_clock::now();// սկսելու ժամանակը
    for (int i = 0; i < N; i++) sum += x; // Register
    auto t2 = high_resolution_clock::now(); // ավարտի ժամանակ

    auto t3 = high_resolution_clock::now();
    for (int i = 0; i < N; i++) sum += arr[i]; // RAM
    auto t4 = high_resolution_clock::now();

    cout << "Reading from Register: "<< duration_cast<milliseconds>(t2 - t1).count()<< " ms" << endl;// հաշվում է ժամանակը ու տպում միլիվայրկյանների քանակը որպես թիվ
    cout << "From RAM: "<< duration_cast<milliseconds>(t4 - t3).count() << " ms" << endl;
}
