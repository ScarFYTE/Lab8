#include <iostream>

using namespace std;

template <typename T , typename U>

void swap(T& a, U& b)
{
    T temp = a;
    a = static_cast<T>(b);
    b = static_cast<U>(temp);
}

int main()
{
    int x = 10;
    double y = 3.14;

    cout << "Before swap: x = " << x << ", y = " << y << endl;
// swapping the values of x and y but float to int would result in loss of precision,
    swap(x, y);

    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}