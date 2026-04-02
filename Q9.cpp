#include <iostream>

using namespace std;

template <typename T>
T max_value(T a, T b, T c)
{
    T max = a;

    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    return max;
}

int main()
{
	cout << "Max of 10, 25, 7: " << max_value(10, 25, 7) << endl;
	cout << "Max of 3.14, 2.71, 4.20: " << max_value(3.14, 2.71, 4.20) << endl;

	return 0;
}