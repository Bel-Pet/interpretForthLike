#ifndef INTERPRETFORTHLIKE_COMMAND_H
#define INTERPRETFORTHLIKE_COMMAND_H

#include <sstream>
#include <cctype>
#include <cstdlib>
#include <vector>
#include "interpreter_error.h"

struct Context {
    Context(std::vector<int>& data_, std::string::iterator &it, std::string::iterator &end) : stack(data_), it(it), end(end) {}
    std::vector<int>& stack;
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
    void apply(Context& x) override {
        if (x.stack.size() < 2)
            throw interpreter_error("Error arithmetic operation: not enough numbers");

        int a  = x.stack.back();
        x.stack.pop_back();
        int b = x.stack.back();
        // CR: add custom stack class
        x.stack.pop_back();
        x.stack.push_back(op(a, b));
    }

    virtual int op(int& a, int& b) = 0;
};

class Add: public ArithCommand {
    int op(int& a, int& b) override {
        return a + b;
    }
};

class Sub: public ArithCommand {
    int op(int& a, int& b) override {
        return a - b;
    }
};

class Mul: public ArithCommand {
    int op(int& a, int& b) override {
        return a * b;
    }
};

// CR: inherit ArithCommand, override apply and then invoke its apply
class Mod: public Command {
    void apply(Context& x) override {
        if (x.stack.size() < 2)
            throw interpreter_error("Error arithmetic operation: not enough numbers");

        int a  = x.stack.back();
        if (a == 0)
            throw interpreter_error("Error mod: first number is null");
        x.stack.pop_back();
        int b = x.stack.back();
        x.stack.pop_back();
        x.stack.push_back(a % b);
    }
};

// CR: same
class Div: public Command {
    void apply(Context& x) override {
        if (x.stack.size() < 2)
            throw interpreter_error("Error arithmetic operation: not enough numbers");

        int a  = x.stack.back();
        if (a == 0)
            throw interpreter_error("Error div: first number is null");
        x.stack.pop_back();
        int b = x.stack.back();
        x.stack.pop_back();
        x.stack.push_back(a / b);
    }
};

class More: public ArithCommand {
    int op(int& a, int& b) override {
        return a > b;
    }
};

class Less: public ArithCommand {
    int op(int& a, int& b) override {
        return a < b;
    }
};

class Equals: public ArithCommand {
    int op(int& a, int& b) override {
        return a == b;
    }
};

class Dup: public Command {
    void apply(Context& x) override {
        if (x.stack.empty())
            throw interpreter_error("Error optional operator: not enough numbers");

        x.stack.push_back(x.stack.back());
    }
};

class Drop: public Command {
    void apply(Context& x) override {
        if (x.stack.empty())
            throw interpreter_error("Error optional operator: not enough numbers");

        x.stack.pop_back();
    }
};

class Swap: public Command {
public:
    void apply(Context& x) override {
        if (x.stack.size() < 2)
            throw interpreter_error("Error swap: not enough numbers");

        std::swap(*(x.stack.end() -1), *(x.stack.end() -2));
    }
};

class Rot: public Command {
public:
    void apply(Context& x) override {
        if (x.stack.size() < 3)
            throw interpreter_error("Error rot: not enough numbers");

        std::swap(*(x.stack.end() -1), *(x.stack.end() -3));
        std::swap(*(x.stack.end() -1), *(x.stack.end() -2));
    }
};

class Over: public Command {
public:
    void apply(Context& x) override {
        if (x.stack.size() < 2)
            throw interpreter_error("Error over: not enough numbers");

        x.stack.push_back(*(x.stack.end() - 2));
    }
};

class Cr: public Command {
public:
    void apply(Context& x) override {
        x.result << '\n';
    }
};

class Point: public Command {
public:
    void apply(Context& x) override {
        if (x.stack.empty())
            throw interpreter_error("Error point: not enough numbers");

        x.result << " " << x.stack.back();
        x.stack.pop_back();
    }
};

class Emit: public Command {
public:
    void apply(Context& x) override {
        if (x.stack.empty())
            throw interpreter_error("Error emit: not enough numbers");

        if (x.stack.back() < 0 || x.stack.back() > 255)
            throw interpreter_error("Error emit: going out of bounds");

        x.result << " " << (char)x.stack.back();
        x.stack.pop_back();
    }
};

class PrintString: public Command {
public:
    void apply(Context& x) override {
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

/*class If: public Command {
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.back() == 0) {
            if (exist_else_) {
                processing_command(else_stack_command_, data, result);
                return;
            }
            return;
        }
        processing_command(stack_command_, data, result);
    }
private:
    static void processing_command(std::vector<Command *>& stack, std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) {
        auto it_stack_command = stack.begin();
        while (it_stack_command != stack.end()) {
            (*it_stack_command)->apply(data, result, it, end);
            it_stack_command++;
        }
    }
    std::vector<Command *> stack_command_;
    std::vector<Command *> else_stack_command_;
    bool exist_else_;
};
class Cycle: public Command {
public:
    Cycle(std::vector<Command *>& stack_command, bool& i): stack_command_(stack_command), i_(i){}
    void apply(std::vector<int>& data, std::stringstream & result, std::string::iterator& it, std::string::iterator& end) override {
        if (data.size() < 2)
            throw interpreter_error("not enough numbers");
        int a, b;
        if (i_) {
            a = *(data.end() - 1);
            b = *(data.end() - 2);
            data.pop_back();
            data.pop_back();
        } else {
            a = *(data.end() - 2);
            b = *(data.end() - 1);
            data.pop_back();
        }
        while (a < b) {
            auto it_stack_command = stack_command_.begin();
            while (it_stack_command != stack_command_.end()) {
                (*it_stack_command)->apply(data, result, it, end);
                it_stack_command++;
            }
            a++;
        }
    }
private:
    std::vector<Command *> stack_command_;
    bool i_;
};*/

/*class NewCommand: public Command {
public:
    explicit NewCommand(std::vector<Command *>& stack) : stack_command_(stack){}
    void apply(std::vector<int>& data) override {
        auto it = stack_command_.begin();
        while (it != stack_command_.end()) {
            (*it)->apply(data);
            it++;
        }
    }
    static std::map<std::string, std::vector<Command *>> command_map;
private:
    std::vector<Command *> stack_command_;
};
class AddCommand: public Command {
public:
    void apply(std::vector<int>& data) override {
    }
};*/

#endif