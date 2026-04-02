#include <iostream>

using namespace std;

class SingletonThread {
    private:
    SingletonThread() {
        cout << "SingletonThread instance created." << endl;
    }
    public:
    static SingletonThread& getInstance() {
        static SingletonThread instance; // Guaranteed to be destroyed and instantiated on first use
        return instance;
    }

    SingletonThread(SingletonThread const&) = delete; // Prevent copy construction
    void operator=(SingletonThread const&) = delete; // Prevent assignment
};

int main() {
    SingletonThread& instance1 = SingletonThread::getInstance();
    SingletonThread& instance2 = SingletonThread::getInstance();

    cout << "Address of instance1: " << &instance1 << endl;
    cout << "Address of instance2: " << &instance2 << endl;

    return 0;
}