#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack{
    T* arr;
    int topIndex;
    int capacity;
public:
    Stack(int size) {
        arr = new T[size];
        capacity = size;
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T x) {
        if (topIndex == capacity - 1) {
            throw runtime_error("Stack overflow");
            return;
        }
        arr[++topIndex] = x;
    }

    T pop() {
        if (topIndex == -1) {
            throw runtime_error("Stack underflow");
            return -1; // Return -1 to indicate stack is empty
        }
        return arr[topIndex--];
    }
    
    T top() {
        if (topIndex == -1) {
            throw runtime_error("Stack is empty");
            return -1; // Return -1 to indicate stack is empty
        }
        return arr[topIndex];
    }

};

int main() {
    Stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top element is: " << s.top() << endl;

    cout << "Popped element is: " << s.pop() << endl;
    cout << "Top element after pop is: " << s.top() << endl;

    return 0;
}