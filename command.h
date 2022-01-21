#ifndef INTERPRETFORTHLIKE_COMMAND_H
#define INTERPRETFORTHLIKE_COMMAND_H

#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <vector>
#include "interpreter_error.h"

class IntStack {
private:
    std::vector<int> data;
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
    // CR: return number instead of iterator
    std::vector<int>::iterator end(){
        return data.end();
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
};

struct Context {
    Context(IntStack& data_, std::string::iterator &it, std::string::iterator &end) : stack(data_), it(it), end(end) {}
    IntStack& stack;
    std::string::iterator& it;
    const std::string::iterator& end;
    std::stringstream result;
};

class Command {
public:
    virtual ~Command()= default;
    virtual void apply(Context& x) = 0;
};

class ArithCommand: public Command {
public:
    void apply(Context& x) override {
        if (x.stack.size() < 2)
            throw interpreter_error("Error arithmetic operation: not enough numbers");

        int a  = x.stack.pop();

        int b = x.stack.pop();
        x.stack.push(op(a, b));
    }

    virtual int op(int& a, int& b)  = 0;
};

class Add: public ArithCommand {
    int op(int& a, int& b) override {
        return a + b;
    }
};

class Sub: public ArithCommand {
    int op(int& a, int& b)  override {
        return a - b;
    }
};

class Mul: public ArithCommand {
    int op(int& a, int& b)  override {
        return a * b;
    }
};

class Mod: public ArithCommand {
public:
    void apply(Context& x)  override {
        if (!x.stack.empty() && x.stack.peek() == 0)
            throw interpreter_error("Error mod: first number is null");
        ArithCommand::apply(x);
    }
    int op(int& a, int& b)  override {
        return a % b;
    }
};

class Div: public ArithCommand {
    void apply(Context& x)  override {
        if (!x.stack.empty() && x.stack.peek() == 0)
            throw interpreter_error("Error div: first number is null");
        ArithCommand::apply(x);
    }
    int op(int& a, int& b)  override {
        return a / b;
    }
};

class More: public ArithCommand {
    int op(int& a, int& b)  override {
        return a > b;
    }
};

class Less: public ArithCommand {
    int op(int& a, int& b)  override {
        return a < b;
    }
};

class Equals: public ArithCommand {
    int op(int& a, int& b)  override {
        return a == b;
    }
};

class Dup: public Command {
    void apply(Context& x)  override {
        if (x.stack.empty())
            throw interpreter_error("Error optional operator: not enough numbers");

        x.stack.push(x.stack.peek());
    }
};

class Drop: public Command {
    void apply(Context& x)  override {
        if (x.stack.empty())
            throw interpreter_error("Error optional operator: not enough numbers");

        x.stack.pop();
    }
};

class Swap: public Command {
public:
    void apply(Context& x)  override {
        if (x.stack.size() < 2)
            throw interpreter_error("Error swap: not enough numbers");

        std::swap(*(x.stack.end() -1), *(x.stack.end() -2));
    }
};

class Rot: public Command {
public:
    void apply(Context& x)  override {
        if (x.stack.size() < 3)
            throw interpreter_error("Error rot: not enough numbers");

        std::swap(*(x.stack.end() -1), *(x.stack.end() -3));
        std::swap(*(x.stack.end() -1), *(x.stack.end() -2));
    }
};

class Over: public Command {
public:
    void apply(Context& x)  override {
        if (x.stack.size() < 2)
            throw interpreter_error("Error over: not enough numbers");

        x.stack.push(*(x.stack.end() - 2));
    }
};

class Cr: public Command {
public:
    void apply(Context& x)  override {
        x.result << '\n';
    }
};

class Point: public Command {
public:
    void apply(Context& x)  override {
        if (x.stack.empty())
            throw interpreter_error("Error point: not enough numbers");

        x.result << " " << x.stack.pop();
    }
};

class Emit: public Command {
public:
    void apply(Context& x)  override {
        if (x.stack.empty())
            throw interpreter_error("Error emit: not enough numbers");

        int a = x.stack.pop();
        if (a < 0 || a > 255)
            throw interpreter_error("Error emit: number on stack is out of ASCII range");

        x.result << " " << (char)a;
    }
};

class PrintString: public Command {
public:
    void apply(Context& x)  override {
        std::string str;
        for (; x.it < x.end && *x.it != '"'; x.it++) {
            str += *x.it;
        }

        if (x.it == x.end)
            throw interpreter_error("Error .\": no \"");

        x.it++;
        x.result << str;
    }
};

#endif