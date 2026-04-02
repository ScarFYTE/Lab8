#include<iostream>

using namespace std;

template <typename T>

int Frequency(T arr[], int size, T element) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 2;

    int freq = Frequency(arr, size, element);
    cout << "Frequency of " << element << " is: " << freq << endl;

    return 0;
}