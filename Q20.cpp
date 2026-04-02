#include <iostream>
#include <vector>
#include<chrono>
using namespace std;

namespace {
    using Clock = std::chrono::high_resolution_clock;
}

template <typename T>
class MemoryAllocator{
    private:
    T* memory;
    vector<T*> allocatedBlocks;


    public:
    MemoryAllocator(size_t size){
        memory = new T[size];
        for(size_t i = 0; i < size; ++i){
            allocatedBlocks.push_back(&memory[i]);
        }
    }

    ~MemoryAllocator(){
        delete[] memory;
    }

    T* allocate(){
        T* block = allocatedBlocks.back();
        allocatedBlocks.pop_back();
        return block;
    }
    void deallocate(T* block){
        allocatedBlocks.push_back(block);
    }
};

int main(){
//Comparing My Memory Allocator with Standard New and Delete
    const size_t numAllocations = 1000000;
    MemoryAllocator<int> allocator(numAllocations);
    // Timing My Memory Allocator
    auto start = Clock::now();
    for(size_t i = 0; i < numAllocations; ++i){
        int* block = allocator.allocate();
        allocator.deallocate(block);
    }
    auto end = Clock::now();
    auto durationMyAllocator = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    // Timing Standard New and Delete
    start = Clock::now();

    for(size_t i = 0; i < numAllocations; ++i){
        int* block = new int;
        delete block;
    }
    end = Clock::now();
    auto durationStandard = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    cout << "My Memory Allocator Time: " << durationMyAllocator << " ms" << endl;
    cout << "Standard New/Delete Time: " << durationStandard << " ms" << endl;
    

    return 0;
}