#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

template <typename T, typename PriorityFunc = std::less<T>>
class PriorityQueue {
    public:
    void insert(const T& element){
        pq.push(element);
    };
    T getHighestPriority(){
        if(pq.empty()){
            throw std::runtime_error("Priority Queue is empty");
        }
        T top = pq.top();
        pq.pop();
        return top;
    };
    private:
    std::priority_queue<T, std::vector<T>, PriorityFunc> pq;
};

class CustomPriority {
    public:
    bool operator()(const int& a, const int& b) {
        return a > b; // Higher value has higher priority
    }
};

int main (){
    PriorityQueue<int , CustomPriority> pq;
    pq.insert(10);
    pq.insert(20);
    pq.insert(5);
    cout <<"This is a Min Priority Queue: " << pq.getHighestPriority() << endl; 


    return 0;
}