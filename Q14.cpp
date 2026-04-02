#include<iostream>

using namespace std;


template <typename T>
class Queue {
    T* arr;
    int front;
    int rear;
    int capacity;
public:
    
    Queue(int size) {
        arr = new T[size];
        capacity = size;
        front = 0;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(T x) {
        if (rear == capacity - 1) {
            cout << "Queue overflow" << endl;
            return;
        }
        arr[++rear] = x;
    }
    T dequeue() {
        if (front > rear) {
            cout << "Queue underflow" << endl;
            return -1; // Return -1 to indicate queue is empty
        }
        return arr[front++];
    }
    
    T Front() {
        if (front > rear) {
            cout << "Queue is empty" << endl;
            return -1; // Return -1 to indicate queue is empty
        }
        return arr[front];
    }

};

int main() {
    Queue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element is: " << q.Front() << endl;

    cout << "Dequeued element is: " << q.dequeue() << endl;
    cout << "Front element after dequeue is: " << q.Front() << endl;

    return 0;
}

