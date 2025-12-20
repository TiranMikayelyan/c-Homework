#include <iostream>
#include <vector>
#include <algorithm>

int qanak = 0;

bool compare(int a, int b) {
    qanak++;  // compare-ների քանակ

    // եթե մեկը կենտ է, մյուսը զույգ
    if ((a % 2) != (b % 2))
        return a % 2 > b % 2;   // կենտը առաջ

    // երկուսն էլ կենտ են
    if (a % 2 == 1)
        return a > b;          // նվազման

    // երկուսն էլ զույգ են
    return a < b;              // աճման
}

int main() {
    int n;
    do {
        std::cout << "n="; std::cin >> n;
    } while (n < 2);

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cout << "v[" << i << "]=";
        std::cin >> v[i];
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++)
        std::cout << v[i] << " ";

    std::cout << "\nCompars: " << qanak << std::endl;
}
