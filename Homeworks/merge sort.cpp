#include <iostream>
#include <cstdlib>

template<typename T>
void mergeSort(T arr[], int n) {
    if (n < 2) return;

    int mid = n / 2;
    T* left = new T[mid];
    T* right = new T[n - mid];

    for (int i = 0; i < mid; i++) left[i] = arr[i];
    for (int i = mid; i < n; i++) right[i - mid] = arr[i];

    mergeSort(left, mid);
    mergeSort(right, n - mid);

    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < mid) arr[k++] = left[i++];
    while (j < n - mid) arr[k++] = right[j++];

    delete[] left;
    delete[] right;
}

int main() {
    int n;
    int arr[10];
    do {
        std::cout << "n=";
        std::cin >> n;
    } while (n < 2 || n > 10);

    for (int i = 0; i < n; i++) arr[i] = std::rand() % 100;

    double arr2[10];
    for (int i = 0; i < n; i++) arr2[i] = (std::rand() % 1000) / 10.0;

    mergeSort(arr, n);
    std::cout << "int sorted list: ";
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;

    mergeSort(arr2, n);
    std::cout << "double sorted list: ";
    for (int i = 0; i < n; i++) std::cout << arr2[i] << " ";
    std::cout << std::endl;
}
