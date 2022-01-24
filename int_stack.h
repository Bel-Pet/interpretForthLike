#ifndef INTERPRETFORTHLIKE_INT_STACK_H
#define INTERPRETFORTHLIKE_INT_STACK_H

#include <vector>
#include <iostream>

class IntStack {
public:
    IntStack() = default;

    ~IntStack() = default;

    void push(int a){
        data.push_back(a);
    }
    int pop(){
        int a = data.back();
        data.pop_back();
        return a;
    }
    // Return copy to stack element number a
    int at(int a){
        return *(data.begin() + a - 1);
    }

    int peek(){
        return data.back();
    }
    size_t size(){
        return data.size();
    }
    bool empty(){
        return data.empty();
    }
    // Swap element number a and b and return true
    // Return false if number does not exist
    bool swap( int a, int b) {
        if (data.size() < a || data.size() < b)
            return false;
        std::swap(*(data.end() - a), *(data.end() - b));
        return true;
    }
private:
    std::vector<int> data;
};

#endif //INTERPRETFORTHLIKE_INT_STACK_H
