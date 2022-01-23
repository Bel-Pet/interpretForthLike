#ifndef INTERPRETFORTHLIKE_INT_STACK_H
#define INTERPRETFORTHLIKE_INT_STACK_H

#include <vector>
#include <iostream>
#include <sstream>

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
    // Return point to stack element number a
    // CR: return n-th element from the beginning of the stack, move `data.end() - n` to call site
    int at(int a) {
        int b = *(data.end() - a);
        return b;
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

// CR: move to separate file
struct Context {
    Context(IntStack& data_, std::string::iterator &it, std::string::iterator &end) : stack(data_), it(it), end(end) {}
    IntStack& stack;
    std::string::iterator& it;
    const std::string::iterator& end;
    std::stringstream result;
};

#endif //INTERPRETFORTHLIKE_INT_STACK_H
