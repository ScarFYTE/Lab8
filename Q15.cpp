#include <iostream>

using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node* next;
};

template <typename T>
class LinkedList {
    Node<T>* head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(T data) {
        if(head == nullptr) {
            head = new Node<T>();
            head->data = data;
            head->next = nullptr;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node<T>();
            temp->next->data = data;
            temp->next->next = nullptr;
        }
    }

    void display() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void Delete(int index) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (position == 0) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node<T>* next = temp->next->next;
        delete temp->next;
        temp->next = next;
    }
};

int main() {
    LinkedList<int> list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    cout << "Linked List: ";
    list.display();

    cout << "Deleting element at Index 1" << endl;
    list.Delete(1);
    cout << "Linked List after deletion: ";
    list.display();

    return 0;
}