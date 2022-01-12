#ifndef INTERPRETFORTHLIKE_COMMAND_H
#define INTERPRETFORTHLIKE_COMMAND_H

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <cctype>
#include <cstdlib>
#include <functional>
#include <cwctype>
#include "interpreter_error.h"

struct Data {
    int pop_back(){
        int a = data.back();
        data.pop_back();
        return a;
    }
    std::string::iterator it;
    std::string::iterator end;
    std::vector<int> data;
    std::string result;
};

class Command {
public:
    virtual ~Command()= default;
    virtual void apply(Data& x) = 0;
};

class ArithCommand: public Command {
    void apply(Data& x) override {
        if (x.data.size() < 2)
            throw interpreter_error("Error arithmetic operation: not enough numbers");

        int a  = x.pop_back();
        int b = x.pop_back();
        x.data.push_back(op(a, b));
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

class Mod: public ArithCommand {
    int op(int& a, int& b) override {
        if (a == 0)
            throw interpreter_error("Error mod: first number is null");
        return a % b;
    }
};

class Div: public ArithCommand {
    int op(int& a, int& b) override {
        if (a == 0)
            throw interpreter_error("Error mod: first number is null");
        return a / b;
    }
};

class Mul: public ArithCommand {
    int op(int& a, int& b) override {
        return a * b;
    }
};

class LogicCommand: public Command {
    void apply(Data& x) override {
        if (x.data.size() < 2)
            throw interpreter_error("Error logic operation: not enough numbers");

        int a  = x.pop_back();
        int b = x.pop_back();

        std::stringstream ss;
        if (op(a, b)) {
            ss <<" "<< "1";
            x.result += ss.str();
            return;
        }
        ss <<" " << "0";
        x.result += ss.str();
    }

    virtual bool op(int& a, int& b) = 0;
};

class More: public LogicCommand {
    bool op(int& a, int& b) override {
        return a > b;
    }
};

class Less: public LogicCommand {
    bool op(int& a, int& b) override {
        return a < b;
    }
};

class Equals: public LogicCommand {
    bool op(int& a, int& b) override {
        return a == b;
    }
};

class OptionCommand: public Command {
    void apply(Data& x) override {
        if (x.data.empty())
            throw interpreter_error("Error optional operator: not enough numbers");

        op(x.data);
    }

    virtual void op(std::vector<int> &data) = 0;
};

class Dup: public OptionCommand {
    void op(std::vector<int> &data) override {
        data.push_back(data.back());
    }
};

class Drop: public OptionCommand {
    void op(std::vector<int> &data) override {
        data.pop_back();
    }
};

class Swap: public Command {
public:
    void apply(Data& x) override {
        if (x.data.size() < 2)
            throw interpreter_error("Error swap: not enough numbers");

        std::swap(*(x.data.end() -1), *(x.data.end() -2));
    }
};

class Rot: public Command {
public:
    void apply(Data& x) override {
        if (x.data.size() < 3)
            throw interpreter_error("Error rot: not enough numbers");

        std::swap(*(x.data.end() -1), *(x.data.end() -3));
        std::swap(*(x.data.end() -1), *(x.data.end() -2));
    }
};

class Over: public Command {
public:
    void apply(Data& x) override {
        if (x.data.size() < 2)
            throw interpreter_error("Error over: not enough numbers");

        x.data.push_back(*(x.data.end() - 2));
    }
};

class Cr: public Command {
public:
    void apply(Data& x) override {
        x.result += '\n';
    }
};

class Point: public Command {
public:
    void apply(Data& x) override {
        if (x.data.empty())
            throw interpreter_error("Error point: not enough numbers");

        std::stringstream ss;
        ss << " " << x.data.back();
        x.result += ss.str();
        x.data.pop_back();
    }
};

class Emit: public Command {
public:
    void apply(Data& x) override {
        if (x.data.empty())
            throw interpreter_error("Error emit: not enough numbers");

        if (x.data.back() < 0 || x.data.back() > 255)
            throw interpreter_error("Error emit: going out of bounds");

        std::stringstream ss;
        ss << " " << (char)x.data.back();
        x.result += ss.str();
        x.data.pop_back();
    }
};

class PrintString: public Command {
public:
    void apply(Data& x) override {
        std::string str;
        for (; x.it < x.end && *x.it != '"'; x.it++) {
            str += *x.it;
        }

        if (x.it == x.end)
            throw interpreter_error("Error .\": no \"");

        x.it++;
        x.result += str;
    }
};

class AddNumber: public Command {
public:
    void apply(Data& x) override {
        std::string str;
        int a = 1;
        if (*x.it == '-') {
            a = -1;
            x.it++;
        }
        for (; x.it < x.end && !std::isspace(*x.it); x.it++) {
            str += *x.it;
            if (!isdigit(*x.it))
                throw interpreter_error("Not number: " + str);
        }

        x.data.push_back(std::stoi(str) * a);
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
