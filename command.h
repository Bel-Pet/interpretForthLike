#ifndef INTERPRETFORTHLIKE_COMMAND_H
#define INTERPRETFORTHLIKE_COMMAND_H

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include "interpreter_error.h"

class Command {
public:
    virtual void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) = 0;
};

class Add: public Command {
public:
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a + b);
    }
};

class Sub: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a + b);
    }
};

class Mod: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a % b);
    }
};

class Div: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a / b);
    }
};

class Mul: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        int a  = data.back();
        data.pop_back();
        int b = data.back();
        data.pop_back();
        data.push_back(a * b);
    }
};

class More: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << 0;
            throw interpreter_error(ss.str());
        }
        auto a = data.end() - 1;
        auto b = data.end() - 2;
        std::cout << (int)(*a > *b) << std::endl;
    }
};

class Less: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << 0;
            throw interpreter_error(ss.str());
        }
        auto a = data.end() - 1;
        auto b = data.end() - 2;
        std::cout << (int)(*a < *b) << std::endl;
    }
};

class Equals: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << 0;
            throw interpreter_error(ss.str());
        }
        auto a = data.end() - 1;
        auto b = data.end() - 2;
        std::cout << (int)(*a == *b) << std::endl;
    }
};

class Dup: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.empty()) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        data.push_back(data.back());
    }
};

class Drop: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.empty()) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        data.pop_back();
    }
};

class Point: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.empty()) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        std::cout << data.back() << std::endl;
        data.pop_back();
    }
};

class Emit: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.empty()) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        std::cout << (char)data.back() << std::endl;
        data.pop_back();
    }
};

class Swap: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        std::swap(*(data.end() -1), *(data.end() -2));
    }
};

class Rot: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.size() < 3) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        std::swap(*(data.end() -1), *(data.end() -3));
        std::swap(*(data.end() -1), *(data.end() -2));
    }
};

class Over: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        data.push_back(*(data.end() - 2));
    }
};

class Cr: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.size() < 2) {
            std::stringstream ss;
            ss << "not enough numbers";
            throw interpreter_error(ss.str());
        }
        std::cout << data.back() << std::endl;
        data.pop_back();
        std::cout << data.back() << std::endl;
        data.pop_back();
    }
};

class PrintString: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        std::string str;
        while (it != end) {
            if (*it == '"')
                break;
            str += *it;
            it++;
        }
        if (it == end) {
            std::stringstream ss;
            ss << "not at the end of the line closing parenthesis";
            throw interpreter_error(ss.str());
        }
        std::cout << str << std::endl;
        it++;
    }
};

class AddNumber: public Command {
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        int num = 0;
        while (it != end && *it != ' ') {
            if (!(*it >= '0' && *it <= '9')) {
                std::stringstream ss;
                ss << "not number";
                throw interpreter_error(ss.str());
            }
            num = num * 10 + (int) (*it - '0');
            it++;
        }
        data.push_back(num);
    }
};


// Добавить private функцию для цикла
/*class If: public Command {
public:
    If(std::vector<Command *>& one_stack_command, std::vector<Command *>& two_stack_command, bool& exist_else): one_stack_command_(one_stack_command), two_stack_command_(two_stack_command), exist_else_(exist_else) {}
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (data.back() == 0) {
            if (exist_else_) {
                auto it_stack_command = two_stack_command_.end() - 1;
                while (it_stack_command != two_stack_command_.begin() - 1) {
                    (*it_stack_command)->apply(it, end, data);
                    it_stack_command--;
                }
                return;
            }
            return;
        }
        auto it_stack_command = one_stack_command_.end() - 1;
        while (it_stack_command != one_stack_command_.begin() - 1) {
            (*it_stack_command)->apply(it, end, data);
            it_stack_command--;
        }
    }
private:
    std::vector<Command *> one_stack_command_;
    std::vector<Command *> two_stack_command_;
    bool exist_else_;
};*/



class Cycle: public Command {
public:
    Cycle(std::vector<Command *>& stack_command, bool& i): stack_command_(stack_command), i_(i){}
    void apply(std::string::iterator & it, std::string::iterator & end, std::vector<int>& data) override {
        if (i_) {
            (*stack_command_.begin())->apply(it, end, data);
            (*stack_command_.begin())->apply(it, end, data);
            int a = data.back();
            data.pop_back();
            int b = data.back();
            data.pop_back();
            while (a > b) {
                auto it_stack = stack_command_.end() - 1;
                while (it_stack != stack_command_.begin() - 1) {
                    (*it_stack)->apply(it, end, data);
                    it_stack--;
                }
                a--;
            }
        }
    }
private:
    std::vector<Command *> stack_command_;
    bool i_;
};

#endif